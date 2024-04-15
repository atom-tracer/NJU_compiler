#include "type.h"
#define N 0x3ff
TypeNode *hash_table[N + 1];
// 创建类型
Type createBasic(enum ValueType basic)
{
    Type type = (Type)malloc(sizeof(struct Type_));
    type->kind = BASIC;
    type->content.basic = basic;
    return type;
}
Type createArray(Type elem, int size)
{
    Type type = (Type)malloc(sizeof(struct Type_));
    type->kind = ARRAY;
    type->content.array.elem = elem;
    type->content.array.size = size;
    return type;
}
Type createStructure(char *name, TypeNode head)
{
    Type type = (Type)malloc(sizeof(struct Type_));
    type->kind = STRUCTURE;
    type->content.stru.name = name;
    type->content.stru.table = malloc(sizeof(TypeNode) * (N + 1));
    memset(type->content.stru.table, 0, sizeof(TypeNode) * (N + 1));
    TypeNode p = head;
    while(p){
        if(find_symbol_in(type, p->name)){
            return NULL;
        }
        add_symbol_to(type, p->name, p->type);
        p = p->next;
    }
    return type;
}
Type createFunction(Type ret, enum FunctionType functiontype, TypeNode head)
{
    Type type = (Type)malloc(sizeof(struct Type_));
    type->kind = FUNCTION;
    type->content.func.ret = ret;
    type->content.func.functiontype = functiontype;
    type->content.func.tail = head;
    return type;
}
Type getFunctionRet(Type type)
{
    return type->content.func.ret;
}
// 比较两个类型是否相同
int compareType(Type a, Type b)
{
    if (a->kind != b->kind)
        return 0;
    switch (a->kind)
    {
    case BASIC:
        return a->content.basic == b->content.basic;
    case ARRAY:
        return compareType(a->content.array.elem, b->content.array.elem);
    case STRUCTURE:
        return strcmp(a->content.stru.name, b->content.stru.name) == 0 && a->content.stru.name != NULL;
    case FUNCTION:
        if (!compareType(a->content.func.ret, b->content.func.ret))
            return 0;
        TypeNode p1 = a->content.func.tail;
        TypeNode p2 = b->content.func.tail;
        while (p1 && p2)
        {
            if (!compareType(p1->type, p2->type))
                return 0;
            p1 = p1->next;
            p2 = p2->next;
        }
        return p1 == p2;
    default:
        assert(0);
    }
}
void addNode(TypeNode *head, Type type, char *name){
    TypeNode p = (TypeNode)malloc(sizeof(TypeNode));
    p->type = type;
    p->next = *head;
    p->name = name;
    *head = p;
}
//符号表

unsigned int hash_pjw(char *name)
{
    unsigned int val = 0, i;
    for (; *name; ++name)
    {
        val = (val << 2) + *name;
        if (i = val & ~N)
            val = (val ^ (i >> 12)) & N;
    }
    return val;
}
void add_symbol(char *name, Type type)
{
    unsigned int val = hash_pjw(name);
    TypeNode p = (TypeNode)malloc(sizeof(TypeNode));
    p->type = type;
    p->next = hash_table[val];
    hash_table[val] = p;
}
Type find_symbol(char *name)
{
    unsigned int val = hash_pjw(name);
    TypeNode p = hash_table[val];
    while (p)
    {
        if (strcmp(p->name, name) == 0){
            return p->type;
        }
        p = p->next;
    }
    return NULL;
}
void add_symbol_to(Type stru, char *name, Type type)
{
    TypeNode *table = stru->content.stru.table;
    unsigned int val = hash_pjw(name);
    TypeNode p = (TypeNode)malloc(sizeof(TypeNode));
    p->type = type;
    p->next = table[val];
    table[val] = p;
}
Type find_symbol_in(Type stru, char *name)
{
    TypeNode *table = stru->content.stru.table;
    unsigned int val = hash_pjw(name);
    TypeNode p = table[val];
    while (p)
    {
        if (strcmp(p->name, name) == 0)
            return p->type;
        p = p->next;
    }
    return NULL;
}