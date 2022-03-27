/* A Bison parser, made by GNU Bison 3.7.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.7.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 3 "Grammar.y"

#include <stdio.h>
#include "tree_nodes.h"
#include "print_tree.h"
#include "dot.h"

void yyerror(const char* message) {
    fprintf(stderr, message);
}
int yylex();
int yyparse();
extern FILE* yyin;

struct program_struct * root;


#line 88 "Grammar.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "Grammar.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_ALIAS_KEYWORD = 3,              /* ALIAS_KEYWORD  */
  YYSYMBOL_AND_KEYWORD = 4,                /* AND_KEYWORD  */
  YYSYMBOL_BEGIN_KEYWORD = 5,              /* BEGIN_KEYWORD  */
  YYSYMBOL_BREAK_KEYWORD = 6,              /* BREAK_KEYWORD  */
  YYSYMBOL_CASE_KEYWORD = 7,               /* CASE_KEYWORD  */
  YYSYMBOL_CLASS_KEYWORD = 8,              /* CLASS_KEYWORD  */
  YYSYMBOL_DEF_KEYWORD = 9,                /* DEF_KEYWORD  */
  YYSYMBOL_DEFINED_KEYWORD = 10,           /* DEFINED_KEYWORD  */
  YYSYMBOL_DO_KEYWORD = 11,                /* DO_KEYWORD  */
  YYSYMBOL_IF_KEYWORD = 12,                /* IF_KEYWORD  */
  YYSYMBOL_ELSE_KEYWORD = 13,              /* ELSE_KEYWORD  */
  YYSYMBOL_ELSIF_KEYWORD = 14,             /* ELSIF_KEYWORD  */
  YYSYMBOL_END_KEYWORD = 15,               /* END_KEYWORD  */
  YYSYMBOL_ENSURE_KEYWORD = 16,            /* ENSURE_KEYWORD  */
  YYSYMBOL_FALSE_KEYWORD = 17,             /* FALSE_KEYWORD  */
  YYSYMBOL_FOR_KEYWORD = 18,               /* FOR_KEYWORD  */
  YYSYMBOL_IN_KEYWORD = 19,                /* IN_KEYWORD  */
  YYSYMBOL_MODULE_KEYWORD = 20,            /* MODULE_KEYWORD  */
  YYSYMBOL_NEXT_KEYWORD = 21,              /* NEXT_KEYWORD  */
  YYSYMBOL_NIL_KEYWORD = 22,               /* NIL_KEYWORD  */
  YYSYMBOL_NOT_KEYWORD = 23,               /* NOT_KEYWORD  */
  YYSYMBOL_OR_KEYWORD = 24,                /* OR_KEYWORD  */
  YYSYMBOL_REDO_KEYWORD = 25,              /* REDO_KEYWORD  */
  YYSYMBOL_RESCUE_KEYWORD = 26,            /* RESCUE_KEYWORD  */
  YYSYMBOL_RETRY_KEYWORD = 27,             /* RETRY_KEYWORD  */
  YYSYMBOL_RETURN_KEYWORD = 28,            /* RETURN_KEYWORD  */
  YYSYMBOL_SELF_KEYWORD = 29,              /* SELF_KEYWORD  */
  YYSYMBOL_SUPER_KEYWORD = 30,             /* SUPER_KEYWORD  */
  YYSYMBOL_THEN_KEYWORD = 31,              /* THEN_KEYWORD  */
  YYSYMBOL_TRUE_KEYWORD = 32,              /* TRUE_KEYWORD  */
  YYSYMBOL_UNDEF_KEYWORD = 33,             /* UNDEF_KEYWORD  */
  YYSYMBOL_UNLESS_KEYWORD = 34,            /* UNLESS_KEYWORD  */
  YYSYMBOL_UNTIL_KEYWORD = 35,             /* UNTIL_KEYWORD  */
  YYSYMBOL_WHEN_KEYWORD = 36,              /* WHEN_KEYWORD  */
  YYSYMBOL_WHILE_KEYWORD = 37,             /* WHILE_KEYWORD  */
  YYSYMBOL_YIELD_KEYWORD = 38,             /* YIELD_KEYWORD  */
  YYSYMBOL_ARITHMETIC_PLUS_OP = 39,        /* ARITHMETIC_PLUS_OP  */
  YYSYMBOL_ARITHMETIC_MINUS_OP = 40,       /* ARITHMETIC_MINUS_OP  */
  YYSYMBOL_ARITHMETIC_MUL_OP = 41,         /* ARITHMETIC_MUL_OP  */
  YYSYMBOL_ARITHMETIC_DIV_OP = 42,         /* ARITHMETIC_DIV_OP  */
  YYSYMBOL_ARITHMETIC_MOD_OP = 43,         /* ARITHMETIC_MOD_OP  */
  YYSYMBOL_ARITHMETIC_POW_OP = 44,         /* ARITHMETIC_POW_OP  */
  YYSYMBOL_EQL_OP = 45,                    /* EQL_OP  */
  YYSYMBOL_NOT_EQL_OP = 46,                /* NOT_EQL_OP  */
  YYSYMBOL_GREATER_OP = 47,                /* GREATER_OP  */
  YYSYMBOL_LESS_OP = 48,                   /* LESS_OP  */
  YYSYMBOL_GREATER_OR_EQL_OP = 49,         /* GREATER_OR_EQL_OP  */
  YYSYMBOL_LESS_OR_EQL_OP = 50,            /* LESS_OR_EQL_OP  */
  YYSYMBOL_COMB_COMPRASION_OP = 51,        /* COMB_COMPRASION_OP  */
  YYSYMBOL_CASE_EQL_OP = 52,               /* CASE_EQL_OP  */
  YYSYMBOL_RECEIVER_EQL_OP = 53,           /* RECEIVER_EQL_OP  */
  YYSYMBOL_OBJ_ID_EQL_OP = 54,             /* OBJ_ID_EQL_OP  */
  YYSYMBOL_ASSIGN_OP = 55,                 /* ASSIGN_OP  */
  YYSYMBOL_ADD_ASSIGN_OP = 56,             /* ADD_ASSIGN_OP  */
  YYSYMBOL_SUB_ASSIGN_OP = 57,             /* SUB_ASSIGN_OP  */
  YYSYMBOL_MUL_ASSIGN_OP = 58,             /* MUL_ASSIGN_OP  */
  YYSYMBOL_DIV_ASSIGN_OP = 59,             /* DIV_ASSIGN_OP  */
  YYSYMBOL_MOD_ASSIGN_OP = 60,             /* MOD_ASSIGN_OP  */
  YYSYMBOL_POW_ASSIGN_OP = 61,             /* POW_ASSIGN_OP  */
  YYSYMBOL_BIN_AND_OP = 62,                /* BIN_AND_OP  */
  YYSYMBOL_BIN_OR_OP = 63,                 /* BIN_OR_OP  */
  YYSYMBOL_BIN_XOR_OP = 64,                /* BIN_XOR_OP  */
  YYSYMBOL_BIN_ONES_COMPLEMENT_OP = 65,    /* BIN_ONES_COMPLEMENT_OP  */
  YYSYMBOL_BIN_LEFT_SHIFT_OP = 66,         /* BIN_LEFT_SHIFT_OP  */
  YYSYMBOL_BIN_RIGHT_SHIFT_OP = 67,        /* BIN_RIGHT_SHIFT_OP  */
  YYSYMBOL_LOGICAL_AND_OP = 68,            /* LOGICAL_AND_OP  */
  YYSYMBOL_LOGICAL_OR_OP = 69,             /* LOGICAL_OR_OP  */
  YYSYMBOL_LOGICAL_NOT_OP = 70,            /* LOGICAL_NOT_OP  */
  YYSYMBOL_INCLUSIVE_RANGE_OP = 71,        /* INCLUSIVE_RANGE_OP  */
  YYSYMBOL_EXCLUSIVE_RANGE_OP = 72,        /* EXCLUSIVE_RANGE_OP  */
  YYSYMBOL_OPEN_ROUND_BRACKET = 73,        /* OPEN_ROUND_BRACKET  */
  YYSYMBOL_CLOSE_ROUND_BRACKET = 74,       /* CLOSE_ROUND_BRACKET  */
  YYSYMBOL_OPEN_CURLY_BRACKET = 75,        /* OPEN_CURLY_BRACKET  */
  YYSYMBOL_CLOSE_CURLY_BRACKET = 76,       /* CLOSE_CURLY_BRACKET  */
  YYSYMBOL_OPEN_SQUARE_BRACKET = 77,       /* OPEN_SQUARE_BRACKET  */
  YYSYMBOL_CLOSE_SQUARE_BRACKET = 78,      /* CLOSE_SQUARE_BRACKET  */
  YYSYMBOL_COMMERCIAL_AT = 79,             /* COMMERCIAL_AT  */
  YYSYMBOL_QUESTION_SYMBOL = 80,           /* QUESTION_SYMBOL  */
  YYSYMBOL_DOT_SYMBOL = 81,                /* DOT_SYMBOL  */
  YYSYMBOL_COMMA_SYMBOL = 82,              /* COMMA_SYMBOL  */
  YYSYMBOL_COLON_SYMBOL = 83,              /* COLON_SYMBOL  */
  YYSYMBOL_DOUBLE_COLON_SYMBOL = 84,       /* DOUBLE_COLON_SYMBOL  */
  YYSYMBOL_SEMICOLON_SYMBOL = 85,          /* SEMICOLON_SYMBOL  */
  YYSYMBOL_NEW_LINE_SYMBOL = 86,           /* NEW_LINE_SYMBOL  */
  YYSYMBOL_STR = 87,                       /* STR  */
  YYSYMBOL_INTEGER_NUMBER = 88,            /* INTEGER_NUMBER  */
  YYSYMBOL_FLOAT_NUMBER = 89,              /* FLOAT_NUMBER  */
  YYSYMBOL_VAR_METHOD_NAME = 90,           /* VAR_METHOD_NAME  */
  YYSYMBOL_INSTANCE_VAR_NAME = 91,         /* INSTANCE_VAR_NAME  */
  YYSYMBOL_CLASS_NAME = 92,                /* CLASS_NAME  */
  YYSYMBOL_CLASS_VAR_NAME = 93,            /* CLASS_VAR_NAME  */
  YYSYMBOL_UNARY_MINUS = 94,               /* UNARY_MINUS  */
  YYSYMBOL_UNARY_PLUS = 95,                /* UNARY_PLUS  */
  YYSYMBOL_YYACCEPT = 96,                  /* $accept  */
  YYSYMBOL_program = 97,                   /* program  */
  YYSYMBOL_program_item = 98,              /* program_item  */
  YYSYMBOL_program_items_list_not_empty = 99, /* program_items_list_not_empty  */
  YYSYMBOL_program_items_list = 100,       /* program_items_list  */
  YYSYMBOL_expr = 101,                     /* expr  */
  YYSYMBOL_stmt_ends = 102,                /* stmt_ends  */
  YYSYMBOL_new_lines_op = 103,             /* new_lines_op  */
  YYSYMBOL_new_lines = 104,                /* new_lines  */
  YYSYMBOL_stmt_ends_op = 105,             /* stmt_ends_op  */
  YYSYMBOL_stmt = 106,                     /* stmt  */
  YYSYMBOL_stmt_list_not_empty = 107,      /* stmt_list_not_empty  */
  YYSYMBOL_stmt_list = 108,                /* stmt_list  */
  YYSYMBOL_stmt_block = 109,               /* stmt_block  */
  YYSYMBOL_if_start_stmt = 110,            /* if_start_stmt  */
  YYSYMBOL_elsif_stmt = 111,               /* elsif_stmt  */
  YYSYMBOL_elsif_stmt_list = 112,          /* elsif_stmt_list  */
  YYSYMBOL_if_stmt = 113,                  /* if_stmt  */
  YYSYMBOL_for_stmt = 114,                 /* for_stmt  */
  YYSYMBOL_while_stmt = 115,               /* while_stmt  */
  YYSYMBOL_until_stmt = 116,               /* until_stmt  */
  YYSYMBOL_method_param = 117,             /* method_param  */
  YYSYMBOL_method_params_list = 118,       /* method_params_list  */
  YYSYMBOL_method_params_list_not_empty = 119, /* method_params_list_not_empty  */
  YYSYMBOL_def_method_stmt = 120,          /* def_method_stmt  */
  YYSYMBOL_expr_list = 121,                /* expr_list  */
  YYSYMBOL_expr_list_not_empty = 122,      /* expr_list_not_empty  */
  YYSYMBOL_class_declaration = 123,        /* class_declaration  */
  YYSYMBOL_def_method_list_op = 124,       /* def_method_list_op  */
  YYSYMBOL_def_method_list = 125           /* def_method_list  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if 1

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
#endif /* 1 */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  65
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1423

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  96
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  30
/* YYNRULES -- Number of rules.  */
#define YYNRULES  131
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  276

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   350


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
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
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   195,   195,   198,   199,   200,   203,   204,   207,   208,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
     261,   262,   263,   264,   265,   266,   269,   270,   271,   272,
     275,   276,   279,   280,   283,   284,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   302,
     303,   306,   307,   310,   313,   314,   315,   318,   319,   320,
     323,   324,   327,   328,   329,   330,   333,   334,   335,   336,
     339,   340,   343,   344,   347,   348,   351,   352,   355,   356,
     359,   360,   363,   364,   367,   368,   371,   372,   376,   377,
     380,   381
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "ALIAS_KEYWORD",
  "AND_KEYWORD", "BEGIN_KEYWORD", "BREAK_KEYWORD", "CASE_KEYWORD",
  "CLASS_KEYWORD", "DEF_KEYWORD", "DEFINED_KEYWORD", "DO_KEYWORD",
  "IF_KEYWORD", "ELSE_KEYWORD", "ELSIF_KEYWORD", "END_KEYWORD",
  "ENSURE_KEYWORD", "FALSE_KEYWORD", "FOR_KEYWORD", "IN_KEYWORD",
  "MODULE_KEYWORD", "NEXT_KEYWORD", "NIL_KEYWORD", "NOT_KEYWORD",
  "OR_KEYWORD", "REDO_KEYWORD", "RESCUE_KEYWORD", "RETRY_KEYWORD",
  "RETURN_KEYWORD", "SELF_KEYWORD", "SUPER_KEYWORD", "THEN_KEYWORD",
  "TRUE_KEYWORD", "UNDEF_KEYWORD", "UNLESS_KEYWORD", "UNTIL_KEYWORD",
  "WHEN_KEYWORD", "WHILE_KEYWORD", "YIELD_KEYWORD", "ARITHMETIC_PLUS_OP",
  "ARITHMETIC_MINUS_OP", "ARITHMETIC_MUL_OP", "ARITHMETIC_DIV_OP",
  "ARITHMETIC_MOD_OP", "ARITHMETIC_POW_OP", "EQL_OP", "NOT_EQL_OP",
  "GREATER_OP", "LESS_OP", "GREATER_OR_EQL_OP", "LESS_OR_EQL_OP",
  "COMB_COMPRASION_OP", "CASE_EQL_OP", "RECEIVER_EQL_OP", "OBJ_ID_EQL_OP",
  "ASSIGN_OP", "ADD_ASSIGN_OP", "SUB_ASSIGN_OP", "MUL_ASSIGN_OP",
  "DIV_ASSIGN_OP", "MOD_ASSIGN_OP", "POW_ASSIGN_OP", "BIN_AND_OP",
  "BIN_OR_OP", "BIN_XOR_OP", "BIN_ONES_COMPLEMENT_OP", "BIN_LEFT_SHIFT_OP",
  "BIN_RIGHT_SHIFT_OP", "LOGICAL_AND_OP", "LOGICAL_OR_OP",
  "LOGICAL_NOT_OP", "INCLUSIVE_RANGE_OP", "EXCLUSIVE_RANGE_OP",
  "OPEN_ROUND_BRACKET", "CLOSE_ROUND_BRACKET", "OPEN_CURLY_BRACKET",
  "CLOSE_CURLY_BRACKET", "OPEN_SQUARE_BRACKET", "CLOSE_SQUARE_BRACKET",
  "COMMERCIAL_AT", "QUESTION_SYMBOL", "DOT_SYMBOL", "COMMA_SYMBOL",
  "COLON_SYMBOL", "DOUBLE_COLON_SYMBOL", "SEMICOLON_SYMBOL",
  "NEW_LINE_SYMBOL", "STR", "INTEGER_NUMBER", "FLOAT_NUMBER",
  "VAR_METHOD_NAME", "INSTANCE_VAR_NAME", "CLASS_NAME", "CLASS_VAR_NAME",
  "UNARY_MINUS", "UNARY_PLUS", "$accept", "program", "program_item",
  "program_items_list_not_empty", "program_items_list", "expr",
  "stmt_ends", "new_lines_op", "new_lines", "stmt_ends_op", "stmt",
  "stmt_list_not_empty", "stmt_list", "stmt_block", "if_start_stmt",
  "elsif_stmt", "elsif_stmt_list", "if_stmt", "for_stmt", "while_stmt",
  "until_stmt", "method_param", "method_params_list",
  "method_params_list_not_empty", "def_method_stmt", "expr_list",
  "expr_list_not_empty", "class_declaration", "def_method_list_op",
  "def_method_list", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350
};
#endif

