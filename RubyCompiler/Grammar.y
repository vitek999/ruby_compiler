%{
#include <stdio.h>
void yyerror(const char* message) {
    fprintf(stderr, message);
}
int yylex();
int yyparse();
extern FILE* yyin;


%}

%token ALIAS_KEYWORD
%token AND_KEYWORD
%token BEGIN_KEYWORD
%token BREAK_KEYWORD
%token CASE_KEYWORD
%token CLASS_KEYWORD
%token DEF_KEYWORD
%token DEFINED_KEYWORD
%token DO_KEYWORD
%token IF_KEYWORD
%token ELSE_KEYWORD
%token ELSIF_KEYWORD
%token END_KEYWORD
%token ENSURE_KEYWORD
%token FALSE_KEYWORD
%token FOR_KEYWORD
%token IN_KEYWORD
%token MODULE_KEYWORD
%token NEXT_KEYWORD
%token NIL_KEYWORD
%token NOT_KEYWORD
%token OR_KEYWORD
%token REDO_KEYWORD
%token RESCUE_KEYWORD
%token RETRY_KEYWORD
%token RETURN_KEYWORD
%token SELF_KEYWORD
%token SUPER_KEYWORD
%token THEN_KEYWORD
%token TRUE_KEYWORD
%token UNDEF_KEYWORD
%token UNLESS_KEYWORD
%token UNTIL_KEYWORD
%token WHEN_KEYWORD
%token WHILE_KEYWORD
%token YIELD_KEYWORD

%token ARITHMETIC_PLUS_OP
%token ARITHMETIC_MINUS_OP
%token ARITHMETIC_MUL_OP
%token ARITHMETIC_DIV_OP
%token ARITHMETIC_MOD_OP
%token ARITHMETIC_POW_OP

%token EQL_OP
%token NOT_EQL_OP
%token GREATER_OP
%token LESS_OP
%token GREATER_OR_EQL_OP
%token LESS_OR_EQL_OP
%token COMB_COMPRASION_OP
%token CASE_EQL_OP
%token RECEIVER_EQL_OP
%token OBJ_ID_EQL_OP

%token ASSIGN_OP
%token ADD_ASSIGN_OP
%token SUB_ASSIGN_OP
%token MUL_ASSIGN_OP
%token DIV_ASSIGN_OP
%token MOD_ASSIGN_OP
%token POW_ASSIGN_OP

%token BIN_AND_OP
%token BIN_OR_OP
%token BIN_XOR_OP
%token BIN_ONES_COMPLEMENT_OP
%token BIN_LEFT_SHIFT_OP
%token BIN_RIGHT_SHIFT_OP

%token LOGICAL_AND_OP
%token LOGICAL_OR_OP
%token LOGICAL_NOT_OP

%token INCLUSIVE_RANGE_OP
%token EXCLUSIVE_RANGE_OP

%token OPEN_ROUND_BRACKET
%token CLOSE_ROUND_BRACKET
%token OPEN_CURLY_BRACKET
%token CLOSE_CURLY_BRACKET
%token OPEN_SQUARE_BRACKET
%token CLOSE_SQUARE_BRACKET
%token COMMERCIAL_AT

%token QUESTION_SYMBOL
%token DOT_SYMBOL
%token COMMA_SYMBOL
%token COLON_SYMBOL
%token DOUBLE_COLON_SYMBOL
%token SEMICOLON_SYMBOL
%token NEW_LINE_SYMBOL

%token STRING 
%token INTEGER_NUMBER
%token FLOAT_NUMBER

%token VAR_METHOD_NAME
%token INSTANCE_VAR_NAME
%token CLASS_NAME
%token CLASS_VAR_NAME

%%

expr: ASSIGN_OP { puts("Found expr"); }
;

%%

void main(int argc, char **argv ){
	yyin = fopen(argv[1], "r" );

    yyparse();
    return;
}