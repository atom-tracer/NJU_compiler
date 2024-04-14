#include "type.h"
// 创建类型
Type createBasic(int basic)
{
    Type type = (Type)malloc(sizeof(struct Type_));
    type->kind = BASIC;
    type->content.basic = basic;
    return type;
}
Type createArray(Type elem, int size)
{
    Type type = (Type)malloc(sizeof(struct Type_));
    type->kind = ARRAY;
    type->content.array.elem = elem;
    type->content.array.size = size;
    return type;
}
Type createStructure(char* name, int num, ...){
    Type type = (Type)malloc(sizeof(struct Type_));
    type->kind = STRUCTURE;
    type->content.tail.name = name;
    va_list args;
    va_start(args, num);
    Type p = type;
    for(int i=0;i<num;i++){
        p->content.tail.type = va_arg(args, Type);
        p->content.tail.next = (Type)malloc(sizeof(struct Type_));
        p = p->content.tail.next;
        p->content.tail.next = NULL;
    }
    return type;
}
Type createFunction(Type ret, int num, ...){
    Type type = (Type)malloc(sizeof(struct Type_));
    type->kind = FUNCTION;
    type->content.tail.type = ret;
    va_list args;
    va_start(args, num);
    type->content.tail.next = (Type)malloc(sizeof(struct Type_));
    Type p = type->content.tail.next;
    p->content.tail.next = NULL;
    for(int i=0;i<num;i++){
        p->content.tail.type = va_arg(args, Type);
        p->content.tail.next = (Type)malloc(sizeof(struct Type_));
        p = p->content.tail.next;
        p->content.tail.next = NULL;
    }
    return type;
}
//比较两个类型是否相同
int compareType(Type a, Type b){
    if(a->kind != b->kind) return 0;
    switch(a->kind){
        case BASIC:
            return a->content.basic == b->content.basic;
        case ARRAY:
            return compareType(a->content.array.elem, b->content.array.elem);
        case STRUCTURE:
            return strcmp(a->content.tail.name, b->content.tail.name) == 0&&a->content.tail.name!=NULL;
        case FUNCTION:
            Type p1 = a;
            Type p2 = b;
            while(p1 && p2){
                if(!compareType(p1->content.tail.type, p2->content.tail.type)) return 0;
                p1 = p1->content.tail.next;
                p2 = p2->content.tail.next;
            }
            return p1 == p2;
        default:
            assert(0);
    }
}
//符号表
const int N = 1e5;
Type var_list[N], func_list[N];
int var_num = 0, func_num = 0;