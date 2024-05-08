#include "ir.h"
int temp_cnt = 0;
int label_cnt = 0;
// 比较文法
static bool compareName(TreeNode *root, int num, ...)
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
char *translate_Program(TreeNode *root)
{
    // 检查选做
    StructureField field = get_all_symbol();
    while (field)
    {
        // 函数参数不能有数组
        if (field->type->kind == FUNCTION)
        {
            StructureField p = field->type->content.func.tail;
            while (p)
            {
                if (p->type->kind == ARRAY)
                {
                    printf("Cannot translate: Code contains variables of multi-dimensional array type or parameters of array type.\n");
                    return "";
                }
                p = p->next;
            }
        }
        // 不能出现高维数组
        if (field->type->kind == ARRAY)
        {
            Type p = field->type;
            p = p->content.array.elem;
            if (p->kind == ARRAY)
            {
                printf("Cannot translate: Code contains variables of multi-dimensional array type or parameters of array type.\n");
                return "";
            }
        }
        field = field->next;
    }
    return translate_ExtDefList(root->child[0]);
}
char *translate_ExtDefList(TreeNode *root)
{
    if (root->child_num == 0)
        return NULL;
    char *code1 = translate_ExtDef(root->child[0]);
    char *code2 = translate_ExtDefList(root->child[1]);
    char *ret = malloc(strlen(code1) + strlen(code2) + 300);
    sprintf(ret, "%s%s", code1, code2);
    return ret;
}
Type translate_Specifier(TreeNode *root)
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
        return translate_StructSpecifier(root->child[0]);
    else
        return NULL;
}
char *translate_ExtDef(TreeNode *root)
{
    if (compareName(root, 2, "Specifier", "SEMI"))
        return NULL;                                                  // 结构体无需生成代码，而且没有全局变量
    else if (compareName(root, 3, "Specifier", "ExtDecList", "SEMI")) // 变量定义
    {
        return NULL; // 结构体无需生成代码，而且没有全局变量
    }
    else if (compareName(root, 3, "Specifier", "FunDec", "CompSt"))
    { // 函数定义
        char *code1 = translate_FunDec(root->child[1]);
        char *code2 = translate_CompSt(root->child[2]);
        char *ret = malloc(strlen(code1) + strlen(code2) + 300);
        sprintf(ret, "%s%s", code1, code2);
        return ret;
    }
    else if (compareName(root, 3, "Specifier", "FunDec", "SEMI")) // 不存在函数声明
        return NULL;
}
char *translate_ExtDecList(TreeNode *root, Type type) // 变量定义
{
    if (root->child_num == 1)
        return translate_VarDec(root->child[0], type, false);
    else if (root->child_num == 3)
    {
        char *code1 = translate_VarDec(root->child[0], type, false);
        char *code2 = translate_ExtDecList(root->child[2], type);
        char *ret = malloc(strlen(code1) + strlen(code2) + 300);
        sprintf(ret, "%s%s", code1, code2);
        return ret;
    }
}
Type translate_StructSpecifier(TreeNode *root)
{
    if (compareName(root, 2, "STRUCT", "Tag"))
    {
        Type type = find_symbol(translate_Tag(root->child[1]));
        if (type == NULL)
        {
            add_semantic_error(17, root->line); // 未定义的结构体
            return NULL;
        }
        return type;
    }
    else if (compareName(root, 5, "STRUCT", "OptTag", "LC", "DefList", "RC"))
    {
        char *anotag = translate_OptTag(root->child[1]);
        Type type = find_symbol(anotag);
        if (type != NULL)
        {
            add_semantic_error(16, root->line);
            return NULL;
        }
        else
        {
            Type strutype = createStructure(anotag, NULL);
            translate_DefList(root->child[3], true);
            if (anotag != NULL)
                add_symbol(anotag, strutype);
            return strutype;
        }
    }
    else
        return NULL;
}
char *translate_OptTag(TreeNode *root)
{
    if (compareName(root, 1, "ID"))
    {
        return root->child[0]->id;
    }
    return NULL;
}
char *translate_Tag(TreeNode *root)
{
    return root->child[0]->id;
}
char *translate_VarDec(TreeNode *root, Type type, bool isVarlist)
{
    char *res;
    if (isVarlist)
    {
        if (compareName(root, 1, "ID"))
        {
            char *ret = malloc(strlen(root->child[0]->id) + 300);
            sprintf(ret, "PARAM %s\n", root->child[0]->id);
            return ret;
        }
        else if (compareName(root, 4, "VarDec", "LB", "INT", "RB"))
        {
            return translate_VarDec(root->child[0], createArray(type, root->child[2]->int_val), isVarlist);
        }
    }
    else
    {
        if (compareName(root, 1, "ID"))
        {
            if (type->kind == STRUCTURE || type->kind == ARRAY)
            {
                int size = size_of(type);
                res = malloc(strlen(root->child[0]->id) + 300);
                sprintf(res, "DEC %s %d\n", root->child[0]->id, size);
            }
        }
        else if (compareName(root, 4, "VarDec", "LB", "INT", "RB"))
        {
            res = translate_VarDec(root->child[0], createArray(type, root->child[2]->int_val), isVarlist);
        }
    }
    return res;
}
char *VarDec_id(TreeNode *root)
{
    if (compareName(root, 1, "ID"))
    {
        return root->child[0]->id;
    }
    else if (compareName(root, 4, "VarDec", "LB", "INT", "RB"))
    {
        return VarDec_id(root->child[0]);
    }
}
char *translate_FunDec(TreeNode *root)
{
    if (compareName(root, 4, "ID", "LP", "VarList", "RP"))
    {
        char *code1 = malloc(strlen(root->child[0]->id) + 300);
        char *code2 = translate_VarList(root->child[2]);
        char *ret = malloc(strlen(code1) + strlen(code2) + 300);
        sprintf(ret, "FUNCTION %s :\n%s", root->child[0]->id, code2);
        return ret;
    }
    else if (compareName(root, 3, "ID", "LP", "RP"))
    {
        char *code1 = malloc(strlen(root->child[0]->id) + 300);
        sprintf(code1, "FUNCTION %s :\n", root->child[0]->id);
        return code1;
    }
    else
    {
        assert(0);
    }
}