#define YYPACT_NINF (-99)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-73)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     259,   -67,   -87,   -69,   918,   918,   -99,    21,   -99,   918,
     891,   -58,   -99,   918,   918,   918,   918,   918,   918,   918,
     -57,   -99,   -99,   -99,   -40,   -99,    50,   -99,   259,   -99,
     628,   -99,   -67,    48,   -67,   -67,   -67,   -67,   -99,   -99,
     -67,   -67,   -99,   298,   -39,   -33,  1170,   694,    29,    36,
    1170,   628,   -99,    11,   355,   424,   -38,   -38,   -38,   -38,
     980,   -57,   918,   -99,   -57,   -99,   -99,   918,   918,   918,
     918,   918,   918,   918,   918,   918,   918,   918,   918,   918,
     918,   918,   918,   918,   918,   918,   918,   918,   918,   918,
     918,   918,   918,   918,   918,   918,   918,   918,   918,   918,
     918,   918,    17,   -99,   -99,   -67,   918,   -99,   -99,   102,
     -99,   -99,   -99,   -99,   -99,   -99,   -99,   298,    42,    27,
     100,    30,   298,   -27,    20,   298,    90,   918,   918,   -99,
      51,   -67,   298,   -67,   298,   -99,   -99,   826,    45,    46,
     918,  1170,  1170,  1127,  1127,   140,   140,   -38,   -38,   -38,
     -38,  1299,  1299,    92,    92,    92,    92,  1299,  1299,  1170,
    1170,  1170,  1170,  1170,  1170,  1170,   168,   212,   212,   300,
     300,  1342,  1256,  1213,  1213,  1029,    56,   298,   760,   -67,
     -99,   -99,   -99,   -99,   -67,   -99,   124,   100,    87,   -99,
      71,    68,   136,   121,   -99,   -67,   493,   562,   918,   298,
     138,   298,   142,   -99,   -99,   -57,    86,   -99,   918,   147,
     -27,   298,   133,   298,   100,   -67,   -99,   918,   -67,    30,
     -67,   -67,   298,   -67,   298,   -67,   298,    91,   151,   -99,
     152,   -99,   918,   -99,    96,   -99,   141,   -99,   -67,   156,
     160,   -99,  1078,   298,   -99,   -99,   298,   -99,   298,   161,
     298,   162,   -99,   -99,   -99,   826,   -99,   -67,   298,   -99,
     -67,   163,   -99,   164,   -99,   170,   -99,   -99,   298,   -99,
     -99,   -67,   -99,   -99,   -99,   -99
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       8,    74,     0,     0,     0,     0,    15,     0,    13,     0,
       0,     0,    14,     0,     0,     0,     0,     0,     0,     0,
      70,    12,    10,    11,    60,    61,     0,     6,     9,     2,
       0,     3,    77,     0,    79,    81,    83,    85,     4,     5,
      66,    67,    75,    91,     0,     0,    52,    70,     0,     0,
      53,     0,    88,     0,     0,     0,    18,    20,    17,    16,
       0,    72,   122,    71,    70,     1,     7,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    76,    78,    74,     0,   102,   100,     0,
      80,    82,    84,    86,    68,    69,    89,    92,     0,     0,
     128,   116,    91,    66,    67,    91,     0,     0,     0,    87,
      64,    74,    91,    74,    91,    56,    73,    70,     0,   123,
     122,    54,    55,    50,    51,    24,    25,    21,    22,    23,
      19,    36,    38,    31,    32,    33,    34,    35,    37,    43,
      47,    46,    48,    45,    44,    49,    28,    29,    30,    26,
      27,    39,    40,    41,    42,     0,    62,    91,    70,    74,
     104,   101,    90,    93,     0,   130,     0,   129,   114,   118,
       0,   117,     0,     0,    94,    74,     0,     0,   122,    91,
       0,    91,     0,   124,    58,    70,     0,    57,   122,     0,
      66,    91,     0,    91,   128,     0,   131,     0,    74,     0,
      74,    74,    91,    74,    91,    74,    91,     0,     0,   112,
       0,   110,     0,    59,     0,   103,     0,    97,    74,     0,
       0,   126,   115,    91,   119,   120,    91,    96,    91,     0,
      91,     0,    65,   113,   111,    70,    63,    74,    91,   105,
       0,     0,    95,     0,   106,     0,   107,   125,    91,    98,
     127,    74,   108,   109,    99,   121
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -99,   -99,   165,   -99,   -99,    -2,   -10,   -15,   -60,   -77,
      10,   -99,    15,   -99,   -99,    79,   -99,   -99,   -99,   -99,
     -99,   -30,   -99,   -99,   -84,   -98,   -99,   -99,   -23,   -99
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    26,    27,    28,    29,    30,    42,    62,    63,    43,
     116,   117,   118,    32,    33,   108,   109,    34,    35,    36,
      37,   189,   190,   191,    38,   138,   139,    39,   186,   187
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      52,   136,    46,    47,   -70,    44,    76,    50,    51,   119,
      31,    54,    55,    56,    57,    58,    59,    60,    40,    41,
     103,    45,   104,    53,   110,   111,   112,   113,   177,    61,
     114,   115,   126,    64,   120,   122,   185,   125,    31,   101,
     121,   129,   206,   102,   132,   134,    40,    41,   127,   140,
      65,   -72,    40,    41,   199,   128,   201,   183,    40,   124,
     137,   105,   106,   107,   136,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     227,   130,   213,   216,   178,    40,   124,   176,   193,     3,
     234,    48,    49,   114,   115,   179,   106,   180,   222,   184,
     188,   195,   203,   204,   198,   196,   197,   182,   205,   208,
     185,    71,    72,    73,    74,    75,    76,   192,   137,   215,
     194,   243,   217,   245,   246,   218,   248,   200,   250,   202,
     219,   220,   221,   229,    92,    93,    94,   231,    95,    96,
     233,   258,   235,   212,   238,   252,   253,   254,   211,   101,
     256,   259,   257,   102,   214,   260,   264,   266,   271,   272,
     268,    73,    74,    75,    76,   273,   224,   226,   181,   244,
     232,   240,   209,    66,   275,   236,   137,     0,     0,     0,
     114,     0,     0,     0,     0,   241,   137,    71,    72,    73,
      74,    75,    76,     0,   228,   242,   230,   101,     0,     0,
       0,   102,     0,     0,     0,     0,   237,     0,   239,     0,
     255,     0,     0,     0,    95,    96,     0,   247,     0,   249,
     267,   251,     0,     0,     0,   101,     0,     0,     0,   102,
     270,    71,    72,    73,    74,    75,    76,     0,   261,     0,
       0,   262,     0,   263,     1,   265,     0,     2,     3,     4,
       0,     5,     0,   269,    92,     0,     6,     7,    95,    96,
       0,     8,     9,   274,     0,     0,     0,    10,    11,   101,
       0,    12,     0,   102,    13,     0,    14,     0,    15,    16,
       0,     0,     0,     1,     0,     0,     0,     0,     4,     0,
       5,     0,     0,     0,     0,     6,     7,     0,     0,     0,
       8,     9,     0,     0,    17,     0,    10,    11,     0,    18,
      12,     0,    19,    13,     0,    14,    20,    15,    16,    71,
      72,    73,    74,    75,    76,     0,    21,    22,    23,    24,
      25,     0,     0,     0,     0,     0,     0,     0,     0,    67,
       0,     0,     0,    17,     0,     0,   131,     0,    18,     0,
       0,    19,     0,     0,     0,    20,     0,   101,     0,    68,
       0,   102,     0,     0,     0,    21,    22,    23,    24,    25,
      69,     0,    70,     0,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,     0,     0,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
       0,    95,    96,    97,    98,     0,    99,   100,    67,     0,
       0,     0,   101,     0,     0,   133,   102,     0,     0,     0,
      40,    41,     0,     0,     0,     0,     0,     0,    68,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    69,
       0,    70,     0,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,     0,     0,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,     0,
      95,    96,    97,    98,     0,    99,   100,    67,     0,     0,
       0,   101,     0,     0,   223,   102,     0,     0,     0,    40,
      41,     0,     0,     0,     0,     0,     0,    68,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    69,     0,
      70,     0,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,     0,     0,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,     0,    95,
      96,    97,    98,     0,    99,   100,    67,     0,     0,     0,
     101,     0,     0,   225,   102,     0,     0,     0,    40,    41,
       0,     0,     0,     0,     0,     0,    68,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    69,     0,    70,
       0,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,     0,     0,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,     0,    95,    96,
      97,    98,    67,    99,   100,     0,     0,     0,     0,   101,
       0,     0,     0,   102,     0,     0,     0,    40,    41,     0,
       0,     0,    68,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    69,     0,    70,     0,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,     0,     0,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,     0,    95,    96,    97,    98,    67,    99,
     100,     0,     0,     0,     0,   101,     0,     0,     0,   102,
       0,     0,     0,    40,    41,     0,     0,     0,    68,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    69,
       0,    70,     0,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,     0,     0,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,     0,
      95,    96,    97,    98,    67,    99,   100,     0,     0,     0,
       0,   101,     0,     0,     0,   102,     0,     0,     0,   123,
     124,     0,     0,     0,    68,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    69,     0,    70,     0,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,     0,     0,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,     0,    95,    96,    97,    98,
      67,    99,   100,     0,     0,     0,     0,   101,     0,     0,
       0,   102,     0,     0,     0,   210,   124,     0,     0,     0,
      68,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    69,     0,    70,     0,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,     0,
       0,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,     0,    95,    96,    97,    98,     0,    99,   100,     0,
       0,     4,     0,   101,     0,     0,     0,   102,     6,     0,
       0,     0,    61,     8,     9,     0,     0,     0,     0,     0,
      11,     0,     0,    12,     0,     0,     0,     0,     4,     0,
      15,    16,     0,     0,     0,     6,     0,     0,     0,     0,
       8,     9,     0,     0,     0,     0,     0,    11,     0,     0,
      12,     0,     0,     0,     0,     0,    17,    15,    16,     0,
       0,    18,     0,     0,    19,     0,     0,     0,    20,     0,
       0,     0,     0,     0,     0,     0,    40,    41,    21,    22,
      23,    24,    25,    17,    67,     0,     0,     0,    18,     0,
       0,    19,     0,     0,     0,    20,     0,     0,     0,     0,
       0,     0,     0,     0,    68,    21,    22,    23,    24,    25,
       0,     0,     0,     0,     0,    69,     0,    70,     0,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    67,     0,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,     0,    95,    96,    97,    98,
       0,    99,   100,    68,   135,     0,     0,   101,     0,     0,
       0,   102,     0,     0,    69,     0,    70,     0,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    67,     0,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,     0,    95,    96,    97,    98,     0,
      99,   100,    68,     0,     0,     0,   101,   207,     0,     0,
     102,     0,     0,    69,     0,    70,     0,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    67,     0,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,     0,    95,    96,    97,    98,     0,    99,
     100,    68,     0,     0,     0,   101,     0,     0,     0,   102,
       0,     0,     0,     0,     0,     0,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
       0,     0,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,     0,    95,    96,    97,    98,     0,    99,   100,
       0,     0,     0,     0,   101,     0,     0,     0,   102,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,     0,     0,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,     0,    95,    96,    97,    98,
       0,    99,   100,     0,     0,     0,     0,   101,     0,     0,
       0,   102,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    92,    93,    94,     0,    95,
      96,    97,    98,     0,   -73,   -73,     0,     0,     0,     0,
     101,     0,     0,     0,   102,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    92,    93,
      94,     0,    95,    96,    97,     0,     0,     0,     0,     0,
       0,     0,     0,   101,     0,     0,     0,   102,    71,    72,
      73,    74,    75,    76,   -73,   -73,    79,    80,    81,    82,
     -73,   -73,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    92,    93,    94,     0,    95,    96,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   101,     0,     0,     0,
     102,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    92,    93,    94,     0,    95,    96,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   101,
       0,     0,     0,   102
};

