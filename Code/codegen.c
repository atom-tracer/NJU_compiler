#include "codegen.h"
int increTime = 0;
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
    for (int i = 0; i < 32; i++)
    {
        RegisterDescriptionTable[i].cnt = 0;
        RegisterDescriptionTable[i].timestamp = 0;
        sprintf(RegisterDescriptionTable[i].regname, "$t%d", i);
    }
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
        fprintf(ASMfile, "store reg%d, %s\n", reg, RegisterDescriptionTable[reg].VarNames[i]);
        VaribleDescriptor *head = VaribleDescriptionTable->next;
        while (head != NULL)
        {
            if (strcmp(head->name, RegisterDescriptionTable[reg].VarNames[i]) == 0)
            {
                head->regNo = -1;
                break;
            }
            head = head->next;
        }
        // free(RegisterDescriptionTable[reg].regNames[i]);
    }
    RegisterDescriptionTable[reg].cnt = 0;
}
void setRegofVarible(char *name, int reg)
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
    RegisterDescriptionTable[reg].VarNames[RegisterDescriptionTable[reg].cnt++] = name;
    RegisterDescriptionTable[reg].timestamp = ++increTime;
}

VaribleDescriptor *VaribleCreate(char *name)
{
    VaribleDescriptor *head = VaribleDescriptionTable->next;
    while (head != NULL)
    {
        if (strcmp(head->name, name) == 0)
            return head;
        head = head->next;
    }
    VaribleDescriptor *newVar = malloc(sizeof(VaribleDescriptor));
    strcpy(newVar->name, name);
    newVar->regNo = -1;
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
        if (strcmp(head->name, name) == 0 && head->regNo != -1)
        {
            if (head->regNo == -1)
                break;
            else
                return head->regNo;
        }
        head = head->next;
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
    setRegofVarible(name, minReg);
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

    //
    if (strcmp(eleArray[0], "LABEL") == 0)
    {
        fprintf(ASMfile, "%s\n", eleArray[1]);
    }
    else if (strcmp(eleArray[0], "FUNCTION") == 0)
    {
        fprintf(ASMfile, "\n%s:\n", eleArray[1]);
        fprintf(ASMfile, "move $fp, $sp\n");
        fprintf(ASMfile, "addi $sp, $sp, -%s\n", eleArray[2]);
    }
    else if (strcmp(eleArray[0], "GOTO") == 0)
    {
        fprintf(ASMfile, "j %s\n", eleArray[1]);
    }
    else if (strcmp(eleArray[0], "RETURN") == 0)
    {
        fprintf(ASMfile, "move $v0, %s\n", eleArray[1]);
        fprintf(ASMfile, "jr $ra\n");
    }
    else if (strcmp(eleArray[0], "ARG") == 0)
    {
        fprintf(ASMfile, "  move $t0, $fp\n");
        fprintf(ASMfile, "  addi $t0, $t0, -%s\n", eleArray[1]);
        fprintf(ASMfile, "  lw $t0, 0($t0)\n");
        fprintf(ASMfile, "  move $a0, $t0\n");
    }
    else if (strcmp(eleArray[0], "PARAM") == 0)
    {
        fprintf(ASMfile, "  move $t0, $fp\n");
        fprintf(ASMfile, "  addi $t0, $t0, -%s\n", eleArray[1]);
        fprintf(ASMfile, "  sw $a0, 0($t0)\n");
    }
    else if (strcmp(eleArray[0], "CALL") == 0)
    {
        fprintf(ASMfile, "  move $ra, $fp\n");
        fprintf(ASMfile, "  jal %s\n", eleArray[1]);
        fprintf(ASMfile, "  move $fp, $ra\n");
    }
    else if (strcmp(eleArray[1], "=") == 0)
    {
        VaribleCreate(eleArray[0]);
        if (eleArray[0][0] == '*')
        {
            fprintf(ASMfile, "sw %s,0(%s)\n", RegisterDescriptionTable[getReg(eleArray[2])].regname, RegisterDescriptionTable[getReg(eleArray[0] + 1)].regname);
        }
    }
    else if (strcmp(eleArray[0], "IF") == 0)
    {
        if (strcmp(eleArray[2], "==") == 0)
        {
            fprintf(ASMfile, "beq %s, %s, %s\n", RegisterDescriptionTable[getReg(eleArray[1])].regname, RegisterDescriptionTable[getReg(eleArray[3])].regname, eleArray[5]);
        }
        else if (strcmp(eleArray[2], "!=") == 0)
        {
            fprintf(ASMfile, "bne %s, %s, %s\n", RegisterDescriptionTable[getReg(eleArray[1])].regname, RegisterDescriptionTable[getReg(eleArray[3])].regname, eleArray[5]);
        }
        else if (strcmp(eleArray[2], ">") == 0)
        {
            fprintf(ASMfile, "bgt %s, %s, %s\n", RegisterDescriptionTable[getReg(eleArray[1])].regname, RegisterDescriptionTable[getReg(eleArray[3])].regname, eleArray[5]);
        }
        else if (strcmp(eleArray[2], "<") == 0)
        {
            fprintf(ASMfile, "blt %s, %s, %s\n", RegisterDescriptionTable[getReg(eleArray[1])].regname, RegisterDescriptionTable[getReg(eleArray[3])].regname, eleArray[5]);
        }
        else if (strcmp(eleArray[2], ">=") == 0)
        {
            fprintf(ASMfile, "bge %s, %s, %s\n", RegisterDescriptionTable[getReg(eleArray[1])].regname, RegisterDescriptionTable[getReg(eleArray[3])].regname, eleArray[5]);
        }
        else if (strcmp(eleArray[2], "<=") == 0)
        {
            fprintf(ASMfile, "ble %s, %s, %s\n", RegisterDescriptionTable[getReg(eleArray[1])].regname, RegisterDescriptionTable[getReg(eleArray[3])].regname, eleArray[5]);
        }
        else
            assert(0);
    }
    else if (strcmp(eleArray[1], ":=") == 0)
    {
        VaribleCreate(eleArray[0]);
        if (index == 3)
        {
            if (eleArray[2][0] == '*')
            {
                fprintf(ASMfile, "lw %s,0(%s)\n", RegisterDescriptionTable[getReg(eleArray[0])].regname, RegisterDescriptionTable[getReg(eleArray[2] + 1)].regname);
            }
            else if (eleArray[2][0] == '#')
            {
                fprintf(ASMfile, "li %s,%s\n", RegisterDescriptionTable[getReg(eleArray[0])].regname, eleArray[2] + 1);
            }
            else
            {
                fprintf(ASMfile, "move %s,%s\n", RegisterDescriptionTable[getReg(eleArray[0])].regname, RegisterDescriptionTable[getReg(eleArray[2])].regname);
            }
        }
        else if (index == 5)
        {
            if (eleArray[4][0] == '+' && eleArray[4][1] == '#')
            {
                fprintf(ASMfile, "addi %s,%s,%s\n", RegisterDescriptionTable[getReg(eleArray[0])].regname, RegisterDescriptionTable[getReg(eleArray[2])].regname, eleArray[4] + 2);
            }
            else if (eleArray[4][0] == '+' && eleArray[4][1] != '#')
            {
                fprintf(ASMfile, "add %s,%s,%s\n", RegisterDescriptionTable[getReg(eleArray[0])].regname, RegisterDescriptionTable[getReg(eleArray[2])].regname, RegisterDescriptionTable[getReg(eleArray[4] + 1)].regname);
            }
            else if (eleArray[4][0] == '-' && eleArray[4][1] == '#')
            {
                fprintf(ASMfile, "subi %s,%s,%s\n", RegisterDescriptionTable[getReg(eleArray[0])].regname, RegisterDescriptionTable[getReg(eleArray[2])].regname, eleArray[4] + 2);
            }
            else if (eleArray[4][0] == '-' && eleArray[4][1] != '#' && eleArray[4][1] != '*')
            {
                fprintf(ASMfile, "sub %s,%s,%s\n", RegisterDescriptionTable[getReg(eleArray[0])].regname, RegisterDescriptionTable[getReg(eleArray[2])].regname, RegisterDescriptionTable[getReg(eleArray[4] + 1)].regname);
            }
            else if (eleArray[4][0] == '*')
            {
                fprintf(ASMfile, "mul %s,%s,%s\n", RegisterDescriptionTable[getReg(eleArray[0])].regname, RegisterDescriptionTable[getReg(eleArray[2])].regname, RegisterDescriptionTable[getReg(eleArray[4] + 1)].regname);
            }
            else if (eleArray[4][0] == '/')
            {
                fprintf(ASMfile, "div %s,%s\n", RegisterDescriptionTable[getReg(eleArray[2])].regname, RegisterDescriptionTable[getReg(eleArray[4] + 1)].regname);
                fprintf(ASMfile, "mflo %s\n", RegisterDescriptionTable[getReg(eleArray[0])].regname);
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