#pragma once
#include "tree.h"
#include "tools.h"
#include "type.h"
bool Program(TreeNode *root);
bool ExtDefList(TreeNode *root);
bool ExtDef(TreeNode *root);
bool ExtDecList(TreeNode *root, Type type);
bool Specifier(TreeNode *root);
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