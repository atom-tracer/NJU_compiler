#pragma once
#include <assert.h>
#include <stdio.h>
#include "tree.h"
#include "tools.h"
#include <stdarg.h>
// 类型
typedef struct Type_ *Type;
enum TypeKind
{
    BASIC,
    ARRAY,
    STRUCTURE,
    FUNCTION
};
struct Type_
{
    enum TypeKind kind;
    union
    {
        int basic;
        struct
        {
            Type elem;
            int size;
        } array;
        struct
        {
            char *name;
            Type type;
            Type next;
        } tail; // 函数或结构体；注意：函数的返回值作为第一个类型参数
    } content;
};
Type createBasic(int basic);
Type createArray(Type elem, int size);
Type createStructure(char *name, int num, ...);
Type createFunction(Type ret, int num, ...);
int compareType(Type a, Type b);
// 符号表
extern Type var_list[], fun_list[];
extern int var_num, func_num;
void add_symbol(Type arr[], Type type);
bool find_symbol(Type arr[], Type type);