static const yytype_int16 yycheck[] =
{
      10,    61,     4,     5,    31,    92,    44,     9,    10,    48,
       0,    13,    14,    15,    16,    17,    18,    19,    85,    86,
      30,    90,    32,    81,    34,    35,    36,    37,   105,    86,
      40,    41,    47,    73,    44,    45,   120,    47,    28,    77,
      73,    51,   140,    81,    54,    55,    85,    86,    19,    64,
       0,    31,    85,    86,   131,    19,   133,    15,    85,    86,
      62,    13,    14,    15,   124,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     198,    90,   179,   187,   106,    85,    86,    90,   123,     9,
     208,    90,    91,   123,   124,    13,    14,    15,   195,    92,
      90,    31,   137,    78,    73,   127,   128,   117,    82,    73,
     214,    39,    40,    41,    42,    43,    44,   122,   140,    15,
     125,   218,    55,   220,   221,    74,   223,   132,   225,   134,
      82,    15,    31,    15,    62,    63,    64,    15,    66,    67,
      74,   238,    15,   178,    31,    74,    15,    15,   178,    77,
      74,    15,    31,    81,   184,    15,    15,    15,    15,    15,
     257,    41,    42,    43,    44,    15,   196,   197,   109,   219,
     205,   214,   177,    28,   271,   210,   198,    -1,    -1,    -1,
     210,    -1,    -1,    -1,    -1,   215,   208,    39,    40,    41,
      42,    43,    44,    -1,   199,   217,   201,    77,    -1,    -1,
      -1,    81,    -1,    -1,    -1,    -1,   211,    -1,   213,    -1,
     232,    -1,    -1,    -1,    66,    67,    -1,   222,    -1,   224,
     255,   226,    -1,    -1,    -1,    77,    -1,    -1,    -1,    81,
     260,    39,    40,    41,    42,    43,    44,    -1,   243,    -1,
      -1,   246,    -1,   248,     5,   250,    -1,     8,     9,    10,
      -1,    12,    -1,   258,    62,    -1,    17,    18,    66,    67,
      -1,    22,    23,   268,    -1,    -1,    -1,    28,    29,    77,
      -1,    32,    -1,    81,    35,    -1,    37,    -1,    39,    40,
      -1,    -1,    -1,     5,    -1,    -1,    -1,    -1,    10,    -1,
      12,    -1,    -1,    -1,    -1,    17,    18,    -1,    -1,    -1,
      22,    23,    -1,    -1,    65,    -1,    28,    29,    -1,    70,
      32,    -1,    73,    35,    -1,    37,    77,    39,    40,    39,
      40,    41,    42,    43,    44,    -1,    87,    88,    89,    90,
      91,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     4,
      -1,    -1,    -1,    65,    -1,    -1,    11,    -1,    70,    -1,
      -1,    73,    -1,    -1,    -1,    77,    -1,    77,    -1,    24,
      -1,    81,    -1,    -1,    -1,    87,    88,    89,    90,    91,
      35,    -1,    37,    -1,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    -1,    -1,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      -1,    66,    67,    68,    69,    -1,    71,    72,     4,    -1,
      -1,    -1,    77,    -1,    -1,    11,    81,    -1,    -1,    -1,
      85,    86,    -1,    -1,    -1,    -1,    -1,    -1,    24,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    35,
      -1,    37,    -1,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    -1,    -1,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    -1,
      66,    67,    68,    69,    -1,    71,    72,     4,    -1,    -1,
      -1,    77,    -1,    -1,    11,    81,    -1,    -1,    -1,    85,
      86,    -1,    -1,    -1,    -1,    -1,    -1,    24,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    35,    -1,
      37,    -1,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    -1,    -1,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    -1,    66,
      67,    68,    69,    -1,    71,    72,     4,    -1,    -1,    -1,
      77,    -1,    -1,    11,    81,    -1,    -1,    -1,    85,    86,
      -1,    -1,    -1,    -1,    -1,    -1,    24,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    35,    -1,    37,
      -1,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    -1,    -1,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    -1,    66,    67,
      68,    69,     4,    71,    72,    -1,    -1,    -1,    -1,    77,
      -1,    -1,    -1,    81,    -1,    -1,    -1,    85,    86,    -1,
      -1,    -1,    24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    35,    -1,    37,    -1,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    -1,    -1,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    -1,    66,    67,    68,    69,     4,    71,
      72,    -1,    -1,    -1,    -1,    77,    -1,    -1,    -1,    81,
      -1,    -1,    -1,    85,    86,    -1,    -1,    -1,    24,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    35,
      -1,    37,    -1,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    -1,    -1,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    -1,
      66,    67,    68,    69,     4,    71,    72,    -1,    -1,    -1,
      -1,    77,    -1,    -1,    -1,    81,    -1,    -1,    -1,    85,
      86,    -1,    -1,    -1,    24,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    35,    -1,    37,    -1,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    -1,    -1,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    -1,    66,    67,    68,    69,
       4,    71,    72,    -1,    -1,    -1,    -1,    77,    -1,    -1,
      -1,    81,    -1,    -1,    -1,    85,    86,    -1,    -1,    -1,
      24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    35,    -1,    37,    -1,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    -1,
      -1,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    -1,    66,    67,    68,    69,    -1,    71,    72,    -1,
      -1,    10,    -1,    77,    -1,    -1,    -1,    81,    17,    -1,
      -1,    -1,    86,    22,    23,    -1,    -1,    -1,    -1,    -1,
      29,    -1,    -1,    32,    -1,    -1,    -1,    -1,    10,    -1,
      39,    40,    -1,    -1,    -1,    17,    -1,    -1,    -1,    -1,
      22,    23,    -1,    -1,    -1,    -1,    -1,    29,    -1,    -1,
      32,    -1,    -1,    -1,    -1,    -1,    65,    39,    40,    -1,
      -1,    70,    -1,    -1,    73,    -1,    -1,    -1,    77,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    85,    86,    87,    88,
      89,    90,    91,    65,     4,    -1,    -1,    -1,    70,    -1,
      -1,    73,    -1,    -1,    -1,    77,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    24,    87,    88,    89,    90,    91,
      -1,    -1,    -1,    -1,    -1,    35,    -1,    37,    -1,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,     4,    -1,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    -1,    66,    67,    68,    69,
      -1,    71,    72,    24,    74,    -1,    -1,    77,    -1,    -1,
      -1,    81,    -1,    -1,    35,    -1,    37,    -1,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,     4,    -1,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    -1,    66,    67,    68,    69,    -1,
      71,    72,    24,    -1,    -1,    -1,    77,    78,    -1,    -1,
      81,    -1,    -1,    35,    -1,    37,    -1,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,     4,    -1,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    -1,    66,    67,    68,    69,    -1,    71,
      72,    24,    -1,    -1,    -1,    77,    -1,    -1,    -1,    81,
      -1,    -1,    -1,    -1,    -1,    -1,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      -1,    -1,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    -1,    66,    67,    68,    69,    -1,    71,    72,
      -1,    -1,    -1,    -1,    77,    -1,    -1,    -1,    81,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    -1,    -1,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    -1,    66,    67,    68,    69,
      -1,    71,    72,    -1,    -1,    -1,    -1,    77,    -1,    -1,
      -1,    81,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    62,    63,    64,    -1,    66,
      67,    68,    69,    -1,    71,    72,    -1,    -1,    -1,    -1,
      77,    -1,    -1,    -1,    81,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    62,    63,
      64,    -1,    66,    67,    68,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    77,    -1,    -1,    -1,    81,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    62,    63,    64,    -1,    66,    67,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    77,    -1,    -1,    -1,
      81,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    62,    63,    64,    -1,    66,    67,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    77,
      -1,    -1,    -1,    81
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     5,     8,     9,    10,    12,    17,    18,    22,    23,
      28,    29,    32,    35,    37,    39,    40,    65,    70,    73,
      77,    87,    88,    89,    90,    91,    97,    98,    99,   100,
     101,   106,   109,   110,   113,   114,   115,   116,   120,   123,
      85,    86,   102,   105,    92,    90,   101,   101,    90,    91,
     101,   101,   102,    81,   101,   101,   101,   101,   101,   101,
     101,    86,   103,   104,    73,     0,    98,     4,    24,    35,
      37,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    66,    67,    68,    69,    71,
      72,    77,    81,   102,   102,    13,    14,    15,   111,   112,
     102,   102,   102,   102,   102,   102,   106,   107,   108,    48,
     102,    73,   102,    85,    86,   102,   103,    19,    19,   102,
      90,    11,   102,    11,   102,    74,   104,   101,   121,   122,
     103,   101,   101,   101,   101,   101,   101,   101,   101,   101,
     101,   101,   101,   101,   101,   101,   101,   101,   101,   101,
     101,   101,   101,   101,   101,   101,   101,   101,   101,   101,
     101,   101,   101,   101,   101,   101,    90,   105,   101,    13,
      15,   111,   106,    15,    92,   120,   124,   125,    90,   117,
     118,   119,   108,   103,   108,    31,   101,   101,    73,   105,
     108,   105,   108,   103,    78,    82,   121,    78,    73,   108,
      85,   102,   103,   105,   102,    15,   120,    55,    74,    82,
      15,    31,   105,    11,   102,    11,   102,   121,   108,    15,
     108,    15,   103,    74,   121,    15,   103,   108,    31,   108,
     124,   102,   101,   105,   117,   105,   105,   108,   105,   108,
     105,   108,    74,    15,    15,   101,    74,    31,   105,    15,
      15,   108,   108,   108,    15,   108,    15,   103,   105,   108,
     102,    15,    15,    15,   108,   105
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    96,    97,    98,    98,    98,    99,    99,   100,   100,
     101,   101,   101,   101,   101,   101,   101,   101,   101,   101,
     101,   101,   101,   101,   101,   101,   101,   101,   101,   101,
     101,   101,   101,   101,   101,   101,   101,   101,   101,   101,
     101,   101,   101,   101,   101,   101,   101,   101,   101,   101,
     101,   101,   101,   101,   101,   101,   101,   101,   101,   101,
     101,   101,   101,   101,   101,   101,   102,   102,   102,   102,
     103,   103,   104,   104,   105,   105,   106,   106,   106,   106,
     106,   106,   106,   106,   106,   106,   106,   106,   106,   107,
     107,   108,   108,   109,   110,   110,   110,   111,   111,   111,
     112,   112,   113,   113,   113,   113,   114,   114,   114,   114,
     115,   115,   116,   116,   117,   117,   118,   118,   119,   119,
     120,   120,   121,   121,   122,   122,   123,   123,   124,   124,
     125,   125
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     1,     2,     0,     1,
       1,     1,     1,     1,     1,     1,     2,     2,     2,     3,
       2,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     2,     2,     3,     3,     3,     4,     4,     5,
       1,     1,     3,     6,     3,     6,     1,     1,     2,     2,
       0,     1,     1,     2,     0,     1,     2,     1,     2,     1,
       2,     1,     2,     1,     2,     1,     2,     3,     2,     1,
       2,     0,     1,     4,     4,     7,     6,     4,     6,     7,
       1,     2,     2,     5,     3,     6,     7,     7,     8,     8,
       5,     6,     5,     6,     1,     3,     0,     1,     1,     3,
       6,     9,     0,     1,     2,     5,     6,     8,     0,     1,
       1,     2
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
# ifndef YY_LOCATION_PRINT
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yykind < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yykind], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


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
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
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


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* program: program_items_list  */
#line 195 "Grammar.y"
                             { root=create_program_struct((yyvsp[0].program_item_list_un)); puts("program"); }
