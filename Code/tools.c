#include "tools.h"

int semantic_error_num = 0;
int semantic_error_type[1000];
int semantic_error_line[1000];
void summit_semantic_error()
{
    for (int i = 0; i < semantic_error_num; i++)
    {
        for (int j = i + 1; j < semantic_error_num; j++)
        {
            if (semantic_error_line[i] > semantic_error_line[j])
            {
                int temp = semantic_error_line[i];
                semantic_error_line[i] = semantic_error_line[j];
                semantic_error_line[j] = temp;
                temp = semantic_error_type[i];
                semantic_error_type[i] = semantic_error_type[j];
                semantic_error_type[j] = temp;
            }
        }
    }
    for (int i = 0; i < semantic_error_num; i++)
    {
        print_semantic_error(semantic_error_type[i], semantic_error_line[i]);
    }
}
void add_semantic_error(int error_type, int line)
{
    assert(semantic_error_num < 1000);
    semantic_error_type[semantic_error_num] = error_type;
    semantic_error_line[semantic_error_num] = line;
    semantic_error_num++;
}
void print_semantic_error(int errortype, int line)
{
    switch (errortype)
    {
    case 1:
        printf("Error type %d at Line %d: Undefined variable.\n", errortype, line);
        break;
    case 2:
        printf("Error type %d at Line %d: Undefined function.\n", errortype, line);
        break;
    case 3:
        printf("Error type %d at Line %d: Redefined variable.\n", errortype, line);
        break;
    case 4:
        printf("Error type %d at Line %d: Redefined function.\n", errortype, line);
        break;
    case 5:
        printf("Error type %d at Line %d: Type mismatched for assignment.\n", errortype, line);
        break;
    case 6:
        printf("Error type %d at Line %d: The left-hand side of an assignment must be a variable.\n", errortype, line);
        break;
    case 7:
        printf("Error type %d at Line %d: Type mismatched for operands.\n", errortype, line);
        break;
    case 8:
        printf("Error type %d at Line %d: Type mismatched for return.\n", errortype, line);
        break;
    case 9:
        printf("Error type %d at Line %d: Function is not applicable for arguments.\n", errortype, line);
        break;
    case 10:
        printf("Error type %d at Line %d: is not an array.\n", errortype, line);
        break;
    case 11:
        printf("Error type %d at Line %d: is not a function.\n", errortype, line);
        break;
    case 12:
        printf("Error type %d at Line %d: is not an integer.\n", errortype, line);
        break;
    case 13:
        printf("Error type %d at Line %d: is not a structure.\n", errortype, line);
        break;
    case 14:
        printf("Error type %d at Line %d: Non-existent field.\n", errortype, line);
        break;
    case 15:
        printf("Error type %d at Line %d: Redefined field.\n", errortype, line);
        break;
    case 16:
        printf("Error type %d at Line %d: Duplicated name.\n", errortype, line);
        break;
    case 17:
        printf("Error type %d at Line %d: Undefined structure.\n", errortype, line);
        break;
    case 18:
        printf("Error type %d at Line %d: Declared function, but undefined.\n", errortype, line);
        break;
    case 19:
        printf("Error type %d at Line %d: Inconsistent declaration of function.\n", errortype, line);
        break;
    }
}