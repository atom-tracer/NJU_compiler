#include "semantic.h"
// 比较文法
bool compareName(TreeNode *root, int num, ...)
{
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
    if (strcmp(root->child[0]->name, "TYPE") == 0)
    {
        if (root->child[0]->type == INT_TYPE)
            return createBasic(INT_TYPE);
        else if (root->child[0]->type == FLOAT_TYPE)
            return createBasic(FLOAT_TYPE);
        else
            return NULL;
    }
    else if (strcmp(root->child[0]->name, "StructSpecifier") == 0)
        return StructSpecifier(root->child[0]);
    else
        return NULL;
}
bool ExtDef(TreeNode *root)
{
    Type type = Specifier(root->child[0]); // 继承属性，确定类型
    if (type == NULL)
        return false;
    if (strcmp(root->child[1]->name, "ExtDecList") == 0) // 变量定义
        return ExtDecList(root->child[1], type);
    else if (strcmp(root->child[1]->name, "SEMI") == 0)
        return true;
    else if (strcmp(root->child[1]->name, "FunDec") == 0) // 函数定义/声明
                                                          // 先findsymbol，查看其是否为定义
        return FunDec(root->child[1], type) && CompSt(root->child[2], type);
    else
        return false;
}
bool ExtDecList(TreeNode *root, Type type)//变量定义
{
    StructureField field = NULL;//对于变量定义，这个符号表没有用
    if (root->child_num == 1)
        return VarDec(root->child[0], type, field);
    else if (root->child_num == 3)
        return VarDec(root->child[0], type, field) && ExtDecList(root->child[2], type);
}

