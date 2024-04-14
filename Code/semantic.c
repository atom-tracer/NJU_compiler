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
bool Specifier(TreeNode *root)
{
}
bool ExtDef(TreeNode *root)
{
    if (my_is_error)
        return false;
    Type type = Specifier(root->child[0]);
    if (type == NULL)
        return false;
    if (strcmp(root->child[1]->name, "ExtDecList") == 0)
        return ExtDecList(root->child[1], type);
    else if (strcmp(root->child[1]->name, "SEMI") == 0)
        return true;
    else if (strcmp(root->child[1]->name, "FunDec") == 0)
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
bool VarList(TreeNode *root, FieldList *field);
bool ParamDec(TreeNode *root, FieldList *field);
bool CompSt(TreeNode *root, Type type);
bool StmtList(TreeNode *root, Type type);
bool Stmt(TreeNode *root, Type type);
bool DefList(TreeNode *root, Type type);
bool Def(TreeNode *root, Type type);
bool DecList(TreeNode *root, Type type);
bool Dec(TreeNode *root, Type type);
bool Exp(TreeNode *root, Type type);
bool Args(TreeNode *root, FieldList *field);