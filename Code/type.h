#pragma once
#include <assert.h>
#include <stdio.h>
#include "tree.h"
typedef struct Type_* Type;
typedef struct FieldList_* FieldList;
struct FieldList_{
    char* name;
    struct Type type;
    struct FieldList tail;
};
struct Type_{
    enum {BASIC, ARRAY, STRUCTURE, FUNCTION} kind;
    union{
        int basic;
        struct {Type elem; int size;} array;
        FieldList tail;
    } content;
};
struct HashTable{

};