#line 1910 "Grammar.tab.c"
    break;

  case 3: /* program_item: stmt  */
#line 198 "Grammar.y"
                    { (yyval.program_item_un)=create_stmt_program_item((yyvsp[0].stmt_un)); puts("program item stmt list"); }
#line 1916 "Grammar.tab.c"
    break;

  case 4: /* program_item: def_method_stmt  */
#line 199 "Grammar.y"
                      { (yyval.program_item_un)=create_def_method_program_item((yyvsp[0].def_method_un));  puts("def method"); }
#line 1922 "Grammar.tab.c"
    break;

  case 5: /* program_item: class_declaration  */
#line 200 "Grammar.y"
                        { (yyval.program_item_un)=(yyvsp[0].program_item_un); puts("program item from class declaration"); }
#line 1928 "Grammar.tab.c"
    break;

  case 6: /* program_items_list_not_empty: program_item  */
#line 203 "Grammar.y"
                                                   { (yyval.program_item_list_un)=create_program_item_list((yyvsp[0].program_item_un)); puts("program items from one prorgram item"); }
#line 1934 "Grammar.tab.c"
    break;

  case 7: /* program_items_list_not_empty: program_items_list_not_empty program_item  */
#line 204 "Grammar.y"
                                                  { (yyval.program_item_list_un)=add_to_program_item_list((yyvsp[-1].program_item_list_un), (yyvsp[0].program_item_un)); puts("add item to program items"); }
