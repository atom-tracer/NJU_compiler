#include "semantic.h"
// 比较文法
bool compareName(TreeNode *root, int num, ...)
{ // num必须从小到大遍历
    if (!root || root->child_num != num)
        return false;
    va_list args;
    va_start(args, num);
    for (int i = 0; i < num; i++)
    {
        if (strcmp(root->child[i]->name, va_arg(args, char *)) != 0)
            return false;
    }
    va_end(args);
    return true;
}
extern int var_list[], fun_list[];
bool Program(TreeNode *root)
{
    return ExtDefList(root->child[0]);
}
bool ExtDefList(TreeNode *root)
{
    if (root->child_num == 0)
        return true;
    return ExtDef(root->child[0]) && ExtDefList(root->child[1]);
}
Type Specifier(TreeNode *root)
{
    if (compareName(root, 1, "TYPE"))
    {
        if (root->child[0]->type == INT_TYPE)
            return createBasic(INT_TYPE);
        else if (root->child[0]->type == FLOAT_TYPE)
            return createBasic(FLOAT_TYPE);
        else
            return NULL;
    }
    else if (compareName(root, 1, "StructSpecifier"))
        return StructSpecifier(root->child[0]);
    else
        return NULL;
}
bool ExtDef(TreeNode *root)
// TODO:类型是否定义过了；函数是否定义过了；函数是否冲突
{
    Type type = Specifier(root->child[0]); // 继承属性，确定类型
    if (type == NULL)
        return false;
    if (compareName(root, 2, "Specifier", "SEMI"))
        return true;
    else if (compareName(root, 3, "Specifier", "ExtDecList", "SEMI")) // 变量定义
        return ExtDecList(root->child[1], type);
    // TODO：也许我不需要传递type？
    else if (compareName(root, 3, "Specifier", "FunDec", "CompSt")) // 函数定义
        return FunDec(root->child[1], type) && CompSt(root->child[2], type);
    // TODO:也许我需要传递参数类型，在CompSt中判断返回值是否匹配
    else if (compareName(root, 3, "Specifier", "FunDec", "SEMI")) // 函数声明
        return FunDec(root->child[1], type);
    else
        return false;
}
bool ExtDecList(TreeNode *root, Type type)
{
    if (root->child_num == 1)
    {
        Type vartype = VarDec(root->child[0], type);
    }
    else if (root->child_num == 3)
        return VarDec(root->child[0], type) && ExtDecList(root->child[2], type);
    else
        return false;
}
bool StructSpecifier(TreeNode *root)
{
    if (compareName(root, 2, "STRUCT", "Tag"))
    {
        Type type = createStructure(NULL, NULL);
        return DefList(root->child[1], type) && Tag(root);
    }
    else if (compareName(root, 5, "STRUCT", "Tag", "LC", "DefList", "RC"))
    {
        Type type = find_symbol(root->child[1]->id);
        if (type != NULL)
        {
            add_semantic_error(16, root->line);
            return false;
        }
        else
        {
            add_symbol(root->child[1]->id, createStructure(root->child[1]->id, NULL));
            return true;
        }
    }
    else if (compareName(root, 2, "STRUCT", "LC"))
    {
        Type type = createStructure(NULL, NULL);
        return DefList(root->child[1], type) && Tag(root);
    }
    else
        return false;
}

