#pragma once
#include "tree.h"
#include "tools.h"
#include "type.h"
#include <assert.h>
bool Program(TreeNode *root);
bool ExtDefList(TreeNode *root);
bool ExtDef(TreeNode *root);
bool ExtDecList(TreeNode *root, Type type);
Type Specifier(TreeNode *root);
Type StructSpecifier(TreeNode *root);
char *OptTag(TreeNode *root);
char *Tag(TreeNode *root);
Type VarDec(TreeNode *root, Type type, Type stru);
bool FunDec(TreeNode *root, enum FunctionType functiontype, Type ret);
bool VarList(TreeNode *root, Type type, StructureField *field);
bool ParamDec(TreeNode *root, Type func, StructureField *field);
bool CompSt(TreeNode *root, Type type);
bool StmtList(TreeNode *root, Type type);
bool Stmt(TreeNode *root, Type type);
bool DefList(TreeNode *root, Type type);
bool Def(TreeNode *root, Type type);
bool DecList(TreeNode *root, Type type, Type stru);
bool Dec(TreeNode *root, Type type, Type stru);
Type Exp(TreeNode *root);
bool Args(TreeNode *root, StructureField *field); // field为返回的参数列表