#line 1940 "Grammar.tab.c"
    break;

  case 8: /* program_items_list: %empty  */
#line 207 "Grammar.y"
                                    { (yyval.program_item_list_un)=0; puts("empty program items");}
#line 1946 "Grammar.tab.c"
    break;

  case 9: /* program_items_list: program_items_list_not_empty  */
#line 208 "Grammar.y"
                                    { (yyval.program_item_list_un)=(yyvsp[0].program_item_list_un); puts("program items from not empty program items");}
#line 1952 "Grammar.tab.c"
    break;

  case 10: /* expr: INTEGER_NUMBER  */
#line 211 "Grammar.y"
                     { (yyval.expr_un)=create_const_integer_expr(Integer, (yyvsp[0].int_un)); /* puts("integer"); */ }
#line 1958 "Grammar.tab.c"
    break;

  case 11: /* expr: FLOAT_NUMBER  */
#line 212 "Grammar.y"
                   { (yyval.expr_un)=create_const_float_expr((yyvsp[0].float_un)); /* puts("float"); */}
#line 1964 "Grammar.tab.c"
    break;

  case 12: /* expr: STR  */
#line 213 "Grammar.y"
          { (yyval.expr_un)=create_const_string_expr(String, (yyvsp[0].string_un)); puts("string"); }
#line 1970 "Grammar.tab.c"
    break;

  case 13: /* expr: NIL_KEYWORD  */
#line 214 "Grammar.y"
                  { puts("nil"); }
#line 1976 "Grammar.tab.c"
    break;

  case 14: /* expr: TRUE_KEYWORD  */
#line 215 "Grammar.y"
                   { (yyval.expr_un)=create_const_integer_expr(Boolean, 1); /* puts("true"); */ }
#line 1982 "Grammar.tab.c"
    break;

  case 15: /* expr: FALSE_KEYWORD  */
#line 216 "Grammar.y"
                    { (yyval.expr_un)=create_const_integer_expr(Boolean, 0); /* puts("false"); */ }
#line 1988 "Grammar.tab.c"
    break;

  case 16: /* expr: LOGICAL_NOT_OP expr  */
#line 217 "Grammar.y"
                          { (yyval.expr_un)=create_op_expr(logical_not, (yyvsp[0].expr_un), 0); /* puts("LOGICAL_NOT_OP"); */ }
#line 1994 "Grammar.tab.c"
    break;

  case 17: /* expr: BIN_ONES_COMPLEMENT_OP expr  */
#line 218 "Grammar.y"
                                  { (yyval.expr_un)=create_op_expr(bin_ones_complement, (yyvsp[0].expr_un), 0); /* puts("BIN_ONES_COMPLEMENT_OP"); */ }
#line 2000 "Grammar.tab.c"
    break;

  case 18: /* expr: ARITHMETIC_PLUS_OP expr  */
#line 219 "Grammar.y"
                                               { (yyval.expr_un)=create_op_expr(unary_plus, (yyvsp[0].expr_un), 0); /* puts("unary plus"); */ }
#line 2006 "Grammar.tab.c"
    break;

  case 19: /* expr: expr ARITHMETIC_POW_OP expr  */
#line 220 "Grammar.y"
                                  {  (yyval.expr_un)=create_op_expr(pow_, (yyvsp[-2].expr_un), (yyvsp[0].expr_un)); /*  puts("pow"); */ }
#line 2012 "Grammar.tab.c"
    break;

  case 20: /* expr: ARITHMETIC_MINUS_OP expr  */
#line 221 "Grammar.y"
                                                 { (yyval.expr_un)=create_op_expr(unary_minus, (yyvsp[0].expr_un), 0); /*  puts("unary minus"); */ }
#line 2018 "Grammar.tab.c"
    break;

  case 21: /* expr: expr ARITHMETIC_MUL_OP expr  */
#line 222 "Grammar.y"
                                  { (yyval.expr_un)=create_op_expr(mul, (yyvsp[-2].expr_un), (yyvsp[0].expr_un)); /* puts("mul"); */ }
#line 2024 "Grammar.tab.c"
    break;

  case 22: /* expr: expr ARITHMETIC_DIV_OP expr  */
#line 223 "Grammar.y"
                                  {  (yyval.expr_un)=create_op_expr(div_, (yyvsp[-2].expr_un), (yyvsp[0].expr_un)); /* puts("div"); */ }
#line 2030 "Grammar.tab.c"
    break;

  case 23: /* expr: expr ARITHMETIC_MOD_OP expr  */
#line 224 "Grammar.y"
                                  {  (yyval.expr_un)=create_op_expr(mod, (yyvsp[-2].expr_un), (yyvsp[0].expr_un)); /* puts("mod"); */ }
#line 2036 "Grammar.tab.c"
    break;

  case 24: /* expr: expr ARITHMETIC_PLUS_OP expr  */
#line 225 "Grammar.y"
                                   {  (yyval.expr_un)=create_op_expr(plus, (yyvsp[-2].expr_un), (yyvsp[0].expr_un)); /* puts("plus"); */ }
#line 2042 "Grammar.tab.c"
    break;

  case 25: /* expr: expr ARITHMETIC_MINUS_OP expr  */
#line 226 "Grammar.y"
                                    { (yyval.expr_un)=create_op_expr(minus, (yyvsp[-2].expr_un), (yyvsp[0].expr_un)); /* puts("minus"); */ }
#line 2048 "Grammar.tab.c"
    break;

  case 26: /* expr: expr BIN_LEFT_SHIFT_OP expr  */
#line 227 "Grammar.y"
                                  { (yyval.expr_un)=create_op_expr(bin_left_shift, (yyvsp[-2].expr_un), (yyvsp[0].expr_un)); /* puts("left shift"); */ }
#line 2054 "Grammar.tab.c"
    break;

  case 27: /* expr: expr BIN_RIGHT_SHIFT_OP expr  */
#line 228 "Grammar.y"
                                   { (yyval.expr_un)=create_op_expr(bin_right_shift, (yyvsp[-2].expr_un), (yyvsp[0].expr_un)); /* puts("right shift"); */ }
#line 2060 "Grammar.tab.c"
    break;

  case 28: /* expr: expr BIN_AND_OP expr  */
#line 229 "Grammar.y"
                           { (yyval.expr_un)=create_op_expr(bin_and_op, (yyvsp[-2].expr_un), (yyvsp[0].expr_un)); /* puts("bin and"); */ }
#line 2066 "Grammar.tab.c"
    break;

  case 29: /* expr: expr BIN_OR_OP expr  */
#line 230 "Grammar.y"
                          { (yyval.expr_un)=create_op_expr(bin_or_op, (yyvsp[-2].expr_un), (yyvsp[0].expr_un)); /* puts("bin or"); */ }
#line 2072 "Grammar.tab.c"
    break;

  case 30: /* expr: expr BIN_XOR_OP expr  */
#line 231 "Grammar.y"
                           { (yyval.expr_un)=create_op_expr(bin_xor_op, (yyvsp[-2].expr_un), (yyvsp[0].expr_un)); /* puts("bin xor"); */ }
#line 2078 "Grammar.tab.c"
    break;

  case 31: /* expr: expr GREATER_OP expr  */
#line 232 "Grammar.y"
                           { (yyval.expr_un)=create_op_expr(greater, (yyvsp[-2].expr_un), (yyvsp[0].expr_un)); /* puts(" > "); */ }
#line 2084 "Grammar.tab.c"
    break;

  case 32: /* expr: expr LESS_OP expr  */
#line 233 "Grammar.y"
                        { (yyval.expr_un)=create_op_expr(less, (yyvsp[-2].expr_un), (yyvsp[0].expr_un)); /* puts(" < "); */ }
#line 2090 "Grammar.tab.c"
    break;

  case 33: /* expr: expr GREATER_OR_EQL_OP expr  */
