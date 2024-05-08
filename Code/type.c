#include "type.h"
#define N 0x3ff
StructureField hash_table[N + 1],var_table[N+1];
StructureField deepcopy_field(StructureField field)
{
    if (field == NULL)
        return NULL;
    StructureField p = (StructureField)malloc(sizeof(struct StructureField_));
    p->name = malloc(strlen(field->name) + 1);
    strcpy(p->name, field->name);
    p->type = deepcopy(field->type);
    p->next = deepcopy_field(field->next);
    return p;
}
// 深拷贝
Type deepcopy(Type type){
    if(type==NULL)
        return NULL;
    Type t = malloc(sizeof(struct Type_));
    switch (type->kind)
    {
    case BASIC:
        t->kind = BASIC;
        t->content.basic = type->content.basic;
        break;
    case ARRAY:
        t->kind = ARRAY;
        t->content.array.elem = deepcopy(type->content.array.elem);
        t->content.array.size = type->content.array.size;
        break;
    case STRUCTURE:
        t->kind = STRUCTURE;
        t->content.stru.name = malloc(strlen(type->content.stru.name) + 1);
        strcpy(t->content.stru.name, type->content.stru.name);
        // t->content.stru.table = malloc(sizeof(StructureField) * (N + 1));
        // memset(t->content.stru.table, 0, sizeof(StructureField) * (N + 1));
        // for (int i = 0; i <= N; i++)
        // {
        //     StructureField p = type->content.stru.table[i];
        //     while (p)
        //     {
        //         add_symbol_to(t, p->name, deepcopy(p->type));
        //         p = p->next;
        //     }
        // }
        t->content.stru.table = deepcopy_field(type->content.stru.table);
        break;
    case FUNCTION:
        t->kind = FUNCTION;
        t->content.func.ret = deepcopy(type->content.func.ret);
        t->content.func.functiontype = type->content.func.functiontype;
        t->content.func.tail = deepcopy_field(type->content.func.tail);
        break;
    }
    return t;
}
// 转化为右值
void change_to_right(Type *type)
{
    Type t = deepcopy(*type);
    *type = t;
    if (type == NULL)
        return;
    switch ((*type)->kind)
    {
    case BASIC:
        (*type)->is_left = false;
        break;
    case STRUCTURE:
        (*type)->is_left = false;
        // for (int i = 0; i <= N; i++)
        // {
        //     StructureField p = (*type)->content.stru.table[i];
        //     while (p)
        //     {
        //         change_to_right(&(p->type));
        //         p = p->next;
        //     }
        // }
        StructureField p = (*type)->content.stru.table;
        while (p)
        {
            change_to_right(&(p->type));
            p = p->next;
        }
        break;
    case ARRAY:
        (*type)->is_left = false;
        change_to_right(&((*type)->content.array.elem));
        break;
    default:
        assert(0);
    }
}
// 创建类型
Type createBasic(enum ValueType basic)
{
    Type type = (Type)malloc(sizeof(struct Type_));
    type->kind = BASIC;
    type->content.basic = basic;
    type->is_left = true;
    return type;
}
Type createArray(Type elem, int size)
{
    Type type = (Type)malloc(sizeof(struct Type_));
    type->kind = ARRAY;
    type->content.array.elem = elem;
    type->content.array.size = size;
    type->is_left = true;
    return type;
}
Type createStructure(char *name, StructureField head)
{
    Type type = (Type)malloc(sizeof(struct Type_));
    type->kind = STRUCTURE;
    type->content.stru.name = name;
    // type->content.stru.table = malloc(sizeof(StructureField) * (N + 1));
    // memset(type->content.stru.table, 0, sizeof(StructureField) * (N + 1));
    StructureField p = head;
    type->is_left = true;
    while (p)
    {
        if (find_symbol_in(type, p->name))
        {
            return NULL;
        }
        add_symbol_to(type, p->name, p->type);
        p = p->next;
    }
    return type;
}
Type createFunction(Type ret, enum FunctionType functiontype, StructureField head)
{
    Type type = (Type)malloc(sizeof(struct Type_));
    type->kind = FUNCTION;
    type->content.func.ret = ret;
    change_to_right(&type->content.func.ret); // 函数的返回值是右值
    type->content.func.functiontype = functiontype;
    type->content.func.tail = head;
    type->is_left = true;
    return type;
}
Type getFunctionRet(Type type)
{
    return type->content.func.ret;
}
// 比较两个类型是否相同
int compareType(Type a, Type b)
{
    if (a == NULL || b == NULL)
        return 0;
    if (a->kind != b->kind)
        return 0;
    switch (a->kind)
    {
    case BASIC:
        return a->content.basic == b->content.basic;
    case ARRAY:
        return compareType(a->content.array.elem, b->content.array.elem);
    case STRUCTURE:
        return strcmp(a->content.stru.name, b->content.stru.name) == 0 && a->content.stru.name != NULL;
    case FUNCTION:
        if (!compareType(a->content.func.ret, b->content.func.ret))
            return 0;
        StructureField p1 = a->content.func.tail;
        StructureField p2 = b->content.func.tail;
        while (p1 && p2)
        {
            if (!compareType(p1->type, p2->type))
                return 0;
            p1 = p1->next;
            p2 = p2->next;
        }
        return p1 == p2;
    default:
        assert(0);
    }
}
bool compareArgs(StructureField a, StructureField b)
{
    while (a && b)
    {
        if (!compareType(a->type, b->type))
            return false;
        a = a->next;
        b = b->next;
    }
    return a == b;
}
void addNode(StructureField *head, Type type, char *name)
{
    StructureField p = (StructureField)malloc(sizeof(StructureField));
    p->type = type;
    p->next = *head;
    p->name = name;
    *head = p;
}
// 符号表