char *translate_VarList(TreeNode *root)
{
    if (compareName(root, 1, "ParamDec"))
    {
        char *code1 = translate_ParamDec(root->child[0]);
        return code1;
    }
    else
    {
        char *code1 = translate_ParamDec(root->child[0]);
        char *code2 = translate_VarList(root->child[2]);
        char *ret = malloc(strlen(code1) + strlen(code2) + 300);
        sprintf(ret, "%s%s", code1, code2);
        return ret;
    }
}
//  函数参数项
char *translate_ParamDec(TreeNode *root)
{
    Type type = translate_Specifier(root->child[0]);
    return translate_VarDec(root->child[1], type, true);
}
// 函数体
char *translate_CompSt(TreeNode *root) // rettype是函数返回值类型
{
    char *code1 = translate_DefList(root->child[1], false);
    char *code2 = translate_StmtList(root->child[2]);
    char *ret = malloc(strlen(code1) + strlen(code2) + 300);
    sprintf(ret, "%s%s", code1, code2);
    return ret;
}
// 语句列表
char *translate_StmtList(TreeNode *root)
{
    if (root->child_num == 0)
        return "";
    else if (compareName(root, 2, "Stmt", "StmtList"))
    {
        char *code1 = translate_Stmt(root->child[0]);
        char *code2 = translate_StmtList(root->child[1]);
        char *ret = malloc(strlen(code1) + strlen(code2) + 300);
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
        return translate_CompSt(root->child[0]);
    }
    else if (compareName(root, 3, "RETURN", "Exp", "SEMI"))
    {
        Variable *t1 = createVar(new_temp());
        char *code1 = translate_Exp(root->child[1], t1);
        char *code2 = malloc(strlen(getVar(t1)) + 300);
        sprintf(code2, "RETURN %s\n", getVar(t1));
        char *ret = malloc(strlen(code1) + strlen(code2) + 300);
        sprintf(ret, "%s%s", code1, code2);
        return ret;
    }
    else if (compareName(root, 5, "IF", "LP", "Exp", "RP", "Stmt"))
    {
        char *label1 = new_label();
        char *label2 = new_label();
        char *code1 = translate_Cond(root->child[2], label1, label2);
        char *code2 = translate_Stmt(root->child[4]);
        char *ret = malloc(strlen(code1) + strlen(label1) + strlen(code2) + strlen(label2) + 300);
        sprintf(ret, "%sLABEL: %s:\n%sLABEL: %s:\n", code1, label1, code2, label2);
        return ret;
    }
    else if (compareName(root, 7, "IF", "LP", "Exp", "RP", "Stmt", "ELSE", "Stmt"))
    {
        char *label1 = new_label();
        char *label2 = new_label();
        char *label3 = new_label();
        char *code1 = translate_Cond(root->child[2], label1, label2);
        char *code2 = translate_Stmt(root->child[4]);
        char *code3 = translate_Stmt(root->child[6]);
        // printf("%d\n", strlen(code1) + strlen(label1) + strlen(code2) + strlen(label2) + strlen(code3) + strlen(label3) + 300);
        char *ret = malloc(strlen(code1) + strlen(label1) + strlen(code2) + strlen(label2) + strlen(code3) + strlen(label3) + 300);
        sprintf(ret, "%sLABEL: %s:\n%sGOTO %s\nLABEL: %s:\n%sLABEL %s:\n", code1, label1, code2, label3, label2, code3, label3);
        return ret;
    }
    else if (compareName(root, 5, "WHILE", "LP", "Exp", "RP", "Stmt"))
    {
        char *label1 = new_label();
        char *label2 = new_label();
        char *label3 = new_label();
        char *code1 = translate_Cond(root->child[2], label2, label3);
        char *code2 = translate_Stmt(root->child[4]);
        char *ret = malloc(strlen(label1) + strlen(code1) + strlen(label2) + strlen(code2) + strlen(label1) + strlen(label3) + 300);
        sprintf(ret, "LABEL %s:\n%sLABEL %s:\n%sGOTO %s\nLABEL %s:\n", label1, code1, label2, code2, label1, label3);
        return ret;
    }
}
char *translate_Cond(TreeNode *root, char *label_true, char *label_false)
{
    if (compareName(root, 3, "Exp", "RELOP", "Exp"))
    {
        Variable *t1 = createVar(new_temp());
        Variable *t2 = createVar(new_temp());
        char *code1 = translate_Exp(root->child[0], t1);
        char *code2 = translate_Exp(root->child[2], t2);
        char *op = get_relop(root->child[1]);
        char *code3 = malloc(strlen(getVar(t1)) + strlen(getVar(t2)) + strlen(op) + strlen(label_true) + 300);
        sprintf(code3, "IF %s %s %s GOTO %s\n", getVar(t1), op, getVar(t2), label_true);
        char *ret = malloc(strlen(code1) + strlen(code2) + strlen(code3) + strlen(label_false) + 300);
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
        char *ret = malloc(strlen(code1) + strlen(label1) + strlen(code2) + 300);
        sprintf(ret, "%sLABEL %s:\n%s", code1, label1, code2);
        return ret;
    }
    else if (compareName(root, 3, "Exp", "OR", "Exp"))
    {
        char *label1 = new_label();
        char *code1 = translate_Cond(root->child[0], label_true, label1);
        char *code2 = translate_Cond(root->child[2], label_true, label_false);
        char *ret = malloc(strlen(code1) + strlen(label1) + strlen(code2) + 300);
        sprintf(ret, "%sLABEL %s:\n%s", code1, label1, code2);
        return ret;
    }
    else
    {
        char *t1 = new_label();
        char *code1 = translate_Exp(root, t1);
        char *code2 = malloc(strlen(t1) + strlen(label_true) + strlen(label_false) + 300);
        sprintf(code2, "IF %s != #0 GOTO %s\n", t1, label_true);
        char *ret = malloc(strlen(code1) + strlen(code2) + 300);
        sprintf(ret, "%s%sGOTO %s\n", code1, code2, label_false);
        return ret;
    }
}
// 变量定义
char *translate_DefList(TreeNode *root, bool isstru)
{ // 可能用于结构体定义以及普通变量定义
    if (root->child_num == 0)
        return "";
    char *code1 = translate_Def(root->child[0]);
    char *code2 = translate_DefList(root->child[1], isstru);
    if (isstru)
        return "";
    else
    {
        char *res = malloc(strlen(code1) + strlen(code2) + 300);
        sprintf(res, "%s%s\n", code1, code2);
        return res;
    }
}
// 单个定义语句；
char *translate_Def(TreeNode *root)
{
    Type type = translate_Specifier(root->child[0]);
    return translate_DecList(root->child[1], type);
}
// 声明列表
char *translate_DecList(TreeNode *root, Type type)
{
    if (compareName(root, 1, "Dec"))
        return translate_Dec(root->child[0], type);
    if (compareName(root, 3, "Dec", "COMMA", "DecList"))
    {
        char *code1 = translate_Dec(root->child[0], type);
        char *code2 = translate_DecList(root->child[2], type);
        char *res = malloc(strlen(code1) + strlen(code2) + 300);
        sprintf(res, "%s%s\n", code1, code2);
        return res;
    }
}
// 声明单项
char *translate_Dec(TreeNode *root, Type type)
{
    char *code = translate_VarDec(root->child[0], type, false);
    char *res = code;
    if (compareName(root, 3, "VarDec", "ASSIGNOP", "Exp"))
    {
        char *code1 = translate_Exp(root->child[2], createVar(VarDec_id(root->child[0])));
        res = malloc(strlen(code1) + strlen(code) + 300);
        sprintf(res, "%s%s\n", code, code1);
    }
    return res;
}
// 表达式
char *translate_Exp(TreeNode *root, Variable *place)
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
            Variable *t1 = createVar(new_temp());
            Variable *t2 = createVar(new_temp());
            char *code1 = translate_Exp(root->child[0], t1);
            char *code2 = translate_Exp(root->child[2], t2);
            if (place != NULL)
            {
                res = malloc(strlen(getVar(t1)) + strlen(getVar(t2)) + strlen(code1) + strlen(code2) + strlen(getVar(place)) + 300);
                sprintf(res, "%s%s%s := %s %s %s\n", code1, code2, getVar(place), getVar(t1), basic3OperatorCode[i], getVar(t2));
            }
            else
            {
                assert(0);
            }
        }
    }
    // 括号
    if (compareName(root, 3, "LP", "Exp", "RP"))
        return translate_Exp(root->child[1], place);
    // 直接确定类型
    if (compareName(root, 1, "INT"))
    {
        int val = root->child[0]->int_val;
        res = malloc(300);
        if (place == NULL)
        {
            return "";
        }
        sprintf(res, "%s := #%d\n", getVar(place), val);
    }
    if (compareName(root, 1, "FLOAT"))
    {
        float val = root->child[0]->float_val;
        res = malloc(300);
        if (place == NULL)
        {
            return "";
        }
        sprintf(res, "%s := #%f\n", getVar(place), val);
    }
    // 变量
    if (compareName(root, 1, "ID"))
    {
        res = malloc(300);
        if (place == NULL)
        {
            return "";
        }
        sprintf(res, "%s := %s\n", getVar(place), root->child[0]->id);
        if (find_symbol(root->child[0]->id)->kind == ARRAY || find_symbol(root->child[0]->id)->kind == STRUCTURE)
        {
            place->is_pointer = true;
            place->is_sa = true;
        }
    }
    // 负号
    if (compareName(root, 2, "MINUS", "Exp"))
    {
        Variable *t1 = createVar(new_temp());
        char *code1 = translate_Exp(root->child[1], t1);
        res = malloc(strlen(getVar(t1)) + strlen(code1) + strlen(code1) + 300);
        if (place == NULL)
        {
            return "";
        }
        sprintf(res, "%s%s := #0 - %s\n", code1, getVar(place), getVar(t1));
    }
    // 数组解析
    if (compareName(root, 4, "Exp", "LB", "Exp", "RB"))
    {
        Variable *t1 = createVar(new_temp());
        Variable *t2 = createVar(new_temp());
        char *code1 = translate_Exp(root->child[0], t1);
        char *code2 = translate_Exp(root->child[2], t2);
        Type element = find_symbol(root->child[0]->id)->content.array.elem;
        int size = size_of(element);
        if (place == NULL)
        {
            return "";
        }
        res = malloc(3 * strlen(getVar(t1)) + 3 * strlen(getVar(t2) + strlen(code1) + strlen(code2) + strlen(getVar(place)) + 300));
        sprintf(res, "%s%s%s := %s * %d\n%s := %s + %s\n%s := %s\n", code1, code2, getVar(t2), getVar(t2), size, getVar(t1), getVar(t1), getVar(t2), getVar(place), getVar(t1));
        place->is_pointer = true;
        if (element->kind == ARRAY || element->kind == STRUCTURE)
        {
            place->is_sa = true;
        }
    }
    // 结构体解析
    if (compareName(root, 3, "Exp", "DOT", "ID"))
    {
        Variable *t1 = createVar(new_temp());
        char *code1 = translate_Exp(root->child[0], t1);
        Type stru = find_symbol(root->child[0]->id);
        int offset = 0;
        StructureField p = stru->content.stru.table;
        while (p)
        {
            if (strcmp(p->name, root->child[2]->id) == 0)
                break;
            offset += size_of(p->type);
            p = p->next;
        }
        if (place == NULL)
        {
            return "";
        }
        res = malloc(2 * strlen(getVar(t1)) + strlen(code1) + strlen(getVar(place) + 300));
        sprintf(res, "%s%s := %s + %d\n%s := %s\n", code1, getVar(t1), getVar(t1), offset, getVar(place), getVar(t1));
        place->is_pointer = true;
        if (p->type->kind == ARRAY || p->type->kind == STRUCTURE)
        {
            place->is_sa = true;
        }
    }
    //  无参函数调用
    if (compareName(root, 3, "ID", "LP", "RP"))
    {
        if (strcmp(root->child[0]->id, "read"))
        {
            if (place == NULL)
            {
                return "";
            }
            res = malloc(strlen(getVar(place)) + 300);
            sprintf(res, "READ %s\n", getVar(place));
        }
        else
        {
            if (place != NULL)
            {
                res = malloc(strlen(getVar(place)) + strlen(root->child[0]->id) + 300);
                sprintf(res, "%s := CALL %s\n", getVar(place), root->child[0]->id);
            }
            else
            {
                res = malloc(strlen(root->child[0]->id) + 300);
                sprintf(res, "CALL %s\n", root->child[0]->id);
            }
        }
    }
    // 有参函数调用
    if (compareName(root, 4, "ID", "LP", "Args", "RP"))
    {
        int cnt = 0;
        Variable **arglist = malloc(sizeof(Variable *) * 3000);
        char *code1 = translate_Args(root->child[2], arglist, &cnt);
        assert(cnt <= 3000);
        if (strcmp(root->child[0]->id, "write"))
        {
            assert(cnt == 1);
            if (place != NULL)
            {
                res = malloc(strlen(code1) + strlen(getVar(place)) + strlen(getVar(arglist[0])) + 300);
                sprintf(res, "%sWRITE %s%s := #0\n", code1, getVar(arglist[0]), getVar(place));
            }
            else
            {
                res = malloc(strlen(code1) + strlen(getVar(arglist[0])) + 300);
                sprintf(res, "%sWRITE %s\n", code1, getVar(arglist[0]));
            }
        }
        else
        {
            char *code2 = malloc(3000);
            for (int i = cnt - 1; i >= 0; i--)
            {
                char *t = malloc(300 + strlen(getVar(arglist[i])));
                sprintf(t, "ARG %s\n", getVar(arglist[i]));
                strcat(code2, t);
            }
            if (place != NULL)
            {
                res = malloc(strlen(code1) + strlen(code2) + strlen(getVar(place)) + strlen(root->child[0]->id) + 300);
                sprintf(res, "%s%s%s := CALL %s\n", code1, code2, getVar(place), root->child[0]->id);
            }
            else
            {
                res = malloc(strlen(code1) + strlen(code2) + strlen(root->child[0]->id) + 300);
                sprintf(res, "%s%sCALL %s\n", code1, code2, root->child[0]->id);
            }
        }
    }

    // 赋值操作
    if (compareName(root, 3, "Exp", "ASSIGNOP", "Exp"))
    {
        if (compareName(root->child[0], 1, "ID"))
        {
            Variable *t1 = createVar(new_temp());
            char *code1 = translate_Exp(root->child[2], t1);
            char *id = root->child[0]->child[0]->id;
            if (place != NULL)
            {
                res = malloc(strlen(getVar(t1)) + strlen(code1) + strlen(getVar(place)) + 300);
                sprintf(res, "%s%s := %s\n%s := %s\n", code1, id, getVar(t1), getVar(place), id);
            }
            else
            {
                res = malloc(strlen(getVar(t1)) + strlen(code1) + strlen(id) + 300);
                sprintf(res, "%s%s := %s\n", code1, id, getVar(t1));
            }
        }
        else
        {
            Variable *t1 = createVar(new_temp());
            Variable *t2 = createVar(new_temp());
            char *code1 = translate_Exp(root->child[0], t1);
            char *code2 = translate_Exp(root->child[2], t2);
            if (place != NULL)
            {
                res = malloc(strlen(getVar(t1)) + strlen(getVar(t2)) + strlen(code1) + strlen(code2) + strlen(getVar(place)) + 300);
                sprintf(res, "%s%s%s := %s\n%s := %s\n", code1, code2, getVar(t1), getVar(t2), getVar(place), getVar(t1));
            }
            else
            {
                res = malloc(strlen(getVar(t1)) + strlen(getVar(t2)) + strlen(code1) + strlen(code2) + 300);
                sprintf(res, "%s%s%s := %s\n", code1, code2, getVar(t1), getVar(t2));
            }
        }
    }
    // 布尔表达式
    if (compareName(root, 3, "Exp", "RELOP", "Exp") || compareName(root, 3, "Exp", "AND", "Exp") || compareName(root, 3, "Exp", "OR", "Exp") || compareName(root, 2, "NOT", "Exp"))
    {
        if (place == NULL)
        {
            assert(0);
            return "";
        }
        char *label1 = new_label();
        char *label2 = new_label();
        char *code0 = malloc(300 + strlen(getVar(place)));
        sprintf(code0, "%s := #0\n", getVar(place));
        char *code1 = translate_Cond(root, label1, label2);
        res = malloc(strlen(code0) + strlen(code1) + strlen(label1) + strlen(label2) + strlen(getVar(place)) + 300);
        sprintf(res, "%s%s\nLABEL %s\n%s := #1\n", code0, code1, label1, getVar(place));
    }
    assert(res != NULL);
    return res;
}
// 调用函数的形参列表
char *translate_Args(TreeNode *root, Variable **field, int *cnt)
{
    if (compareName(root, 1, "Exp")) // 参数列表末尾
    {
        Variable *t1 = createVar(new_temp());
        char *code1 = translate_Exp(root->child[0], t1);
        field[(*cnt)++] = t1;
        return code1;
    }
    // 参数列表非末尾
    else if (compareName(root, 3, "Exp", "COMMA", "Args"))
    {
        Variable *t1 = createVar(new_temp());
        char *code1 = translate_Exp(root->child[0], t1);
        field[(*cnt)++] = t1;
        char *code2 = translate_Args(root->child[2], field, cnt);
        char *res = malloc(strlen(code1) + strlen(code2) + 300);
        sprintf(res, "%s%s", code1, code2);
        return res;
    }
}
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