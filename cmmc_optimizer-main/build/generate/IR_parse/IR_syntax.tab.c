/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Substitute the type names.  */
#define YYSTYPE         IR_YYSTYPE
/* Substitute the variable and function names.  */
#define yyparse         IR_yyparse
#define yylex           IR_yylex
#define yyerror         IR_yyerror
#define yydebug         IR_yydebug
#define yynerrs         IR_yynerrs
#define yylval          IR_yylval
#define yychar          IR_yychar

<<<<<<< HEAD:Code/syntax.tab.c
/* Copy the first part of user declarations.  */
#line 2 "./syntax.y" /* yacc.c:339  */
=======
/* First part of user prologue.  */
#line 5 "src/IR_parse/IR_syntax.y"
>>>>>>> a768f7c42fc8cedf061cec867b3e39a8a0fd0079:cmmc_optimizer-main/build/generate/IR_parse/IR_syntax.tab.c


#include <macro.h>
#include <object.h>
#include <IR_parse.h>

static void args_stack_push(IR_val arg);
static void args_stack_pop(unsigned *argc_ptr, IR_val **argv_ptr);

static IR_function *now_function = NULL;


<<<<<<< HEAD:Code/syntax.tab.c
#line 90 "./syntax.tab.c" /* yacc.c:339  */
=======
#line 92 "build/generate/IR_parse/IR_syntax.tab.c"
>>>>>>> a768f7c42fc8cedf061cec867b3e39a8a0fd0079:cmmc_optimizer-main/build/generate/IR_parse/IR_syntax.tab.c

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

<<<<<<< HEAD:Code/syntax.tab.c
/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "syntax.tab.h".  */
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
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 27 "./syntax.y" /* yacc.c:355  */
=======
#include "IR_syntax.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_EOL = 3,                        /* EOL  */
  YYSYMBOL_COLON = 4,                      /* COLON  */
  YYSYMBOL_FUNCTION = 5,                   /* FUNCTION  */
  YYSYMBOL_LABEL = 6,                      /* LABEL  */
  YYSYMBOL_SHARP = 7,                      /* SHARP  */
  YYSYMBOL_INT = 8,                        /* INT  */
  YYSYMBOL_ASSIGN = 9,                     /* ASSIGN  */
  YYSYMBOL_STAR = 10,                      /* STAR  */
  YYSYMBOL_OP = 11,                        /* OP  */
  YYSYMBOL_IF = 12,                        /* IF  */
  YYSYMBOL_RELOP = 13,                     /* RELOP  */
  YYSYMBOL_ADDR_OF = 14,                   /* ADDR_OF  */
  YYSYMBOL_GOTO = 15,                      /* GOTO  */
  YYSYMBOL_RETURN = 16,                    /* RETURN  */
  YYSYMBOL_DEC = 17,                       /* DEC  */
  YYSYMBOL_ARG = 18,                       /* ARG  */
  YYSYMBOL_CALL = 19,                      /* CALL  */
  YYSYMBOL_PARAM = 20,                     /* PARAM  */
  YYSYMBOL_READ = 21,                      /* READ  */
  YYSYMBOL_WRITE = 22,                     /* WRITE  */
  YYSYMBOL_ID = 23,                        /* ID  */
  YYSYMBOL_YYACCEPT = 24,                  /* $accept  */
  YYSYMBOL_IR_globol = 25,                 /* IR_globol  */
  YYSYMBOL_IR_program = 26,                /* IR_program  */
  YYSYMBOL_IR_function = 27,               /* IR_function  */
  YYSYMBOL_IR_stmt = 28,                   /* IR_stmt  */
  YYSYMBOL_IR_val = 29,                    /* IR_val  */
  YYSYMBOL_val_deref = 30,                 /* val_deref  */
  YYSYMBOL_IR_val_rs = 31,                 /* IR_val_rs  */
  YYSYMBOL_IR_var = 32,                    /* IR_var  */
  YYSYMBOL_IR_label = 33,                  /* IR_label  */
  YYSYMBOL_MUL_EOL = 34                    /* MUL_EOL  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;
>>>>>>> a768f7c42fc8cedf061cec867b3e39a8a0fd0079:cmmc_optimizer-main/build/generate/IR_parse/IR_syntax.tab.c

    TreeNode* val;

#line 166 "./syntax.tab.c" /* yacc.c:355  */
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

/* Copy the second part of user declarations.  */

#line 197 "./syntax.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

<<<<<<< HEAD:Code/syntax.tab.c
#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)
=======
#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;
>>>>>>> a768f7c42fc8cedf061cec867b3e39a8a0fd0079:cmmc_optimizer-main/build/generate/IR_parse/IR_syntax.tab.c

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


<<<<<<< HEAD:Code/syntax.tab.c
#if ! defined yyoverflow || YYERROR_VERBOSE
=======
#define YY_ASSERT(E) ((void) (0 && (E)))

#if 1
>>>>>>> a768f7c42fc8cedf061cec867b3e39a8a0fd0079:cmmc_optimizer-main/build/generate/IR_parse/IR_syntax.tab.c

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
<<<<<<< HEAD:Code/syntax.tab.c
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */

=======
#endif /* 1 */
>>>>>>> a768f7c42fc8cedf061cec867b3e39a8a0fd0079:cmmc_optimizer-main/build/generate/IR_parse/IR_syntax.tab.c

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined IR_YYSTYPE_IS_TRIVIAL && IR_YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
<<<<<<< HEAD:Code/syntax.tab.c
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)
=======
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)
>>>>>>> a768f7c42fc8cedf061cec867b3e39a8a0fd0079:cmmc_optimizer-main/build/generate/IR_parse/IR_syntax.tab.c

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   66

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  24
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  11
/* YYNRULES -- Number of rules.  */
#define YYNRULES  31
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  66

<<<<<<< HEAD:Code/syntax.tab.c
/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   286
=======
/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   278
>>>>>>> a768f7c42fc8cedf061cec867b3e39a8a0fd0079:cmmc_optimizer-main/build/generate/IR_parse/IR_syntax.tab.c

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23
};