unsigned int hash_pjw(char *name)
{
    unsigned int val = 0, i;
    for (; *name; ++name)
    {
        val = (val << 2) + *name;
        if (i = val & ~N)
            val = (val ^ (i >> 12)) & N;
    }
    return val;
}
void add_symbol(char *name, Type type)
{
    unsigned int val = hash_pjw(name);
    StructureField p = (StructureField)malloc(sizeof(StructureField));
    p->type = type;
    p->next = hash_table[val];
    p->name = name;
    hash_table[val] = p;
}
void add_symbol_var(char *name, Type type){
    add_symbol(name,type);
    unsigned int val = hash_pjw(name);
    StructureField p = (StructureField)malloc(sizeof(StructureField));
    p->type = NULL;
    p->next = var_table[val];
    p->name = name;
    var_table[val] = p;
}
bool find_symbol_var(char*name){
    if(name==NULL)
        return false;
    unsigned int val = hash_pjw(name);
    StructureField p = var_table[val];
    while (p)
    {
        if (strcmp(p->name, name) == 0)
        {
            return true;
        }
        p = p->next;
    }
    return false;
}
Type find_symbol(char *name)
{
    if(name==NULL)
        return NULL;
    unsigned int val = hash_pjw(name);
    StructureField p = hash_table[val];
    while (p)
    {
        if (strcmp(p->name, name) == 0)
        {
            return p->type;
        }
        p = p->next;
    }
    return NULL;
}
StructureField get_all_symbol()
{
    StructureField head = NULL;
    for (int i = 0; i <= N; i++)
    {
        StructureField p = hash_table[i];
        while (p)
        {
            addNode(&head, p->type, p->name);
            p = p->next;
        }
    }
    return head;
}
void add_symbol_to(Type stru, char *name, Type type)
{
    // StructureField *table = stru->content.stru.table;
    // unsigned int val = hash_pjw(name);
    // StructureField p = (StructureField)malloc(sizeof(StructureField));
    // p->type = type;
    // p->type->is_left = true;
    // p->name = name;
    // p->next = table[val];
    // table[val] = p;
    StructureField p = (StructureField)malloc(sizeof(StructureField));
    p->type = type;
    p->name = name;
    p->type->is_left = true;
    if (stru->content.stru.table == NULL)
    {
        stru->content.stru.table = p;
        return;
    }
    else{
        StructureField q = stru->content.stru.table;
        while (q->next)
        {
            q = q->next;
        }
        q->next = p;
    }
}
Type find_symbol_in(Type stru, char *name)
{
    // if(name==NULL||stru==NULL||stru->kind!=STRUCTURE)
    //     return NULL;
    // StructureField *table = stru->content.stru.table;
    // unsigned int val = hash_pjw(name);
    // StructureField p = table[val];
    // while (p)
    // {
    //     if (strcmp(p->name, name) == 0){
    //         //assert(p->type->is_left);//结构体域的类型是左值
    //         return p->type;
    //     }
    //     p = p->next;
    // }
    // return NULL;
    if(name==NULL||stru==NULL||stru->kind!=STRUCTURE)
        return NULL;
    StructureField p = stru->content.stru.table;
    while (p)
    {
        if (strcmp(p->name, name) == 0)
        {
            //assert(p->type->is_left);//结构体域的类型是左值
            return p->type;
        }
        p = p->next;
    }
    return NULL;
}
int size_of(Type type){
    int size = 0;
    StructureField p;
    if(type==NULL)
        return 0;
    switch (type->kind)
    {
    case BASIC:
        return 4;
    case ARRAY:
        return size_of(type->content.array.elem) * type->content.array.size;
    case STRUCTURE:
        p = type->content.stru.table;
        while (p)
        {
            size += size_of(p->type);
            p = p->next;
        }
        return size;
    case FUNCTION:
        return 0;
    default:
        assert(0);
    }
    return 0;
}
char* getVar(Variable*var){
    char*temp=malloc(strlen(var->name)+2);
    if(var->is_pointer&&!var->is_sa){
        sprintf(temp,"*%s",var->name);
    }
    else{
        sprintf(temp,"%s",var->name);
    }
    return temp;
}
Variable* createVar(char*name){
    Variable* t = malloc(sizeof(struct Variable));
    t->name = name;
    t->is_pointer = false;
    t->is_sa = false;
    return t;
}