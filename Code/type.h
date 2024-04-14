#pragma once
#include <assert.h>
#include <stdio.h>
#include "tree.h"
#include <stdarg.h>
typedef struct Type_* Type;
enum {BASIC, ARRAY, STRUCTURE, FUNCTION};
struct Type_{
    int kind;
    union
    {
        int basic;
        struct {Type elem; int size;} array;
        struct {char* name; Type type; Type next;} tail;//函数或结构体；注意：函数的返回值作为第一个类型参数
    } content;
};
Type createBasic(int basic);
Type createArray(Type elem, int size);
Type createStructure(char* name, int num, ...);
Type createFunction(Type ret, int num, ...);
int compareType(Type a, Type b);