#line 234 "Grammar.y"
                                  { (yyval.expr_un)=create_op_expr(greater_eql, (yyvsp[-2].expr_un), (yyvsp[0].expr_un)); /* puts(" >= "); */ }
#line 2096 "Grammar.tab.c"
    break;

  case 34: /* expr: expr LESS_OR_EQL_OP expr  */
#line 235 "Grammar.y"
                               { (yyval.expr_un)=create_op_expr(less_eql, (yyvsp[-2].expr_un), (yyvsp[0].expr_un)); /* puts(" <= "); */ }
#line 2102 "Grammar.tab.c"
    break;

  case 35: /* expr: expr COMB_COMPRASION_OP expr  */
#line 236 "Grammar.y"
                                   { (yyval.expr_un)=create_op_expr(comb_comprassion, (yyvsp[-2].expr_un), (yyvsp[0].expr_un)); /* puts(" COMB_COMPRASION_OP "); */ }
#line 2108 "Grammar.tab.c"
    break;

  case 36: /* expr: expr EQL_OP expr  */
#line 237 "Grammar.y"
                       { (yyval.expr_un)=create_op_expr(equal, (yyvsp[-2].expr_un), (yyvsp[0].expr_un)); /* puts(" EQL_OP "); */ }
#line 2114 "Grammar.tab.c"
    break;

  case 37: /* expr: expr CASE_EQL_OP expr  */
#line 238 "Grammar.y"
                            {  (yyval.expr_un)=create_op_expr(case_equal, (yyvsp[-2].expr_un), (yyvsp[0].expr_un)); /* puts(" CASE_EQL_OP "); */ }
#line 2120 "Grammar.tab.c"
    break;

  case 38: /* expr: expr NOT_EQL_OP expr  */
#line 239 "Grammar.y"
                           { (yyval.expr_un)=create_op_expr(not_equal, (yyvsp[-2].expr_un), (yyvsp[0].expr_un)); /* puts("NOT_EQL_OP"); */ }
#line 2126 "Grammar.tab.c"
    break;

  case 39: /* expr: expr LOGICAL_AND_OP expr  */
#line 240 "Grammar.y"
                               { (yyval.expr_un)=create_op_expr(logical_and, (yyvsp[-2].expr_un), (yyvsp[0].expr_un)); /* puts("LOGICAL_AND_OP"); */ }
#line 2132 "Grammar.tab.c"
    break;

  case 40: /* expr: expr LOGICAL_OR_OP expr  */
#line 241 "Grammar.y"
                              { (yyval.expr_un)=create_op_expr(logical_or, (yyvsp[-2].expr_un), (yyvsp[0].expr_un)); /* puts("LOGICAL_OR_OP");  */ }
#line 2138 "Grammar.tab.c"
    break;

  case 41: /* expr: expr INCLUSIVE_RANGE_OP expr  */
#line 242 "Grammar.y"
                                   { (yyval.expr_un)=create_op_expr(inclusive_range, (yyvsp[-2].expr_un), (yyvsp[0].expr_un)); /* puts("INCLUSIVE_RANGE_OP"); */ }
#line 2144 "Grammar.tab.c"
    break;

  case 42: /* expr: expr EXCLUSIVE_RANGE_OP expr  */
#line 243 "Grammar.y"
                                   { (yyval.expr_un)=create_op_expr(exclusive_range, (yyvsp[-2].expr_un), (yyvsp[0].expr_un)); /* puts("EXCLUSIVE_RANGE_OP"); */ }
#line 2150 "Grammar.tab.c"
    break;

  case 43: /* expr: expr ASSIGN_OP expr  */
#line 244 "Grammar.y"
                          { (yyval.expr_un)=create_op_expr(assign, (yyvsp[-2].expr_un), (yyvsp[0].expr_un)); /* puts("assign"); */ }
#line 2156 "Grammar.tab.c"
    break;

  case 44: /* expr: expr MOD_ASSIGN_OP expr  */
#line 245 "Grammar.y"
                              { (yyval.expr_un)=create_op_expr(mod_assign, (yyvsp[-2].expr_un), (yyvsp[0].expr_un)); /* puts("MOD_ASSIGN_OP"); */ }
#line 2162 "Grammar.tab.c"
    break;

  case 45: /* expr: expr DIV_ASSIGN_OP expr  */
#line 246 "Grammar.y"
                              { (yyval.expr_un)=create_op_expr(div_assign, (yyvsp[-2].expr_un), (yyvsp[0].expr_un)); /* puts("DIV_ASSIGN_OP"); */ }
#line 2168 "Grammar.tab.c"
    break;

  case 46: /* expr: expr SUB_ASSIGN_OP expr  */
#line 247 "Grammar.y"
                              { (yyval.expr_un)=create_op_expr(sub_assign, (yyvsp[-2].expr_un), (yyvsp[0].expr_un)); /* puts("SUB_ASSIGN_OP"); */ }
#line 2174 "Grammar.tab.c"
    break;

  case 47: /* expr: expr ADD_ASSIGN_OP expr  */
#line 248 "Grammar.y"
                              { (yyval.expr_un)=create_op_expr(add_assign, (yyvsp[-2].expr_un), (yyvsp[0].expr_un)); /* puts("SUB_ASSIGN_OP"); */ }
#line 2180 "Grammar.tab.c"
    break;

  case 48: /* expr: expr MUL_ASSIGN_OP expr  */
#line 249 "Grammar.y"
                              { (yyval.expr_un)=create_op_expr(mul_assign, (yyvsp[-2].expr_un), (yyvsp[0].expr_un)); /* puts("MUL_ASSIGN_OP"); */ }
#line 2186 "Grammar.tab.c"
    break;

  case 49: /* expr: expr POW_ASSIGN_OP expr  */
#line 250 "Grammar.y"
                              { (yyval.expr_un)=create_op_expr(pow_assign, (yyvsp[-2].expr_un), (yyvsp[0].expr_un)); /* puts("POW_ASSIGN_OP"); */ }
#line 2192 "Grammar.tab.c"
    break;

  case 50: /* expr: expr UNTIL_KEYWORD expr  */
#line 251 "Grammar.y"
                              { (yyval.expr_un)=create_op_expr(until_op, (yyvsp[-2].expr_un), (yyvsp[0].expr_un)); }
#line 2198 "Grammar.tab.c"
    break;

  case 51: /* expr: expr WHILE_KEYWORD expr  */
#line 252 "Grammar.y"
                              { (yyval.expr_un)=create_op_expr(while_op, (yyvsp[-2].expr_un), (yyvsp[0].expr_un)); }
#line 2204 "Grammar.tab.c"
    break;

  case 52: /* expr: DEFINED_KEYWORD expr  */
#line 253 "Grammar.y"
                           { (yyval.expr_un)=create_op_expr(defined, (yyvsp[0].expr_un), 0); /* puts("DEFINED_KEYWORD"); */ }
#line 2210 "Grammar.tab.c"
    break;

  case 53: /* expr: NOT_KEYWORD expr  */
#line 254 "Grammar.y"
                       { (yyval.expr_un)=create_op_expr(not_keyword, (yyvsp[0].expr_un), 0); /* puts("NOT_KEYWORD");  */ }
#line 2216 "Grammar.tab.c"
    break;

  case 54: /* expr: expr AND_KEYWORD expr  */
#line 255 "Grammar.y"
                            { (yyval.expr_un)=create_op_expr(and_keyword, (yyvsp[-2].expr_un), (yyvsp[0].expr_un)); /* puts("AND_KEYWORD"); */ }
#line 2222 "Grammar.tab.c"
    break;

  case 55: /* expr: expr OR_KEYWORD expr  */
#line 256 "Grammar.y"
                           { (yyval.expr_un)=create_op_expr(or_keyword, (yyvsp[-2].expr_un), (yyvsp[0].expr_un)); /* puts("OR_KEYWORD"); */ }
#line 2228 "Grammar.tab.c"
    break;

  case 56: /* expr: OPEN_ROUND_BRACKET expr CLOSE_ROUND_BRACKET  */
#line 257 "Grammar.y"
                                                  { (yyval.expr_un)=(yyvsp[-1].expr_un); /* puts(" expr in round brackets "); */ }
#line 2234 "Grammar.tab.c"
    break;

  case 57: /* expr: expr OPEN_SQUARE_BRACKET expr CLOSE_SQUARE_BRACKET  */
#line 258 "Grammar.y"
                                                             { (yyval.expr_un)=create_op_expr(member_access, (yyvsp[-3].expr_un), (yyvsp[-1].expr_un)); puts(" expr in square brackets "); }
#line 2240 "Grammar.tab.c"
    break;

  case 58: /* expr: OPEN_SQUARE_BRACKET new_lines_op expr_list CLOSE_SQUARE_BRACKET  */
#line 259 "Grammar.y"
                                                                      { (yyval.expr_un)=create_array_struct((yyvsp[-1].expr_list_un));puts(" expr list"); }
#line 2246 "Grammar.tab.c"
    break;

  case 59: /* expr: VAR_METHOD_NAME OPEN_ROUND_BRACKET new_lines_op expr_list CLOSE_ROUND_BRACKET  */
#line 260 "Grammar.y"
                                                                                    { (yyval.expr_un)=create_method_call_expr((yyvsp[-4].var_name_un), (yyvsp[-1].expr_list_un)); puts("method call");}
#line 2252 "Grammar.tab.c"
    break;

  case 60: /* expr: VAR_METHOD_NAME  */
#line 261 "Grammar.y"
                      { (yyval.expr_un)=create_const_string_expr(var_or_method, (yyvsp[0].var_name_un)); /* puts("var"); */ }
#line 2258 "Grammar.tab.c"
    break;

  case 61: /* expr: INSTANCE_VAR_NAME  */
#line 262 "Grammar.y"
                        { (yyval.expr_un)=create_const_string_expr(instance_var, (yyvsp[0].instance_var_name_un)); /* puts("instance var"); */ }
#line 2264 "Grammar.tab.c"
    break;

  case 62: /* expr: expr DOT_SYMBOL VAR_METHOD_NAME  */