bool OptTag(TreeNode *root, Type type);
bool Tag(TreeNode *root);
bool VarDec(TreeNode *root, Type type)
{
    if (compareName(root, 1, "ID"))
    {
        if (find_symbol(root->child[0]->id) != NULL)
        {
            add_semantic_error(3, root->line);
            return false;
        }
        else
        {
            add_symbol(root->child[0]->id, type);
            return true;
        }
    }
    else if (compareName(root, 4, "VarDec", "LB", "INT", "RB"))
    {
        return VarDec(root->child[0], createArray(type, root->child[2]->int_val));
    }
    else
        return false;
}
bool FunDec(TreeNode *root, Type type)
{
    if (strcmp(root->child[2]->name, "VarList") == 0)
    {
        ; // 插入符号表，判断合法性
    }
    else if (strcmp(root->child[2]->name, "RP") == 0)
    {
        ; // 插入符号表，判断合法性
    }
    else
        return false;
}
bool VarList(TreeNode *root, Type type)
{
    if (strcmp(root->child[0]->name, "ParamDec") == 0)
        return ParamDec(root->child[0], type) && VarList(root->child[2], type);
    else
        return false;
}
bool ParamDec(TreeNode *root, Type type);
bool CompSt(TreeNode *root, Type type);
bool StmtList(TreeNode *root, Type type);
bool Stmt(TreeNode *root, Type type);
bool DefList(TreeNode *root, Type type);
bool Def(TreeNode *root, Type type);
bool DecList(TreeNode *root, Type type);
bool Dec(TreeNode *root, Type type);
// 表达式
Type Exp(TreeNode *root)
{
    // 三元运算符
    char **basic3Operator = {"PLUS", "MINUS", "STAR", "DIV", "AND", "OR", "RELOP"};
    for (int i = 0; i < 7; i++)
    {
        char *op = basic3Operator[i];
        if (compareName(root, 3, "Exp", op, "Exp"))
        {
            Type type1 = Exp(root->child[0]);
            Type type2 = Exp(root->child[2]);
            if (type1 == NULL || type2 == NULL)
                return NULL;
            if (!compareType(type1, type2) || type1->kind != BASIC || type2->kind != BASIC)
            { // 类型不同或不是基本类型
                add_semantic_error(7, root->line);
                return NULL;
            }
            return type1;
        }
    }
    // 括号
    if (compareName(root, 3, "LP", "Exp", "RP"))
        return Exp(root->child[1]);
    // 直接确定类型
    if (compareName(root, 1, "INT") || compareName(root, 1, "FLOAT"))
        return createBasic(root->child[0]->type);
    // 变量
    if (compareName(root, 1, "ID"))
    {
        Type type = find_symbol(root->child[0]->id);
        if (type == NULL)
        {
            add_semantic_error(1, root->line);
            return NULL;
        }
        return type;
    }
    // 负号
    if (compareName(root, 2, "MINUS", "Exp"))
    {
        Type type = Exp(root->child[1]);
        if (type == NULL)
            return NULL;
        if (type->kind != BASIC)
        {
            add_semantic_error(7, root->line);
            return NULL;
        }
        return type;
        float a = 1.0;
    }
    // 数组解析
    if (compareName(root, 4, "Exp", "LB", "Exp", "RB"))
    {
        Type type1 = Exp(root->child[0]);
        Type type2 = Exp(root->child[2]);
        if (type1 == NULL || type2 == NULL)
            return NULL;
        if (type1->kind != ARRAY)
        { // 不是数组
            add_semantic_error(10, root->line);
            return NULL;
        }
        if (type2->kind != BASIC || type2->content.basic != INT_TYPE)
        { // 下标不是整数
            add_semantic_error(12, root->line);
            return NULL;
        }
        return type1->content.array.elem;
    }
    // 结构体解析
    if (compareName(root, 3, "Exp", "DOT", "ID"))
    {
        Type type = Exp(root->child[0]);
        if (type == NULL)
            return NULL;
        if (type->kind != STRUCTURE)
        {
            add_semantic_error(13, root->line); // 不是结构体
            return NULL;
        }
        Type field = find_symbol_in(type, root->child[2]->id);
        if (field == NULL)
        { // 域不存在
            add_semantic_error(14, root->line);
            return NULL;
        }
        return field;
    }
    // 无参函数调用
    if (compareName(root, 3, "ID", "LP", "RP"))
    {
        Type type = find_symbol(root->child[0]->id);
        if (type == NULL)
        { // 函数不存在
            add_semantic_error(2, root->line);
            return NULL;
        }
        if (type->kind != FUNCTION)
        { // 不是函数
            add_semantic_error(11, root->line);
            return NULL;
        }
        if (type->content.func.tail != NULL)
        { // 参数不匹配
            add_semantic_error(9, root->line);
            return NULL;
        }
        type->content.func.isused = true;
        return getFunctionRet(type);
    }
    // 有参函数调用
    if (compareName(root, 4, "ID", "LP", "Args", "RP"))
    {
        Type type = find_symbol(root->child[0]->id);
        if (type == NULL)
        {
            add_semantic_error(2, root->line);
            return NULL;
        }
        if (type->kind != FUNCTION)
        {
            add_semantic_error(11, root->line);
            return NULL;
        }
        StructureField field = NULL;
        if (!Args(root->child[2], field))
            return NULL;
        if (!compareArgs(type->content.func.tail, field))
        {
            add_semantic_error(9, root->line);
            return NULL;
        }
        type->content.func.isused = true;
        return getFunctionRet(type);
    }
    // not操作
    if (compareName(root, 2, "NOT", "Exp"))
    {
        Type type = Exp(root->child[1]);
        if (type == NULL)
            return NULL;
        if (type->kind != BASIC)
        {
            add_semantic_error(7, root->line);
            return NULL;
        }
        return type;
    }
    // 赋值操作
    if (compareName(root, 3, "Exp", "ASSIGNOP", "Exp"))
    {
        Type type1 = Exp(root->child[0]);
        Type type2 = Exp(root->child[2]);
        if (type1 == NULL || type2 == NULL)
            return NULL;
        if (!compareType(type1, type2))
        { // 类型不同
            add_semantic_error(5, root->line);
            return NULL;
        }

        return type1;
    }
    assign(0);
}
// 调用函数的形参列表
bool Args(TreeNode *root, StructureField *field)
{
    if (compareName(root, 1, "Exp")) // 参数列表末尾
    {
        Type exp_type = Exp(root->child[0]);
        if (exp_type == NULL) // 存在表达式类型错误
            return false;
        addNode(field, exp_type, NULL);
        return true;
    }
    // 参数列表非末尾
    else if (compareName(root, 3, "Exp", "COMMA", "Args"))
    {
        Type exp_type = Exp(root->child[0]);
        if (exp_type == NULL)
            return false;
        addNode(field, exp_type, NULL);
        return Args(root->child[2], field);
    }
    assert(0);
}