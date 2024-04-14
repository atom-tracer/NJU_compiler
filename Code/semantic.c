#include "semantic.h"
bool Program(TreeNode *root)
{
    if (my_is_error)
        return false;
    return ExtDefList(root->child[0]);
}
bool ExtDefList(TreeNode *root)
{
    if (my_is_error)
        return false;
    if (root->child_num == 0)
        return true;
    return ExtDef(root->child[0]) && ExtDefList(root->child[1]);
}
Type Specifier(TreeNode *root)
{
    if(my_is_error)
        return NULL;
    if (strcmp(root->child[0]->name, "TYPE") == 0)
    {
        if(strcmp(root->child[0]->value, "int") == 0)
            return createBasic(INT_TYPE);
        else if(strcmp(root->child[0]->value, "float") == 0)
            return createBasic(1);
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
    if (my_is_error)
        return false;
    Type type = Specifier(root->child[0]); // 继承属性，确定类型
    if (type == NULL)
        return false;
    if (strcmp(root->child[1]->name, "ExtDecList") == 0) // 变量定义
        return ExtDecList(root->child[1], type);
    else if (strcmp(root->child[1]->name, "SEMI") == 0)
        return true;
    else if (strcmp(root->child[1]->name, "FunDec") == 0) // 函数定义/声明
        return FunDec(root->child[1], type) && CompSt(root->child[2], type);
    else
        return false;
}
bool ExtDecList(TreeNode *root, Type type);

bool StructSpecifier(TreeNode *root);
bool OptTag(TreeNode *root, Type type);
bool Tag(TreeNode *root);
bool VarDec(TreeNode *root, Type type);
bool FunDec(TreeNode *root, Type type);
bool VarList(TreeNode *root, Type type);
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