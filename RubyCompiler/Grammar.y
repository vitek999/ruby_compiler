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

%right LOGICAL_NOT_OP BIN_ONES_COMPLEMENT_OP UNARY_PLUS ARITHMETIC_POW_OP  
%right UNARY_MINUS
%left ARITHMETIC_MUL_OP ARITHMETIC_DIV_OP ARITHMETIC_MOD_OP
%left ARITHMETIC_PLUS_OP ARITHMETIC_MINUS_OP
%left BIN_LEFT_SHIFT_OP BIN_RIGHT_SHIFT_OP
%left BIN_AND_OP
%left BIN_OR_OP BIN_XOR_OP
%left GREATER_OP LESS_OP GREATER_OR_EQL_OP LESS_OR_EQL_OP
%nonassoc COMB_COMPRASION_OP EQL_OP CASE_EQL_OP NOT_EQL_OP
%left LOGICAL_AND_OP
%left LOGICAL_OR_OP
%nonassoc INCLUSIVE_RANGE_OP EXCLUSIVE_RANGE_OP
%right ASSIGN_OP MOD_ASSIGN_OP DIV_ASSIGN_OP SUB_ASSIGN_OP ADD_ASSIGN_OP MUL_ASSIGN_OP POW_ASSIGN_OP
%nonassoc DEFINED_KEYWORD
%right NOT_KEYWORD
%left AND_KEYWORD OR_KEYWORD
%nonassoc CLOSE_ROUND_BRACKET

%%

expr: INTEGER_NUMBER
    | FLOAT_NUMBER
    | STRING
    | NIL_KEYWORD
    | TRUE_KEYWORD
    | FALSE_KEYWORD
    | LOGICAL_NOT_OP expr
    | BIN_ONES_COMPLEMENT_OP expr
    | ARITHMETIC_PLUS_OP expr %prec UNARY_PLUS
    | expr ARITHMETIC_POW_OP expr
    | ARITHMETIC_MINUS_OP expr %prec UNARY_MINUS
    | expr ARITHMETIC_MUL_OP expr
    | expr ARITHMETIC_DIV_OP expr
    | expr ARITHMETIC_MOD_OP expr
    | expr ARITHMETIC_PLUS_OP expr
    | expr ARITHMETIC_MINUS_OP expr
    | expr BIN_LEFT_SHIFT_OP expr
    | expr BIN_RIGHT_SHIFT_OP expr
    | expr BIN_AND_OP expr
    | expr BIN_OR_OP expr
    | expr BIN_XOR_OP expr
    | expr GREATER_OP expr
    | expr LESS_OP expr
    | expr GREATER_OR_EQL_OP expr
    | expr LESS_OR_EQL_OP expr
    | expr COMB_COMPRASION_OP expr
    | expr EQL_OP expr
    | expr CASE_EQL_OP expr
    | expr NOT_EQL_OP expr
    | expr LOGICAL_AND_OP expr
    | expr LOGICAL_OR_OP expr
    | expr INCLUSIVE_RANGE_OP expr
    | expr EXCLUSIVE_RANGE_OP expr
    | expr ASSIGN_OP expr
    | expr MOD_ASSIGN_OP expr
    | expr DIV_ASSIGN_OP expr
    | expr SUB_ASSIGN_OP expr
    | expr ADD_ASSIGN_OP expr
    | expr MUL_ASSIGN_OP expr
    | expr POW_ASSIGN_OP expr
    | DEFINED_KEYWORD expr
    | NOT_KEYWORD expr
    | expr AND_KEYWORD expr 
    | expr OR_KEYWORD expr 
    | OPEN_ROUND_BRACKET expr CLOSE_ROUND_BRACKET 
	| OPEN_SQUARE_BRACKET expr CLOSE_SQUARE_BRACKET 
    ;

new_lines: NEW_LINE_SYMBOL
    | new_lines NEW_LINE_SYMBOL
    ;

semicolons: SEMICOLON_SYMBOL
    | semicolons SEMICOLON_SYMBOL
    ;

stmt_end: new_lines
    | semicolons
    ;

stmt_ends: stmt_end
    | stmt_ends stmt_end
    ;

stmt: expr stmt_ends
    | stmt_block
    ;

stmt_list_not_empty: stmt
    | stmt_list_not_empty stmt
    ;

stmt_list: /* empty */
    | stmt_list_not_empty
    ;

stmt_block: BEGIN_KEYWORD stmt_list END_KEYWORD
    ;

%%

void main(int argc, char **argv ){
	yyin = fopen(argv[1], "r" );

    yyparse();
    return;
}