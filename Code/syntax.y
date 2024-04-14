%locations
%{
    #include "tree.h"
    #include "lex.yy.c"
    #include <stdarg.h>

    #define NNAC(parent,name,line_no,n,...) \
        TreeNode* p = new_node(name, node_grammar); \
        p->line = line_no; \
        TreeNode* children[] = {__VA_ARGS__}; \
        for(int i = 0; i < n; i++) \
        { \
            TreeNode* child = children[i]; \
            insert_child(p, child); \
        } \
        parent = p;


    void yyerror(char* msg) 
    {
        my_is_error = 1;
        printf("Error type B at Line %d: Mysterious characters \'%s\'\n", yylineno, msg);
    }
%}


%union {
    TreeNode* val;
}

%token <val> INT FLOAT
%token <val> PLUS MINUS STAR DIV AND OR DOT NOT
%token <val> ID
%token <val> SEMI COMMA ASSIGNOP
%token <val> RELOP
%token <val> TYPE
%token <val> LP RP LB RB LC RC STRUCT RETURN IF ELSE WHILE

%type <val> Program ExtDefList ExtDef ExtDecList Specifier StructSpecifier OptTag Tag VarDec FunDec VarList ParamDec CompSt StmtList Stmt DefList Def DecList Dec Exp Args

%right ASSIGN
%left OR
%left AND
%left RELOP
%left PLUS MINUS
%left MUL DIV
%right NOT
%left LP RP LB RB DOT

%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE

%%

//High-level Definitions

Program: ExtDefList {root = new_node("Program",node_grammar);root->line=@$.first_line;insert_child(root,$1);$$=root;}
    | ExtDefList error
    ;
ExtDefList: ExtDef ExtDefList {NNAC($$, "ExtDefList", @$.first_line, 2, $1, $2)}
    | error ExtDefList
    | {$$=new_node("ExtDefList",node_grammar);}
    ;
ExtDef: Specifier ExtDecList SEMI {NNAC($$, "ExtDef", @$.first_line, 3, $1, $2,$3)}
    | Specifier SEMI {NNAC($$, "ExtDef", @$.first_line, 2, $1, $2);}
    | Specifier FunDec CompSt {NNAC($$, "ExtDef", @$.first_line, 3, $1, $2,$3)}
    | Specifier FunDec error
    ;
ExtDecList: VarDec {NNAC($$, "ExtDecList", @$.first_line, 1, $1)}
    | VarDec COMMA ExtDecList { NNAC($$, "ExtDecList", @$.first_line, 3, $1, $2,$3)}
    ;

//Specifiers

Specifier: TYPE {NNAC($$, "Specifier", @$.first_line, 1, $1)}
    | StructSpecifier {NNAC($$, "Specifier", @$.first_line, 1, $1)}
    ;
StructSpecifier: STRUCT OptTag LC DefList RC { NNAC($$, "StructSpecifier", @$.first_line, 5, $1, $2,$3,$4,$5)}
    | STRUCT Tag {NNAC($$, "StructSpecifier", @$.first_line, 2, $1, $2)}
    ;
OptTag: ID {NNAC($$, "OptTag", @$.first_line, 1, $1)}
    | {$$=new_node("OptTag",node_grammar);}
    ;
Tag: ID {NNAC($$, "Tag", @$.first_line, 1, $1)}
    ;

//Declarators

VarDec: ID { NNAC($$, "VarDec", @$.first_line, 1, $1)}
    | VarDec LB INT RB {NNAC($$, "VarDec", @$.first_line, 4, $1, $2,$3,$4)}
    ;
FunDec: ID LP VarList RP { NNAC($$, "FunDec", @$.first_line, 4, $1, $2,$3,$4)}
    | ID LP RP {NNAC($$, "FunDec", @$.first_line, 3, $1, $2,$3)}
    ;
VarList: ParamDec COMMA VarList {NNAC($$, "VarList", @$.first_line, 3, $1, $2,$3)}
    | ParamDec {NNAC($$, "VarList", @$.first_line, 1, $1)}
    ;
ParamDec: Specifier VarDec {NNAC($$, "ParamDec", @$.first_line, 2, $1, $2)}
    ;

//Statements

CompSt: LC DefList StmtList RC { NNAC($$, "CompSt", @$.first_line, 4, $1, $2,$3,$4)}
    | LC error RC
    ;
