#include "codegen.h"
int increTime = 0;
int ParamCnt = 0;
int TrueFrameSize = 0;  // 整个栈帧的大小（包括存储的寄存器和局部变量）
int LocalFrameSize = 0; // 存储局部变量的栈空间大小

int FuncCnt = 0, FuncCnt2 = 0; // 函数个数，现在是第几个函数
char *args[500][10000];
int argsize[500][10000];
int argsCnt[500];
int regCnt = 0;
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
        for (int j = 0; j < 50; j++)
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

VaribleDescriptor *getVariableDescriptor(char *name)
{
    VaribleDescriptor *head = VaribleDescriptionTable->next;
    while (head != NULL)
    {
        if (strcmp(head->name, name) == 0)
            return head;
        head = head->next;
    }
    assert(0); // 不应当找不到变量
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
        for (int j = 0; j < 50; j++)
        {
            memset(RegisterDescriptionTable[i].VarNames[j], 0, 10);
        }
    }
}

void PushVariableToStack(VaribleDescriptor *var, int varsize) // 在函数开头，在栈上为可能用到的局部变量一次性分配空间，但不生成指令
{
    TrueFrameSize += varsize;
    LocalFrameSize += varsize;
    if (var->regNo != -1)
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

void RegRecycle(uint32_t reg, bool flushback) // 将一个寄存器中的内容溢出到内存中
{
    int cnt = RegisterDescriptionTable[reg].cnt;
    for (int i = 0; i < cnt; i++)
    {
        VaribleDescriptor *head = VaribleDescriptionTable->next;
        while (head != NULL)
        {
            if (strcmp(head->name, RegisterDescriptionTable[reg].VarNames[i]) == 0)
            {
                assert(head->regNo != -1);
                if (flushback)
                    CopyVariableToStack(head);
                head->regNo = -1;
                break;
            }
            head = head->next;
        }
    }
    RegisterDescriptionTable[reg].cnt = 0;
}
void VariableRegClear() // 清空寄存器描述符表
{
    for (int i = 8; i <= 15; i++)
    {
        RegRecycle(i, false);
    }
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

    while (head != NULL) // 如果已经在reg里了(前4个参数)
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
    int minReg = 8 + regCnt;
    if (name[0] == '#') // 立即数
    {
        fprintf(ASMfile, "  li %s,%s\n", RegisterDescriptionTable[minReg].regname, name + 1);
    }
    else
    {

        // 等号右边如果是解引用变量，需要二次加载
        if (name[0] == '*')
        {
            LoadVaribleIntoReg(name + 1, minReg);
            fprintf(ASMfile, "  lw %s,0(%s)\n", RegisterDescriptionTable[minReg].regname, RegisterDescriptionTable[minReg].regname);
        }
        else
        {
            LoadVaribleIntoReg(name, minReg);
        }
    }
    regCnt++;
    regCnt %= 8;
    return minReg;
}
int getEmptyReg()
{
    int minReg = 8 + regCnt;
    regCnt++;
    regCnt %= 8;
    return minReg;
}
void handleRegUse(uint32_t reg)
{
    if (reg >= 8 && reg <= 15)
    {
        RegRecycle(reg, true);
    }
}
// 解析一条中间代码
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
        TrueFrameSize = 0;
        LocalFrameSize = 0;
        FuncCnt2++;
        // ParamClear();
        ParamCnt = 0;
        fprintf(ASMfile, "\n%s:\n", eleArray[1]);
        // int frameSize = 10 * 4;
        int frameSize = 9 * 4;
        TrueFrameSize += frameSize;
        fprintf(ASMfile, "  addi $sp, $sp, %d\n", -frameSize);
        fprintf(ASMfile, "  sw $fp, %d($sp)\n", (frameSize - 4));
        fprintf(ASMfile, "  addi $fp, $sp, %d\n", frameSize);
        // 保存被调用者保存寄存器
        for (int i = 16; i <= 23; i++)
        {
            fprintf(ASMfile, "  sw %s, %d($sp)\n", RegisterDescriptionTable[i].regname, frameSize - 4 * (9 - (i - 16)));
        }
        // 为局部变量在变量表中创建表项
        for (int i = 0; i < argsCnt[FuncCnt2]; i++)
        {
            PushVariableToStack(VaribleCreate(args[FuncCnt2][i]), argsize[FuncCnt2][i]);
        }
        // 计算局部变量占用的空间
        fprintf(ASMfile, "  addi $sp, $sp, -%d\n", LocalFrameSize);
    }
    else if (strcmp(eleArray[0], "GOTO") == 0)
    {
        fprintf(ASMfile, "  j %s\n", eleArray[1]);
    }
    else if (strcmp(eleArray[0], "RETURN") == 0)
    {
        fprintf(ASMfile, "  move $v0, %s\n", RegisterDescriptionTable[getReg(eleArray[1])].regname);
        handleRegUse(getReg(eleArray[1]));
        fprintf(ASMfile, "  addi $sp, $sp, %d\n", LocalFrameSize);
        //  恢复被调用者保存寄存器
        // int frameSize = (ParamListHead->Paramcnt + 10) * 4;
        int frameSize = (ParamListHead->Paramcnt + 9) * 4;
        for (int i = 16; i <= 23; i++)
        {
            fprintf(ASMfile, "  lw %s, %d($sp)\n", RegisterDescriptionTable[i].regname, frameSize - 4 * (9 - (i - 16)));
        }
        fprintf(ASMfile, "  lw $fp, %d($sp)\n", (frameSize - 4));
        fprintf(ASMfile, "  addi $sp, $sp, %d\n", frameSize);
        TrueFrameSize -= frameSize;
        fprintf(ASMfile, "  jr $ra\n");
    }
    else if (strcmp(eleArray[0], "ARG") == 0)
    {
        TrueParamList *newParam = malloc(sizeof(TrueParamList));
        strcpy(newParam->name, eleArray[1]);
        newParam->next = TrueParamListHead->next;
        newParam->prev = TrueParamListHead;
        TrueParamListHead->next = newParam;
        if (newParam->next != NULL)
            newParam->next->prev = newParam;
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
                if (p->name[0] == '*')
                {
                    LoadVaribleIntoReg(p->name + 1, i + 4);
                    fprintf(ASMfile, "  lw %s,0(%s)\n", RegisterDescriptionTable[i + 4].regname, RegisterDescriptionTable[i + 4].regname);
                }
                else
                {
                    LoadVaribleIntoReg(p->name, i + 4);
                }
            }
            else
            {
                if (p->name[0] == '*')
                {
                    int tmpEmptyReg = getEmptyReg();
                    LoadVaribleIntoReg(p->name + 1, tmpEmptyReg);
                    fprintf(ASMfile, "  lw %s,0(%s)\n", RegisterDescriptionTable[tmpEmptyReg].regname, RegisterDescriptionTable[tmpEmptyReg].regname);
                    fprintf(ASMfile, "  sw %s,%d($sp)\n", RegisterDescriptionTable[tmpEmptyReg].regname, (i - 4) * 4);
                }
                else
                {
                    fprintf(ASMfile, "  sw %s,%d($sp)\n", RegisterDescriptionTable[getReg(p->name)].regname, (i - 4) * 4);
                }
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
            if (index > 1)
            {
                fprintf(ASMfile, "  move %s,$v0\n", RegisterDescriptionTable[getReg(eleArray[1])].regname);
                handleRegUse(getReg(eleArray[1]));
            }
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
        fprintf(ASMfile, "  lw $ra,%d($sp)\n", 14 * 4);
        fprintf(ASMfile, "  addi $sp,$sp,%d\n", 15 * 4);
        TrueFrameSize -= 15 * 4;
        ParamRegClear();
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
            if (eleArray[0][0] != '*')
            {
                if (eleArray[2][0] == '#')
                {
                    fprintf(ASMfile, "  li %s,%s\n", RegisterDescriptionTable[getReg(eleArray[0])].regname, eleArray[2] + 1);
                }
                else if (eleArray[2][0] == '&')
                {
                    VaribleDescriptor *tmp = getVariableDescriptor(eleArray[2] + 1);
                    if (tmp->posRef == POS_FP)
                    {
                        fprintf(ASMfile, "  addi %s,$fp,%d\n", RegisterDescriptionTable[getReg(eleArray[0])].regname, tmp->offset);
                    }
                    else if (tmp->posRef == POS_SP)
                    {
                        assert(0);
                        fprintf(ASMfile, "  addi %s,$sp,%d\n", RegisterDescriptionTable[getReg(eleArray[0])].regname, tmp->offset);
                    }
                    else
                    {
                        assert(0);
                    }
                }
                else
                {
                    fprintf(ASMfile, "  move %s,%s\n", RegisterDescriptionTable[getReg(eleArray[0])].regname, RegisterDescriptionTable[getReg(eleArray[2])].regname);
                }
                handleRegUse(getReg(eleArray[0]));
            }
            else
            {
                int tmpEmptyReg = getEmptyReg();
                if (eleArray[2][0] == '#')
                {
                    fprintf(ASMfile, "  li %s,%s\n", RegisterDescriptionTable[tmpEmptyReg].regname, eleArray[2] + 1);
                    // handleRegUse(getReg(eleArray[0]));
                }
                else if (eleArray[2][0] == '&')
                {
                    VaribleDescriptor *tmp = getVariableDescriptor(eleArray[2] + 1);
                    if (tmp->posRef == POS_FP)
                    {
                        fprintf(ASMfile, "  addi %s,$fp,%d\n", RegisterDescriptionTable[tmpEmptyReg].regname, tmp->offset);
                    }
                    else if (tmp->posRef == POS_SP)
                    {
                        assert(0);
                        fprintf(ASMfile, "  addi %s,$sp,%d\n", RegisterDescriptionTable[tmpEmptyReg].regname, tmp->offset);
                    }
                    else
                    {
                        assert(0);
                    }
                }
                else
                {
                    fprintf(ASMfile, "  move %s,%s\n", RegisterDescriptionTable[tmpEmptyReg].regname, RegisterDescriptionTable[getReg(eleArray[2])].regname);
                }
                fprintf(ASMfile, "  sw %s,0(%s)\n", RegisterDescriptionTable[tmpEmptyReg].regname, RegisterDescriptionTable[getReg(eleArray[0] + 1)].regname);
            }
        }
        else if (index == 4)
        {
            if (strcmp(eleArray[2], "CALL") == 0)
            {
                // 调用者保存寄存器
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
                        if (p->name[0] == '*')
                        {
                            LoadVaribleIntoReg(p->name + 1, i + 4);
                            fprintf(ASMfile, "  lw %s,0(%s)\n", RegisterDescriptionTable[i + 4].regname, RegisterDescriptionTable[i + 4].regname);
                        }
                        else
                        {
                            LoadVaribleIntoReg(p->name, i + 4);
                        }
                    }
                    else
                    {
                        if (p->name[0] == '*')
                        {
                            int tmpEmptyReg = getEmptyReg();
                            LoadVaribleIntoReg(p->name + 1, tmpEmptyReg);
                            fprintf(ASMfile, "  lw %s,0(%s)\n", RegisterDescriptionTable[tmpEmptyReg].regname, RegisterDescriptionTable[tmpEmptyReg].regname);
                            fprintf(ASMfile, "  sw %s,%d($sp)\n", RegisterDescriptionTable[tmpEmptyReg].regname, (i - 4) * 4);
                        }
                        else
                        {
                            fprintf(ASMfile, "  sw %s,%d($sp)\n", RegisterDescriptionTable[getReg(p->name)].regname, (i - 4) * 4);
                        }
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
                fprintf(ASMfile, "  addi $sp,$sp,%d\n", 15 * 4);
                TrueFrameSize -= 15 * 4;
                // 最后讨论一下接住返回值的是不是解引用
                if (eleArray[0][0] != '*')
                {
                    fprintf(ASMfile, "  move %s,$v0\n", RegisterDescriptionTable[getReg(eleArray[0])].regname);
                    handleRegUse(getReg(eleArray[0]));
                }
                else
                {
                    int tmpEmptyReg = getEmptyReg();
                    fprintf(ASMfile, "  move %s,$v0\n", RegisterDescriptionTable[tmpEmptyReg].regname);
                    fprintf(ASMfile, "  sw %s,0(%s)\n", RegisterDescriptionTable[tmpEmptyReg].regname, RegisterDescriptionTable[getReg(eleArray[0] + 1)].regname);
                }
            }
            else
                assert(0);
        }
        else if (index == 5)
        {
            if (eleArray[0][0] != '*')
            {
                if (eleArray[3][0] == '+')
                {
                    fprintf(ASMfile, "  add %s,%s,%s\n", RegisterDescriptionTable[getReg(eleArray[0])].regname, RegisterDescriptionTable[getReg(eleArray[2])].regname, RegisterDescriptionTable[getReg(eleArray[4])].regname);
                }
                else if (eleArray[3][0] == '-')
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
                {
                    assert(0);
                }
                handleRegUse(getReg(eleArray[0])); // 存回去
            }
            else
            {
                int tmpEmptyReg = getEmptyReg();
                if (eleArray[3][0] == '+')
                {
                    fprintf(ASMfile, "  add %s,%s,%s\n", RegisterDescriptionTable[tmpEmptyReg].regname, RegisterDescriptionTable[getReg(eleArray[2])].regname, RegisterDescriptionTable[getReg(eleArray[4])].regname);
                }
                else if (eleArray[3][0] == '-')
                {
                    fprintf(ASMfile, "  sub %s,%s,%s\n", RegisterDescriptionTable[tmpEmptyReg].regname, RegisterDescriptionTable[getReg(eleArray[2])].regname, RegisterDescriptionTable[getReg(eleArray[4])].regname);
                }
                else if (eleArray[3][0] == '*')
                {
                    fprintf(ASMfile, "  mul %s,%s,%s\n", RegisterDescriptionTable[tmpEmptyReg].regname, RegisterDescriptionTable[getReg(eleArray[2])].regname, RegisterDescriptionTable[getReg(eleArray[4])].regname);
                }
                else if (eleArray[3][0] == '/')
                {
                    fprintf(ASMfile, "  div %s,%s\n", RegisterDescriptionTable[getReg(eleArray[2])].regname, RegisterDescriptionTable[getReg(eleArray[4])].regname);
                    fprintf(ASMfile, "  mflo %s\n", RegisterDescriptionTable[tmpEmptyReg].regname);
                }
                else
                {
                    assert(0);
                }
                fprintf(ASMfile, "  sw %s,0(%s)\n", RegisterDescriptionTable[tmpEmptyReg].regname, RegisterDescriptionTable[getReg(eleArray[0] + 1)].regname);
            }
        }
        else
            assert(0);
    }
}
void initArg()
{
    char *IRcode;
    int state = 0;
    while ((IRcode = getOneIR()) != NULL)
    {
        int index = 0;
        char *token = strtok(IRcode, " ");
        char *eleArray[8] = {NULL};
        while (token != NULL && index < 8)
        {
            eleArray[index] = token;
            index++;
            token = strtok(NULL, " ");
        }
        char *waitname = malloc(12);
        int waitsize = -1;
        if (strcmp(eleArray[0], "FUNCTION") == 0)
        {
            FuncCnt++;
            argsCnt[FuncCnt] = 0;
        }
        else if (strcmp(eleArray[0], "READ") == 0)
        {
            strcpy(waitname, eleArray[1]);
            waitsize = 4;
        }
        else if (strcmp(eleArray[1], ":=") == 0)
        {
            if (eleArray[0][0] == '*')
                eleArray[0]++;
            strcpy(waitname, eleArray[0]);
            waitsize = 4;
        }
        else if (strcmp(eleArray[0], "DEC") == 0)
        {
            strcpy(waitname, eleArray[1]);
            waitsize = atoi(eleArray[2]);
        }
        if (waitsize == -1)
            continue;
        bool flag = true;
        for (int i = 0; i < argsCnt[FuncCnt]; i++)
        {
            if (strcmp(args[FuncCnt][i], eleArray[0]) == 0)
            {
                flag = false;
                break;
            }
        }
        if (flag)
        {
            char *tmp = malloc(12);
            strcpy(tmp, eleArray[0]);
            argsize[FuncCnt][argsCnt[FuncCnt]] = waitsize;
            args[FuncCnt][argsCnt[FuncCnt]++] = waitname;
        }
        free(IRcode);
    }
}
void targetCodeGen(char *irname, char *filename)
{
    IRfile = fopen(irname, "r+");
    ASMfile = fopen(filename, "w+");
    // 扫描并记录每个函数中的局部变量
    initArg();
    fclose(IRfile);
    IRfile = fopen(irname, "r+");
    initCode();
    char *IRcode;
    while ((IRcode = getOneIR()) != NULL)
    {
        genASM(IRcode);
        VariableRegClear();
        free(IRcode);
    }
    fclose(IRfile);
    fclose(ASMfile);
}