#include "codegen.h"
int increTime = 0;
int ParamCnt = 0;
int TrueFrameSize = 0;  // 整个栈帧的大小（包括存储的寄存器和局部变量）
int LocalFrameSize = 0; // 存储局部变量的栈空间大小
void initCode()
{
    fprintf(ASMfile, ".data\n");
    fprintf(ASMfile, "_prompt: .asciiz \"Enter an integer:\"\n");
    fprintf(ASMfile, "_ret: .asciiz \"\\n\"\n");
    fprintf(ASMfile, ".globl main\n");

    // read function
    fprintf(ASMfile, ".text\n");
    fprintf(ASMfile, "read:\n");
    fprintf(ASMfile, "  li $v0, 4\n");
    fprintf(ASMfile, "  la $a0, _prompt\n");
    fprintf(ASMfile, "  syscall\n");
    fprintf(ASMfile, "  li $v0, 5\n");
    fprintf(ASMfile, "  syscall\n");
    fprintf(ASMfile, "  jr $ra\n\n");

    // write function
    fprintf(ASMfile, "write:\n");
    fprintf(ASMfile, "  li $v0, 1\n");
    fprintf(ASMfile, "  syscall\n");
    fprintf(ASMfile, "  li $v0, 4\n");
    fprintf(ASMfile, "  la $a0, _ret\n");
    fprintf(ASMfile, "  syscall\n");
    fprintf(ASMfile, "  move $v0, $0\n");
    fprintf(ASMfile, "  jr $ra\n");

    VaribleDescriptionTable = malloc(sizeof(VaribleDescriptor));
    VaribleDescriptionTable->next = NULL;
    VaribleDescriptionTable->prev = NULL;
    // 初始化寄存器名称
    sprintf(RegisterDescriptionTable[0].regname, "$zero");
    sprintf(RegisterDescriptionTable[1].regname, "$at");
    for (int i = 2; i <= 3; i++)
    {
        sprintf(RegisterDescriptionTable[i].regname, "$v%d", i - 2);
    }
    for (int i = 4; i <= 7; i++)
    {
        sprintf(RegisterDescriptionTable[i].regname, "$a%d", i - 4);
    }
    for (int i = 8; i <= 15; i++)
    {
        sprintf(RegisterDescriptionTable[i].regname, "$t%d", i - 8);
    }
    for (int i = 16; i <= 23; i++)
    {
        sprintf(RegisterDescriptionTable[i].regname, "$s%d", i - 16);
    }
    for (int i = 24; i <= 25; i++)
    {
        sprintf(RegisterDescriptionTable[i].regname, "$t%d", i - 16);
    }
    sprintf(RegisterDescriptionTable[26].regname, "$k0");
    sprintf(RegisterDescriptionTable[27].regname, "$k1");
    sprintf(RegisterDescriptionTable[28].regname, "$gp");
    sprintf(RegisterDescriptionTable[29].regname, "$sp");
    sprintf(RegisterDescriptionTable[30].regname, "$fp");
    sprintf(RegisterDescriptionTable[31].regname, "$ra");
    // 初始化寄存器描述符表的名称数组，给其分配空间
    for (int i = 0; i < 32; i++)
    {
        RegisterDescriptionTable[i].cnt = 0;
        // RegisterDescriptionTable[i].timestamp = 0;
        for (int j = 0; j < 10; j++)
        {
            RegisterDescriptionTable[i].VarNames[j] = malloc(10);
        }
    }
    //  初始化参数的工具（链表）
    ParamListHead = malloc(sizeof(ParamList));
    ParamListHead->next = NULL;
    ParamListHead->prev = NULL;
    ParamListHead->Paramcnt = 0;
    TrueParamListHead = malloc(sizeof(TrueParamList));
    TrueParamListTail = TrueParamListHead;
    TrueParamListHead->next = NULL;
    TrueParamListHead->prev = NULL;
    TrueParamListHead->Paramcnt = 0;
    TrueParamListHead->ParamNo = 0;
}