<<<<<<< HEAD:Code/syntax.tab.c
#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
=======
#if IR_YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int8 yyrline[] =
>>>>>>> a768f7c42fc8cedf061cec867b3e39a8a0fd0079:cmmc_optimizer-main/build/generate/IR_parse/IR_syntax.tab.c
{
       0,    68,    68,    70,    75,    77,    78,    79,    80,    81,
      82,    84,    85,    86,    87,    88,    89,    90,    92,    93,
     100,   101,   103,   104,   105,   108,   109,   110,   116,   118,
     120,   121
};
#endif

<<<<<<< HEAD:Code/syntax.tab.c
#if YYDEBUG || YYERROR_VERBOSE || 0
=======
/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

>>>>>>> a768f7c42fc8cedf061cec867b3e39a8a0fd0079:cmmc_optimizer-main/build/generate/IR_parse/IR_syntax.tab.c
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
<<<<<<< HEAD:Code/syntax.tab.c
  "$end", "error", "$undefined", "INT", "FLOAT", "PLUS", "MINUS", "STAR",
  "DIV", "AND", "OR", "DOT", "NOT", "ID", "SEMI", "COMMA", "ASSIGNOP",
  "RELOP", "TYPE", "LP", "RP", "LB", "RB", "LC", "RC", "STRUCT", "RETURN",
  "IF", "ELSE", "WHILE", "ASSIGN", "LOWER_THAN_ELSE", "$accept", "Program",
  "ExtDefList", "ExtDef", "ExtDecList", "Specifier", "StructSpecifier",
  "OptTag", "Tag", "VarDec", "FunDec", "VarList", "ParamDec", "CompSt",
  "StmtList", "Stmt", "DefList", "Def", "DecList", "Dec", "Exp", "Args", YY_NULLPTR
=======
  "\"end of file\"", "error", "\"invalid token\"", "EOL", "COLON",
  "FUNCTION", "LABEL", "SHARP", "INT", "ASSIGN", "STAR", "OP", "IF",
  "RELOP", "ADDR_OF", "GOTO", "RETURN", "DEC", "ARG", "CALL", "PARAM",
  "READ", "WRITE", "ID", "$accept", "IR_globol", "IR_program",
  "IR_function", "IR_stmt", "IR_val", "val_deref", "IR_val_rs", "IR_var",
  "IR_label", "MUL_EOL", YY_NULLPTR
>>>>>>> a768f7c42fc8cedf061cec867b3e39a8a0fd0079:cmmc_optimizer-main/build/generate/IR_parse/IR_syntax.tab.c
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286
};
# endif

<<<<<<< HEAD:Code/syntax.tab.c
#define YYPACT_NINF -56
=======
#define YYPACT_NINF (-15)
>>>>>>> a768f7c42fc8cedf061cec867b3e39a8a0fd0079:cmmc_optimizer-main/build/generate/IR_parse/IR_syntax.tab.c

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-56)))

<<<<<<< HEAD:Code/syntax.tab.c
#define YYTABLE_NINF -47
=======
#define YYTABLE_NINF (-13)
>>>>>>> a768f7c42fc8cedf061cec867b3e39a8a0fd0079:cmmc_optimizer-main/build/generate/IR_parse/IR_syntax.tab.c

#define yytable_value_is_error(Yytable_value) \
  0

<<<<<<< HEAD:Code/syntax.tab.c
  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
=======
/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
>>>>>>> a768f7c42fc8cedf061cec867b3e39a8a0fd0079:cmmc_optimizer-main/build/generate/IR_parse/IR_syntax.tab.c
{
     -15,     8,    17,   -15,   -15,    21,     7,     1,    27,    11,
      35,    41,    11,    35,    15,    41,    15,    15,    41,   -15,
      36,    31,    34,    49,   -15,    40,    45,    15,   -15,   -15,
     -15,   -15,    43,   -15,   -15,    46,    54,    56,   -15,   -15,
     -15,    41,    22,   -15,    57,   -15,   -15,    41,    58,   -15,
     -15,   -15,    39,    60,    62,    -1,   -15,    51,   -15,   -15,
      41,    41,    11,   -15,   -15,   -15
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
      31,     0,     4,     1,    30,     2,     0,     3,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    28,
       0,     0,     0,     0,    29,     0,     0,     0,    25,    22,
      26,    27,     0,    16,    18,     0,     0,     0,    20,    21,
      10,     0,     0,     5,     0,    23,    24,     0,     0,     8,
       6,    13,     0,    26,    27,     0,     9,     0,     7,    19,
       0,     0,     0,    15,    14,    17
};

<<<<<<< HEAD:Code/syntax.tab.c
  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
