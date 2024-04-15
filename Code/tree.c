#include "tree.h"
TreeNode *root;
int my_is_error = 0;
void print_node(struct TreeNode *n, int level)
{
    for (int i = 0; i < level; i++)
        printf("  ");
    printf("%s", n->name);
    switch (n->type)
    {
    case node_grammar:
        printf(" (%d)", n->line);
        break;
    case node_id:
        printf(": %s", n->id);
        break;
    case node_type:
        printf(": %s", n->type_val == INT_TYPE ? "int" : "float");
        break;
    case node_int:
        printf(": %d", n->int_val);
        break;
    case node_float:
        printf(": %f", n->float_val);
        break;
    }
    printf("\n");
}

void print_tree(struct TreeNode *root, int level)
{
    // assert(root!=NULL);
    if (root == NULL || root->type == node_grammar && root->child_num == 0)
        return; // empty grammar
    print_node(root, level);
    for (int i = 0; i < root->child_num; i++)
    {
        print_tree(root->child[i], level + 1);
    }
}

void insert_child(struct TreeNode *parent, struct TreeNode *child)
{
    parent->child[parent->child_num++] = child;
}
TreeNode *new_node(char *name, int type)
{
    TreeNode *node = (TreeNode *)malloc(sizeof(TreeNode));
    node->type = type;
    strcpy(node->name, name);
    node->child_num = 0;
    return node;
}
