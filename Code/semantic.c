#include "semantic.h"
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
bool ExtDecList(TreeNode *root, Type type)
{
    if (root->child_num == 1)
        return VarDec(root->child[0], type);
    else if (root->child_num == 3)
        return VarDec(root->child[0], type) && ExtDecList(root->child[2], type);
}

bool StructSpecifier(TreeNode *root);
bool OptTag(TreeNode *root, Type type);
bool Tag(TreeNode *root);
Type VarDec(TreeNode *root, Type type)
{
    Type new_type = type;
    if (strcmp(root->child[0]->name, "ID") == 0)
    {
        ; // 查找是否重复定义并插入
    }
    else if (strcmp(root->child[0]->name, "VarDec") == 0)
    {
        // 数组定义
        new_type = VarDec(root->child[0], type);
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
bool ParamDec(TreeNode *root, Type type);
bool CompSt(TreeNode *root, Type type);
bool StmtList(TreeNode *root, Type type);
bool Stmt(TreeNode *root, Type type);
bool DefList(TreeNode *root, Type type);
bool Def(TreeNode *root, Type type);
bool DecList(TreeNode *root, Type type);
bool Dec(TreeNode *root, Type type);
bool Exp(TreeNode *root, Type type);
bool Args(TreeNode *root, Type type);