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
void yyerror(const char* message) {
    fprintf(stderr, message);
}
int yylex();
int yyparse();
extern FILE* yyin;



#line 83 "Grammar.tab.c"

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
  YYSYMBOL_STRING = 87,                    /* STRING  */
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
  YYSYMBOL_expr = 98,                      /* expr  */
  YYSYMBOL_new_lines = 99,                 /* new_lines  */
  YYSYMBOL_semicolons = 100,               /* semicolons  */
  YYSYMBOL_stmt_end = 101,                 /* stmt_end  */
  YYSYMBOL_stmt_ends = 102,                /* stmt_ends  */
  YYSYMBOL_stmt = 103,                     /* stmt  */
  YYSYMBOL_stmt_list_not_empty = 104,      /* stmt_list_not_empty  */
  YYSYMBOL_stmt_list = 105,                /* stmt_list  */
  YYSYMBOL_stmt_block = 106,               /* stmt_block  */
  YYSYMBOL_if_start_stmt = 107,            /* if_start_stmt  */
  YYSYMBOL_elsif_stmt = 108,               /* elsif_stmt  */
  YYSYMBOL_elsif_stmt_list = 109,          /* elsif_stmt_list  */
  YYSYMBOL_if_stmt = 110,                  /* if_stmt  */
  YYSYMBOL_for_stmt = 111,                 /* for_stmt  */
  YYSYMBOL_while_stmt = 112,               /* while_stmt  */
  YYSYMBOL_while_modifier_stmt = 113,      /* while_modifier_stmt  */
  YYSYMBOL_until_stmt = 114,               /* until_stmt  */
  YYSYMBOL_until_modifier_stmt = 115,      /* until_modifier_stmt  */
  YYSYMBOL_method_param = 116,             /* method_param  */
  YYSYMBOL_method_params_list = 117,       /* method_params_list  */
  YYSYMBOL_method_params_list_not_empty = 118, /* method_params_list_not_empty  */
  YYSYMBOL_def_method_stmt = 119,          /* def_method_stmt  */
  YYSYMBOL_method_call_param_list = 120,   /* method_call_param_list  */
  YYSYMBOL_method_call_param_list_not_empty = 121, /* method_call_param_list_not_empty  */
  YYSYMBOL_method_call_stmt = 122          /* method_call_stmt  */
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
typedef yytype_uint8 yy_state_t;

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
#define YYFINAL  60
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1180

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  96
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  27
/* YYNRULES -- Number of rules.  */
#define YYNRULES  123
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  239

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
       0,   138,   138,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   191,   192,   195,   196,   199,   200,   203,   204,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   226,   227,   230,
     231,   234,   235,   238,   239,   240,   243,   244,   245,   248,
     249,   252,   253,   254,   255,   256,   257,   260,   261,   262,
     263,   264,   265,   268,   269,   270,   273,   276,   277,   278,
     281,   284,   285,   288,   289,   292,   293,   296,   297,   300,
     301,   304,   305,   308
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
  "NEW_LINE_SYMBOL", "STRING", "INTEGER_NUMBER", "FLOAT_NUMBER",
  "VAR_METHOD_NAME", "INSTANCE_VAR_NAME", "CLASS_NAME", "CLASS_VAR_NAME",
  "UNARY_MINUS", "UNARY_PLUS", "$accept", "program", "expr", "new_lines",
  "semicolons", "stmt_end", "stmt_ends", "stmt", "stmt_list_not_empty",
  "stmt_list", "stmt_block", "if_start_stmt", "elsif_stmt",
  "elsif_stmt_list", "if_stmt", "for_stmt", "while_stmt",
  "while_modifier_stmt", "until_stmt", "until_modifier_stmt",
  "method_param", "method_params_list", "method_params_list_not_empty",
  "def_method_stmt", "method_call_param_list",
  "method_call_param_list_not_empty", "method_call_stmt", YY_NULLPTR
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

