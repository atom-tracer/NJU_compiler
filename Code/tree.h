#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "tools.h"

typedef struct TreeNode TreeNode;

enum
{
    node_grammar,
    node_id,
    node_type,
    node_int,
    node_float,
    node_other,
    node_relop,
};

struct TreeNode
{
    int line;
    int type;
    char id[32], name[32];
    int type_val;
    int int_val;
    float float_val;
    struct TreeNode *child[8];
    int child_num;
    int relop_val;
};

extern TreeNode *root;

void print_tree(struct TreeNode *root, int level);
void print_node(struct TreeNode *node, int level);
void insert_child(struct TreeNode *parent, struct TreeNode *child);
TreeNode *new_node(char *name, int type);
