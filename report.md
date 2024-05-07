# Project2--语义分析

**成员：田昊东（211275022），汪科（211275032）**

### 类型、域的设计

类型Type和域StructureField的实现我们大致参照了Project_2.pdf中给出的示例。不同的是，我们在Type的union结构中额外添加了如下信息：

```C
struct
{
    StructureField tail;
    Type ret;
    enum FunctionType functiontype; // 函数类型（定义或声明）
    int line;//函数定义的行数(用于定义缺失的输出)
} func;                             // 函数
struct
{
    StructureField *table;
    char *name;
} stru;
```

这意味着我们将这个结构额外用于两处：

* 我们将函数视为一种类型Type，包含了函数标识符的信息，标识符中的参数列表以StructureField链表的形式存在。
* 我们将类型视为一种类型Type，包含了结构体名称，以及一个StructureField指针数组（作为哈希表），含了结构体所有成员信息。

### 语义分析流程

在语法分析阶段我们生成了语法分析树，它使用TreeNode数据结构实现。在这一阶段，我们对树进行递归式前序遍历，来扫描对应的语义错误。

遍历到某个结点时，它负责生成在当前结点能够辨识的语义错误信息。

举例说明：

```C
else if (stru->kind == STRUCTURE)
{
    if (find_symbol_in(stru, root->child[0]->id) != NULL)
    {
        add_semantic_error(15, root->line);
        return NULL;
    }
    else
    {
        add_symbol_to(stru, root->child[0]->id, type);
        return type;
    }
}
```

这是函数VarDec中的一部分。这里描述了：当声明的结构体名称已经存在于符号表中，表明出现了结构体重定义，此时加入报错信息。

这一错误应当在VarDec层级识别。

### VarDec类型创建

VarDec的生成式如下：

```
VarDec: ID { NNAC($$, "VarDec", @$.first_line, 1, $1)}
| VarDec LB INT RB {NNAC($$, "VarDec", @$.first_line, 4, $1, $2,$3,$4)}
;
```

在完成（数组）变量定义插入到符号表这一操作时，我们最初的设想是：令VarDec返回一个Type类型，然后带着这个类型去遍历INT，将INT代表的维度插入到Type的最后。但这样的插入方式进行了不必要的链表遍历。

经过分析，我们决定采用从右到左的遍历：

* VarDec函数接受一个Type参数，代表上层已经生成的子类型。
* 若当前VarDec仅包含ID，那么在这一层生成变量名和类型，插入到符号表中。
* 若不然，则创建INT个上层Type，作为新的Type传入下一级VarDec。

### 使用二级指针创建链表

在FunDec中，我们研究了如何管理函数参数列表。

* 我们希望能够将这些参数串成一个StructureField链表。
* 我们希望能够在递归中比较高效地进行链表结点插入，并且希望能简化链表操作，不需要对链表是否为空等特殊情况讨论

因此我们采用了StructureField二级指针来实现。

在FunDec中的调用：

```C
StructureField *field = malloc(sizeof(StructureField));
*field = NULL;
VarList(root->child[2], createFunction(ret, functiontype, NULL), field);
```

VarList：

```C
bool VarList(TreeNode *root, Type type, StructureField *field)
{
    if (compareName(root, 1, "ParamDec"))
        return ParamDec(root->child[0], type, field);
    else{
        bool state = true;
        state = ParamDec(root->child[0], type, field) && state;
        state = VarList(root->child[2], type, field) && state;
        return state;
    }
}
```

我们只需要始终传递二级指针，就可以不必遍历链表实现结点插入。

最终解引用FunDec的field二级指针就可以创建函数Type。

### 左值与右值的转化

由于实验要求只能对左值进行赋值，因此我们需要考虑左值与右值的转化。

变量是左值，但是变量运算之后就不是左值，函数返回值是同样不是左值，进行如下操作：

- 创建函数时就对返回值类型设置为右值（使用一个bool标志）。
- 两个exp运算后得到的新exp需要为右值。

需要注意的是不能在原先的type上直接修改标志位，不然由于指针的副作用会休要原先变量在符号表种的内容。

因此设计了`Type deepcopy(Type type)`和`StructureField deepcopy_field(StructureField field)`通过递归调用实现对type的完全深拷贝，之后再将深拷贝的结果转化为右值`void change_to_right(Type *type)`

此处也使用了二级指针，使用时只需要传入一个type，就会自动进行转化`change_to_right(&type1);`

```c
void change_to_right(Type *type){
    Type t = deepcopy(*type);
    *type = t;
    switch ((*type)->kind)
    {
        case BASIC:...
        case STRUCTURE:...
            case ARRAY:.
    }
}
```

### 函数的声明与定义

函数只能有一次定义，但是可以有多次声明并且顺序不固定，使用一个枚举类型表示当前FunDec是声明还是定义，并且在符号表种也存储作为func类型的属性。

得到一个新的函数type之后进行如下检查：

- 如果符号表中有同名函数
  - 如果表中为定义，新得到的同为定义，则发生重定义，报错
  - 如果表中为定义，新得到的为声明，则比较函数类型（返回值及参数）是否相同
  - 如果表中为声明，同样进行参数检查，并且吐过新得到的为定义，则要将符号表种的type从声明更新为定义
- 如果符号表中没有，则直接插入

当树上搜索检查完成后，遍历符号表中的函数类型，如果有标记为声明的（即没有出现对应的定义）就进行报错
