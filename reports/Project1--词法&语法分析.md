# Project1--词法&语法分析

**成员：田昊东（211275022），汪科（211275032）**

## 功能简述

除了必做部分，我们还完成了选做部分2.3。

### 词法分析器

我们使用Flex工具在`lexical.l`中实现了一个词法分析器。具体来说，我们：

* 为常见正则表达式定义了别名。这是通过形如`INT [-+]?([1-9][0-9]*|0)`的Flex语法实现的。
* 为识别到的词法单元定义动作，例如赋值属性值。
* 修改宏定义YY_USER_ACTION，以跟踪行/列号。

特别地，为了代码的简洁、易读和可维护性，我们使用了**宏定义**来帮助我们处理动作：

```C++
#define TOKEN_ACTION(token) \
    if(debug_printf)printf(#token"\n"); \
    yylval.val=new_node(#token,node_other); \
    return token; \
```

它能处理绝大多数的识别-动作：

```C++
{SEMI} { TOKEN_ACTION(SEMI)}
{COMMA} { TOKEN_ACTION(COMMA) }//etc
```

**选做部分**

对于行内注释`//`的识别，我们一旦识别到`//`就一直读取，直到遇到换行符或文件结尾：

```C++
"//" { 
    char c;
    while ((c = input()) != '\n' && c != EOF);
}
```

对于块注释，我们一旦识别到`/*`，就一直检测输入，直到遇到`*/`位置：

```C++
"/*" { 
    char c;
    while (1) 
    { 
        c = input(); 
        if (c == '*') 
        { 
            c = input();
            if (c == '/') 
                break;
        }
    } 
}
```

### 语法分析器

在`syntax.y`中，我们实现了语法分析器，具体来说，我们：

* 为每个词法单元添加了属性值`TreeNode* val`，含义是每个词法单元占据一个树节点。
* 规定了运算符的结合性和优先级。
* 填充了产生式的语法和动作。

进一步地，我们构建语法分析树。为此我们在`tree.h`中定义了结构体`TreeNode`。它主要包含如下信息：

```C++
struct TreeNode{
    int line;//所在行号
    int type;//所在列号
    char id[32],name[32];//名称
    int type_val;//词法单元类型
    int int_val;//如果是INT类型，它的值
    float float_val;//如果是FLOAT类型，它的值
    struct TreeNode* child[8];//它的子节点（产生式右侧）
    int child_num;//跟踪子节点数目
    int relop_val;//如果是运算符，它的类型
};
```

由于Bison应用自底向上的分析方法，采用移入-规约技术。所以在产生式的规约动作中，我们先创建父节点，然后将产生式右侧的节点当作子节点加入父节点的`child`数组中。

同样地，为了代码的简洁、易读和可维护性，我们使用了**宏定义**来帮助我们处理动作。它使用了C语言的**可变参数**，这样我们就能将其应用在不同的产生式上。

```C++
#define NNAC(parent,name,line_no,n,...) \
    TreeNode* p = new_node(name, node_grammar); \
    p->line = line_no; \
    TreeNode* children[] = {__VA_ARGS__}; \
    for(int i = 0; i < n; i++) \
    { \
        TreeNode* child = children[i]; \
        insert_child(p, child); \
    } \
    parent = p;
```

它能处理绝大多数的识别-动作：

```Bison
Specifier: TYPE {NNAC($$, "Specifier", @$.first_line, 1, $1)}
    | StructSpecifier {NNAC($$, "Specifier", @$.first_line, 1, $1)}
    ;
```

### 打印结果

编写了`print_tree`函数进行树的前序遍历，它在`tree.c`中定义。

## 编译-运行

我们修改了`CODE/p1/Code/Makefile`，并在`Code/p1/Test`中编写了一些额外的测试用例。

要编译运行，运行如下命令；

```makefile
cd /Code/p1/Code
make
make test
```

这将按照**编译词法分析器**——**编译语法分析器**——**编译语法分析器的C源代码文件（syntax）**——**编译其他C源代码文件**——**链接生成可执行文件parser**的顺序执行。

最后调用parser对输入文件进行解析并打印分析结果。