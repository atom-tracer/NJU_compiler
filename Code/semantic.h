#pragma once
#include "tree.h"
#include "tools.h"
#include "type.h"
bool Program(TreeNode *root);
bool ExtDefList(TreeNode *root);
bool ExtDef(TreeNode *root);
bool ExtDecList(TreeNode *root, Type type);
Type Specifier(TreeNode *root);
bool StructSpecifier(TreeNode *root);
bool OptTag(TreeNode *root, Type type);
bool Tag(TreeNode *root);
Type VarDec(TreeNode *root, Type type);
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
Type Exp(TreeNode *root);
bool Args(TreeNode *root, StructureField* field);//field为返回的参数列表