=======
/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
>>>>>>> a768f7c42fc8cedf061cec867b3e39a8a0fd0079:cmmc_optimizer-main/build/generate/IR_parse/IR_syntax.tab.c
{
     -15,   -15,   -15,   -15,   -15,    -7,    -5,   -14,    -2,   -12,
     -15
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
<<<<<<< HEAD:Code/syntax.tab.c
      -1,     4,     5,     6,    18,     7,     8,    11,    12,    19,
      20,    35,    36,    62,    63,    64,    31,    32,    43,    44,
      65,    95
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
=======
       0,     1,     5,     7,    20,    30,    31,    32,    29,    25,
       2
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
>>>>>>> a768f7c42fc8cedf061cec867b3e39a8a0fd0079:cmmc_optimizer-main/build/generate/IR_parse/IR_syntax.tab.c
{
      33,    36,    21,    28,    39,    22,    34,     9,     3,    60,
      61,    10,    35,    11,    37,    38,    12,    13,    14,    15,
       4,    16,    17,    18,    19,    46,     6,    51,    55,    26,
       8,    23,    10,    57,    24,    53,    27,    54,    19,    40,
      41,    52,    26,    42,    44,    19,    63,    64,    26,    27,
      65,    10,    43,    45,    48,    27,    47,    49,    19,    50,
      56,    58,    59,   -11,    19,   -12,    62
};

static const yytype_int8 yycheck[] =
{
      12,    15,     7,    10,    18,     7,    13,     6,     0,    10,
      11,    10,    14,    12,    16,    17,    15,    16,    17,    18,
       3,    20,    21,    22,    23,    27,     5,    41,    42,     7,
      23,     4,    10,    47,    23,    42,    14,    42,    23,     3,
       9,    19,     7,     9,     4,    23,    60,    61,     7,    14,
      62,    10,     3,     8,     8,    14,    13,     3,    23,     3,
       3,     3,    23,     3,    23,     3,    15
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    25,    34,     0,     3,    26,     5,    27,    23,     6,
      10,    12,    15,    16,    17,    18,    20,    21,    22,    23,
      28,    30,    32,     4,    23,    33,     7,    14,    29,    32,
      29,    30,    31,    33,    29,    32,    31,    32,    32,    31,
       3,     9,     9,     3,     4,     8,    32,    13,     8,     3,
       3,    31,    19,    29,    30,    31,     3,    31,     3,    23,
      10,    11,    15,    31,    31,    33
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    24,    25,    26,    26,    27,    27,    27,    27,    27,
      27,    28,    28,    28,    28,    28,    28,    28,    28,    28,
      28,    28,    29,    29,    29,    30,    31,    31,    32,    33,
      34,    34
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     2,     0,     4,     4,     5,     4,     5,
       3,     3,     3,     3,     5,     5,     2,     6,     2,     4,
       2,     2,     1,     2,     2,     2,     1,     1,     1,     1,
       2,     0
};


#define yyerrok         (yyerrstatus = 0)
<<<<<<< HEAD:Code/syntax.tab.c
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0
=======
#define yyclearin       (yychar = IR_TOKEN_IR_YYEMPTY)
>>>>>>> a768f7c42fc8cedf061cec867b3e39a8a0fd0079:cmmc_optimizer-main/build/generate/IR_parse/IR_syntax.tab.c

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

<<<<<<< HEAD:Code/syntax.tab.c
#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
=======
#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == IR_TOKEN_IR_YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use IR_TOKEN_IR_YYerror or IR_TOKEN_IR_YYUNDEF. */
#define YYERRCODE IR_TOKEN_IR_YYUNDEF
>>>>>>> a768f7c42fc8cedf061cec867b3e39a8a0fd0079:cmmc_optimizer-main/build/generate/IR_parse/IR_syntax.tab.c


/* Enable debugging if requested.  */
#if IR_YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)


<<<<<<< HEAD:Code/syntax.tab.c
/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static unsigned
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  unsigned res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif
=======
>>>>>>> a768f7c42fc8cedf061cec867b3e39a8a0fd0079:cmmc_optimizer-main/build/generate/IR_parse/IR_syntax.tab.c


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
<<<<<<< HEAD:Code/syntax.tab.c
                  Type, Value, Location); \
=======
                  Kind, Value); \
>>>>>>> a768f7c42fc8cedf061cec867b3e39a8a0fd0079:cmmc_optimizer-main/build/generate/IR_parse/IR_syntax.tab.c
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
<<<<<<< HEAD:Code/syntax.tab.c
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  YYUSE (yylocationp);
=======
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
>>>>>>> a768f7c42fc8cedf061cec867b3e39a8a0fd0079:cmmc_optimizer-main/build/generate/IR_parse/IR_syntax.tab.c
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
<<<<<<< HEAD:Code/syntax.tab.c
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
=======
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
>>>>>>> a768f7c42fc8cedf061cec867b3e39a8a0fd0079:cmmc_optimizer-main/build/generate/IR_parse/IR_syntax.tab.c
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

<<<<<<< HEAD:Code/syntax.tab.c
  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
  YYFPRINTF (yyoutput, ")");
=======
  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
>>>>>>> a768f7c42fc8cedf061cec867b3e39a8a0fd0079:cmmc_optimizer-main/build/generate/IR_parse/IR_syntax.tab.c
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
<<<<<<< HEAD:Code/syntax.tab.c
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
=======
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
>>>>>>> a768f7c42fc8cedf061cec867b3e39a8a0fd0079:cmmc_optimizer-main/build/generate/IR_parse/IR_syntax.tab.c
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
<<<<<<< HEAD:Code/syntax.tab.c
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                       , &(yylsp[(yyi + 1) - (yynrhs)])                       );
=======
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
>>>>>>> a768f7c42fc8cedf061cec867b3e39a8a0fd0079:cmmc_optimizer-main/build/generate/IR_parse/IR_syntax.tab.c
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
<<<<<<< HEAD:Code/syntax.tab.c
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
=======
#else /* !IR_YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
>>>>>>> a768f7c42fc8cedf061cec867b3e39a8a0fd0079:cmmc_optimizer-main/build/generate/IR_parse/IR_syntax.tab.c
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !IR_YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


<<<<<<< HEAD:Code/syntax.tab.c
#if YYERROR_VERBOSE
=======
/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
  if (!yypact_value_is_default (yyn))
    {
      /* Start YYX at -YYN if negative to avoid negative indexes in
         YYCHECK.  In other words, skip the first -YYN actions for
         this state because they are default actions.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;
      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yyx;
      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}
>>>>>>> a768f7c42fc8cedf061cec867b3e39a8a0fd0079:cmmc_optimizer-main/build/generate/IR_parse/IR_syntax.tab.c

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
# endif
#endif

#ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;
      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
      case N:                               \
        yyformat = S;                       \
        break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
<<<<<<< HEAD:Code/syntax.tab.c
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
=======
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
>>>>>>> a768f7c42fc8cedf061cec867b3e39a8a0fd0079:cmmc_optimizer-main/build/generate/IR_parse/IR_syntax.tab.c
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.
       'yyls': related to locations.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

<<<<<<< HEAD:Code/syntax.tab.c
    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYSIZE_T yystacksize;

=======
>>>>>>> a768f7c42fc8cedf061cec867b3e39a8a0fd0079:cmmc_optimizer-main/build/generate/IR_parse/IR_syntax.tab.c
  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
<<<<<<< HEAD:Code/syntax.tab.c
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))
=======

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))
>>>>>>> a768f7c42fc8cedf061cec867b3e39a8a0fd0079:cmmc_optimizer-main/build/generate/IR_parse/IR_syntax.tab.c

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

<<<<<<< HEAD:Code/syntax.tab.c
  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
=======
  yychar = IR_TOKEN_IR_YYEMPTY; /* Cause a token to be read.  */

>>>>>>> a768f7c42fc8cedf061cec867b3e39a8a0fd0079:cmmc_optimizer-main/build/generate/IR_parse/IR_syntax.tab.c
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
<<<<<<< HEAD:Code/syntax.tab.c
        yytype_int16 *yyss1 = yyss;
        YYLTYPE *yyls1 = yyls;
=======
>>>>>>> a768f7c42fc8cedf061cec867b3e39a8a0fd0079:cmmc_optimizer-main/build/generate/IR_parse/IR_syntax.tab.c

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
<<<<<<< HEAD:Code/syntax.tab.c
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yyls1, yysize * sizeof (*yylsp),
=======
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
>>>>>>> a768f7c42fc8cedf061cec867b3e39a8a0fd0079:cmmc_optimizer-main/build/generate/IR_parse/IR_syntax.tab.c
                    &yystacksize);

        yyls = yyls1;
        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

