#pragma once
#include <assert.h>
#include <stdio.h>
#include "tree.h"
#include "tools.h"
#include <stdarg.h>
// 类型
typedef struct Type_ *Type;
typedef struct TypeNode *TypeNode;
enum TypeKind
{
    BASIC,
    ARRAY,
    STRUCTURE,
    FUNCTION
};
struct TypeNode{
    char* name;
    Type type;
    TypeNode next;
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
            TypeNode tail;
            Type ret;
            enum FunctionType functiontype;//函数类型（定义或声明）
        } func; // 函数
        struct
        {
            TypeNode*table;
            char *name;
        }stru;
        
    } content;
};
Type createBasic(enum ValueType basic);
Type createArray(Type elem, int size);
//如果存在域名重复定义（错误15），则返回NULL
//对于结构体类型名，是这里的name（匿名结构体用NULL），根据错误13（类型名不能与变量名重复），因此非匿名
//结构体类型也应该被加入到符号表(类型名，类型)，在之后使用该类型时，通过查找符号表获得类型信息type，用于将变量加入到符号表
Type createStructure(char *name, TypeNode head);
Type createFunction(Type ret, enum FunctionType functiontype, TypeNode head);
Type getFunctionRet(Type type);
int compareType(Type a, Type b);
//这里提供了一个向链表中添加元素的函数，第一个参数是链表头指针的地址（即使是NULL）！！！
void addNode(TypeNode *head, Type type, char *name);//没有名称就输入NULL（名称是给结构体域用的）
// 符号表
void add_symbol(char *name, Type type);
Type find_symbol(char *name);
//结构体域符号操作
void add_symbol_to(Type stru, char *name, Type type);
Type find_symbol_in(Type stru, char *name);
