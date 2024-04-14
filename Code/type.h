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
        enum ValueType basic; // 基本元素类型
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
            enum FunctionType functiontype;//函数类型（定义或声明）
        } tail; // 函数或结构体；注意：函数的返回值作为第一个类型参数
    } content;
};
Type createBasic(enum ValueType basic);
Type createArray(Type elem, int size);
//如果存在域名重复定义（错误15），则返回NULL
Type createStructure(char *name, int num, ...);
Type createFunction(Type ret, enum FunctionType functiontype, int num, ...);
Type getFunctionRet(Type type);
int compareType(Type a, Type b);
// 符号表
void add_symbol(char *name, Type type);
Type find_symbol(char *name);