<<<<<<< HEAD:Code/syntax.tab.c
  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
=======
  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == IR_TOKEN_IR_YYEMPTY)
>>>>>>> a768f7c42fc8cedf061cec867b3e39a8a0fd0079:cmmc_optimizer-main/build/generate/IR_parse/IR_syntax.tab.c
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= IR_TOKEN_YYEOF)
    {
<<<<<<< HEAD:Code/syntax.tab.c
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
=======
      yychar = IR_TOKEN_YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == IR_TOKEN_IR_YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = IR_TOKEN_IR_YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
>>>>>>> a768f7c42fc8cedf061cec867b3e39a8a0fd0079:cmmc_optimizer-main/build/generate/IR_parse/IR_syntax.tab.c
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
<<<<<<< HEAD:Code/syntax.tab.c
  *++yylsp = yylloc;
=======

  /* Discard the shifted token.  */
  yychar = IR_TOKEN_IR_YYEMPTY;
>>>>>>> a768f7c42fc8cedf061cec867b3e39a8a0fd0079:cmmc_optimizer-main/build/generate/IR_parse/IR_syntax.tab.c
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

<<<<<<< HEAD:Code/syntax.tab.c
  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 57 "./syntax.y" /* yacc.c:1646  */
    {root = new_node("Program",node_grammar);root->line=(yyloc).first_line;insert_child(root,(yyvsp[0].val));(yyval.val)=root;}
#line 1502 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 60 "./syntax.y" /* yacc.c:1646  */
    {NNAC((yyval.val), "ExtDefList", (yyloc).first_line, 2, (yyvsp[-1].val), (yyvsp[0].val))}
#line 1508 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 62 "./syntax.y" /* yacc.c:1646  */
    {(yyval.val)=new_node("ExtDefList",node_grammar);}
#line 1514 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 64 "./syntax.y" /* yacc.c:1646  */
    {NNAC((yyval.val), "ExtDef", (yyloc).first_line, 3, (yyvsp[-2].val), (yyvsp[-1].val),(yyvsp[0].val))}
#line 1520 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 65 "./syntax.y" /* yacc.c:1646  */
    {NNAC((yyval.val), "ExtDef", (yyloc).first_line, 2, (yyvsp[-1].val), (yyvsp[0].val));}
#line 1526 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 66 "./syntax.y" /* yacc.c:1646  */
    {NNAC((yyval.val), "ExtDef", (yyloc).first_line, 3, (yyvsp[-2].val), (yyvsp[-1].val),(yyvsp[0].val))}
#line 1532 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 67 "./syntax.y" /* yacc.c:1646  */
    {NNAC((yyval.val), "ExtDef", (yyloc).first_line, 3, (yyvsp[-2].val), (yyvsp[-1].val),(yyvsp[0].val))}
#line 1538 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 71 "./syntax.y" /* yacc.c:1646  */
    {NNAC((yyval.val), "ExtDecList", (yyloc).first_line, 1, (yyvsp[0].val))}
#line 1544 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 72 "./syntax.y" /* yacc.c:1646  */
    { NNAC((yyval.val), "ExtDecList", (yyloc).first_line, 3, (yyvsp[-2].val), (yyvsp[-1].val),(yyvsp[0].val))}
#line 1550 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 77 "./syntax.y" /* yacc.c:1646  */
    {NNAC((yyval.val), "Specifier", (yyloc).first_line, 1, (yyvsp[0].val))}
#line 1556 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 78 "./syntax.y" /* yacc.c:1646  */
    {NNAC((yyval.val), "Specifier", (yyloc).first_line, 1, (yyvsp[0].val))}
#line 1562 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 80 "./syntax.y" /* yacc.c:1646  */
    { NNAC((yyval.val), "StructSpecifier", (yyloc).first_line, 5, (yyvsp[-4].val), (yyvsp[-3].val),(yyvsp[-2].val),(yyvsp[-1].val),(yyvsp[0].val))}
#line 1568 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 81 "./syntax.y" /* yacc.c:1646  */
    {NNAC((yyval.val), "StructSpecifier", (yyloc).first_line, 2, (yyvsp[-1].val), (yyvsp[0].val))}
#line 1574 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 83 "./syntax.y" /* yacc.c:1646  */
    {NNAC((yyval.val), "OptTag", (yyloc).first_line, 1, (yyvsp[0].val))}
#line 1580 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 84 "./syntax.y" /* yacc.c:1646  */
    {(yyval.val)=new_node("OptTag",node_grammar);}
#line 1586 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 86 "./syntax.y" /* yacc.c:1646  */
    {NNAC((yyval.val), "Tag", (yyloc).first_line, 1, (yyvsp[0].val))}
#line 1592 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 91 "./syntax.y" /* yacc.c:1646  */
    { NNAC((yyval.val), "VarDec", (yyloc).first_line, 1, (yyvsp[0].val))}
#line 1598 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 92 "./syntax.y" /* yacc.c:1646  */
    {NNAC((yyval.val), "VarDec", (yyloc).first_line, 4, (yyvsp[-3].val), (yyvsp[-2].val),(yyvsp[-1].val),(yyvsp[0].val))}
#line 1604 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 94 "./syntax.y" /* yacc.c:1646  */
    { NNAC((yyval.val), "FunDec", (yyloc).first_line, 4, (yyvsp[-3].val), (yyvsp[-2].val),(yyvsp[-1].val),(yyvsp[0].val))}
#line 1610 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 95 "./syntax.y" /* yacc.c:1646  */
    {NNAC((yyval.val), "FunDec", (yyloc).first_line, 3, (yyvsp[-2].val), (yyvsp[-1].val),(yyvsp[0].val))}
#line 1616 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 97 "./syntax.y" /* yacc.c:1646  */
    {NNAC((yyval.val), "VarList", (yyloc).first_line, 3, (yyvsp[-2].val), (yyvsp[-1].val),(yyvsp[0].val))}
#line 1622 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 98 "./syntax.y" /* yacc.c:1646  */
    {NNAC((yyval.val), "VarList", (yyloc).first_line, 1, (yyvsp[0].val))}
#line 1628 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 100 "./syntax.y" /* yacc.c:1646  */
    {NNAC((yyval.val), "ParamDec", (yyloc).first_line, 2, (yyvsp[-1].val), (yyvsp[0].val))}
#line 1634 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 105 "./syntax.y" /* yacc.c:1646  */
    { NNAC((yyval.val), "CompSt", (yyloc).first_line, 4, (yyvsp[-3].val), (yyvsp[-2].val),(yyvsp[-1].val),(yyvsp[0].val))}
#line 1640 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 108 "./syntax.y" /* yacc.c:1646  */
    {NNAC((yyval.val), "StmtList", (yyloc).first_line, 2, (yyvsp[-1].val), (yyvsp[0].val))}
#line 1646 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 109 "./syntax.y" /* yacc.c:1646  */
    {(yyval.val)=new_node("StmtList",node_grammar);}
#line 1652 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 111 "./syntax.y" /* yacc.c:1646  */
    {NNAC((yyval.val), "Stmt", (yyloc).first_line, 2, (yyvsp[-1].val), (yyvsp[0].val))}
#line 1658 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 112 "./syntax.y" /* yacc.c:1646  */
    {NNAC((yyval.val), "Stmt", (yyloc).first_line, 1, (yyvsp[0].val))}
#line 1664 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 113 "./syntax.y" /* yacc.c:1646  */
    {NNAC((yyval.val), "Stmt", (yyloc).first_line, 3, (yyvsp[-2].val), (yyvsp[-1].val),(yyvsp[0].val))}
#line 1670 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 114 "./syntax.y" /* yacc.c:1646  */
    {NNAC((yyval.val), "Stmt", (yyloc).first_line, 5, (yyvsp[-4].val), (yyvsp[-3].val),(yyvsp[-2].val),(yyvsp[-1].val), (yyvsp[0].val))}
#line 1676 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 115 "./syntax.y" /* yacc.c:1646  */
    { NNAC((yyval.val), "Stmt", (yyloc).first_line, 7, (yyvsp[-6].val), (yyvsp[-5].val),(yyvsp[-4].val),(yyvsp[-3].val), (yyvsp[-2].val), (yyvsp[-1].val),(yyvsp[0].val))}
#line 1682 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 116 "./syntax.y" /* yacc.c:1646  */
    { NNAC((yyval.val), "Stmt", (yyloc).first_line, 5, (yyvsp[-4].val), (yyvsp[-3].val),(yyvsp[-2].val),(yyvsp[-1].val), (yyvsp[0].val))}
#line 1688 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 124 "./syntax.y" /* yacc.c:1646  */
    {NNAC((yyval.val), "DefList", (yyloc).first_line, 2, (yyvsp[-1].val), (yyvsp[0].val))}
#line 1694 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 125 "./syntax.y" /* yacc.c:1646  */
    {(yyval.val)=new_node("DefList",node_grammar);}
#line 1700 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 127 "./syntax.y" /* yacc.c:1646  */
    { NNAC((yyval.val), "Def", (yyloc).first_line, 3, (yyvsp[-2].val), (yyvsp[-1].val),(yyvsp[0].val))}
#line 1706 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 129 "./syntax.y" /* yacc.c:1646  */
    { NNAC((yyval.val), "DecList", (yyloc).first_line, 1, (yyvsp[0].val))}
#line 1712 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 130 "./syntax.y" /* yacc.c:1646  */
    { NNAC((yyval.val), "DecList", (yyloc).first_line, 3, (yyvsp[-2].val), (yyvsp[-1].val),(yyvsp[0].val))}
#line 1718 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 132 "./syntax.y" /* yacc.c:1646  */
    {NNAC((yyval.val), "Dec", (yyloc).first_line, 1, (yyvsp[0].val))}
#line 1724 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 133 "./syntax.y" /* yacc.c:1646  */
    { NNAC((yyval.val), "Dec", (yyloc).first_line, 3, (yyvsp[-2].val), (yyvsp[-1].val),(yyvsp[0].val))}
#line 1730 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 139 "./syntax.y" /* yacc.c:1646  */
    { NNAC((yyval.val), "Exp", (yyloc).first_line, 3, (yyvsp[-2].val), (yyvsp[-1].val),(yyvsp[0].val))}
#line 1736 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 140 "./syntax.y" /* yacc.c:1646  */
    { NNAC((yyval.val), "Exp", (yyloc).first_line, 3, (yyvsp[-2].val), (yyvsp[-1].val),(yyvsp[0].val))}
#line 1742 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 141 "./syntax.y" /* yacc.c:1646  */
    { NNAC((yyval.val), "Exp", (yyloc).first_line, 3, (yyvsp[-2].val), (yyvsp[-1].val),(yyvsp[0].val))}
#line 1748 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 142 "./syntax.y" /* yacc.c:1646  */
    { NNAC((yyval.val), "Exp", (yyloc).first_line, 3, (yyvsp[-2].val), (yyvsp[-1].val),(yyvsp[0].val))}
#line 1754 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 143 "./syntax.y" /* yacc.c:1646  */
    { NNAC((yyval.val), "Exp", (yyloc).first_line, 3, (yyvsp[-2].val), (yyvsp[-1].val),(yyvsp[0].val))}
#line 1760 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 144 "./syntax.y" /* yacc.c:1646  */
    { NNAC((yyval.val), "Exp", (yyloc).first_line, 3, (yyvsp[-2].val), (yyvsp[-1].val),(yyvsp[0].val))}
#line 1766 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 145 "./syntax.y" /* yacc.c:1646  */
    { NNAC((yyval.val), "Exp", (yyloc).first_line, 3, (yyvsp[-2].val), (yyvsp[-1].val),(yyvsp[0].val))}
#line 1772 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 146 "./syntax.y" /* yacc.c:1646  */
    { NNAC((yyval.val), "Exp", (yyloc).first_line, 3, (yyvsp[-2].val), (yyvsp[-1].val),(yyvsp[0].val))}
#line 1778 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 147 "./syntax.y" /* yacc.c:1646  */
    { NNAC((yyval.val), "Exp", (yyloc).first_line, 3, (yyvsp[-2].val), (yyvsp[-1].val),(yyvsp[0].val))}
#line 1784 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 148 "./syntax.y" /* yacc.c:1646  */
    { NNAC((yyval.val), "Exp", (yyloc).first_line, 2, (yyvsp[-1].val), (yyvsp[0].val))}
#line 1790 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 149 "./syntax.y" /* yacc.c:1646  */
    { NNAC((yyval.val), "Exp", (yyloc).first_line, 2, (yyvsp[-1].val), (yyvsp[0].val))}
#line 1796 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 150 "./syntax.y" /* yacc.c:1646  */
    { NNAC((yyval.val), "Exp", (yyloc).first_line, 4, (yyvsp[-3].val), (yyvsp[-2].val),(yyvsp[-1].val),(yyvsp[0].val))}
#line 1802 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 151 "./syntax.y" /* yacc.c:1646  */
    { NNAC((yyval.val), "Exp", (yyloc).first_line, 3, (yyvsp[-2].val), (yyvsp[-1].val),(yyvsp[0].val))}
#line 1808 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 152 "./syntax.y" /* yacc.c:1646  */
    { NNAC((yyval.val), "Exp", (yyloc).first_line, 4, (yyvsp[-3].val), (yyvsp[-2].val),(yyvsp[-1].val),(yyvsp[0].val))}
#line 1814 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 153 "./syntax.y" /* yacc.c:1646  */
    { NNAC((yyval.val), "Exp", (yyloc).first_line, 3, (yyvsp[-2].val), (yyvsp[-1].val),(yyvsp[0].val))}
#line 1820 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 154 "./syntax.y" /* yacc.c:1646  */
    { NNAC((yyval.val), "Exp", (yyloc).first_line, 1, (yyvsp[0].val))}
#line 1826 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 155 "./syntax.y" /* yacc.c:1646  */
    { NNAC((yyval.val), "Exp", (yyloc).first_line, 1, (yyvsp[0].val))}
#line 1832 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 156 "./syntax.y" /* yacc.c:1646  */
    { NNAC((yyval.val), "Exp", (yyloc).first_line, 1, (yyvsp[0].val))}
#line 1838 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 159 "./syntax.y" /* yacc.c:1646  */
    { NNAC((yyval.val), "Args", (yyloc).first_line, 3, (yyvsp[-2].val), (yyvsp[-1].val),(yyvsp[0].val))}
#line 1844 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 160 "./syntax.y" /* yacc.c:1646  */
    { NNAC((yyval.val), "Args", (yyloc).first_line, 1, (yyvsp[0].val))}
#line 1850 "./syntax.tab.c" /* yacc.c:1646  */
    break;


#line 1854 "./syntax.tab.c" /* yacc.c:1646  */
=======

  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* IR_globol: MUL_EOL IR_program  */
#line 68 "src/IR_parse/IR_syntax.y"
                                                        { ir_program_global = (yyvsp[0].IR_program_ptr_node); }
#line 1416 "build/generate/IR_parse/IR_syntax.tab.c"
    break;

  case 3: /* IR_program: IR_program IR_function  */
#line 70 "src/IR_parse/IR_syntax.y"
                                                        {
                                                            (yyval.IR_program_ptr_node) = (yyvsp[-1].IR_program_ptr_node);
                                                            IR_function_closure((yyvsp[0].IR_function_ptr_node));
                                                            VCALL((yyval.IR_program_ptr_node)->functions, push_back, (yyvsp[0].IR_function_ptr_node));
                                                        }
#line 1426 "build/generate/IR_parse/IR_syntax.tab.c"
    break;

  case 4: /* IR_program: %empty  */
#line 75 "src/IR_parse/IR_syntax.y"
                                                        { (yyval.IR_program_ptr_node) = NEW(IR_program); }
#line 1432 "build/generate/IR_parse/IR_syntax.tab.c"
    break;

  case 5: /* IR_function: FUNCTION ID COLON EOL  */
#line 77 "src/IR_parse/IR_syntax.y"
                                                        { (yyval.IR_function_ptr_node) = NEW(IR_function, (yyvsp[-2].id)); now_function = (yyval.IR_function_ptr_node); free((yyvsp[-2].id)); }
#line 1438 "build/generate/IR_parse/IR_syntax.tab.c"
    break;

  case 6: /* IR_function: IR_function PARAM IR_var EOL  */
#line 78 "src/IR_parse/IR_syntax.y"
                                                        { (yyval.IR_function_ptr_node) = (yyvsp[-3].IR_function_ptr_node); VCALL((yyval.IR_function_ptr_node)->params, push_back, (yyvsp[-1].IR_var_node)); }
#line 1444 "build/generate/IR_parse/IR_syntax.tab.c"
    break;

  case 7: /* IR_function: IR_function DEC IR_var INT EOL  */
#line 79 "src/IR_parse/IR_syntax.y"
                                                        { (yyval.IR_function_ptr_node) = (yyvsp[-4].IR_function_ptr_node); IR_function_insert_dec((yyval.IR_function_ptr_node), (yyvsp[-2].IR_var_node), (unsigned)(yyvsp[-1].INT)); }
#line 1450 "build/generate/IR_parse/IR_syntax.tab.c"
    break;

  case 8: /* IR_function: IR_function ARG IR_val_rs EOL  */
#line 80 "src/IR_parse/IR_syntax.y"
                                                        { (yyval.IR_function_ptr_node) = (yyvsp[-3].IR_function_ptr_node); args_stack_push((yyvsp[-1].IR_val_node)); }
#line 1456 "build/generate/IR_parse/IR_syntax.tab.c"
    break;

  case 9: /* IR_function: IR_function LABEL IR_label COLON EOL  */
#line 81 "src/IR_parse/IR_syntax.y"
                                                        { (yyval.IR_function_ptr_node) = (yyvsp[-4].IR_function_ptr_node); IR_function_push_label((yyval.IR_function_ptr_node), (yyvsp[-2].IR_label_node)); }
#line 1462 "build/generate/IR_parse/IR_syntax.tab.c"
    break;

  case 10: /* IR_function: IR_function IR_stmt EOL  */
#line 82 "src/IR_parse/IR_syntax.y"
                                                        { (yyval.IR_function_ptr_node) = (yyvsp[-2].IR_function_ptr_node); IR_function_push_stmt((yyval.IR_function_ptr_node), (yyvsp[-1].IR_stmt_ptr_node)); }
#line 1468 "build/generate/IR_parse/IR_syntax.tab.c"
    break;

  case 11: /* IR_stmt: IR_var ASSIGN IR_val  */
#line 84 "src/IR_parse/IR_syntax.y"
                                                        { (yyval.IR_stmt_ptr_node) = (IR_stmt*)NEW(IR_assign_stmt, (yyvsp[-2].IR_var_node), (yyvsp[0].IR_val_node)); }
#line 1474 "build/generate/IR_parse/IR_syntax.tab.c"
    break;

  case 12: /* IR_stmt: IR_var ASSIGN val_deref  */
#line 85 "src/IR_parse/IR_syntax.y"
                                                        { (yyval.IR_stmt_ptr_node) = (IR_stmt*)NEW(IR_load_stmt, (yyvsp[-2].IR_var_node), (yyvsp[0].IR_val_node)); }
#line 1480 "build/generate/IR_parse/IR_syntax.tab.c"
    break;

  case 13: /* IR_stmt: val_deref ASSIGN IR_val_rs  */
#line 86 "src/IR_parse/IR_syntax.y"
                                                        { (yyval.IR_stmt_ptr_node) = (IR_stmt*)NEW(IR_store_stmt, (yyvsp[-2].IR_val_node), (yyvsp[0].IR_val_node)); }
#line 1486 "build/generate/IR_parse/IR_syntax.tab.c"
    break;

  case 14: /* IR_stmt: IR_var ASSIGN IR_val_rs OP IR_val_rs  */
#line 87 "src/IR_parse/IR_syntax.y"
                                                        { (yyval.IR_stmt_ptr_node) = (IR_stmt*)NEW(IR_op_stmt, (yyvsp[-1].IR_op_type), (yyvsp[-4].IR_var_node), (yyvsp[-2].IR_val_node), (yyvsp[0].IR_val_node)); }
#line 1492 "build/generate/IR_parse/IR_syntax.tab.c"
    break;

  case 15: /* IR_stmt: IR_var ASSIGN IR_val_rs STAR IR_val_rs  */
#line 88 "src/IR_parse/IR_syntax.y"
                                                        { (yyval.IR_stmt_ptr_node) = (IR_stmt*)NEW(IR_op_stmt, (yyvsp[-1].IR_op_type), (yyvsp[-4].IR_var_node), (yyvsp[-2].IR_val_node), (yyvsp[0].IR_val_node)); }
#line 1498 "build/generate/IR_parse/IR_syntax.tab.c"
    break;

  case 16: /* IR_stmt: GOTO IR_label  */
#line 89 "src/IR_parse/IR_syntax.y"
                                                        { (yyval.IR_stmt_ptr_node) = (IR_stmt*)NEW(IR_goto_stmt, (yyvsp[0].IR_label_node)); }
#line 1504 "build/generate/IR_parse/IR_syntax.tab.c"
    break;

  case 17: /* IR_stmt: IF IR_val_rs RELOP IR_val_rs GOTO IR_label  */
#line 91 "src/IR_parse/IR_syntax.y"
                                                        { (yyval.IR_stmt_ptr_node) = (IR_stmt*)NEW(IR_if_stmt, (yyvsp[-3].IR_relop_type), (yyvsp[-4].IR_val_node), (yyvsp[-2].IR_val_node), (yyvsp[0].IR_label_node), IR_LABEL_NONE); }
#line 1510 "build/generate/IR_parse/IR_syntax.tab.c"
    break;

  case 18: /* IR_stmt: RETURN IR_val  */
#line 92 "src/IR_parse/IR_syntax.y"
                                                        { (yyval.IR_stmt_ptr_node) = (IR_stmt*)NEW(IR_return_stmt, (yyvsp[0].IR_val_node)); }
#line 1516 "build/generate/IR_parse/IR_syntax.tab.c"
    break;

  case 19: /* IR_stmt: IR_var ASSIGN CALL ID  */
#line 93 "src/IR_parse/IR_syntax.y"
                                                        {
                                                             unsigned argc;
                                                             IR_val *argv;
                                                             args_stack_pop(&argc, &argv);
                                                             (yyval.IR_stmt_ptr_node) = (IR_stmt*)NEW(IR_call_stmt, (yyvsp[-3].IR_var_node), (yyvsp[0].id), argc, argv);
                                                             free((yyvsp[0].id));
                                                        }
#line 1528 "build/generate/IR_parse/IR_syntax.tab.c"
    break;

  case 20: /* IR_stmt: READ IR_var  */
#line 100 "src/IR_parse/IR_syntax.y"
                                                        { (yyval.IR_stmt_ptr_node) = (IR_stmt*)NEW(IR_read_stmt, (yyvsp[0].IR_var_node)); }
#line 1534 "build/generate/IR_parse/IR_syntax.tab.c"
    break;

  case 21: /* IR_stmt: WRITE IR_val_rs  */
#line 101 "src/IR_parse/IR_syntax.y"
                                                        { (yyval.IR_stmt_ptr_node) = (IR_stmt*)NEW(IR_write_stmt, (yyvsp[0].IR_val_node)); }
#line 1540 "build/generate/IR_parse/IR_syntax.tab.c"
    break;

  case 22: /* IR_val: IR_var  */
#line 103 "src/IR_parse/IR_syntax.y"
                                                        { (yyval.IR_val_node) = (IR_val){.is_const = false, .var = (yyvsp[0].IR_var_node)}; }
#line 1546 "build/generate/IR_parse/IR_syntax.tab.c"
    break;

  case 23: /* IR_val: SHARP INT  */
#line 104 "src/IR_parse/IR_syntax.y"
                                                        { (yyval.IR_val_node) = (IR_val){.is_const = true, .const_val = (yyvsp[0].INT)}; }
#line 1552 "build/generate/IR_parse/IR_syntax.tab.c"
    break;

  case 24: /* IR_val: ADDR_OF IR_var  */
#line 105 "src/IR_parse/IR_syntax.y"
                                                        { (yyval.IR_val_node) = (IR_val){.is_const = false,
                                                                        .var = VCALL(now_function->map_dec, get, (yyvsp[0].IR_var_node)).dec_addr}; }
#line 1559 "build/generate/IR_parse/IR_syntax.tab.c"
    break;

  case 25: /* val_deref: STAR IR_val  */
#line 108 "src/IR_parse/IR_syntax.y"
                                                        { (yyval.IR_val_node) = (yyvsp[0].IR_val_node); }
#line 1565 "build/generate/IR_parse/IR_syntax.tab.c"
    break;

  case 26: /* IR_val_rs: IR_val  */
#line 109 "src/IR_parse/IR_syntax.y"
                                                        { (yyval.IR_val_node) = (yyvsp[0].IR_val_node); }
#line 1571 "build/generate/IR_parse/IR_syntax.tab.c"
    break;

  case 27: /* IR_val_rs: val_deref  */
#line 110 "src/IR_parse/IR_syntax.y"
                                                        {
                                                            IR_var content = ir_var_generator();
                                                            IR_function_push_stmt(now_function,
                                                                                  (IR_stmt*)NEW(IR_load_stmt, content, (yyvsp[0].IR_val_node)));
                                                            (yyval.IR_val_node) = (IR_val){.is_const = false, .var = content};
                                                        }
#line 1582 "build/generate/IR_parse/IR_syntax.tab.c"
    break;

  case 28: /* IR_var: ID  */
#line 116 "src/IR_parse/IR_syntax.y"
                                                        { (yyval.IR_var_node) = get_IR_var((yyvsp[0].id)); free((yyvsp[0].id)); }
#line 1588 "build/generate/IR_parse/IR_syntax.tab.c"
    break;

  case 29: /* IR_label: ID  */
#line 118 "src/IR_parse/IR_syntax.y"
                                                        { (yyval.IR_label_node) = get_IR_label((yyvsp[0].id)); free((yyvsp[0].id)); }
#line 1594 "build/generate/IR_parse/IR_syntax.tab.c"
    break;


#line 1598 "build/generate/IR_parse/IR_syntax.tab.c"

>>>>>>> a768f7c42fc8cedf061cec867b3e39a8a0fd0079:cmmc_optimizer-main/build/generate/IR_parse/IR_syntax.tab.c
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
<<<<<<< HEAD:Code/syntax.tab.c
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

=======
  yytoken = yychar == IR_TOKEN_IR_YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
>>>>>>> a768f7c42fc8cedf061cec867b3e39a8a0fd0079:cmmc_optimizer-main/build/generate/IR_parse/IR_syntax.tab.c
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
<<<<<<< HEAD:Code/syntax.tab.c
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }

  yyerror_range[1] = yylloc;

