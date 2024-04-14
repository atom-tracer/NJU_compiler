typedef int bool;
#define true 1
#define false 0
int my_is_error;
enum ValueType
{
    INT_TYPE = 1,
    FLOAT_TYPE = 0
};
enum FunctionType
{
    FUNCTION_DEFINITION = 1,
    FUNCTION_DECLARATION = 0
};
//字符串查找表
typedef struct StringTable_
{
    char *name;
    struct StringTable_ *next;
} StringTable;
void add_string(char *name, StringTable **table){
    StringTable *p = (StringTable *)malloc(sizeof(StringTable));
    p->name = name;
    p->next = *table;
    *table = p;
}
bool find_string(char *name, StringTable *table){
    while (table)
    {
        if (strcmp(table->name, name) == 0)
            return true;
        table = table->next;
    }
    return false;
}