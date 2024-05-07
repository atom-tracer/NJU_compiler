#include "ir.h"
int temp_cnt = 0;
int label_cnt = 0;
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
    bool state = true;
    state = ExtDefList(root->child[0]) && state;
    state = check_func_definition() && state;
    return state;
}
char *translate_ExtDefList(TreeNode *root)
{
    if (root->child_num == 0)
        return NULL;
    char *code1 = translate_ExtDef(root->child[0]);
    char *code2 = translate_ExtDefList(root->child[1]);
    char *ret = malloc(strlen(code1) + strlen(code2) + 10);
    sprintf(ret, "%s%s", code1, code2);
    return ret;
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
char *translate_ExtDef(TreeNode *root)
{
    Type type = Specifier(root->child[0]); // 继承属性，确定类型
    if (compareName(root, 2, "Specifier", "SEMI"))
        return NULL;                                                  // 结构体无需生成代码，而且没有全局变量
    else if (compareName(root, 3, "Specifier", "ExtDecList", "SEMI")) // 变量定义
    {
        return NULL; // 结构体无需生成代码，而且没有全局变量
    }
    else if (compareName(root, 3, "Specifier", "FunDec", "CompSt"))
    { // 函数定义
        char *code1 = malloc(root->child[1]->);
        state = FunDec(root->child[1], FUNCTION_DEFINITION, type) && state;
        state = CompSt(root->child[2], type) && state;
        return state;
    }
    else if (compareName(root, 3, "Specifier", "FunDec", "SEMI")) // 函数声明
        return FunDec(root->child[1], FUNCTION_DECLARATION, type);
    else
        return false;
}
char *translate_ExtDecList(TreeNode *root, Type type) // 变量定义
{
    StructureField *field = malloc(sizeof(StructureField));
    *field = NULL;
    if (root->child_num == 1)
        return VarDec(root->child[0], type, NULL) != NULL;
    else if (root->child_num == 3)
    {
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
char *VarDec(TreeNode *root, Type type)
{
    char *res;
    if (compareName(root, 1, "ID"))
    {
        if (type->kind == STRUCTURE)
    }
    else if (compareName(root, 4, "VarDec", "LB", "INT", "RB"))
    {
        res = VarDec(root->child[0], createArray(type, root->child[2]->int_val));
    }
    return res;
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
        oldtype->content.func.functiontype = functiontype > oldtype->content.func.functiontype ? functiontype : oldtype->content.func.functiontype;
        return true;
    }
}
bool VarList(TreeNode *root, Type type, StructureField *field)
{
    if (compareName(root, 1, "ParamDec"))
        return ParamDec(root->child[0], type, field);
    else
    {
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
char *translate_CompSt(TreeNode *root) // rettype是函数返回值类型
{
    char *code1 = translate_DefList(root->child[1]);
    char *code2 = translate_StmtList(root->child[2]);
    char *ret = malloc(strlen(code1) + strlen(code2) + 10);
    sprintf(ret, "%s%s", code1, code2);
    return ret;
}
// 语句列表
char *translate_StmtList(TreeNode *root)
{
    if (root->child_num == 0)
        return NULL; // #TODO:会出问题吗？
    else if (compareName(root, 2, "Stmt", "StmtList"))
    {
        char *code1 = translate_Stmt(root->child[0]);
        char *code2 = translate_StmtList(root->child[1]);
        char *ret = malloc(strlen(code1) + strlen(code2) + 10);
        sprintf(ret, "%s%s", code1, code2);
        return ret;
    }
}
// 语句
char *translate_Stmt(TreeNode *root)
{
    if (compareName(root, 2, "Exp", "SEMI"))
    {
        return translate_Exp(root->child[0], NULL);
    }
    else if (compareName(root, 1, "CompSt"))
    {
        return CompSt(root->child[0]);
    }
    else if (compareName(root, 3, "RETURN", "Exp", "SEMI"))
    {
        char *t1 = new_temp();
        char *code1 = translate_Exp(root->child[1], t1);
        char *code2 = malloc(strlen(t1) + 10);
        sprintf(code2, "RETURN %s\n", t1);
        char *ret = malloc(strlen(code1) + strlen(code2) + 10);
        sprintf(ret, "%s%s", code1, code2);
    }
    else if (compareName(root, 5, "IF", "LP", "Exp", "RP", "Stmt"))
    {
        char *label1 = new_label();
        char *label2 = new_label();
        char *code1 = translate_Cond(root->child[0], label1, label2);
        char *code2 = translate_Stmt(root->child[4]);
        char *ret = malloc(strlen(code1) + strlen(label1) + strlen(code2) + strlen(label2) + 10);
        sprintf(ret, "%sLABEL: %s:\n%sLABEL: %s:\n", code1, label1, code2, label2);
        return ret;
    }
    else if (compareName(root, 7, "IF", "LP", "Exp", "RP", "Stmt", "ELSE", "Stmt"))
    {
        char *label1 = new_label();
        char *label2 = new_label();
        char *label3 = new_label();
        char *code1 = translate_Cond(root->child[0], label1, label2);
        char *code2 = translate_Stmt(root->child[4]);
        char *code3 = translate_Stmt(root->child[6]);
        char *ret = malloc(strlen(code1) + strlen(label1) + strlen(code2) + strlen(label2) + strlen(code3) + strlen(label3) + 30);
        sprintf(ret, "%sLABEL: %s:\n%sGOTO %s\nLABEL: %s:\n%sLABEL %s:\n", code1, label1, code2, label3, label2, code3, label3);
        return ret;
    }
    else if (compareName(root, 5, "WHILE", "LP", "Exp", "RP", "Stmt"))
    {
        char *label1 = new_label();
        char *label2 = new_label();
        char *label3 = new_label();
        char *code1 = translate_Cond(root->child[0], label2, label3);
        char *code2 = translate_Stmt(root->child[4]);
        char *ret = malloc(strlen(label1) + strlen(code1) + strlen(label2) + strlen(code2) + strlen(label1) + strlen(label3) + 30);
        sprintf(ret, "LABEL %s:\n%sLABEL %s:\n%sGOTO %s\nLABEL %s:\n", label1, code1, label2, code2, label1, label3);
        return ret;
    }
}
char *translate_Cond(TreeNode *root, char *label_true, char *label_false)
{
    if (compareName(root, 3, "Exp", "RELOP", "Exp"))
    {
        char *t1 = new_temp();
        char *t2 = new_temp();
        char *code1 = Exp(root->child[0], t1);
        char *code2 = Exp(root->child[2], t2);
        char *op = get_relop(root->child[1]);
        char *code3 = malloc(strlen(t1) + strlen(t2) + strlen(op) + strlen(label_true) + 20);
        char *ret = malloc(strlen(code1) + strlen(code2) + strlen(code3) + strlen(label_false) + 20);
        sprintf(ret, "%s%s%sGOTO %s\n", code1, code2, code3, label_false);
        return ret;
    }
    else if (compareName(root, 2, "NOT", "Exp"))
    {
        return translate_Cond(root->child[1], label_false, label_true);
    }
    else if (compareName(root, 3, "Exp", "AND", "Exp"))
    {
        char *label1 = new_label();
        char *code1 = translate_Cond(root->child[0], label1, label_false);
        char *code2 = translate_Cond(root->child[2], label_true, label_false);
        char *ret = malloc(strlen(code1) + strlen(label1) + strlen(code2) + 20);
        sprintf(ret, "%sLABEL %s:\n%s", code1, label1, code2);
        return ret;
    }
    else if (compareName(root, 3, "Exp", "OR", "Exp"))
    {
        char *label1 = new_label();
        char *code1 = translate_Cond(root->child[0], label_true, label1);
        char *code2 = translate_Cond(root->child[2], label_true, label_false);
        char *ret = malloc(strlen(code1) + strlen(label1) + strlen(code2) + 20);
        sprintf(ret, "%sLABEL %s:\n%s", code1, label1, code2);
        return ret;
    }
    else
        ; // TODO:other cases
}
// 变量定义
char *DefList(TreeNode *root, bool isstru)
{ // 可能用于结构体定义以及普通变量定义
    if (root->child_num == 0)
        return "";
    char *code1 = Def(root->child[0]);
    char *code2 = DefList(root->child[1], isstru);
    if (isstru)
        return "";
    else
    {
        char *res = malloc(strlen(code1) + strlen(code2) + 10);
        if (strlen(code2) == 0)
            sprintf(res, "%s", code1);
        else
            sprintf(res, "%s\n%s", code1, code2);
        return res;
    }
}
// 单个定义语句；
char *Def(TreeNode *root)
{
    Type type = Specifier(root->child[0]);
    return DecList(root->child[1], node_type);
}
// 声明列表
char *DecList(TreeNode *root, Type type)
{
    if (compareName(root, 1, "Dec"))
        return Dec(root->child[0], type);
    if (compareName(root, 3, "Dec", "COMMA", "DecList"))
    {
        char *code1 = Dec(root->child[0], type);
        char *code2 = DecList(root->child[2], type);
        char *res = malloc(strlen(code1) + strlen(code2) + 10);
        if (strlen(code2) == 0)
            sprintf(res, "%s", code1);
        else
            sprintf(res, "%s\n%s", code1, code2);
        return res;
    }
}
// 声明单项
char *Dec(TreeNode *root, Type type)
{
    Type var = VarDec(root->child[0], type);
    if (compareName(root, 1, "VarDec"))
    {
    }
    if (compareName(root, 3, "VarDec", "ASSIGNOP", "Exp"))
    {
    }
}
// 表达式
char *translate_Exp(TreeNode *root, char *place)
{
    char *res = NULL;
    // 三元运算符
    char *basic3Operator[] = {"PLUS", "MINUS", "STAR", "DIV"};
    char *basic3OperatorCode[] = {"+", "-", "*", "/"};
    for (int i = 0; i < 4; i++)
    {
        char *op = basic3Operator[i];
        if (compareName(root, 3, "Exp", op, "Exp"))
        {
            char *t1 = new_temp();
            char *t2 = new_temp();
            char *code1 = Exp(root->child[0], t1);
            char *code2 = Exp(root->child[2], t2);
            res = malloc(strlen(t1) + strlen(t2) + strlen(code1) + strlen(code2) + strlen(place) + 30);
            sprintf(res, "%s\n%s\n%s := %s %s %s", code1, code2, place, t1, basic3OperatorCode[i], t2);
        }
    }
    // 括号
    if (compareName(root, 3, "LP", "Exp", "RP"))
        return Exp(root->child[1], place);
    // 直接确定类型
    if (compareName(root, 1, "INT"))
    {
        int val = root->child[0]->int_val;
        res = malloc(30);
        sprintf(res, "place := #%d", val);
    }
    if (compareName(root, 1, "FLOAT"))
    {
        float val = root->child[0]->float_val;
        res = malloc(30);
        sprintf(res, "place := #%f", val);
    }
    // 变量
    if (compareName(root, 1, "ID"))
    {
        sprintf(res, "%s := %s", root->child[0]->id);
    }
    // 负号
    if (compareName(root, 2, "MINUS", "Exp"))
    {
        char *t1 = new_temp();
        char *code1 = Exp(root->child[1], t1);
        res = malloc(strlen(t1) + strlen(code1) + strlen(code1) + 30);
        sprintf(res, "%s\n%s := #0 - %s", code1, place, t1);
    }
    // 数组解析
    if (compareName(root, 4, "Exp", "LB", "Exp", "RB"))
    {
        char *t1 = new_temp();
        char *t2 = new_temp();
        char *t4 = new_temp();
        char *code2 = Exp(root->child[2], t4);
        char *id = root->child[0]->child[0]->id;
        res = malloc(4 * strlen(t1) + 2 * strlen(t2) + strlen(place) + strlen(code2) + strlen(t4) + 50);
        sprintf(res, "%s\n%s := &%s\n%s := %s * %s\n%s := %s + %s\n%s := *%s", code2, t1, id, t2, 4, t4, t1, t1, t2, place, t1);
    }
    // 结构体解析
    if (compareName(root, 3, "Exp", "DOT", "ID"))
    {
        int size = 0;
        char *ar = root->child[2]->id;
        char *id = root->child[0]->child[0]->id;
        Type stru = find_symbol(id);
        assert(stru != NULL && stru->kind == STRUCTURE);
        StructureField p = stru->content.stru.table;
        while (p)
        {
            if (strcmp(p->name, ar) == 0)
            {
                break;
            }
            size += size_of(p->type);
            p = p->next;
        }
        assert(p != NULL);
        char *t1 = new_temp();
        res = malloc(4 * strlen(t1) + strlen(place) + strlen(id) + strlen(ar) + 50);
        sprintf(res, "%s := &%s\n%s := %s + %s\n%s := *%s", t1, id, t1, t1, size, place, t1);
    }
    // 无参函数调用
    if (compareName(root, 3, "ID", "LP", "RP"))
    {
        if (strcmp(root->child[0]->id, "read"))
        {
            res = malloc(strlen(place) + 30);
            sprintf(res, "%s := read()", place);
        }
        else
        {
            res = malloc(strlen(place) + strlen(root->child[0]->id) + 30);
            sprintf(res, "%s := CALL %s", place, root->child[0]->id);
        }
    }
    // 有参函数调用
    if (compareName(root, 4, "ID", "LP", "Args", "RP"))
    {
        StructureField arglist = NULL;
        char *code1 = translate_Args(Args, &arglist);
        if (strcmp(root->child[0]->id, "write"))
        {
            assert(arglist = NULL);
            res = malloc(strlen(code1) + strlen(place) + strlen(arglist->name) + 30);
            res = sprintf(res, "%s\nWRITE %s\n%s := #0", code1, arglist->name, place);
        }
        else
        {
            char *code2 = malloc(300);
            while (arglist)
            {
                char *t = malloc(30 + strlen(arglist->name));
                sprintf(t, "ARG %s\n", arglist->name);
                strcat(code2, t);
            }
            res = malloc(strlen(code1) + strlen(code2) + strlen(place) + srelen(root->child[0]->id) + 30);
            sprintf(res, "%s\n%s%s := CALL %s", code1, code2, place, root->child[0]->id);
        }
    }

    // 赋值操作
    if (compareName(root, 3, "Exp", "ASSIGNOP", "Exp"))
    {
        char *t1 = new_temp();
        char *code1 = Exp(root->child[0], NULL);
        char *code2 = Exp(root->child[2], t1);
        res = malloc(strlen(t1) + strlen(code1) + strlen(code2) + strlen(place) + 30);
        sprintf(res, "%s\n%s := %s\n%s := %s", code2, code1, t1, place, code1);
    }
    // 布尔表达式
    if (compareName(root, 3, "Exp", "RELOP", "Exp") || compareName(root, 3, "Exp", "AND", "Exp") || compareName(root, 3, "Exp", "OR", "Exp") || compareName(root, 2, "NOT", "Exp"))
    {
        char *label1 = new_label();
        char *label2 = new_label();
        char *code0 = malloc(30 + strlen(place));
        sprintf(code0, "%s := #0", place);
        char *code1 = translate_Cond(root, label1, label2);
        res = malloc(strlen(code0) + strlen(code1) + strlen(label1) + strlen(label2) + 30);
        sprintf(res, "%s\n%s\nLABEL %s\n%s := #1", code0, code1, label1, place);
    }
    assert(res != NULL);
    return res;
}
// 调用函数的形参列表
char *translate_Args(TreeNode *root, StructureField *field)
{
    if (compareName(root, 1, "Exp")) // 参数列表末尾
    {
        char *t1 = new_temp();
        char *code1 = Exp(root->child[0], t1);
        Type exp_type = Exp(root->child[0]);
        addNode(field, exp_type, NULL);
        return code1;
    }
    // 参数列表非末尾
    else if (compareName(root, 3, "Exp", "COMMA", "Args"))
    {
        char *t1 = new_temp();
        char *code1 = Exp(root->child[0], t1);
        Type exp_type = Exp(root->child[0]);
        addNode(field, exp_type, NULL);
        return Args(root->child[2], field);
    }
}
char *new_label()
{
    char *label = malloc(20);
    sprintf(label, "label%d", label_cnt++);
    return label;
}
char *new_temp()
{
    char *temp = malloc(20);
    sprintf(temp, "t%d", temp_cnt++);
    return temp;
}
char *get_relop(TreeNode *root)
{
    if (root->relop_val == 1)
        return ">";
    else if (root->relop_val == 2)
        return "<";
    else if (root->relop_val == 3)
        return ">=";
    else if (root->relop_val == 4)
        return "<=";
    else if (root->relop_val == 5)
        return "==";
    else if (root->relop_val == 6)
        return "!=";
    assert(0);
}