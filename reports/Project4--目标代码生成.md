# Project4--目标代码生成

**成员：田昊东（211275022），汪科（211275032）**

## 基本数据结构

### 变量描述符表

用结构体链表实现。结构体如下：

```C
struct VaribleDescriptor
{
    char name[10];
    int regNo; //存储在的寄存器编号，没有装载的话就为-1
    int offset; //相对于$sp寄存器的偏移量
    struct VaribleDescriptor *next;
    struct VaribleDescriptor *prev;
};
typedef struct VaribleDescriptor VaribleDescriptor;
VaribleDescriptor *VaribleDescriptionTable;
```

### 寄存器描述符表

用结构体数组实现：

```C
struct RegisterDescriptor
{
    int cnt;
    int timestamp;
    char regname[5];
    char *VarNames[50];
};
typedef struct RegisterDescriptor RegisterDescriptor;
RegisterDescriptor RegisterDescriptionTable[32];
```

## 工具函数

* `void TrueParamClear()` 

  它的功能是把实参链表清空以供下一次函数调用使用。

* `void PushVariableToStack(VaribleDescriptor *var, int varsize)`

  在函数开头，在栈上为可能用到的局部变量一次性分配空间，但不生成指令。

* `CopyVariableToStack`

  将原本在栈上有分配空间的局部变量从寄存器拷回栈上。

* `RegRecycle`

  将一个寄存器中的内容溢出到内存中。

* `LoadVaribleIntoReg`

  将变量（或者内存位置）装入指定寄存器。

* `VaribleDescriptor *VaribleCreate(char *name)`

  在变量描述符表中创建一个变量的表项并附上寻址方式。

* `int getReg(char *name)`

  以模8递增的方式为一个变量分配一个寄存器（如果已经在某个寄存器里就不重新分配），然后返回寄存器编号。

* 还有别的

## 框架简述

在上一阶段中，我们生成了中间代码并以文本形式保存下来。这一阶段，我们直接读取这个文本文件，生成目标代码文本文件。

我们扫描两次：

* 第一次扫描，确定每个函数使用多少个中间变量，确定给它分配的栈空间。
* 第二次扫描，逐语句生成目标代码，我们按照空格进行切分，然后根据匹配规则生成对应目标代码。

### 栈空间分配

对于中间代码中这样的一个函数：

```
FUNCTION add :
PARAM ai
PARAM aj
t1 := ai
t2 := aj
t0 := t1 + t2
RETURN t0
```

经过第一次扫描，我们知道它需要使用到的局部变量有t1，t2，t0。所以在第二次扫描中，遇到`FUNCTION add:`语句时，就给它的栈帧中的局部变量分配4*3=12字节大小的空间。在目标代码中体现为：

```
addi $sp, $sp, -12
```

并在结尾（遇到`RETURN t0`语句时）处回收这部分空间。

#### 如何管理？

在一个栈帧中，\$fp寄存器的内容不变。所以我们以基于\$fp的偏移量来使用形参和局部变量。

在第二次扫描中，我们在一个函数内使用变量TrueFrameSize跟踪栈帧大小，并据此生成调整\$sp的汇编指令。

### 变量存储空间分配策略

在第一次扫描时我们已经知道有多少个局部变量了，所以第二次扫描时遇到形如`t1 := t2 + #k`形式的语句时，我们顺序地在栈上的一块区域给该变量绑定一个基于$fp寄存器偏移寻址的空间（该信息存储在变量描述符表中）。

### 寄存器分配策略

朴素地，对于每条语句需要使用到的变量，我们都先将其从栈帧中拷到寄存器中，计算完毕后再保存回去。

一条语句使用到的寄存器最多为6个，所以我们以模8递增的形式为调用getReg函数的变量分配一个寄存器号用于存储。我们仅对于目标变量所在的寄存器进行写回。

### x，&x，*x与#k

在我们的中间代码表示中，任何一个操作数（除了结果变量）都可能是立即数，普通变量或者变量解引用形式，结果变量可能是普通变量或者变量解引用形式。

当目标变量是普通变量或者变量解引用形式时：

* 当为普通变量时，我们直接将这个变量从内存拷贝到寄存器，运算完毕后再写回。

* 当为解引用形式变量时，我们先以相同策略申请一个寄存器来存放结果，然后按照这样的方式生成语句进行存储：

  ```C
  fprintf(ASMfile, "  sw %s,0(%s)\n", RegisterDescriptionTable[tmpEmptyReg].regname, RegisterDescriptionTable[getReg(eleArray[0] + 1)].regname);
  ```

对于操作数，我们一视同仁地使用getReg获取存储操作数的寄存器，并将不同的操作数类型所需要的指令在getReg函数中生成。具体地：

* 当操作数为立即数时，将操作数装载到某个寄存器中，然后返回其编号。
* 当操作数为普通变量时，将操作数使用lw指令从内存中拷贝到某个寄存器中，返回其编号。
* 当操作数为解引用变量时，在普通变量的基础上，二次使用`  lw %t0,0(t0)`指令来装载实际操作数，返回编号。
* 当操作数为引用形式`&x`时，我们**不在**getReg中进行处理，而简单地生成将该变量在内存中的地址（通过\$fp寄存器加偏移量形式进行定位）赋给某个寄存器的语句（addi实现）。

### 函数调用ARG和CALL

MIPS32的传参策略是：前4个寄存器装载到a0-a3寄存器，后面的逆序压栈。**由于在栈上的压入位置和参数个数有关，所以在扫描到ARG时，将其记录到实参链表中，等到CALL语句一起处理。**

当扫描到CALL时，顺序扫描实参链表，将4个及以下的参数装入寄存器，给多于4个的参数分配栈空间（修改$sp），然后装入（拷贝）。

此外，还需要在栈上保存调用者保存寄存器，并在扫描到RETURN的时候恢复。

