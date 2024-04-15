#pragma once
#include <assert.h>
#include <stdio.h>
typedef int bool;
#define true 1
#define false 0
extern int my_is_error;
enum ValueType
{
    INT_TYPE = 1,
    FLOAT_TYPE = 2
};
enum FunctionType
{
    FUNCTION_DEFINITION = 1,
    FUNCTION_DECLARATION = 0
};

void summit_semantic_error();
void add_semantic_error(int error_type, int line);