=======
      {
        yypcontext_t yyctx
          = {yyssp, yytoken};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          YYNOMEM;
      }
    }

>>>>>>> a768f7c42fc8cedf061cec867b3e39a8a0fd0079:cmmc_optimizer-main/build/generate/IR_parse/IR_syntax.tab.c
  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= IR_TOKEN_YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == IR_TOKEN_YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = IR_TOKEN_IR_YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  yyerror_range[1] = yylsp[1-yylen];
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
<<<<<<< HEAD:Code/syntax.tab.c
                  yystos[yystate], yyvsp, yylsp);
=======
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
>>>>>>> a768f7c42fc8cedf061cec867b3e39a8a0fd0079:cmmc_optimizer-main/build/generate/IR_parse/IR_syntax.tab.c
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

<<<<<<< HEAD:Code/syntax.tab.c
  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;
=======
>>>>>>> a768f7c42fc8cedf061cec867b3e39a8a0fd0079:cmmc_optimizer-main/build/generate/IR_parse/IR_syntax.tab.c

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

<<<<<<< HEAD:Code/syntax.tab.c
yyreturn:
  if (yychar != YYEMPTY)
=======
/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != IR_TOKEN_IR_YYEMPTY)
>>>>>>> a768f7c42fc8cedf061cec867b3e39a8a0fd0079:cmmc_optimizer-main/build/generate/IR_parse/IR_syntax.tab.c
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
<<<<<<< HEAD:Code/syntax.tab.c
                  yystos[*yyssp], yyvsp, yylsp);