Type StructSpecifier(TreeNode *root){
    if(compareName(root, 5, "STRUCT", "Tag", "LC", "DefList", "RC")){
        StructureField field = NULL;
        if(!DefList(root->child[3], field))
            return NULL;
        Type type = createStructure(Tag(root->child[1]), field);
        add_symbol(Tag(root->child[1]), type);//存储结构体类型
        return type;
    }
    if(compareName(root, 2, "STRUCT", "Tag")){
        Type type = find_symbol(Tag(root->child[1]));
        if(type==NULL||type->kind!=STRUCTURE)
            return NULL;
        return type;
    }
}
char* OptTag(TreeNode *root, Type type){
    if(strcmp(root->child[0]->name,"ID")==0){
        return root->child[0]->id;
    }
    return NULL;
}
char* Tag(TreeNode *root){
    return root->child[0]->id;
}
Type VarDec(TreeNode *root, Type type, StructureField *field)
{
    Type new_type = type;
    if (strcmp(root->child[0]->name, "ID") == 0)
    {
        ; // 查找是否重复定义并插入
    }
    else if (strcmp(root->child[0]->name, "VarDec") == 0)
    {
        // 数组定义
        new_type = VarDec(root->child[0], type, field);
        Type typetail = new_type;
        while (typetail->kind != BASIC)
            typetail = typetail->content.array.elem;
        typetail->kind = ARRAY;
        typetail->content.array.elem = createArray(createBasic(typetail->content.basic), root->child[2]->int_val);
        return new_type;
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
// 函数参数项
bool ParamDec(TreeNode *root, StructureField *field){
    Type new_type = Specifier(root->child[0]);
    if(new_type==NULL)
        return false;
    return VarDec(root->child[1],new_type,field);
}
// 函数体
bool CompSt(TreeNode *root, Type rettype) // rettype是函数返回值类型
{
    StructureField *field = NULL; // 对于函数，这个符号表没有用
    return DefList(root->child[1], field) && StmtList(root->child[2], rettype);
}
// 语句列表
bool StmtList(TreeNode *root, Type rettype)
{
    if (root->child_num == 0)
        return true;
    if (compareName(root, 2, "Stmt", "StmtList"))
        return Stmt(root->child[0], rettype) && StmtList(root->child[1], rettype);
}
// 语句
bool Stmt(TreeNode *root, Type rettype)
{
    if (compareName(root, 2, "Exp", "SEMI"))
    {
        Type exp = Exp(root->child[0]);
        if (exp == NULL)
            return false;
        return true;
    }
    if (compareName(root, 1, "CompSt"))
    {
        return CompSt(root->child[0], rettype);
    }
    if (compareName(root, 3, "RETURN", "Exp", "SEMI"))
    {
        Type exp = Exp(root->child[1]);
        if (exp == NULL)
            return false;
        if (!compareType(exp, rettype)) // 返回值类型不匹配
        {
            add_semantic_error(8, root->line);
            return false;
        }
        return true;
    }
    if (compareName(root, 5, "IF", "LP", "Exp", "RP", "Stmt"))
    {
        Type exp = Exp(root->child[2]);
        if (exp == NULL)
            return false;
        if (exp->kind != BASIC || exp->content.basic != INT_TYPE)
        {
            add_semantic_error(7, root->line);
            return false;
        }
        return Stmt(root->child[4], rettype);
    }
    if (compareName(root, 7, "IF", "LP", "Exp", "RP", "Stmt", "ELSE", "Stmt"))
    {
        Type exp = Exp(root->child[2]);
        if (exp == NULL)
            return false;
        if (exp->kind != BASIC || exp->content.basic != INT_TYPE)
        {
            add_semantic_error(7, root->line);
            return false;
        }
        return Stmt(root->child[4], rettype) && Stmt(root->child[6], rettype);
    }
    if (compareName(root, 5, "WHILE", "LP", "Exp", "RP", "Stmt"))
    {
        Type exp = Exp(root->child[2]);
        if (exp == NULL)
            return false;
        if (exp->kind != BASIC || exp->content.basic != INT_TYPE)
        {
            add_semantic_error(7, root->line);
            return false;
        }
        return Stmt(root->child[4], rettype);
    }
}
// 变量定义
bool DefList(TreeNode *root, StructureField *field)
{ // 可能用于结构体定义以及普通变量定义
    if (root->child_num == 0)
        return true;
    return Def(root->child[0], field) && DefList(root->child[1], field);
}
// 单个定义语句；
bool Def(TreeNode *root, StructureField *field)
{
    Type type = Specifier(root->child[0]);
    if (type == NULL)
        return false;
    return DecList(root->child[1], type, field);
}
// 声明列表
bool DecList(TreeNode *root, Type type, StructureField *field)
{
    if (compareName(root, 1, "Dec"))
        return Dec(root->child[0], type, field);
    if (compareName(root, 3, "Dec", "COMMA", "DecList"))
        return Dec(root->child[0], type, field) && DecList(root->child[2], type, field);
}
// 声明单项
bool Dec(TreeNode *root, Type type, StructureField *field)
{
    Type var = VarDec(root->child[0], type, field);
    if (var == NULL)
        return false;
    if (compareName(root, 1, "VarDec"))
    {
        return true;
    }
    if (compareName(root, 3, "VarDec", "ASSIGNOP", "Exp"))
    {
        Type exp = Exp(root->child[2]);
        if (exp == NULL)
            return false;
        if (!compareType(var, exp))
        {
            add_semantic_error(5, root->line);
            return false;
        }
        if (!var->is_left)
        { // 变量定义不应该有右值
            assert(0);
            add_semantic_error(6, root->line);
            return false;
        }
        return true;
    }
}
// 表达式
Type Exp(TreeNode *root)
{
    // 三元运算符
    char **basic3Operator = {"PLUS", "MINUS", "STAR", "DIV", "RELOP", "AND", "OR"};
    for (int i = 0; i < 7; i++)
    {
        char *op = basic3Operator[i];
        if (compareName(root, 3, "Exp", op, "Exp"))
        {
            Type type1 = Exp(root->child[0]);
            Type type2 = Exp(root->child[2]);
            if (type1 == NULL || type2 == NULL)
                return NULL;
            if (!compareType(type1, type2) || type1->kind != BASIC || type2->kind != BASIC || i > 4 && (type1->content.basic != INT_TYPE || type2->content.basic != INT_TYPE))
            { // 类型不同或不是基本类型
                add_semantic_error(7, root->line);
                return NULL;
            }
            { // 类型不同或不是基本类型
                add_semantic_error(7, root->line);
                return NULL;
            }
            change_to_right(&type1); // 转换为右值
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
        Type type1 = Exp(root->child[1]);
        if (type1 == NULL)
            return NULL;
        if (type1->kind != BASIC)
        {
            add_semantic_error(7, root->line);
            return NULL;
        }
        change_to_right(&type1); // 转换为右值
        return type1;
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
        return getFunctionRet(type);
    }
    // not操作
    if (compareName(root, 2, "NOT", "Exp"))
    {
        Type type1 = Exp(root->child[1]);
        if (type1 == NULL)
            return NULL;
        if (type1->kind != BASIC || type1->content.basic != INT_TYPE)
        {
            add_semantic_error(7, root->line);
            return NULL;
        }
        change_to_right(&type1); // 转换为右值
        return type1;
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
        if (!type1->is_left)
        { // 不是左值
            add_semantic_error(6, root->line);
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