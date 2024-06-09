#pragma once
#include <assert.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tools.h"
typedef __uint32_t uint32_t;
struct VaribleDescriptor
{
    char name[10];
    int regNo;
    struct VaribleDescriptor *next;
    struct VaribleDescriptor *prev;
};
struct RegisterDescriptor
{
    int cnt;
    int timestamp;
    char regname[5];
    char *VarNames[10];
};
typedef struct VaribleDescriptor VaribleDescriptor;
VaribleDescriptor *VaribleDescriptionTable;
typedef struct RegisterDescriptor RegisterDescriptor;
RegisterDescriptor RegisterDescriptionTable[32];


FILE *IRfile, *ASMfile;

void initCode();
char *getOneIR();
void RegRecycle(uint32_t reg);
VaribleDescriptor *VaribleCreate(char *name);
int getReg(char *name);
void genASM(char *IRcode);
void targetCodeGen();
