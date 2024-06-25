# Project2--中间代码生成

**成员：田昊东（211275022），汪科（211275032）**

## 框架简述

考虑到在语义分析的语义规则处理函数中，我们部分地利用了函数返回值传递类型或合法信息：

```C
Type Exp(TreeNode *root)
{
    // 三元运算符
    char *basic3Operator[] = {"PLUS", "MINUS", "STAR", "DIV", "RELOP", "AND", "OR"};
    for (int i = 0; i < 7; i++)
    {
        char *op = basic3Operator[i];
        if (compareName(root, 3, "Exp", op, "Exp"))
        {
            ...
```

而在中间代码生成过程中我们需要利用返回值来传递子节点中创建好的中间代码。所以，我们创建了ir.c，它的框架和semantic.c类似，但我们将不再检查语义错误，同时将返回值（大多）替换成char*类型：

```C
char *translate_Exp(TreeNode *root, Variable *place)
{
    char *res = NULL;
    // 三元运算符
    char *basic3Operator[] = {"PLUS", "MINUS", "STAR", "DIV"};
    char *basic3OperatorCode[] = {"+", "-", "*", "/"};
    for (int i = 0; i < 4; i++)
    {
        ...
```

## 表达式*

## 临时变量Variable*

最初我们认为在这一阶段，不太需要关心变量的类型，而只需关心其名称。但是在写代码时我们发现一些问题：

* 我们需要根据变量类型来确定访问成员变量时的偏移
* 在使用变量时，我们需要区分局部变量和实参

因此我们创建了Variable类型：

```C
struct Variable{
    char*name;
    bool is_pointer;
    bool is_sa;
};
```



## 变量定义VarDec

这部分功能由`translate_VarDec`实现。在实现的时候我们注意到：该函数会被**局部变量定义**和**函数参数列表**共同使用，前者需要由`DEC`声明，后者需要由`PARAM`声明。

这里我们在该函数的参数列表中加入一个bool类型变量来区分这两种情况。

## （临时）变量名/标签生成

```C
char *new_label()
{
    char *label = malloc(30);
    sprintf(label, "label%d", label_cnt++);
    return label;
}
char *new_temp()
{
    char *temp = malloc(30);
    sprintf(temp, "t%d", temp_cnt++);
    return temp;
}
char *get_relop(TreeNode *root)
{
    if (root->relop_val == 1)
        return ">";
    ...
}
```

这里我们使用全局变量自增形式来保证不会出现重复的中间变量。

## 条件

translate_Cond函数负责对条件表达式进行翻译。举一个例子来说明其机制：

```C
else if (compareName(root, 3, "Exp", "AND", "Exp"))
{
    char *label1 = new_label();
    char *code1 = translate_Cond(root->child[0], label1, label_false);
    char *code2 = translate_Cond(root->child[2], label_true, label_false);
    char *ret = malloc(strlen(code1) + strlen(label1) + strlen(code2) + 300);
    sprintf(ret, "%sLABEL %s :\n%s", code1, label1, code2);
    return ret;
}
```

* 翻译 `root` 的第一个子节点，并生成对应的中间代码 `code1`。这个翻译过程需要两个标签：`label1` 和 `label_false`，这两个标签分别表示这个表达式为真和为假时应该跳转到的位置。
* 翻译 `root` 的第三个子节点，并生成对应的中间代码 `code2`。这个翻译过程也需要两个标签：`label_true` 和 `label_false`，这两个标签分别表示这个表达式为真和为假时应该跳转到的位置。
* 将 `code1`、`label1` 和 `code2` 拼接起来，形成最终的中间代码 `ret`。这个中间代码首先执行 `code1`，然后跳转到 `label1`，然后执行 `code2`。

这个过程可以理解为：如果 `root` 的第一个子节点的表达式为真，那么就跳转到 `label1`，然后执行 `root` 的第三个子节点的表达式；如果 `root` 的第一个子节点的表达式为假，那么就直接跳转到 `label_false`。

### 当结构体作为函数参数*