#define YYPACT_NINF (-79)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     350,    18,   -78,   829,   829,   -79,   -59,   -79,   829,   -79,
     829,   829,   829,   829,   829,   829,   829,   829,   -79,   -79,
     -79,   -58,   -79,    22,   407,   -79,   350,   -79,   -40,    11,
     -40,   -40,   -40,   -40,   -40,   -40,   -40,   -79,   -79,   -79,
     -38,   -36,   -79,    18,    32,   -72,  1015,   456,    33,    35,
    1015,   522,   588,     7,     7,     7,     7,   932,   883,   829,
     -79,   829,   829,   829,   829,   829,   829,   829,   829,   829,
     829,   829,   829,   829,   829,   829,   829,   829,   829,   829,
     829,   829,   829,   829,   829,   829,   829,   829,   829,   829,
     829,   829,   829,   829,   829,   -40,   -79,   -40,    18,   829,
     -79,   -79,    24,   -40,   -40,   -40,   -40,   -40,   -40,   -40,
     -79,   -79,   -79,    41,   -79,   -31,    18,    18,    18,   829,
     829,    18,    18,    18,    18,   -79,   -79,   981,   -14,   -21,
    1015,  1015,   981,   981,   -39,   -39,     7,     7,     7,     7,
     834,   834,    23,    23,    23,    23,   834,   834,  1015,  1015,
    1015,  1015,  1015,  1015,  1015,   -23,   -33,   -33,   164,   164,
    1113,  1083,  1049,  1049,    18,    55,   637,    18,   -79,   -79,
     -79,    16,   -79,    -2,    -8,    69,    18,   -79,   -79,   703,
     769,    18,    77,    78,    18,    79,    81,   -79,   829,    83,
     -79,    18,    18,    18,    84,   829,   350,   -31,   -79,   -79,
      18,    18,    18,    18,    85,   -79,   -79,    86,   -79,   -79,
     981,   -79,    18,   -79,   -79,    87,   -79,   981,    95,   -79,
      18,    96,    97,    18,    98,    99,   -79,   -79,   -79,   -79,
     -79,   103,   -79,   -79,   104,   -79,   -79,   -79,   -79
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
      79,    79,     0,     0,     0,     8,     0,     6,     0,     7,
       0,     0,     0,     0,     0,     0,     0,     0,     5,     3,
       4,    50,    51,     0,     0,    77,    80,     2,    61,     0,
      63,    65,    67,    69,    71,    73,    75,    49,    54,    52,
      56,    57,    58,    79,     0,     0,    43,     0,     0,     0,
      44,     0,     0,    11,    13,    10,     9,     0,     0,   119,
       1,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    60,    78,    62,    79,     0,
      91,    89,     0,    64,    66,    68,    70,    72,    74,    76,
      53,    55,    59,     0,    81,   113,    79,    79,    79,     0,
       0,    79,    79,    79,    79,    47,    48,   121,     0,   120,
      45,    46,   110,   106,    17,    18,    14,    15,    16,    12,
      29,    31,    24,    25,    26,    27,    28,    30,    36,    40,
      39,    41,    38,    37,    42,    21,    22,    23,    19,    20,
      32,    33,    34,    35,    79,     0,     0,    79,    94,    90,
      82,   111,   115,     0,   114,     0,    79,    84,    83,     0,
       0,    79,     0,     0,    79,     0,     0,   123,     0,     0,
      92,    79,    79,    79,     0,     0,    79,     0,   117,    85,
      79,    79,    79,    79,     0,   108,   107,     0,   104,   103,
     122,    93,    79,    87,    86,     0,    95,   112,     0,   116,
      79,     0,     0,    79,     0,     0,   109,   105,    88,    96,
     118,     0,    99,    97,     0,   101,    98,   100,   102
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -79,   -79,    65,   -79,   -79,   126,   233,   134,   -79,    -1,
     -79,   -79,    59,   -79,   -79,   -79,   -79,   -79,   -79,   -79,
     -35,   -79,   -79,   -79,   -79,   -79,   -79
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    23,    24,    40,    41,    42,    43,    25,    26,    27,
      28,    29,   101,   102,    30,    31,    32,    33,    34,    35,
     172,   173,   174,    36,   128,   129,    37
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      44,   115,    67,    68,    69,    70,    65,    66,    67,    68,
      69,    70,    45,    38,    39,    59,    65,    66,    67,    68,
      69,    70,    60,     1,    98,    99,   100,     2,     3,    86,
       4,    48,    49,    89,    90,     5,     6,   167,    99,   168,
       7,     8,   113,    89,    90,    38,    39,   114,   110,   111,
       9,    70,   119,    10,   120,    11,   170,    12,    13,   171,
     187,   188,    65,    66,    67,    68,    69,    70,    46,    47,
     190,   195,   196,    50,   197,    51,    52,    53,    54,    55,
      56,    57,    58,    14,   198,    86,    87,    88,    15,    89,
      90,    16,   205,   206,   208,    17,   209,   165,   211,   216,
     226,   227,   229,    38,    39,    18,    19,    20,    21,    22,
     230,   232,   233,   235,   236,   175,   177,   178,   237,   238,
     182,   183,   185,   186,   127,     0,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
      96,   169,   219,   189,   166,     0,   194,     0,     0,   112,
       0,     0,     0,     0,     0,   199,     0,     0,     0,     0,
     204,     0,     0,   207,   179,   180,     0,     0,     0,     0,
     213,   214,   215,     0,     0,   218,     0,     0,     0,   221,
     222,   224,   225,    65,    66,    67,    68,    69,    70,     0,
       0,   228,     0,     0,     0,     0,     0,     0,     0,   231,
       0,   112,   234,   112,     0,     0,     0,     0,     0,   112,
     112,   112,   112,   112,   112,   112,     0,     0,     0,     0,
       0,     0,   112,     0,   112,     0,     0,     0,   112,     0,
     112,     0,     0,   210,     0,     0,     0,    95,     0,     0,
     217,    97,     0,   103,   104,   105,   106,   107,   108,   109,
       0,     0,     0,     0,     0,     0,     0,     0,   116,     0,
     118,     0,     0,     0,   122,   124,     0,     0,     0,     0,
     112,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   112,     0,     0,     0,     0,   112,     0,     0,
     112,     0,     0,     0,     0,     0,     0,     0,   112,   112,
       0,     0,     0,     0,     0,     0,     0,   112,     0,   112,
       0,   164,     0,     0,     0,     0,     0,     0,   112,     0,
       0,     0,     0,     0,     0,     0,   112,     0,     0,   112,
     176,     0,     0,     0,   181,     1,   184,     0,     0,     2,
       3,     0,     4,     0,     0,     0,     0,     5,     6,     0,
       0,     0,     7,     8,     0,     0,     0,     0,     0,     0,
       0,     0,     9,     0,     0,    10,     0,    11,     0,    12,
      13,     0,     0,     0,     0,     0,     0,     0,     0,   192,
     193,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    61,   201,   203,     0,    14,     0,     0,     0,     0,
      15,     0,     0,    16,   212,     0,     0,    17,     0,     0,
       0,    62,     0,   220,     0,   223,     0,    18,    19,    20,
      21,    22,    63,     0,    64,     0,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      61,     0,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,     0,    89,    90,    91,    92,     0,    93,    94,
      62,     0,     0,     0,     0,     0,     0,   117,     0,     0,
       0,     0,    38,    39,     0,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,     0,
       0,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,     0,    89,    90,    91,    92,    61,    93,    94,     0,
       0,     0,     0,   121,     0,     0,     0,     0,     0,     0,
       0,    38,    39,     0,     0,     0,    62,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,     0,     0,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,     0,    89,    90,
      91,    92,    61,    93,    94,     0,     0,     0,     0,   123,
       0,     0,     0,     0,     0,     0,     0,    38,    39,     0,
       0,     0,    62,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    61,     0,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,     0,    89,    90,    91,    92,     0,    93,
      94,    62,     0,     0,     0,     0,     0,     0,   191,     0,
       0,     0,     0,    38,    39,     0,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
       0,     0,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,     0,    89,    90,    91,    92,    61,    93,    94,
       0,     0,     0,     0,   200,     0,     0,     0,     0,     0,
       0,     0,    38,    39,     0,     0,     0,    62,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,     0,     0,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,     0,    89,
      90,    91,    92,    61,    93,    94,     0,     0,     0,     0,
     202,     0,     0,     0,     0,     0,     0,     0,    38,    39,
       0,     0,     0,    62,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,     0,     0,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,     0,    89,    90,    91,    92,     3,
      93,    94,     0,     0,     0,     0,     5,     0,     0,     0,
       0,     7,     8,     0,    38,    39,     0,     0,     0,     0,
       0,     9,     0,     0,     0,     0,     0,     0,    12,    13,
       0,     0,     0,    65,    66,    67,    68,    69,    70,    -1,
      -1,    73,    74,    75,    76,    -1,    -1,    61,     0,     0,
       0,     0,     0,     0,    14,     0,    86,    87,    88,    15,
      89,    90,    16,     0,     0,     0,    17,    62,     0,     0,
       0,     0,     0,     0,     0,     0,    18,    19,    20,    21,
      22,     0,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    61,     0,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,     0,    89,
      90,    91,    92,     0,    93,    94,    62,     0,     0,     0,
       0,   126,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    61,     0,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,     0,    89,    90,
      91,    92,     0,    93,    94,    62,   125,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,     0,     0,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,     0,    89,    90,    91,
      92,     0,    93,    94,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,     0,     0,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
       0,    89,    90,    91,    92,     0,    93,    94,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    86,    87,    88,     0,    89,    90,    91,    92,     0,
      -1,    -1,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    86,    87,    88,     0,    89,
      90,    91,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    86,    87,    88,     0,    89,
      90
};