#line 263 "Grammar.y"
                                      { (yyval.expr_un)=create_field_call_expr((yyvsp[-2].expr_un), (yyvsp[0].var_name_un)); puts("object field call"); }
#line 2270 "Grammar.tab.c"
    break;

  case 63: /* expr: expr DOT_SYMBOL VAR_METHOD_NAME OPEN_ROUND_BRACKET expr_list CLOSE_ROUND_BRACKET  */
#line 264 "Grammar.y"
                                                                                       { (yyval.expr_un)=create_object_method_call_expr((yyvsp[-5].expr_un), (yyvsp[-3].var_name_un), (yyvsp[-1].expr_list_un)); puts("object method call"); }
#line 2276 "Grammar.tab.c"
    break;

  case 64: /* expr: SELF_KEYWORD DOT_SYMBOL VAR_METHOD_NAME  */
#line 265 "Grammar.y"
                                              { (yyval.expr_un)=create_self_field_call_expr((yyvsp[0].var_name_un)); puts("678"); }
#line 2282 "Grammar.tab.c"
    break;

  case 65: /* expr: SELF_KEYWORD DOT_SYMBOL VAR_METHOD_NAME OPEN_ROUND_BRACKET expr_list CLOSE_ROUND_BRACKET  */
#line 266 "Grammar.y"
                                                                                               { (yyval.expr_un)=create_self_method_call_expr((yyvsp[-3].var_name_un), (yyvsp[-1].expr_list_un)); puts("910"); }
#line 2288 "Grammar.tab.c"
    break;

  case 76: /* stmt: expr stmt_ends  */
#line 287 "Grammar.y"
                     { (yyval.stmt_un)=create_expr_stmt((yyvsp[-1].expr_un)); puts("stmt"); }
#line 2294 "Grammar.tab.c"
    break;

  case 77: /* stmt: stmt_block  */
#line 288 "Grammar.y"
                    { (yyval.stmt_un)=create_block_stmt((yyvsp[0].block_un)); puts("stmt block"); }
#line 2300 "Grammar.tab.c"
    break;

  case 78: /* stmt: stmt_block stmt_ends  */
#line 289 "Grammar.y"
                           { (yyval.stmt_un)=create_block_stmt((yyvsp[-1].block_un)); }
#line 2306 "Grammar.tab.c"
    break;

  case 79: /* stmt: if_stmt  */
#line 290 "Grammar.y"
                    { (yyval.stmt_un)=(yyvsp[0].stmt_un); puts("if stmt"); }
#line 2312 "Grammar.tab.c"
    break;

  case 80: /* stmt: if_stmt stmt_ends  */
#line 291 "Grammar.y"
                           { (yyval.stmt_un)=(yyvsp[-1].stmt_un); puts("if stmt"); }
#line 2318 "Grammar.tab.c"
    break;

  case 81: /* stmt: for_stmt  */
#line 292 "Grammar.y"
                     { (yyval.stmt_un)=(yyvsp[0].stmt_un); puts("for stmt"); }
#line 2324 "Grammar.tab.c"
    break;

  case 82: /* stmt: for_stmt stmt_ends  */
#line 293 "Grammar.y"
                         { (yyval.stmt_un)=(yyvsp[-1].stmt_un); puts("for stmt with ends"); }
#line 2330 "Grammar.tab.c"
    break;

  case 83: /* stmt: while_stmt  */
#line 294 "Grammar.y"
                         { (yyval.stmt_un)=(yyvsp[0].stmt_un); puts("while stmt"); }
#line 2336 "Grammar.tab.c"
    break;

  case 84: /* stmt: while_stmt stmt_ends  */
#line 295 "Grammar.y"
                                 { (yyval.stmt_un)=(yyvsp[-1].stmt_un); puts("while stmt"); }
#line 2342 "Grammar.tab.c"
    break;

  case 85: /* stmt: until_stmt  */
#line 296 "Grammar.y"
                    { (yyval.stmt_un)=(yyvsp[0].stmt_un); puts("until stmt"); }
#line 2348 "Grammar.tab.c"
    break;

  case 86: /* stmt: until_stmt stmt_ends  */
#line 297 "Grammar.y"
                             { (yyval.stmt_un)=(yyvsp[-1].stmt_un); puts("until stmt"); }
#line 2354 "Grammar.tab.c"
    break;

  case 87: /* stmt: RETURN_KEYWORD expr stmt_ends  */
#line 298 "Grammar.y"
                                    { (yyval.stmt_un)=create_return_stmt((yyvsp[-1].expr_un)); puts("return with expr"); /* TODO: implement */}
#line 2360 "Grammar.tab.c"
    break;

  case 88: /* stmt: RETURN_KEYWORD stmt_ends  */
#line 299 "Grammar.y"
                               { (yyval.stmt_un)=create_return_stmt(0); puts("return"); /* TODO: implement */}
#line 2366 "Grammar.tab.c"
    break;

  case 89: /* stmt_list_not_empty: stmt  */
#line 302 "Grammar.y"
                           { (yyval.stmt_list_un)=create_stmt_list((yyvsp[0].stmt_un)); puts("list from one stmt"); }
#line 2372 "Grammar.tab.c"
    break;

  case 90: /* stmt_list_not_empty: stmt_list_not_empty stmt  */
#line 303 "Grammar.y"
                               { (yyval.stmt_list_un)=add_to_stmt_list((yyvsp[-1].stmt_list_un), (yyvsp[0].stmt_un)); puts("add stmt to list"); }
#line 2378 "Grammar.tab.c"
    break;

  case 91: /* stmt_list: %empty  */
#line 306 "Grammar.y"
                       { (yyval.stmt_list_un)=0; puts("empty stmt list"); }
#line 2384 "Grammar.tab.c"
    break;

  case 92: /* stmt_list: stmt_list_not_empty  */
#line 307 "Grammar.y"
                           { (yyval.stmt_list_un)=(yyvsp[0].stmt_list_un); puts("stmt list"); }
#line 2390 "Grammar.tab.c"
    break;

  case 93: /* stmt_block: BEGIN_KEYWORD stmt_ends_op stmt_list END_KEYWORD  */
#line 310 "Grammar.y"
                                                              { (yyval.block_un)=create_stmt_block_struct((yyvsp[-1].stmt_list_un)); puts("begin without stmt ends"); }
#line 2396 "Grammar.tab.c"
    break;

  case 94: /* if_start_stmt: IF_KEYWORD expr stmt_ends stmt_list  */
#line 313 "Grammar.y"
                                                   { (yyval.if_part_un)=create_if_part_struct((yyvsp[-2].expr_un), (yyvsp[0].stmt_list_un)); puts("if without then"); }
#line 2402 "Grammar.tab.c"
    break;

  case 95: /* if_start_stmt: IF_KEYWORD expr SEMICOLON_SYMBOL new_lines_op THEN_KEYWORD stmt_ends_op stmt_list  */
#line 314 "Grammar.y"
                                                                                        { (yyval.if_part_un)=create_if_part_struct((yyvsp[-5].expr_un), (yyvsp[0].stmt_list_un)); puts("if with then"); }
#line 2408 "Grammar.tab.c"
    break;

  case 96: /* if_start_stmt: IF_KEYWORD expr new_lines_op THEN_KEYWORD stmt_ends_op stmt_list  */
#line 315 "Grammar.y"
                                                                       { (yyval.if_part_un)=create_if_part_struct((yyvsp[-4].expr_un), (yyvsp[0].stmt_list_un)); puts("if with then"); }
#line 2414 "Grammar.tab.c"
    break;

  case 97: /* elsif_stmt: ELSIF_KEYWORD expr stmt_ends stmt_list  */
#line 318 "Grammar.y"
                                                   { (yyval.if_part_un)=create_if_part_struct((yyvsp[-2].expr_un), (yyvsp[0].stmt_list_un)); puts("elsif without then");  }
#line 2420 "Grammar.tab.c"
    break;

  case 98: /* elsif_stmt: ELSIF_KEYWORD expr new_lines_op THEN_KEYWORD stmt_ends_op stmt_list  */
#line 319 "Grammar.y"
                                                                          { (yyval.if_part_un)=create_if_part_struct((yyvsp[-4].expr_un), (yyvsp[0].stmt_list_un)); puts("elsif with then");  }
#line 2426 "Grammar.tab.c"
    break;

  case 99: /* elsif_stmt: ELSIF_KEYWORD expr SEMICOLON_SYMBOL new_lines_op THEN_KEYWORD stmt_ends_op stmt_list  */
#line 320 "Grammar.y"
                                                                                           { (yyval.if_part_un)=create_if_part_struct((yyvsp[-5].expr_un), (yyvsp[0].stmt_list_un)); puts("elsif with then");  }
#line 2432 "Grammar.tab.c"
    break;

  case 100: /* elsif_stmt_list: elsif_stmt  */
#line 323 "Grammar.y"
                            { (yyval.elsif_list_un)=create_elsif_stmt_list((yyvsp[0].if_part_un)); }
#line 2438 "Grammar.tab.c"
    break;

  case 101: /* elsif_stmt_list: elsif_stmt_list elsif_stmt  */
#line 324 "Grammar.y"
                                 { (yyval.elsif_list_un)=add_to_elsif_stmt_list((yyvsp[-1].elsif_list_un), (yyvsp[0].if_part_un)); }
#line 2444 "Grammar.tab.c"
    break;

  case 102: /* if_stmt: if_start_stmt END_KEYWORD  */
#line 327 "Grammar.y"
                                   { (yyval.stmt_un)=create_if_stmt((yyvsp[-1].if_part_un), 0, 0); }
#line 2450 "Grammar.tab.c"
    break;

  case 103: /* if_stmt: if_start_stmt ELSE_KEYWORD stmt_ends_op stmt_list END_KEYWORD  */
#line 328 "Grammar.y"
                                                                    { (yyval.stmt_un)=create_if_stmt((yyvsp[-4].if_part_un), 0, (yyvsp[-1].stmt_list_un)); }