ParamList *ParamPush(char *name) // 把参数压入参数列表
{
    ParamList *newParam = malloc(sizeof(ParamList));
    strcpy(newParam->name, name);
    newParam->next = ParamListHead->next;
    newParam->prev = ParamListHead;
    ParamListHead->next = newParam;
    if (newParam->next != NULL)
        newParam->next->prev = newParam;
    newParam->offset = ParamListHead->Paramcnt++; // Re:0
    return newParam;
}

void ParamClear() // 把参数列表清空
{
    ParamList *head = ParamListHead->next;
    while (head != NULL)
    {
        ParamList *tmp = head;
        head = head->next;
        free(tmp);
    }
    ParamListHead->next = NULL;
    ParamListHead->Paramcnt = 0;
}
void TrueParamClear() // 把真实参数列表清空
{
    TrueParamList *head = TrueParamListHead->next;
    while (head != NULL)
    {
        TrueParamList *tmp = head;
        head = head->next;
        free(tmp);
    }
    TrueParamListHead->next = NULL;
    TrueParamListHead->Paramcnt = 0;
    TrueParamListTail = TrueParamListHead;
}
void ParamRegClear() // 把传递实参会使用到的寄存器清空
{
    for (int i = 4; i <= 7; i++)
    {
        RegisterDescriptionTable[i].cnt = 0;
        for (int j = 0; j < 10; j++)
        {
            memset(RegisterDescriptionTable[i].VarNames[j], 0, 10);
        }
    }
}

void PushVariableToStack(VaribleDescriptor *var) // 将一个局部变量压栈
{
    fprintf(ASMfile, "  addi $sp, $sp, %d\n", -4);
    TrueFrameSize += 4;
    LocalFrameSize += 4;
    fprintf(ASMfile, "  sw %s, 0($sp)\n", RegisterDescriptionTable[var->regNo].regname);
    var->posRef = POS_FP;
    var->offset = -TrueFrameSize;
}
void CopyVariableToStack(VaribleDescriptor *var) // 将原本在栈上有分配空间的局部变量从寄存器拷回栈上
{
    if (var->posRef == POS_FP)
    {
        fprintf(ASMfile, "  sw %s, %d($fp)\n", RegisterDescriptionTable[var->regNo].regname, var->offset);
    }
    else if (var->posRef == POS_SP)
    {
        fprintf(ASMfile, "  sw %s, %d($sp)\n", RegisterDescriptionTable[var->regNo].regname, var->offset);
    }
    else
        assert(0);
}

char *getOneIR()
{
    char *line = malloc(40);
    if (fgets(line, 40, IRfile) == NULL)
    {
        free(line);
        return NULL;
    }
    line[strcspn(line, "\n")] = '\0';
    return line;
}
void RegRecycle(uint32_t reg) // 将一个寄存器中的内容溢出到内存中
{
    int cnt = RegisterDescriptionTable[reg].cnt;
    for (int i = 0; i < cnt; i++)
    {
        // fprintf(ASMfile, "  sw %s, %s\n", RegisterDescriptionTable[reg].regname, RegisterDescriptionTable[reg].VarNames[i]);
        VaribleDescriptor *head = VaribleDescriptionTable->next;
        while (head != NULL)
        {
            if (strcmp(head->name, RegisterDescriptionTable[reg].VarNames[i]) == 0)
            {
                assert(head->regNo != -1);
                if (head->posRef == POS_REG) // 只存在于寄存器中的变量，现在要给它分配内存了
                {
                    PushVariableToStack(head);
                }
                // else if (head->dirtybit == true)
                // {
                //     CopyVariableToStack(head);
                // }
                head->regNo = -1;
                break;
            }
            head = head->next;
        }
    }
    RegisterDescriptionTable[reg].cnt = 0;
}
void setRegofVarible(char *name, int reg) // 当变量被装进寄存器后，记录之
{
    VaribleDescriptor *head = VaribleDescriptionTable->next;
    while (head != NULL)
    {
        if (strcmp(head->name, name) == 0)
        {
            head->regNo = reg;
            break;
        }
        head = head->next;
    }
    assert(head != NULL); // 不应当找不到变量
    strcpy(RegisterDescriptionTable[reg].VarNames[RegisterDescriptionTable[reg].cnt++], name);
    // RegisterDescriptionTable[reg].VarNames[RegisterDescriptionTable[reg].cnt++] = name;
    RegisterDescriptionTable[reg].timestamp = ++increTime;
}