StmtList: Stmt StmtList {NNAC($$, "StmtList", @$.first_line, 2, $1, $2)}
    | {$$=new_node("StmtList",node_grammar);}
    ;
Stmt: Exp SEMI {NNAC($$, "Stmt", @$.first_line, 2, $1, $2)}
    | CompSt {NNAC($$, "Stmt", @$.first_line, 1, $1)}
    | RETURN Exp SEMI {NNAC($$, "Stmt", @$.first_line, 3, $1, $2,$3)}
    | IF LP Exp RP Stmt %prec LOWER_THAN_ELSE {NNAC($$, "Stmt", @$.first_line, 5, $1, $2,$3,$4, $5)}
    | IF LP Exp RP Stmt ELSE Stmt { NNAC($$, "Stmt", @$.first_line, 7, $1, $2,$3,$4, $5, $6,$7)}
    | WHILE LP Exp RP Stmt { NNAC($$, "Stmt", @$.first_line, 5, $1, $2,$3,$4, $5)}
    | WHILE LP error RP Stmt
    | IF LP error RP Stmt %prec LOWER_THAN_ELSE
    | IF LP Exp RP error ELSE Stmt
    ;

//Local Definitions

DefList: Def DefList {NNAC($$, "DefList", @$.first_line, 2, $1, $2)}
    | {$$=new_node("DefList",node_grammar);}
    ;
Def: Specifier DecList SEMI { NNAC($$, "Def", @$.first_line, 3, $1, $2,$3)}
    ;
DecList: Dec { NNAC($$, "DecList", @$.first_line, 1, $1)}
    | Dec COMMA DecList { NNAC($$, "DecList", @$.first_line, 3, $1, $2,$3)}
    ;
Dec: VarDec {NNAC($$, "Dec", @$.first_line, 1, $1)}
    | VarDec ASSIGNOP Exp { NNAC($$, "Dec", @$.first_line, 3, $1, $2,$3)}
    | VarDec error
    ;

//Expressions

Exp: Exp ASSIGNOP Exp { NNAC($$, "Exp", @$.first_line, 3, $1, $2,$3)}
    | Exp AND Exp { NNAC($$, "Exp", @$.first_line, 3, $1, $2,$3)}
    | Exp OR Exp { NNAC($$, "Exp", @$.first_line, 3, $1, $2,$3)}
    | Exp RELOP Exp { NNAC($$, "Exp", @$.first_line, 3, $1, $2,$3)}
    | Exp PLUS Exp { NNAC($$, "Exp", @$.first_line, 3, $1, $2,$3)}
    | Exp MINUS Exp { NNAC($$, "Exp", @$.first_line, 3, $1, $2,$3)}
    | Exp STAR Exp { NNAC($$, "Exp", @$.first_line, 3, $1, $2,$3)}
    | Exp DIV Exp { NNAC($$, "Exp", @$.first_line, 3, $1, $2,$3)}
    | LP Exp RP { NNAC($$, "Exp", @$.first_line, 3, $1, $2,$3)}
    | MINUS Exp %prec NOT { NNAC($$, "Exp", @$.first_line, 2, $1, $2)}
    | NOT Exp { NNAC($$, "Exp", @$.first_line, 2, $1, $2)}
    | ID LP Args RP { NNAC($$, "Exp", @$.first_line, 4, $1, $2,$3,$4)}
    | ID LP RP { NNAC($$, "Exp", @$.first_line, 3, $1, $2,$3)}
    | Exp LB Exp RB { NNAC($$, "Exp", @$.first_line, 4, $1, $2,$3,$4)}
    | Exp DOT ID { NNAC($$, "Exp", @$.first_line, 3, $1, $2,$3)}
    | ID { NNAC($$, "Exp", @$.first_line, 1, $1)}
    | INT { NNAC($$, "Exp", @$.first_line, 1, $1)}
    | FLOAT { NNAC($$, "Exp", @$.first_line, 1, $1)}
    | error
    ;
Args: Exp COMMA Args { NNAC($$, "Args", @$.first_line, 3, $1, $2,$3)}
    | Exp { NNAC($$, "Args", @$.first_line, 1, $1)}
    ;
%%

// int main() {
//     yyparse();
// }
