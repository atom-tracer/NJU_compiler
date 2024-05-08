/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_SYNTAX_TAB_H_INCLUDED
# define YY_YY_SYNTAX_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
<<<<<<< HEAD
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    INT = 258,                     /* INT  */
    FLOAT = 259,                   /* FLOAT  */
    PLUS = 260,                    /* PLUS  */
    MINUS = 261,                   /* MINUS  */
    STAR = 262,                    /* STAR  */
    DIV = 263,                     /* DIV  */
    AND = 264,                     /* AND  */
    OR = 265,                      /* OR  */
    DOT = 266,                     /* DOT  */
    NOT = 267,                     /* NOT  */
    ID = 268,                      /* ID  */
    SEMI = 269,                    /* SEMI  */
    COMMA = 270,                   /* COMMA  */
    ASSIGNOP = 271,                /* ASSIGNOP  */
    RELOP = 272,                   /* RELOP  */
    TYPE = 273,                    /* TYPE  */
    LP = 274,                      /* LP  */
    RP = 275,                      /* RP  */
    LB = 276,                      /* LB  */
    RB = 277,                      /* RB  */
    LC = 278,                      /* LC  */
    RC = 279,                      /* RC  */
    STRUCT = 280,                  /* STRUCT  */
    RETURN = 281,                  /* RETURN  */
    IF = 282,                      /* IF  */
    ELSE = 283,                    /* ELSE  */
    WHILE = 284,                   /* WHILE  */
    ASSIGN = 285,                  /* ASSIGN  */
    LOWER_THAN_ELSE = 286          /* LOWER_THAN_ELSE  */
=======
    INT = 258,
    FLOAT = 259,
    PLUS = 260,
    MINUS = 261,
    STAR = 262,
    DIV = 263,
    AND = 264,
    OR = 265,
    DOT = 266,
    NOT = 267,
    ID = 268,
    SEMI = 269,
    COMMA = 270,
    ASSIGNOP = 271,
    RELOP = 272,
    TYPE = 273,
    LP = 274,
    RP = 275,
    LB = 276,
    RB = 277,
    LC = 278,
    RC = 279,
    STRUCT = 280,
    RETURN = 281,
    IF = 282,
    ELSE = 283,
    WHILE = 284,
    ASSIGN = 285,
    LOWER_THAN_ELSE = 286
>>>>>>> abdb47b9b6342db191414ff3fc87cdb0522e6828
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 27 "./syntax.y" /* yacc.c:1909  */

    TreeNode* val;

<<<<<<< HEAD
#line 99 "./syntax.tab.h"

=======
#line 90 "./syntax.tab.h" /* yacc.c:1909  */
>>>>>>> abdb47b9b6342db191414ff3fc87cdb0522e6828
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;
int yyparse (void);

#endif /* !YY_YY_SYNTAX_TAB_H_INCLUDED  */