void LoadVaribleIntoReg(char *name, int reg) // 将变量（或者内存位置）装入指定寄存器
{
    VaribleDescriptor *head = VaribleDescriptionTable->next;
    while (head != NULL)
    {
        if (strcmp(head->name, name) == 0)
        {
            break;
        }
        head = head->next;
    }
    assert(head != NULL); // 不应当找不到实参变量
    if (head->regNo != -1)
    {
        fprintf(ASMfile, "  move %s, %s\n", RegisterDescriptionTable[reg].regname, RegisterDescriptionTable[head->regNo].regname);
    }
    else if (head->posRef == POS_FP)
    {
        fprintf(ASMfile, "  lw %s, %d($fp)\n", RegisterDescriptionTable[reg].regname, head->offset);
    }
    else if (head->posRef == POS_REG && head->regNo == -1) // 特殊情况，这个变量还没有被分配寄存器
    {
        setRegofVarible(name, reg);
        return;
    }
    else
        assert(0);
    head->regNo = reg;
    strcpy(RegisterDescriptionTable[reg].VarNames[RegisterDescriptionTable[reg].cnt++], name);
    // RegisterDescriptionTable[reg].VarNames[RegisterDescriptionTable[reg].cnt++] = name;
    RegisterDescriptionTable[reg].timestamp = ++increTime;
}

VaribleDescriptor *VaribleCreate(char *name)
{
    VaribleDescriptor *head = VaribleDescriptionTable->next;
    while (head != NULL) // 如果已经在表里了
    {
        if (strcmp(head->name, name) == 0)
            return head;
        head = head->next;
    }
    VaribleDescriptor *newVar = malloc(sizeof(VaribleDescriptor));
    strcpy(newVar->name, name);
    newVar->regNo = -1;
    newVar->posRef = POS_REG; // 这种情况代表变量的声明，但是还没有在栈上或者寄存器中分配空间
    newVar->offset = 0;
    newVar->next = VaribleDescriptionTable->next;
    newVar->prev = VaribleDescriptionTable;
    VaribleDescriptionTable->next = newVar;
    if (newVar->next != NULL)
        newVar->next->prev = newVar;
    return newVar;
}

int getReg(char *name)
{
    VaribleDescriptor *head = VaribleDescriptionTable->next;
    while (head != NULL) // 如果已经在reg里了
    {
        if (strcmp(head->name, name) == 0)
        {
            if (head->regNo == -1)
                break;
            else
                return head->regNo;
        }
        head = head->next;
    }
    if (head == NULL)
    {
        head = VaribleCreate(name);
    }
    // 当前策略：LRU
    int mintime = 0x7fffffff;
    int minReg = 8;
    for (int i = 8; i <= 25; i++)
    {
        if (RegisterDescriptionTable[i].timestamp < mintime)
        {
            mintime = RegisterDescriptionTable[i].timestamp;
            minReg = i;
        }
    }
    RegRecycle(minReg);
    // setRegofVarible(name, minReg);
    //  从内存中加载变量到寄存器
    LoadVaribleIntoReg(name, minReg);
    // fprintf(ASMfile, "  lw %s, %s\n", RegisterDescriptionTable[minReg].regname, name);
    return minReg;
}

