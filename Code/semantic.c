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
// 最后检查是否有函数没定义
bool check_func_definition()
{
    StructureField field = get_all_symbol();
    while (field)
    {
        if (field->type->kind == FUNCTION && field->type->content.func.functiontype == FUNCTION_DECLARATION)
        {
            add_semantic_error(18, field->type->content.func.line);
            return false;
        }
        field = field->next;
    }
}
bool Program(TreeNode *root)
{
    bool state=true;
    state = ExtDefList(root->child[0]) && state;
    state = check_func_definition() && state;
    return state;
}
bool ExtDefList(TreeNode *root)
{
    bool state = true;
    if (root->child_num == 0)
        return true;
    state = ExtDef(root->child[0]) && state;
    state = ExtDefList(root->child[1]) && state;
    return state;
}
Type Specifier(TreeNode *root)
{
    if (compareName(root, 1, "TYPE"))
    {
        if (root->child[0]->type_val == INT_TYPE)
            return createBasic(INT_TYPE);
        else if (root->child[0]->type_val == FLOAT_TYPE)
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
{
    Type type = Specifier(root->child[0]); // 继承属性，确定类型
    if (type == NULL)
        return false;
    if (compareName(root, 2, "Specifier", "SEMI"))
        return true;
    else if (compareName(root, 3, "Specifier", "ExtDecList", "SEMI")) // 变量定义
        return ExtDecList(root->child[1], type);
    else if (compareName(root, 3, "Specifier", "FunDec", "CompSt")){ // 函数定义
        bool state = true;
        state = FunDec(root->child[1], FUNCTION_DEFINITION, type) && state;
        state = CompSt(root->child[2], type) && state;
        return state;
    }
    else if (compareName(root, 3, "Specifier", "FunDec", "SEMI")) // 函数声明
        return FunDec(root->child[1], FUNCTION_DECLARATION, type);
    else
        return false;
}
bool ExtDecList(TreeNode *root, Type type) // 变量定义
{
    StructureField *field = malloc(sizeof(StructureField));
    *field = NULL;
    if (root->child_num == 1)
        return VarDec(root->child[0], type, NULL) != NULL;
    else if (root->child_num == 3){
        bool state = true;
        state = VarDec(root->child[0], type, NULL) != NULL && state;
        state = ExtDecList(root->child[2], type) && state;
        return state;
    }
}

Type StructSpecifier(TreeNode *root)
{
    if (compareName(root, 2, "STRUCT", "Tag"))
    {
        Type type = find_symbol(Tag(root->child[1]));
        if (type == NULL)
        {
            add_semantic_error(17, root->line); // 未定义的结构体
            return NULL;
        }
        return type;
    }
    else if (compareName(root, 5, "STRUCT", "OptTag", "LC", "DefList", "RC"))
    {
        char *anotag = OptTag(root->child[1]);
        Type type = find_symbol(anotag);
        if (type != NULL)
        {
            add_semantic_error(16, root->line);
            return NULL;
        }
        else
        {
            Type strutype = createStructure(anotag, NULL);
            DefList(root->child[3], strutype);
            if (anotag != NULL)
                add_symbol(anotag, strutype);
            return strutype;
        }
    }
    else
        return NULL;
}
char *OptTag(TreeNode *root)
{
    if (compareName(root, 1, "ID"))
    {
        return root->child[0]->id;
    }
    return NULL;
}
char *Tag(TreeNode *root)
{
    return root->child[0]->id;
}
Type VarDec(TreeNode *root, Type type, Type stru)
{
    if (compareName(root, 1, "ID"))
    {
        if (stru == NULL || stru->kind == FUNCTION)
        {
            if (find_symbol(root->child[0]->id) != NULL && (stru == NULL || stru->content.func.functiontype == FUNCTION_DEFINITION))
            {//对于函数声明，不应该加入符号表
                add_semantic_error(3, root->line);
                return NULL;
            }
            else
            {
                if (stru == NULL || stru->content.func.functiontype == FUNCTION_DEFINITION) // 函数声明不加入符号表
                    add_symbol(root->child[0]->id, type);
                return type;
            }
        }
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
    }
    else if (compareName(root, 4, "VarDec", "LB", "INT", "RB"))
    {
        return VarDec(root->child[0], createArray(type, root->child[2]->int_val), stru);
    }
    else
        return NULL;
}
bool FunDec(TreeNode *root, enum FunctionType functiontype, Type ret)
{
    StructureField *field = malloc(sizeof(StructureField));
    *field = NULL;
    if (compareName(root, 4, "ID", "LP", "VarList", "RP"))
    {
        VarList(root->child[2], createFunction(ret, functiontype, NULL), field);
    }
    else
        ;
    Type type = createFunction(ret, functiontype, *field);
    type->content.func.line = root->line;
    Type oldtype = find_symbol(root->child[0]->id);
    if (oldtype == NULL)
    {
        add_symbol(root->child[0]->id, type);
        return true;
    }
    else if (oldtype->content.func.functiontype == FUNCTION_DEFINITION && functiontype == FUNCTION_DEFINITION)
    {
        add_semantic_error(4, root->line); // 重定义
        return false;
    }
    else
    {
        if (!compareType(oldtype, type))
        {
            add_semantic_error(19, root->line);
            return false;
        }
        oldtype->content.func.functiontype = functiontype>oldtype->content.func.functiontype?functiontype:oldtype->content.func.functiontype;
        return true;
    }
}
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
// 函数参数项
bool ParamDec(TreeNode *root, Type func, StructureField *field)
{
    Type type = Specifier(root->child[0]);
    if (type == NULL)
        return false;
    Type vartype = VarDec(root->child[1], type, func);
    if (vartype == NULL)
        return false;
    addNode(field, vartype, root->child[1]->id);
    return true;
}
// 函数体
bool CompSt(TreeNode *root, Type ret) // rettype是函数返回值类型
{
    bool state = true;
    state = DefList(root->child[1], NULL) && state;
    state = StmtList(root->child[2], ret) && state;
    return state;
}
// 语句列表
bool StmtList(TreeNode *root, Type rettype)
{
    if (root->child_num == 0)
        return true;
    if (compareName(root, 2, "Stmt", "StmtList")){
        bool state = true;
        state = Stmt(root->child[0], rettype) && state;
        state = StmtList(root->child[1], rettype) && state;
        return state;
    }
}
// 语句
bool Stmt(TreeNode *root, Type ret)
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
        return CompSt(root->child[0], ret);
    }
    if (compareName(root, 3, "RETURN", "Exp", "SEMI"))
    {
        Type exp = Exp(root->child[1]);
        if (exp == NULL)
            return false;
        if (!compareType(exp, ret)) // 返回值类型不匹配
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
        return Stmt(root->child[4], ret);
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
        bool state = true;
        state = Stmt(root->child[4], ret) && state;
        state = Stmt(root->child[6], ret) && state;
        return state;
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
        return Stmt(root->child[4], ret);
    }
}
// 变量定义
bool DefList(TreeNode *root, Type stru)
{ // 可能用于结构体定义以及普通变量定义
    if (root->child_num == 0)
        return true;
    bool state = true;
    state = Def(root->child[0], stru) && state;
    state = DefList(root->child[1], stru) && state;
    return state;
}
// 单个定义语句；
bool Def(TreeNode *root, Type stru)
{
    Type type = Specifier(root->child[0]);
    if (type == NULL)
        return false;
    return DecList(root->child[1], type, stru);
}
// 声明列表
bool DecList(TreeNode *root, Type type, Type stru)
{
    if (compareName(root, 1, "Dec"))
        return Dec(root->child[0], type, stru);
    if (compareName(root, 3, "Dec", "COMMA", "DecList")){
        bool state = true;
        state = Dec(root->child[0], type, stru) && state;
        state = DecList(root->child[2], type, stru) && state;
        return state;
    }
}
// 声明单项
bool Dec(TreeNode *root, Type type, Type stru)
{
    Type var = VarDec(root->child[0], type, stru);
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
        if (stru != NULL)
        { // 结构体内部变量赋值
            add_semantic_error(15, root->line);
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
char* Exp(TreeNode *root, char *place)
{
    // 三元运算符
    char *basic3Operator[] = {"PLUS", "MINUS", "STAR", "DIV", "RELOP", "AND", "OR"};
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
            change_to_right(&type1); // 转换为右值
            return type1;
        }
    }
    // 括号
    if (compareName(root, 3, "LP", "Exp", "RP"))
        return Exp(root->child[1]);
    // 直接确定类型
    if (compareName(root, 1, "INT") || compareName(root, 1, "FLOAT"))
    {
        Type type = createBasic(strcmp(root->child[0]->name, "INT") == 0 ? INT_TYPE : FLOAT_TYPE);
        type->is_left = false;
        return type;
    }
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
        StructureField *field = malloc(sizeof(StructureField));
        *field = NULL;
        if (!Args(root->child[2], field))
            return NULL;
        if (!compareArgs(type->content.func.tail, *field))
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
    assert(0);
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
    else
        assert(0);
}