/* A Bison parser, made by GNU Bison 3.7.1.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_GRAMMAR_TAB_H_INCLUDED
# define YY_YY_GRAMMAR_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    ALIAS_KEYWORD = 258,           /* ALIAS_KEYWORD  */
    AND_KEYWORD = 259,             /* AND_KEYWORD  */
    BEGIN_KEYWORD = 260,           /* BEGIN_KEYWORD  */
    BREAK_KEYWORD = 261,           /* BREAK_KEYWORD  */
    CASE_KEYWORD = 262,            /* CASE_KEYWORD  */
    CLASS_KEYWORD = 263,           /* CLASS_KEYWORD  */
    DEF_KEYWORD = 264,             /* DEF_KEYWORD  */
    DEFINED_KEYWORD = 265,         /* DEFINED_KEYWORD  */
    DO_KEYWORD = 266,              /* DO_KEYWORD  */
    IF_KEYWORD = 267,              /* IF_KEYWORD  */
    ELSE_KEYWORD = 268,            /* ELSE_KEYWORD  */
    ELSIF_KEYWORD = 269,           /* ELSIF_KEYWORD  */
    END_KEYWORD = 270,             /* END_KEYWORD  */
    ENSURE_KEYWORD = 271,          /* ENSURE_KEYWORD  */
    FALSE_KEYWORD = 272,           /* FALSE_KEYWORD  */
    FOR_KEYWORD = 273,             /* FOR_KEYWORD  */
    IN_KEYWORD = 274,              /* IN_KEYWORD  */
    MODULE_KEYWORD = 275,          /* MODULE_KEYWORD  */
    NEXT_KEYWORD = 276,            /* NEXT_KEYWORD  */
    NIL_KEYWORD = 277,             /* NIL_KEYWORD  */
    NOT_KEYWORD = 278,             /* NOT_KEYWORD  */
    OR_KEYWORD = 279,              /* OR_KEYWORD  */
    REDO_KEYWORD = 280,            /* REDO_KEYWORD  */
    RESCUE_KEYWORD = 281,          /* RESCUE_KEYWORD  */
    RETRY_KEYWORD = 282,           /* RETRY_KEYWORD  */
    RETURN_KEYWORD = 283,          /* RETURN_KEYWORD  */
    SELF_KEYWORD = 284,            /* SELF_KEYWORD  */
    SUPER_KEYWORD = 285,           /* SUPER_KEYWORD  */
    THEN_KEYWORD = 286,            /* THEN_KEYWORD  */
    TRUE_KEYWORD = 287,            /* TRUE_KEYWORD  */
    UNDEF_KEYWORD = 288,           /* UNDEF_KEYWORD  */
    UNLESS_KEYWORD = 289,          /* UNLESS_KEYWORD  */
    UNTIL_KEYWORD = 290,           /* UNTIL_KEYWORD  */
    WHEN_KEYWORD = 291,            /* WHEN_KEYWORD  */
    WHILE_KEYWORD = 292,           /* WHILE_KEYWORD  */
    YIELD_KEYWORD = 293,           /* YIELD_KEYWORD  */
    ARITHMETIC_PLUS_OP = 294,      /* ARITHMETIC_PLUS_OP  */
    ARITHMETIC_MINUS_OP = 295,     /* ARITHMETIC_MINUS_OP  */
    ARITHMETIC_MUL_OP = 296,       /* ARITHMETIC_MUL_OP  */
    ARITHMETIC_DIV_OP = 297,       /* ARITHMETIC_DIV_OP  */
    ARITHMETIC_MOD_OP = 298,       /* ARITHMETIC_MOD_OP  */
    ARITHMETIC_POW_OP = 299,       /* ARITHMETIC_POW_OP  */
    EQL_OP = 300,                  /* EQL_OP  */
    NOT_EQL_OP = 301,              /* NOT_EQL_OP  */
    GREATER_OP = 302,              /* GREATER_OP  */
    LESS_OP = 303,                 /* LESS_OP  */
    GREATER_OR_EQL_OP = 304,       /* GREATER_OR_EQL_OP  */
    LESS_OR_EQL_OP = 305,          /* LESS_OR_EQL_OP  */
    COMB_COMPRASION_OP = 306,      /* COMB_COMPRASION_OP  */
    CASE_EQL_OP = 307,             /* CASE_EQL_OP  */
    RECEIVER_EQL_OP = 308,         /* RECEIVER_EQL_OP  */
    OBJ_ID_EQL_OP = 309,           /* OBJ_ID_EQL_OP  */
    ASSIGN_OP = 310,               /* ASSIGN_OP  */
    ADD_ASSIGN_OP = 311,           /* ADD_ASSIGN_OP  */
    SUB_ASSIGN_OP = 312,           /* SUB_ASSIGN_OP  */
    MUL_ASSIGN_OP = 313,           /* MUL_ASSIGN_OP  */
    DIV_ASSIGN_OP = 314,           /* DIV_ASSIGN_OP  */
    MOD_ASSIGN_OP = 315,           /* MOD_ASSIGN_OP  */
    POW_ASSIGN_OP = 316,           /* POW_ASSIGN_OP  */
    BIN_AND_OP = 317,              /* BIN_AND_OP  */
    BIN_OR_OP = 318,               /* BIN_OR_OP  */
    BIN_XOR_OP = 319,              /* BIN_XOR_OP  */
    BIN_ONES_COMPLEMENT_OP = 320,  /* BIN_ONES_COMPLEMENT_OP  */
    BIN_LEFT_SHIFT_OP = 321,       /* BIN_LEFT_SHIFT_OP  */
    BIN_RIGHT_SHIFT_OP = 322,      /* BIN_RIGHT_SHIFT_OP  */
    LOGICAL_AND_OP = 323,          /* LOGICAL_AND_OP  */
    LOGICAL_OR_OP = 324,           /* LOGICAL_OR_OP  */
    LOGICAL_NOT_OP = 325,          /* LOGICAL_NOT_OP  */
    INCLUSIVE_RANGE_OP = 326,      /* INCLUSIVE_RANGE_OP  */
    EXCLUSIVE_RANGE_OP = 327,      /* EXCLUSIVE_RANGE_OP  */
    OPEN_ROUND_BRACKET = 328,      /* OPEN_ROUND_BRACKET  */
    CLOSE_ROUND_BRACKET = 329,     /* CLOSE_ROUND_BRACKET  */
    OPEN_CURLY_BRACKET = 330,      /* OPEN_CURLY_BRACKET  */
    CLOSE_CURLY_BRACKET = 331,     /* CLOSE_CURLY_BRACKET  */
    OPEN_SQUARE_BRACKET = 332,     /* OPEN_SQUARE_BRACKET  */
    CLOSE_SQUARE_BRACKET = 333,    /* CLOSE_SQUARE_BRACKET  */
    COMMERCIAL_AT = 334,           /* COMMERCIAL_AT  */
    QUESTION_SYMBOL = 335,         /* QUESTION_SYMBOL  */
    DOT_SYMBOL = 336,              /* DOT_SYMBOL  */
    COMMA_SYMBOL = 337,            /* COMMA_SYMBOL  */
    COLON_SYMBOL = 338,            /* COLON_SYMBOL  */
    DOUBLE_COLON_SYMBOL = 339,     /* DOUBLE_COLON_SYMBOL  */
    SEMICOLON_SYMBOL = 340,        /* SEMICOLON_SYMBOL  */
    NEW_LINE_SYMBOL = 341,         /* NEW_LINE_SYMBOL  */
    STRING = 342,                  /* STRING  */
    INTEGER_NUMBER = 343,          /* INTEGER_NUMBER  */
    FLOAT_NUMBER = 344,            /* FLOAT_NUMBER  */
    VAR_METHOD_NAME = 345,         /* VAR_METHOD_NAME  */
    INSTANCE_VAR_NAME = 346,       /* INSTANCE_VAR_NAME  */
    CLASS_NAME = 347,              /* CLASS_NAME  */
    CLASS_VAR_NAME = 348,          /* CLASS_VAR_NAME  */
    UNARY_MINUS = 349,             /* UNARY_MINUS  */
    UNARY_PLUS = 350               /* UNARY_PLUS  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 26 "Grammar.y"

    int int_un;
    float float_un;
    char * string_un;
    char * var_name_un;
    char * instance_var_name_un;
    char * class_name_un;
    char * class_var_name_un;
    struct expr_struct * expr_un; 
    struct stmt_struct * stmt_un;
    struct stmt_list_struct * stmt_list_un;

#line 172 "Grammar.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_GRAMMAR_TAB_H_INCLUDED  */