static const yytype_int16 yycheck[] =
{
       1,    73,    41,    42,    43,    44,    39,    40,    41,    42,
      43,    44,    90,    85,    86,    73,    39,    40,    41,    42,
      43,    44,     0,     5,    13,    14,    15,     9,    10,    62,
      12,    90,    91,    66,    67,    17,    18,    13,    14,    15,
      22,    23,    43,    66,    67,    85,    86,    15,    86,    85,
      32,    44,    19,    35,    19,    37,    15,    39,    40,    90,
      74,    82,    39,    40,    41,    42,    43,    44,     3,     4,
      15,    55,    74,     8,    82,    10,    11,    12,    13,    14,
      15,    16,    17,    65,    15,    62,    63,    64,    70,    66,
      67,    73,    15,    15,    15,    77,    15,    98,    15,    15,
      15,    15,    15,    85,    86,    87,    88,    89,    90,    91,
      15,    15,    15,    15,    15,   116,   117,   118,    15,    15,
     121,   122,   123,   124,    59,    -1,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      26,   102,   197,   164,    99,    -1,   167,    -1,    -1,    43,
      -1,    -1,    -1,    -1,    -1,   176,    -1,    -1,    -1,    -1,
     181,    -1,    -1,   184,   119,   120,    -1,    -1,    -1,    -1,
     191,   192,   193,    -1,    -1,   196,    -1,    -1,    -1,   200,
     201,   202,   203,    39,    40,    41,    42,    43,    44,    -1,
      -1,   212,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   220,
      -1,    95,   223,    97,    -1,    -1,    -1,    -1,    -1,   103,
     104,   105,   106,   107,   108,   109,    -1,    -1,    -1,    -1,
      -1,    -1,   116,    -1,   118,    -1,    -1,    -1,   122,    -1,
     124,    -1,    -1,   188,    -1,    -1,    -1,    24,    -1,    -1,
     195,    28,    -1,    30,    31,    32,    33,    34,    35,    36,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,    -1,
      47,    -1,    -1,    -1,    51,    52,    -1,    -1,    -1,    -1,
     164,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   176,    -1,    -1,    -1,    -1,   181,    -1,    -1,
     184,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   192,   193,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   201,    -1,   203,
      -1,    98,    -1,    -1,    -1,    -1,    -1,    -1,   212,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   220,    -1,    -1,   223,
     117,    -1,    -1,    -1,   121,     5,   123,    -1,    -1,     9,
      10,    -1,    12,    -1,    -1,    -1,    -1,    17,    18,    -1,
      -1,    -1,    22,    23,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    32,    -1,    -1,    35,    -1,    37,    -1,    39,
      40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   166,
     167,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     4,   179,   180,    -1,    65,    -1,    -1,    -1,    -1,
      70,    -1,    -1,    73,   191,    -1,    -1,    77,    -1,    -1,
      -1,    24,    -1,   200,    -1,   202,    -1,    87,    88,    89,
      90,    91,    35,    -1,    37,    -1,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
       4,    -1,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    -1,    66,    67,    68,    69,    -1,    71,    72,
      24,    -1,    -1,    -1,    -1,    -1,    -1,    31,    -1,    -1,
      -1,    -1,    85,    86,    -1,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    -1,
      -1,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    -1,    66,    67,    68,    69,     4,    71,    72,    -1,
      -1,    -1,    -1,    11,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    85,    86,    -1,    -1,    -1,    24,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    -1,    -1,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    -1,    66,    67,
      68,    69,     4,    71,    72,    -1,    -1,    -1,    -1,    11,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    85,    86,    -1,
      -1,    -1,    24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,     4,    -1,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    -1,    66,    67,    68,    69,    -1,    71,
      72,    24,    -1,    -1,    -1,    -1,    -1,    -1,    31,    -1,
      -1,    -1,    -1,    85,    86,    -1,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      -1,    -1,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    -1,    66,    67,    68,    69,     4,    71,    72,
      -1,    -1,    -1,    -1,    11,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    85,    86,    -1,    -1,    -1,    24,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    -1,    -1,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    -1,    66,
      67,    68,    69,     4,    71,    72,    -1,    -1,    -1,    -1,
      11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    85,    86,
      -1,    -1,    -1,    24,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    -1,    -1,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    -1,    66,    67,    68,    69,    10,
      71,    72,    -1,    -1,    -1,    -1,    17,    -1,    -1,    -1,
      -1,    22,    23,    -1,    85,    86,    -1,    -1,    -1,    -1,
      -1,    32,    -1,    -1,    -1,    -1,    -1,    -1,    39,    40,
      -1,    -1,    -1,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,     4,    -1,    -1,
      -1,    -1,    -1,    -1,    65,    -1,    62,    63,    64,    70,
      66,    67,    73,    -1,    -1,    -1,    77,    24,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    87,    88,    89,    90,
      91,    -1,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,     4,    -1,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    -1,    66,
      67,    68,    69,    -1,    71,    72,    24,    -1,    -1,    -1,
      -1,    78,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,     4,    -1,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    -1,    66,    67,
      68,    69,    -1,    71,    72,    24,    74,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    -1,    -1,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    -1,    66,    67,    68,
      69,    -1,    71,    72,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    -1,    -1,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      -1,    66,    67,    68,    69,    -1,    71,    72,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    62,    63,    64,    -1,    66,    67,    68,    69,    -1,
      71,    72,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    62,    63,    64,    -1,    66,
      67,    68,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    62,    63,    64,    -1,    66,
      67
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     5,     9,    10,    12,    17,    18,    22,    23,    32,
      35,    37,    39,    40,    65,    70,    73,    77,    87,    88,
      89,    90,    91,    97,    98,   103,   104,   105,   106,   107,
     110,   111,   112,   113,   114,   115,   119,   122,    85,    86,
      99,   100,   101,   102,   105,    90,    98,    98,    90,    91,
      98,    98,    98,    98,    98,    98,    98,    98,    98,    73,
       0,     4,    24,    35,    37,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    66,
      67,    68,    69,    71,    72,   102,   103,   102,    13,    14,
      15,   108,   109,   102,   102,   102,   102,   102,   102,   102,
      86,    85,   101,   105,    15,    73,   102,    31,   102,    19,
      19,    11,   102,    11,   102,    74,    78,    98,   120,   121,
      98,    98,    98,    98,    98,    98,    98,    98,    98,    98,
      98,    98,    98,    98,    98,    98,    98,    98,    98,    98,
      98,    98,    98,    98,    98,    98,    98,    98,    98,    98,
      98,    98,    98,    98,   102,   105,    98,    13,    15,   108,
      15,    90,   116,   117,   118,   105,   102,   105,   105,    98,
      98,   102,   105,   105,   102,   105,   105,    74,    82,   105,
      15,    31,   102,   102,   105,    55,    74,    82,    15,   105,
      11,   102,    11,   102,   105,    15,    15,   105,    15,    15,
      98,    15,   102,   105,   105,   105,    15,    98,   105,   116,
     102,   105,   105,   102,   105,   105,    15,    15,   105,    15,
      15,   105,    15,    15,   105,    15,    15,    15,    15
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    96,    97,    98,    98,    98,    98,    98,    98,    98,
      98,    98,    98,    98,    98,    98,    98,    98,    98,    98,
      98,    98,    98,    98,    98,    98,    98,    98,    98,    98,
      98,    98,    98,    98,    98,    98,    98,    98,    98,    98,
      98,    98,    98,    98,    98,    98,    98,    98,    98,    98,
      98,    98,    99,    99,   100,   100,   101,   101,   102,   102,
     103,   103,   103,   103,   103,   103,   103,   103,   103,   103,
     103,   103,   103,   103,   103,   103,   103,   104,   104,   105,
     105,   106,   106,   107,   107,   107,   108,   108,   108,   109,
     109,   110,   110,   110,   110,   110,   110,   111,   111,   111,
     111,   111,   111,   112,   112,   112,   113,   114,   114,   114,
     115,   116,   116,   117,   117,   118,   118,   119,   119,   120,
     120,   121,   121,   122
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     1,     1,     1,     2,
       2,     2,     3,     2,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     2,     2,     3,     3,     3,     3,     1,
       1,     1,     1,     2,     1,     2,     1,     1,     1,     2,
       2,     1,     2,     1,     2,     1,     2,     1,     2,     1,
       2,     1,     2,     1,     2,     1,     2,     1,     2,     0,
       1,     3,     4,     4,     4,     5,     4,     4,     5,     1,
       2,     2,     4,     5,     3,     5,     6,     7,     7,     7,
       8,     7,     8,     5,     5,     6,     3,     5,     5,     6,
       3,     1,     3,     0,     1,     1,     3,     5,     7,     0,
       1,     1,     3,     4
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
  case 2: /* program: stmt_list  */
#line 138 "Grammar.y"
                    { puts("program"); }
#line 1838 "Grammar.tab.c"
    break;

  case 3: /* expr: INTEGER_NUMBER  */
#line 140 "Grammar.y"
                     { puts("integer"); }
#line 1844 "Grammar.tab.c"
    break;

  case 4: /* expr: FLOAT_NUMBER  */
#line 141 "Grammar.y"
                     { puts("float"); }
#line 1850 "Grammar.tab.c"
    break;

  case 5: /* expr: STRING  */
#line 142 "Grammar.y"
                     { puts("string"); }
#line 1856 "Grammar.tab.c"
    break;

  case 6: /* expr: NIL_KEYWORD  */
#line 143 "Grammar.y"
                     { puts("nil"); }
#line 1862 "Grammar.tab.c"
    break;

  case 7: /* expr: TRUE_KEYWORD  */
#line 144 "Grammar.y"
                     { puts("true"); }
#line 1868 "Grammar.tab.c"
    break;

  case 8: /* expr: FALSE_KEYWORD  */
#line 145 "Grammar.y"
                     { puts("false"); }
#line 1874 "Grammar.tab.c"
    break;

  case 9: /* expr: LOGICAL_NOT_OP expr  */
#line 146 "Grammar.y"
                          { puts("LOGICAL_NOT_OP"); }
#line 1880 "Grammar.tab.c"
    break;

  case 10: /* expr: BIN_ONES_COMPLEMENT_OP expr  */
#line 147 "Grammar.y"
                                  { puts("BIN_ONES_COMPLEMENT_OP"); }
#line 1886 "Grammar.tab.c"
    break;

  case 11: /* expr: ARITHMETIC_PLUS_OP expr  */
#line 148 "Grammar.y"
                                               { puts("unary plus"); }
#line 1892 "Grammar.tab.c"
    break;

  case 12: /* expr: expr ARITHMETIC_POW_OP expr  */
#line 149 "Grammar.y"
                                  { puts("pow"); }
#line 1898 "Grammar.tab.c"
    break;

  case 13: /* expr: ARITHMETIC_MINUS_OP expr  */
#line 150 "Grammar.y"
                                                  { puts("unary minus"); }
#line 1904 "Grammar.tab.c"
    break;

  case 14: /* expr: expr ARITHMETIC_MUL_OP expr  */
#line 151 "Grammar.y"
                                   { puts("mul"); }
#line 1910 "Grammar.tab.c"
    break;

  case 15: /* expr: expr ARITHMETIC_DIV_OP expr  */
#line 152 "Grammar.y"
                                  { puts("div"); }
#line 1916 "Grammar.tab.c"
    break;

  case 16: /* expr: expr ARITHMETIC_MOD_OP expr  */
#line 153 "Grammar.y"
                                   { puts("mod"); }
#line 1922 "Grammar.tab.c"
    break;

  case 17: /* expr: expr ARITHMETIC_PLUS_OP expr  */
#line 154 "Grammar.y"
                                   { puts("plus"); }
#line 1928 "Grammar.tab.c"
    break;

  case 18: /* expr: expr ARITHMETIC_MINUS_OP expr  */
#line 155 "Grammar.y"
                                    { puts("minus"); }
#line 1934 "Grammar.tab.c"
    break;

  case 19: /* expr: expr BIN_LEFT_SHIFT_OP expr  */
#line 156 "Grammar.y"
                                   { puts("left shift"); }
#line 1940 "Grammar.tab.c"
    break;

  case 20: /* expr: expr BIN_RIGHT_SHIFT_OP expr  */
#line 157 "Grammar.y"
                                   { puts("right shift"); }
#line 1946 "Grammar.tab.c"
    break;

  case 21: /* expr: expr BIN_AND_OP expr  */
#line 158 "Grammar.y"
                           { puts("bin and"); }
#line 1952 "Grammar.tab.c"
    break;

  case 22: /* expr: expr BIN_OR_OP expr  */
#line 159 "Grammar.y"
                            { puts("bin or"); }
#line 1958 "Grammar.tab.c"
    break;

  case 23: /* expr: expr BIN_XOR_OP expr  */
#line 160 "Grammar.y"
                            { puts("bin xor"); }
#line 1964 "Grammar.tab.c"
    break;

  case 24: /* expr: expr GREATER_OP expr  */
#line 161 "Grammar.y"
                            { puts(" > "); }
#line 1970 "Grammar.tab.c"
    break;

  case 25: /* expr: expr LESS_OP expr  */
#line 162 "Grammar.y"
                             { puts(" < "); }
#line 1976 "Grammar.tab.c"
    break;

  case 26: /* expr: expr GREATER_OR_EQL_OP expr  */
#line 163 "Grammar.y"
                                   { puts(" >= "); }
#line 1982 "Grammar.tab.c"
    break;

  case 27: /* expr: expr LESS_OR_EQL_OP expr  */
#line 164 "Grammar.y"
                                    { puts(" <= "); }
#line 1988 "Grammar.tab.c"
    break;

  case 28: /* expr: expr COMB_COMPRASION_OP expr  */
#line 165 "Grammar.y"
                                     { puts(" COMB_COMPRASION_OP "); }
#line 1994 "Grammar.tab.c"
    break;

  case 29: /* expr: expr EQL_OP expr  */
#line 166 "Grammar.y"
                                { puts(" EQL_OP "); }
#line 2000 "Grammar.tab.c"
    break;

  case 30: /* expr: expr CASE_EQL_OP expr  */
#line 167 "Grammar.y"
                                { puts(" CASE_EQL_OP "); }
#line 2006 "Grammar.tab.c"
    break;

  case 31: /* expr: expr NOT_EQL_OP expr  */
#line 168 "Grammar.y"
                                { puts("NOT_EQL_OP"); }
#line 2012 "Grammar.tab.c"
    break;

  case 32: /* expr: expr LOGICAL_AND_OP expr  */
#line 169 "Grammar.y"
                                { puts("LOGICAL_AND_OP"); }
#line 2018 "Grammar.tab.c"
    break;

  case 33: /* expr: expr LOGICAL_OR_OP expr  */
#line 170 "Grammar.y"
                                { puts("LOGICAL_OR_OP"); }
#line 2024 "Grammar.tab.c"
    break;

  case 34: /* expr: expr INCLUSIVE_RANGE_OP expr  */
#line 171 "Grammar.y"
                                    { puts("INCLUSIVE_RANGE_OP"); }
#line 2030 "Grammar.tab.c"
    break;

  case 35: /* expr: expr EXCLUSIVE_RANGE_OP expr  */
#line 172 "Grammar.y"
                                    { puts("EXCLUSIVE_RANGE_OP"); }
#line 2036 "Grammar.tab.c"
    break;

  case 36: /* expr: expr ASSIGN_OP expr  */
#line 173 "Grammar.y"
                                    { puts("assign"); }
#line 2042 "Grammar.tab.c"
    break;

  case 37: /* expr: expr MOD_ASSIGN_OP expr  */
#line 174 "Grammar.y"
                                            { puts("MOD_ASSIGN_OP"); }
#line 2048 "Grammar.tab.c"
    break;

  case 38: /* expr: expr DIV_ASSIGN_OP expr  */
#line 175 "Grammar.y"
                                    { puts("DIV_ASSIGN_OP"); }
#line 2054 "Grammar.tab.c"
    break;

  case 39: /* expr: expr SUB_ASSIGN_OP expr  */
#line 176 "Grammar.y"
                                     { puts("SUB_ASSIGN_OP"); }
#line 2060 "Grammar.tab.c"
    break;

  case 40: /* expr: expr ADD_ASSIGN_OP expr  */
#line 177 "Grammar.y"
                                      { puts("SUB_ASSIGN_OP"); }
#line 2066 "Grammar.tab.c"
    break;

  case 41: /* expr: expr MUL_ASSIGN_OP expr  */
#line 178 "Grammar.y"
                                        { puts("MUL_ASSIGN_OP"); }
#line 2072 "Grammar.tab.c"
    break;

  case 42: /* expr: expr POW_ASSIGN_OP expr  */
#line 179 "Grammar.y"
                                    { puts("POW_ASSIGN_OP"); }
#line 2078 "Grammar.tab.c"
    break;

  case 43: /* expr: DEFINED_KEYWORD expr  */
#line 180 "Grammar.y"
                                    { puts("DEFINED_KEYWORD"); }
#line 2084 "Grammar.tab.c"
    break;

  case 44: /* expr: NOT_KEYWORD expr  */
#line 181 "Grammar.y"
                                     { puts("NOT_KEYWORD"); }
#line 2090 "Grammar.tab.c"
    break;

  case 45: /* expr: expr AND_KEYWORD expr  */
#line 182 "Grammar.y"
                                    { puts("AND_KEYWORD"); }
#line 2096 "Grammar.tab.c"
    break;

  case 46: /* expr: expr OR_KEYWORD expr  */
#line 183 "Grammar.y"
                                    { puts("OR_KEYWORD"); }
#line 2102 "Grammar.tab.c"
    break;

  case 47: /* expr: OPEN_ROUND_BRACKET expr CLOSE_ROUND_BRACKET  */
#line 184 "Grammar.y"
                                                     { puts(" expr in round brackets "); }
#line 2108 "Grammar.tab.c"
    break;

  case 48: /* expr: OPEN_SQUARE_BRACKET expr CLOSE_SQUARE_BRACKET  */
#line 185 "Grammar.y"
                                                            { puts(" expr in square brackets "); }
#line 2114 "Grammar.tab.c"
    break;

  case 49: /* expr: method_call_stmt  */
#line 186 "Grammar.y"
                                             { puts("method call"); }
#line 2120 "Grammar.tab.c"
    break;

  case 50: /* expr: VAR_METHOD_NAME  */
#line 187 "Grammar.y"
                       { puts("var"); }
#line 2126 "Grammar.tab.c"
    break;

  case 51: /* expr: INSTANCE_VAR_NAME  */
#line 188 "Grammar.y"
                            { puts("instance var"); }
#line 2132 "Grammar.tab.c"
    break;

  case 60: /* stmt: expr stmt_ends  */
#line 207 "Grammar.y"
                     { puts("stmt"); }
#line 2138 "Grammar.tab.c"
    break;

  case 61: /* stmt: stmt_block  */
#line 208 "Grammar.y"
                    { puts("stmt block"); }
#line 2144 "Grammar.tab.c"
    break;

  case 63: /* stmt: if_stmt  */
#line 210 "Grammar.y"
                    { puts("if stmt"); }
#line 2150 "Grammar.tab.c"
    break;

  case 64: /* stmt: if_stmt stmt_ends  */
#line 211 "Grammar.y"
                           { puts("if stmt"); }
#line 2156 "Grammar.tab.c"
    break;

  case 65: /* stmt: for_stmt  */
#line 212 "Grammar.y"
                     { puts("for stmt"); }
#line 2162 "Grammar.tab.c"
    break;

  case 67: /* stmt: while_stmt  */
#line 214 "Grammar.y"
                         { puts("while stmt"); }
#line 2168 "Grammar.tab.c"
    break;

  case 68: /* stmt: while_stmt stmt_ends  */
#line 215 "Grammar.y"
                                 { puts("while stmt"); }
#line 2174 "Grammar.tab.c"
    break;

  case 69: /* stmt: while_modifier_stmt  */
#line 216 "Grammar.y"
                                                                           { puts("while modifer stmt"); }
#line 2180 "Grammar.tab.c"
    break;

  case 70: /* stmt: while_modifier_stmt stmt_ends  */
#line 217 "Grammar.y"
                                                                                     { puts("while modifer stmt"); }
#line 2186 "Grammar.tab.c"
    break;

  case 71: /* stmt: until_stmt  */
#line 218 "Grammar.y"
                    { puts("until stmt"); }
#line 2192 "Grammar.tab.c"
    break;

  case 72: /* stmt: until_stmt stmt_ends  */
#line 219 "Grammar.y"
                             { puts("until stmt"); }
#line 2198 "Grammar.tab.c"
    break;

  case 73: /* stmt: until_modifier_stmt  */
#line 220 "Grammar.y"
                                                                           { puts("until modifer stmt"); }
#line 2204 "Grammar.tab.c"
    break;

  case 74: /* stmt: until_modifier_stmt stmt_ends  */
#line 221 "Grammar.y"
                                                                                     { puts("until modifer stmt"); }
#line 2210 "Grammar.tab.c"
    break;

  case 75: /* stmt: def_method_stmt  */
#line 222 "Grammar.y"
                        { puts("def method"); }
#line 2216 "Grammar.tab.c"
    break;

  case 76: /* stmt: def_method_stmt stmt_ends  */
#line 223 "Grammar.y"
                                { puts("def method"); }
#line 2222 "Grammar.tab.c"
    break;

  case 77: /* stmt_list_not_empty: stmt  */
#line 226 "Grammar.y"
                           { puts("list from one stmt"); }
#line 2228 "Grammar.tab.c"
    break;

  case 78: /* stmt_list_not_empty: stmt_list_not_empty stmt  */
#line 227 "Grammar.y"
                               { puts("add stmt to list"); }
#line 2234 "Grammar.tab.c"
    break;

  case 79: /* stmt_list: %empty  */
#line 230 "Grammar.y"
                       { puts("empty stmt list"); }
#line 2240 "Grammar.tab.c"
    break;

  case 80: /* stmt_list: stmt_list_not_empty  */
#line 231 "Grammar.y"
                           { puts("stmt list"); }
#line 2246 "Grammar.tab.c"
    break;

  case 81: /* stmt_block: BEGIN_KEYWORD stmt_list END_KEYWORD  */
#line 234 "Grammar.y"
                                                 { puts("begin without stmt ends"); }
#line 2252 "Grammar.tab.c"
    break;

  case 82: /* stmt_block: BEGIN_KEYWORD stmt_ends stmt_list END_KEYWORD  */
#line 235 "Grammar.y"
                                                    { puts("begin with stmt ends"); }
#line 2258 "Grammar.tab.c"
    break;

  case 83: /* if_start_stmt: IF_KEYWORD expr stmt_ends stmt_list  */
#line 238 "Grammar.y"
                                                   { puts("if without then"); }
#line 2264 "Grammar.tab.c"
    break;

  case 84: /* if_start_stmt: IF_KEYWORD expr THEN_KEYWORD stmt_list  */
#line 239 "Grammar.y"
                                             { puts("if with then"); }
#line 2270 "Grammar.tab.c"
    break;

  case 85: /* if_start_stmt: IF_KEYWORD expr THEN_KEYWORD stmt_ends stmt_list  */
#line 240 "Grammar.y"
                                                       { puts("if with then"); }
#line 2276 "Grammar.tab.c"
    break;

  case 86: /* elsif_stmt: ELSIF_KEYWORD expr stmt_ends stmt_list  */
#line 243 "Grammar.y"
                                                   { puts("elsif without then");  }
#line 2282 "Grammar.tab.c"
    break;

  case 87: /* elsif_stmt: ELSIF_KEYWORD expr THEN_KEYWORD stmt_list  */
#line 244 "Grammar.y"
                                                { puts("elsif with then");  }
#line 2288 "Grammar.tab.c"
    break;

  case 88: /* elsif_stmt: ELSIF_KEYWORD expr THEN_KEYWORD stmt_ends stmt_list  */
#line 245 "Grammar.y"
                                                          { puts("elsif with then");  }
#line 2294 "Grammar.tab.c"
    break;


#line 2298 "Grammar.tab.c"

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

#line 311 "Grammar.y"


void main(int argc, char **argv ){
	yyin = fopen(argv[1], "r" );

    yyparse();
    return;
}