=======
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
>>>>>>> a768f7c42fc8cedf061cec867b3e39a8a0fd0079:cmmc_optimizer-main/build/generate/IR_parse/IR_syntax.tab.c
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
<<<<<<< HEAD:Code/syntax.tab.c
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 162 "./syntax.y" /* yacc.c:1906  */
=======
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 124 "src/IR_parse/IR_syntax.y"


int IR_yyerror(const char *msg) {
    fprintf(YYERROR_OUTPUT, "IR syntax error: %s\n", msg);
    return 0;
}

//// ================================== args stack ==================================

unsigned args_stack_top = 0;
static IR_val args_stack[16];
>>>>>>> a768f7c42fc8cedf061cec867b3e39a8a0fd0079:cmmc_optimizer-main/build/generate/IR_parse/IR_syntax.tab.c

static void args_stack_push(IR_val arg) {
    args_stack[args_stack_top ++] = arg;
}

static void args_stack_pop(unsigned *argc_ptr, IR_val **argv_ptr) {
    unsigned argc = args_stack_top;
    IR_val *argv = (IR_val*)malloc(sizeof(IR_val[argc]));
    for(int i = 0; i < argc; i ++)
        argv[i] = args_stack[i];
    *argc_ptr = argc;
    *argv_ptr = argv;
    args_stack_top = 0;
}

