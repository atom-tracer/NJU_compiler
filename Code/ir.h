#pragma once
#include "tree.h"
#include "tools.h"
#include "type.h"
#include <assert.h>
char *translate_Program(TreeNode *root);
char *translate_ExtDefList(TreeNode *root);
Type translate_Specifier(TreeNode *root);
char *translate_ExtDef(TreeNode *root);
char *translate_ExtDecList(TreeNode *root, Type type);
Type translate_StructSpecifier(TreeNode *root);
char *translate_OptTag(TreeNode *root);
char *translate_Tag(TreeNode *root);
char *translate_VarDec(TreeNode *root, Type type, bool isVarlist);
char *VarDec_id(TreeNode *root);
char *translate_FunDec(TreeNode *root);
char *translate_VarList(TreeNode *root);
char *translate_ParamDec(TreeNode *root);
char *translate_CompSt(TreeNode *root);
char *translate_StmtList(TreeNode *root);
char *translate_Stmt(TreeNode *root);
char *translate_Cond(TreeNode *root, char *label_true, char *label_false);
char *translate_DefList(TreeNode *root, bool isstru);
char *translate_Def(TreeNode *root);
char *translate_DecList(TreeNode *root, Type type);
char *translate_Dec(TreeNode *root, Type type);
char *translate_Exp(TreeNode *root, Variable *place);
char *translate_Args(TreeNode *root, Variable **field, int *cnt);
char *new_label();
char *new_temp();
char *get_relop(TreeNode *root);