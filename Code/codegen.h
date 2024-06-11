#pragma once
#include <assert.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tools.h"
typedef __uint32_t uint32_t;
typedef int bool;
#define true 1
#define false 0
enum PosRefType
{
    POS_SP,
    POS_FP,
    POS_REG
};
typedef enum PosRefType PosRefType;
struct VaribleDescriptor
{
    char name[10];
    int regNo;
    PosRefType posRef;
    int offset;
    bool dirtybit;
    struct VaribleDescriptor *next;
    struct VaribleDescriptor *prev;
};
struct RegisterDescriptor
{
    int cnt;
    int timestamp;
    char regname[5];
    char *VarNames[50];
};

struct ParamList
{
    int Paramcnt;
    int ParamNo;       // 第几个参数
    PosRefType posRef; // 寻找参数的方式
    int offset;        // 参数的偏移
    char name[10];
    struct ParamList *next;
    struct ParamList *prev;
};

struct TrueParamList
{
    int Paramcnt; // 从1计数
    int ParamNo;  // 第几个参数，从1计数
    char name[10];
    struct TrueParamList *next;
    struct TrueParamList *prev;
};

typedef struct VaribleDescriptor VaribleDescriptor;
VaribleDescriptor *VaribleDescriptionTable;
typedef struct RegisterDescriptor RegisterDescriptor;
RegisterDescriptor RegisterDescriptionTable[32];
typedef struct ParamList ParamList;
ParamList *ParamListHead;
typedef struct TrueParamList TrueParamList;
TrueParamList *TrueParamListHead, *TrueParamListTail;

FILE *IRfile, *ASMfile;

void initCode();
char *getOneIR();
void RegRecycle(uint32_t reg, bool flushback);
VaribleDescriptor *VaribleCreate(char *name);
int getReg(char *name);
void genASM(char *IRcode);
void targetCodeGen();