void genASM(char *IRcode)
{
    int index = 0;
    char *eleArray[8] = {NULL};

    char *token = strtok(IRcode, " ");
    while (token != NULL && index < 8)
    {
        eleArray[index] = token;
        index++;
        token = strtok(NULL, " ");
    }
    if (strcmp(eleArray[0], "LABEL") == 0)
    {
        fprintf(ASMfile, "%s:\n", eleArray[1]);
    }
    else if (strcmp(eleArray[0], "FUNCTION") == 0)
    {
        // ParamClear();
        ParamCnt = 0;
        fprintf(ASMfile, "\n%s:\n", eleArray[1]);
        // int frameSize = 10 * 4;
        int frameSize = 9 * 4;
        TrueFrameSize += frameSize;
        fprintf(ASMfile, "  addi $sp, $sp, %d\n", -frameSize);
        // fprintf(ASMfile, "  sw $ra, %d($sp)\n", (frameSize - 4));
        // fprintf(ASMfile, "  sw $fp, %d($sp)\n", (frameSize - 8));
        fprintf(ASMfile, "  sw $fp, %d($sp)\n", (frameSize - 4));
        fprintf(ASMfile, "  addi $fp, $sp, %d\n", frameSize);
        // 保存被调用者保存寄存器
        for (int i = 16; i <= 23; i++)
        {
            // fprintf(ASMfile, "  sw %s, %d($sp)\n", RegisterDescriptionTable[i].regname, frameSize - 4 * (10 - (i - 16)));
            fprintf(ASMfile, "  sw %s, %d($sp)\n", RegisterDescriptionTable[i].regname, frameSize - 4 * (9 - (i - 16)));
        }
    }
    else if (strcmp(eleArray[0], "GOTO") == 0)
    {
        fprintf(ASMfile, "  j %s\n", eleArray[1]);
    }
    else if (strcmp(eleArray[0], "RETURN") == 0)
    {
        fprintf(ASMfile, "  move $v0, %s\n", RegisterDescriptionTable[getReg(eleArray[1])].regname);
        // 回收局部变量占用的空间
        if (LocalFrameSize > 0)
            fprintf(ASMfile, "  addi $sp, $sp, %d\n", LocalFrameSize);
        LocalFrameSize = 0;
        //  恢复被调用者保存寄存器
        // int frameSize = (ParamListHead->Paramcnt + 10) * 4;
        int frameSize = (ParamListHead->Paramcnt + 9) * 4;
        for (int i = 16; i <= 23; i++)
        {
            // fprintf(ASMfile, "  lw %s, %d($sp)\n", RegisterDescriptionTable[i].regname, frameSize - 4 * (10 - (i - 16)));
            fprintf(ASMfile, "  lw %s, %d($sp)\n", RegisterDescriptionTable[i].regname, frameSize - 4 * (9 - (i - 16)));
        }
        // fprintf(ASMfile, "  lw $ra, %d($sp)\n", (frameSize - 4));
        // fprintf(ASMfile, "  lw $fp, %d($sp)\n", (frameSize - 8));
        fprintf(ASMfile, "  lw $fp, %d($sp)\n", (frameSize - 4));
        fprintf(ASMfile, "  addi $sp, $sp, %d\n", frameSize);
        TrueFrameSize -= frameSize;
        fprintf(ASMfile, "  jr $ra\n");
    }
    else if (strcmp(eleArray[0], "ARG") == 0)
    {
        // 任务：记录实参的信息到真实参数列表
        TrueParamListTail->next = malloc(sizeof(TrueParamList));
        TrueParamListTail->next->prev = TrueParamListTail;
        TrueParamListTail = TrueParamListTail->next;
        strcpy(TrueParamListTail->name, eleArray[1]);
        TrueParamListTail->ParamNo = TrueParamListTail->prev->ParamNo + 1;
        TrueParamListTail->next = NULL;
        TrueParamListHead->Paramcnt++;
    }
    else if (strcmp(eleArray[0], "PARAM") == 0)
    {
        // 任务：绑定到寄存器或者内存位置
        VaribleDescriptor *newParamVar = VaribleCreate(eleArray[1]);
        if (ParamCnt < 4)
        {
            newParamVar->posRef = POS_REG;
            newParamVar->offset = 0;
            newParamVar->regNo = ParamCnt + 4;
        }
        else
        {
            newParamVar->posRef = POS_FP;
            newParamVar->offset = (ParamCnt - 4 + 2) * 4;
        }
        ParamCnt++;
    }
    else if (strcmp(eleArray[0], "CALL") == 0 || strcmp(eleArray[0], "WRITE") == 0 || strcmp(eleArray[0], "READ") == 0)
    {
        // 调用者保存寄存器
        // fprintf(ASMfile, "  addi $sp,$sp,-%d\n", 14 * 4);
        // TrueFrameSize += 14 * 4;
        // 调用者应当保存ra
        fprintf(ASMfile, "  addi $sp,$sp,-%d\n", 15 * 4);
        TrueFrameSize += 15 * 4;
        //  特殊对待WRITE
        if (strcmp(eleArray[0], "WRITE") == 0)
        {
            // 和ARG做的事情一样
            TrueParamListTail->next = malloc(sizeof(TrueParamList));
            TrueParamListTail->next->prev = TrueParamListTail;
            TrueParamListTail = TrueParamListTail->next;
            strcpy(TrueParamListTail->name, eleArray[1]);
            TrueParamListTail->ParamNo = TrueParamListTail->prev->ParamNo + 1;
            TrueParamListTail->next = NULL;
            TrueParamListHead->Paramcnt++;
        }
        for (int i = 8; i <= 15; i++)
        {
            fprintf(ASMfile, "  sw %s,%d($sp)\n", RegisterDescriptionTable[i].regname, (i - 8 + 4) * 4);
        }
        for (int i = 24; i <= 25; i++)
        {
            fprintf(ASMfile, "  sw %s,%d($sp)\n", RegisterDescriptionTable[i].regname, (i - 16 + 4) * 4);
        }
        for (int i = 4; i <= 7; i++)
        {
            fprintf(ASMfile, "  sw %s,%d($sp)\n", RegisterDescriptionTable[i].regname, (i - 4) * 4);
        }
        fprintf(ASMfile, "  sw $ra,%d($sp)\n", 14 * 4);
        // 将实参放入寄存器及栈上
        int TrueParamCnt = TrueParamListHead->Paramcnt;
        // 给多于4个的参数分配栈空间
        if (TrueParamCnt > 4)
        {
            fprintf(ASMfile, "  addi $sp,$sp,-%d\n", (TrueParamCnt - 4) * 4);
            TrueFrameSize += (TrueParamCnt - 4) * 4;
        }
        TrueParamList *p = TrueParamListHead->next;
        for (int i = 0; i < TrueParamCnt; i++)
        {
            if (i < 4)
            {
                LoadVaribleIntoReg(p->name, i + 4);
            }
            else
            {
                fprintf(ASMfile, "  sw %s,%d($sp)\n", RegisterDescriptionTable[getReg(p->name)].regname, (i - 4) * 4);
            }
            p = p->next;
        }
        // 实参列表已经没用了
        TrueParamClear();
        // 调用函数
        if (strcmp(eleArray[0], "WRITE") == 0)
        {
            fprintf(ASMfile, "  jal write\n");
        }
        else if (strcmp(eleArray[0], "READ") == 0)
        {
            fprintf(ASMfile, "  jal read\n");
        }
        else
        {
            fprintf(ASMfile, "  jal %s\n", eleArray[3]);
        }
        // fprintf(ASMfile, "  jal %s\n", eleArray[3]);
        //  回收多于4个的参数
        if (ParamListHead->Paramcnt > 4)
        {
            fprintf(ASMfile, "  addi $sp,$sp,%d\n", (ParamListHead->Paramcnt - 4) * 4);
            TrueFrameSize -= (ParamListHead->Paramcnt - 4) * 4;
        }
        // 恢复调用者保存寄存器
        for (int i = 8; i <= 15; i++)
        {
            fprintf(ASMfile, "  lw %s,%d($sp)\n", RegisterDescriptionTable[i].regname, (i - 8 + 4) * 4);
        }
        for (int i = 24; i <= 25; i++)
        {
            fprintf(ASMfile, "  lw %s,%d($sp)\n", RegisterDescriptionTable[i].regname, (i - 16 + 4) * 4);
        }
        for (int i = 4; i <= 7; i++)
        {
            fprintf(ASMfile, "  lw %s,%d($sp)\n", RegisterDescriptionTable[i].regname, (i - 4) * 4);
        }
        // 调用者恢复ra
        fprintf(ASMfile, "  lw $ra,%d($sp)\n", 14 * 4);
        // fprintf(ASMfile, "  addi $sp,$sp,%d\n", 14 * 4);
        // TrueFrameSize -= 14 * 4;
        fprintf(ASMfile, "  addi $sp,$sp,%d\n", 15 * 4);
        TrueFrameSize -= 15 * 4;
        ParamRegClear();
    }
    else if (strcmp(eleArray[1], "=") == 0) // 在进行这种赋值操作之前，左值变量应当已经定义过了
    {
        if (eleArray[0][0] == '*')
        {
            fprintf(ASMfile, "  sw %s,0(%s)\n", RegisterDescriptionTable[getReg(eleArray[2])].regname, RegisterDescriptionTable[getReg(eleArray[0] + 1)].regname);
        }
        else
            assert(0); // 先假设没有x=y这种赋值操作
    }
    else if (strcmp(eleArray[0], "IF") == 0)
    {
        if (strcmp(eleArray[2], "==") == 0)
        {
            fprintf(ASMfile, "  beq %s, %s, %s\n", RegisterDescriptionTable[getReg(eleArray[1])].regname, RegisterDescriptionTable[getReg(eleArray[3])].regname, eleArray[5]);
        }
        else if (strcmp(eleArray[2], "!=") == 0)
        {
            fprintf(ASMfile, "  bne %s, %s, %s\n", RegisterDescriptionTable[getReg(eleArray[1])].regname, RegisterDescriptionTable[getReg(eleArray[3])].regname, eleArray[5]);
        }
        else if (strcmp(eleArray[2], ">") == 0)
        {
            fprintf(ASMfile, "  bgt %s, %s, %s\n", RegisterDescriptionTable[getReg(eleArray[1])].regname, RegisterDescriptionTable[getReg(eleArray[3])].regname, eleArray[5]);
        }
        else if (strcmp(eleArray[2], "<") == 0)
        {
            fprintf(ASMfile, "  blt %s, %s, %s\n", RegisterDescriptionTable[getReg(eleArray[1])].regname, RegisterDescriptionTable[getReg(eleArray[3])].regname, eleArray[5]);
        }
        else if (strcmp(eleArray[2], ">=") == 0)
        {
            fprintf(ASMfile, "  bge %s, %s, %s\n", RegisterDescriptionTable[getReg(eleArray[1])].regname, RegisterDescriptionTable[getReg(eleArray[3])].regname, eleArray[5]);
        }
        else if (strcmp(eleArray[2], "<=") == 0)
        {
            fprintf(ASMfile, "  ble %s, %s, %s\n", RegisterDescriptionTable[getReg(eleArray[1])].regname, RegisterDescriptionTable[getReg(eleArray[3])].regname, eleArray[5]);
        }
        else
            assert(0);
    }
    else if (strcmp(eleArray[1], ":=") == 0) // 重点！
    {
        VaribleCreate(eleArray[0]);
        if (index == 3)
        {
            if (eleArray[2][0] == '*')
            {
                fprintf(ASMfile, "  lw %s,0(%s)\n", RegisterDescriptionTable[getReg(eleArray[0])].regname, RegisterDescriptionTable[getReg(eleArray[2] + 1)].regname);
            }
            else if (eleArray[2][0] == '#')
            {
                fprintf(ASMfile, "  li %s,%s\n", RegisterDescriptionTable[getReg(eleArray[0])].regname, eleArray[2] + 1);
            }
            else
            {
                // TODO:可优化
                fprintf(ASMfile, "  move %s,%s\n", RegisterDescriptionTable[getReg(eleArray[0])].regname, RegisterDescriptionTable[getReg(eleArray[2])].regname);
            }
        }
        else if (index == 4)
        {
            if (strcmp(eleArray[2], "CALL") == 0)
            {
                // 调用者保存寄存器
                // fprintf(ASMfile, "  addi $sp,$sp,-%d\n", 14 * 4);
                // TrueFrameSize += 14 * 4;
                // 调用者应当保存ra
                fprintf(ASMfile, "  addi $sp,$sp,-%d\n", 15 * 4);
                TrueFrameSize += 15 * 4;
                //  特殊对待WRITE
                if (strcmp(eleArray[0], "WRITE") == 0)
                {
                    // 和ARG做的事情一样
                    TrueParamListTail->next = malloc(sizeof(TrueParamList));
                    TrueParamListTail->next->prev = TrueParamListTail;
                    TrueParamListTail = TrueParamListTail->next;
                    strcpy(TrueParamListTail->name, eleArray[1]);
                    TrueParamListTail->ParamNo = TrueParamListTail->prev->ParamNo + 1;
                    TrueParamListTail->next = NULL;
                    TrueParamListHead->Paramcnt++;
                }
                for (int i = 8; i <= 15; i++)
                {
                    fprintf(ASMfile, "  sw %s,%d($sp)\n", RegisterDescriptionTable[i].regname, (i - 8 + 4) * 4);
                }
                for (int i = 24; i <= 25; i++)
                {
                    fprintf(ASMfile, "  sw %s,%d($sp)\n", RegisterDescriptionTable[i].regname, (i - 16 + 4) * 4);
                }
                for (int i = 4; i <= 7; i++)
                {
                    fprintf(ASMfile, "  sw %s,%d($sp)\n", RegisterDescriptionTable[i].regname, (i - 4) * 4);
                }
                fprintf(ASMfile, "  sw $ra,%d($sp)\n", 14 * 4);
                // 将实参放入寄存器及栈上
                int TrueParamCnt = TrueParamListHead->Paramcnt;
                // 给多于4个的参数分配栈空间
                if (TrueParamCnt > 4)
                {
                    fprintf(ASMfile, "  addi $sp,$sp,-%d\n", (TrueParamCnt - 4) * 4);
                    TrueFrameSize += (TrueParamCnt - 4) * 4;
                }
                TrueParamList *p = TrueParamListHead->next;
                for (int i = 0; i < TrueParamCnt; i++)
                {
                    if (i < 4)
                    {
                        LoadVaribleIntoReg(p->name, i + 4);
                    }
                    else
                    {
                        fprintf(ASMfile, "  sw %s,%d($sp)\n", RegisterDescriptionTable[getReg(p->name)].regname, (i - 4) * 4);
                    }
                    p = p->next;
                }
                // 实参列表已经没用了
                TrueParamClear();
                // 调用函数
                fprintf(ASMfile, "  jal %s\n", eleArray[3]);
                //  回收多于4个的参数
                if (ParamListHead->Paramcnt > 4)
                {
                    fprintf(ASMfile, "  addi $sp,$sp,%d\n", (ParamListHead->Paramcnt - 4) * 4);
                    TrueFrameSize -= (ParamListHead->Paramcnt - 4) * 4;
                }
                // 恢复调用者保存寄存器
                for (int i = 8; i <= 15; i++)
                {
                    fprintf(ASMfile, "  lw %s,%d($sp)\n", RegisterDescriptionTable[i].regname, (i - 8 + 4) * 4);
                }
                for (int i = 24; i <= 25; i++)
                {
                    fprintf(ASMfile, "  lw %s,%d($sp)\n", RegisterDescriptionTable[i].regname, (i - 16 + 4) * 4);
                }
                for (int i = 4; i <= 7; i++)
                {
                    fprintf(ASMfile, "  lw %s,%d($sp)\n", RegisterDescriptionTable[i].regname, (i - 4) * 4);
                }
                // 调用者恢复ra
                fprintf(ASMfile, "  lw $ra,%d($sp)\n", 14 * 4);
                // fprintf(ASMfile, "  addi $sp,$sp,%d\n", 14 * 4);
                // TrueFrameSize -= 14 * 4;
                fprintf(ASMfile, "  addi $sp,$sp,%d\n", 15 * 4);
                TrueFrameSize -= 15 * 4;
                fprintf(ASMfile, "  move %s,$v0\n", RegisterDescriptionTable[getReg(eleArray[0])].regname);
            }
            else
                assert(0);
        }
        else if (index == 5)
        {
            if (eleArray[3][0] == '+' && eleArray[4][1] == '#') // x := y + #k
            {
                fprintf(ASMfile, "  addi %s,%s,%s\n", RegisterDescriptionTable[getReg(eleArray[0])].regname, RegisterDescriptionTable[getReg(eleArray[2])].regname, eleArray[4] + 1);
            }
            else if (eleArray[3][0] == '+' && eleArray[4][1] != '#') // x := y + z
            {
                fprintf(ASMfile, "  add %s,%s,%s\n", RegisterDescriptionTable[getReg(eleArray[0])].regname, RegisterDescriptionTable[getReg(eleArray[2])].regname, RegisterDescriptionTable[getReg(eleArray[4])].regname);
            }
            else if (eleArray[3][0] == '-' && eleArray[4][1] == '#') // x := y - #k
            {
                fprintf(ASMfile, "  subi %s,%s,%s\n", RegisterDescriptionTable[getReg(eleArray[0])].regname, RegisterDescriptionTable[getReg(eleArray[2])].regname, eleArray[4] + 1);
            }
            else if (eleArray[3][0] == '-' && eleArray[4][1] != '#') // x := y - z
            {
                fprintf(ASMfile, "  sub %s,%s,%s\n", RegisterDescriptionTable[getReg(eleArray[0])].regname, RegisterDescriptionTable[getReg(eleArray[2])].regname, RegisterDescriptionTable[getReg(eleArray[4])].regname);
            }
            else if (eleArray[3][0] == '*')
            {
                fprintf(ASMfile, "  mul %s,%s,%s\n", RegisterDescriptionTable[getReg(eleArray[0])].regname, RegisterDescriptionTable[getReg(eleArray[2])].regname, RegisterDescriptionTable[getReg(eleArray[4])].regname);
            }
            else if (eleArray[3][0] == '/')
            {
                fprintf(ASMfile, "  div %s,%s\n", RegisterDescriptionTable[getReg(eleArray[2])].regname, RegisterDescriptionTable[getReg(eleArray[4])].regname);
                fprintf(ASMfile, "  mflo %s\n", RegisterDescriptionTable[getReg(eleArray[0])].regname);
            }
            else
                assert(0);
        }
        else
            assert(0);
    }
}

void targetCodeGen()
{
    IRfile = fopen("a.ir", "r+");
    ASMfile = fopen("ASM.asm", "w+");
    initCode();
    char *IRcode;
    while ((IRcode = getOneIR()) != NULL)
    {
        genASM(IRcode);
        free(IRcode);
    }
    fclose(IRfile);
    fclose(ASMfile);
}