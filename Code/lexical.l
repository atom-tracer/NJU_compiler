%{
#include "tree.h"
#include "syntax.tab.h"
#include "tools.h"
#include "semantic.h"
#include "ir.h"
int yycolumn = 1;
int debug_printf=0;

#define TOKEN_ACTION(token) \
    if(debug_printf)printf(#token"\n"); \
    yylval.val=new_node(#token,node_other); \
    return token; \

#define YY_USER_ACTION \
yylloc.first_line = yylloc.last_line = yylineno; \
yylloc.first_column = yycolumn; \
yylloc.last_column = yycolumn + yyleng - 1; \
yycolumn += yyleng; \

%}

%option yylineno

INT ([1-9][0-9]*|0)
FLOAT ([0-9]+\.[0-9]+)
SEMI ";"
COMMA ","
ASSIGNOP "="
RELOP (">"|"<"|">="|"<="|"=="|"!=")
PLUS "+"
MINUS "-"
STAR "*"
DIV "/"
AND "&&"
OR "||"
DOT "."
NOT "!"
TYPE "int"|"float"
LP "("
RP ")"
LB "["
RB "]"
LC "{"
RC "}"
STRUCT "struct"
RETURN "return"
IF "if"
ELSE "else"
WHILE "while"
SPACE [ \t\r]+
ID [a-zA-Z_][a-zA-Z0-9_]*

%%
"//" { 
    char c;
    while ((c = input()) != '\n' && c != EOF);
}
"/*" { 
    char c;
    while (1) 
    { 
        c = input(); 
        if (c == '*') 
        { 
            c = input();
            if (c == '/') 
                break;
        }
    } 
}
{INT} { 
    if(debug_printf)
        printf("INT:%d\n",atoi(yytext));
    TreeNode* node=new_node("INT",node_int);
    node->int_val=atoi(yytext);
    yylval.val=node;
    return INT;
    }
{FLOAT} { 
    if(debug_printf)
        printf("FLOAT:%f\n",atof(yytext));
    TreeNode* node=new_node("FLOAT",node_float);
    node->float_val=atof(yytext);
    yylval.val=node;
    return FLOAT; 
    }
{SEMI} { TOKEN_ACTION(SEMI)}
{COMMA} { TOKEN_ACTION(COMMA) }
{ASSIGNOP} { TOKEN_ACTION(ASSIGNOP) }
{RELOP} { 
    if(debug_printf)
        printf("RELOP\n");
    TreeNode* node=new_node("RELOP",node_relop); 
    if(strcmp(yytext,">")) node->relop_val=1;
    else if(strcmp(yytext,"<")) node->relop_val=2;
    else if(strcmp(yytext,">=")) node->relop_val=3;
    else if(strcmp(yytext,"<=")) node->relop_val=4;
    else if(strcmp(yytext,"==")) node->relop_val=5;
    else if(strcmp(yytext,"!=")) node->relop_val=6;
    else assert("error relop\n");
    yylval.val=node;
    return RELOP;}
{PLUS} { TOKEN_ACTION(PLUS)}
{MINUS} { TOKEN_ACTION(MINUS)}
{STAR} { TOKEN_ACTION(STAR)}
{DIV} { TOKEN_ACTION(DIV)}
{AND} { TOKEN_ACTION(AND)}
{OR} { TOKEN_ACTION(OR)}
{DOT} { TOKEN_ACTION(DOT)}
{NOT} { TOKEN_ACTION(NOT)}
{TYPE} {
    if(debug_printf)
        printf("TYPE:%s\n",yytext);
    TreeNode* node=new_node("TYPE",node_type);
    if(strcmp(yytext,"int")==0)
        node->type_val=INT_TYPE;
    else 
        node->type_val=FLOAT_TYPE;
    yylval.val=node;
    return TYPE;
    }
{LP} { TOKEN_ACTION(LP)}
{RP} { TOKEN_ACTION(RP)}
{LB} { TOKEN_ACTION(LB) }
{RB} { TOKEN_ACTION(RB)}
{LC} { TOKEN_ACTION(LC)}
{RC} { TOKEN_ACTION(RC)}
{STRUCT} { TOKEN_ACTION(STRUCT)}
{RETURN} { TOKEN_ACTION(RETURN);}
{IF} { TOKEN_ACTION(IF)}
{ELSE} { TOKEN_ACTION(ELSE)}
{WHILE} { TOKEN_ACTION(WHILE)}
{ID} {
    if(debug_printf)
        printf("ID:%s\n",yytext);
    TreeNode* node=new_node("ID",node_id);
    strcpy(node->id,yytext);
    yylval.val=node;
    return ID;
    }
{SPACE} { if(debug_printf)printf("SPACE\n");}
\n { yycolumn = 1; }
.  { printf("Error type A at Line %d: Mysterious characters \'%s\'\n", yylineno, yytext); my_is_error=1; } 

%%

int main(int argc, char** argv) { 
    if (argc > 1) 
    { 
        if (!(yyin = fopen(argv[1], "r"))) 
        { 
            perror(argv[1]); 
                return 1; 
        }
    }
    // yydebug=1;
    yyrestart(yyin);
    yyparse();
    //yylex();
    // if(!my_is_error)
    //print_tree(root,0);
    assert(!my_is_error);

    Program(root);
    //输出语义错误
    summit_semantic_error();
    // //创建out1.ir文件
    // FILE *fp=fopen("out1.ir","w");
    // //输出中间代码
    // fprintf(fp,"%s",translate_Program(root));
    // fclose(fp);
    printf("%s",translate_Program(root));
    return 0; 
} 