#line 2456 "Grammar.tab.c"
    break;

  case 104: /* if_stmt: if_start_stmt elsif_stmt_list END_KEYWORD  */
#line 329 "Grammar.y"
                                                { (yyval.stmt_un)=create_if_stmt((yyvsp[-2].if_part_un), (yyvsp[-1].elsif_list_un), 0); }
#line 2462 "Grammar.tab.c"
    break;

  case 105: /* if_stmt: if_start_stmt elsif_stmt_list ELSE_KEYWORD stmt_ends_op stmt_list END_KEYWORD  */
#line 330 "Grammar.y"
                                                                                    { (yyval.stmt_un)=create_if_stmt((yyvsp[-5].if_part_un), (yyvsp[-4].elsif_list_un), (yyvsp[-1].stmt_list_un)); }
#line 2468 "Grammar.tab.c"
    break;

  case 106: /* for_stmt: FOR_KEYWORD VAR_METHOD_NAME IN_KEYWORD expr stmt_ends stmt_list END_KEYWORD  */
#line 333 "Grammar.y"
                                                                                      { (yyval.stmt_un)=create_for_stmt((yyvsp[-5].var_name_un), (yyvsp[-3].expr_un), (yyvsp[-1].stmt_list_un)); }
#line 2474 "Grammar.tab.c"
    break;

  case 107: /* for_stmt: FOR_KEYWORD INSTANCE_VAR_NAME IN_KEYWORD expr stmt_ends stmt_list END_KEYWORD  */
#line 334 "Grammar.y"
                                                                                    { (yyval.stmt_un)=create_for_stmt((yyvsp[-5].instance_var_name_un), (yyvsp[-3].expr_un), (yyvsp[-1].stmt_list_un)); }
#line 2480 "Grammar.tab.c"
    break;

  case 108: /* for_stmt: FOR_KEYWORD VAR_METHOD_NAME IN_KEYWORD expr DO_KEYWORD stmt_ends_op stmt_list END_KEYWORD  */
#line 335 "Grammar.y"
                                                                                                    { (yyval.stmt_un)=create_for_stmt((yyvsp[-6].var_name_un), (yyvsp[-4].expr_un), (yyvsp[-1].stmt_list_un)); }
#line 2486 "Grammar.tab.c"
    break;

  case 109: /* for_stmt: FOR_KEYWORD INSTANCE_VAR_NAME IN_KEYWORD expr DO_KEYWORD stmt_ends_op stmt_list END_KEYWORD  */
#line 336 "Grammar.y"
                                                                                                  { (yyval.stmt_un)=create_for_stmt((yyvsp[-6].instance_var_name_un), (yyvsp[-4].expr_un), (yyvsp[-1].stmt_list_un)); }
#line 2492 "Grammar.tab.c"
    break;

  case 110: /* while_stmt: WHILE_KEYWORD expr stmt_ends stmt_list END_KEYWORD  */
#line 339 "Grammar.y"
                                                               { (yyval.stmt_un)=create_while_stmt((yyvsp[-3].expr_un), (yyvsp[-1].stmt_list_un)); }
#line 2498 "Grammar.tab.c"
    break;

  case 111: /* while_stmt: WHILE_KEYWORD expr DO_KEYWORD stmt_ends_op stmt_list END_KEYWORD  */
#line 340 "Grammar.y"
                                                                           { (yyval.stmt_un)=create_while_stmt((yyvsp[-4].expr_un), (yyvsp[-1].stmt_list_un)); }
#line 2504 "Grammar.tab.c"
    break;

  case 112: /* until_stmt: UNTIL_KEYWORD expr stmt_ends stmt_list END_KEYWORD  */
#line 343 "Grammar.y"
                                                               { (yyval.stmt_un)=create_until_stmt((yyvsp[-3].expr_un), (yyvsp[-1].stmt_list_un)); }
#line 2510 "Grammar.tab.c"
    break;

  case 113: /* until_stmt: UNTIL_KEYWORD expr DO_KEYWORD stmt_ends_op stmt_list END_KEYWORD  */
#line 344 "Grammar.y"
                                                                           { (yyval.stmt_un)=create_until_stmt((yyvsp[-4].expr_un), (yyvsp[-1].stmt_list_un)); }
#line 2516 "Grammar.tab.c"
    break;

  case 114: /* method_param: VAR_METHOD_NAME  */
#line 347 "Grammar.y"
                              { (yyval.method_param_un)=create_method_param_struct((yyvsp[0].var_name_un), 0); }
#line 2522 "Grammar.tab.c"
    break;

  case 115: /* method_param: VAR_METHOD_NAME ASSIGN_OP expr  */
#line 348 "Grammar.y"
                                         { (yyval.method_param_un)=create_method_param_struct((yyvsp[-2].var_name_un), (yyvsp[0].expr_un)); }
#line 2528 "Grammar.tab.c"
    break;

  case 116: /* method_params_list: %empty  */
#line 351 "Grammar.y"
                                { (yyval.method_param_list_un)=0; }
#line 2534 "Grammar.tab.c"
    break;

  case 117: /* method_params_list: method_params_list_not_empty  */
#line 352 "Grammar.y"
                                       { (yyval.method_param_list_un)=(yyvsp[0].method_param_list_un); }
#line 2540 "Grammar.tab.c"
    break;

  case 118: /* method_params_list_not_empty: method_param  */
#line 355 "Grammar.y"
                                           { (yyval.method_param_list_un)=create_method_param_list((yyvsp[0].method_param_un)); }
#line 2546 "Grammar.tab.c"
    break;

  case 119: /* method_params_list_not_empty: method_params_list_not_empty COMMA_SYMBOL method_param  */
#line 356 "Grammar.y"
                                                                 { (yyval.method_param_list_un)=add_to_method_param_list((yyvsp[-2].method_param_list_un), (yyvsp[0].method_param_un)); }
#line 2552 "Grammar.tab.c"
    break;

  case 120: /* def_method_stmt: DEF_KEYWORD VAR_METHOD_NAME stmt_ends stmt_list END_KEYWORD stmt_ends_op  */
#line 359 "Grammar.y"
                                                                                          { (yyval.def_method_un)=create_def_method_struct((yyvsp[-4].var_name_un), 0, (yyvsp[-2].stmt_list_un)); }
#line 2558 "Grammar.tab.c"
    break;

  case 121: /* def_method_stmt: DEF_KEYWORD VAR_METHOD_NAME OPEN_ROUND_BRACKET method_params_list CLOSE_ROUND_BRACKET stmt_ends_op stmt_list END_KEYWORD stmt_ends_op  */
#line 360 "Grammar.y"
                                                                                                                                            { (yyval.def_method_un)=create_def_method_struct((yyvsp[-7].var_name_un), (yyvsp[-5].method_param_list_un), (yyvsp[-2].stmt_list_un)); }
#line 2564 "Grammar.tab.c"
    break;

  case 122: /* expr_list: %empty  */
#line 363 "Grammar.y"
                       { (yyval.expr_list_un)=0; }
#line 2570 "Grammar.tab.c"
    break;

  case 123: /* expr_list: expr_list_not_empty  */
#line 364 "Grammar.y"
                              {(yyval.expr_list_un)=(yyvsp[0].expr_list_un); }
#line 2576 "Grammar.tab.c"
    break;

  case 124: /* expr_list_not_empty: expr new_lines_op  */
#line 367 "Grammar.y"
                                       { (yyval.expr_list_un)=create_expr_list((yyvsp[-1].expr_un)); }
#line 2582 "Grammar.tab.c"
    break;

  case 125: /* expr_list_not_empty: expr_list_not_empty COMMA_SYMBOL new_lines_op expr new_lines_op  */
#line 368 "Grammar.y"
                                                                          { (yyval.expr_list_un)=add_to_expr_list((yyvsp[-4].expr_list_un), (yyvsp[-1].expr_un)); }
#line 2588 "Grammar.tab.c"
    break;

  case 126: /* class_declaration: CLASS_KEYWORD CLASS_NAME stmt_ends def_method_list_op END_KEYWORD stmt_ends  */
#line 371 "Grammar.y"
                                                                                               { (yyval.program_item_un)=create_class_declaration_program_item((yyvsp[-4].class_name_un), 0, (yyvsp[-2].def_method_list_un)); puts("class declaration"); }
#line 2594 "Grammar.tab.c"
    break;

  case 127: /* class_declaration: CLASS_KEYWORD CLASS_NAME LESS_OP CLASS_NAME stmt_ends def_method_list_op END_KEYWORD stmt_ends  */
#line 372 "Grammar.y"
                                                                                                     { (yyval.program_item_un)=create_class_declaration_program_item((yyvsp[-6].class_name_un), (yyvsp[-4].class_name_un), (yyvsp[-2].def_method_list_un)); puts("class declaration"); }
#line 2600 "Grammar.tab.c"
    break;

  case 128: /* def_method_list_op: %empty  */
#line 376 "Grammar.y"
                                { (yyval.def_method_list_un)=0; }
#line 2606 "Grammar.tab.c"
    break;

  case 129: /* def_method_list_op: def_method_list  */
#line 377 "Grammar.y"
                      { (yyval.def_method_list_un)=(yyvsp[0].def_method_list_un); }
#line 2612 "Grammar.tab.c"
    break;

  case 130: /* def_method_list: def_method_stmt  */
#line 380 "Grammar.y"
                                 { (yyval.def_method_list_un)=create_def_method_list((yyvsp[0].def_method_un)); }
#line 2618 "Grammar.tab.c"
    break;

  case 131: /* def_method_list: def_method_list def_method_stmt  */
#line 381 "Grammar.y"
                                      { (yyval.def_method_list_un)=add_to_def_method_list((yyvsp[-1].def_method_list_un), (yyvsp[0].def_method_un)); }
#line 2624 "Grammar.tab.c"
    break;


#line 2628 "Grammar.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
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
          goto yyexhaustedlab;
      }
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

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


#if 1
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturn;
#endif


/*-------------------------------------------------------.
| yyreturn -- parsing is finished, clean up and return.  |
`-------------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 384 "Grammar.y"

