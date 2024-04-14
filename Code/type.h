#pragma once
#include <assert.h>
#include <stdio.h>
#include "tree.h"
#include <stdarg.h>
#include "tools.h"
typedef struct Type_ *Type;
typedef struct FieldList_ *FieldList;
enum
{
    BASIC,
    ARRAY,
    STRUCTURE,
    FUNCTION
};
struct FieldList_
{
    char *name;
    Type type;
    FieldList tail;
};
struct Type_
{
    int kind;
    union
    {
        int basic;
        struct
        {
            Type elem;
            int size;
        } array;
        FieldList tail;
    } content;
};
// 创建类型
Type createBasic(int basic)
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
Type createStructure(int num, ...)
{
    Type type = (Type)malloc(sizeof(struct Type_));
    type->kind = STRUCTURE;
    type->content.tail = NULL;
    va_list ap;
    va_start(ap, num);
    FieldList tail = NULL;
    for (int i = 0; i < num; i++)
    {
        FieldList temp = (FieldList)malloc(sizeof(struct FieldList_));
        temp->name = va_arg(ap, char *);
        temp->type = va_arg(ap, Type);
        temp->tail = NULL;
        if (tail == NULL)
            type->content.tail = temp;
        else
            tail->tail = temp;
        tail = temp;
    }
    va_end(ap);
    return type;
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
        return strcmp(a->content.tail->name, b->content.tail->name) == 0;
    case FUNCTION:
        if (strcmp(a->content.tail->name, b->content.tail->name) == 0)
        {
            FieldList p = a->content.tail->tail;
            FieldList q = b->content.tail->tail;
            while (p != NULL && q != NULL)
            {
                if (!compareType(p->type, q->type))
                    return -1; // 同名函数参数类型/返回值不同（错误19）
                p = p->tail;
                q = q->tail;
            }
            if (p == NULL && q == NULL)
                return 1;
            else
                return -1;
        }
        else
            return 0; // 函数名不同
    default:
        assert(0);
    }
}
struct HashTable
{
};