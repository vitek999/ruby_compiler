%define parse.error verbose

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

%start program

%left AND_KEYWORD OR_KEYWORD
%right NOT_KEYWORD
%nonassoc DEFINED_KEYWORD
%right ASSIGN_OP MOD_ASSIGN_OP DIV_ASSIGN_OP SUB_ASSIGN_OP ADD_ASSIGN_OP MUL_ASSIGN_OP POW_ASSIGN_OP
%nonassoc INCLUSIVE_RANGE_OP EXCLUSIVE_RANGE_OP
%left LOGICAL_OR_OP
%left LOGICAL_AND_OP
%nonassoc COMB_COMPRASION_OP EQL_OP CASE_EQL_OP NOT_EQL_OP
%left GREATER_OP LESS_OP GREATER_OR_EQL_OP LESS_OR_EQL_OP
%left BIN_OR_OP BIN_XOR_OP
%left BIN_AND_OP
%left BIN_LEFT_SHIFT_OP BIN_RIGHT_SHIFT_OP
%left ARITHMETIC_PLUS_OP ARITHMETIC_MINUS_OP
%left ARITHMETIC_MUL_OP ARITHMETIC_DIV_OP ARITHMETIC_MOD_OP
%right UNARY_MINUS
%right LOGICAL_NOT_OP BIN_ONES_COMPLEMENT_OP UNARY_PLUS ARITHMETIC_POW_OP  
%nonassoc CLOSE_ROUND_BRACKET

%%
program: stmt_list  { puts("program"); }

expr: INTEGER_NUMBER { puts("integer"); }
    | FLOAT_NUMBER   { puts("float"); }
    | STRING         { puts("string"); }
    | NIL_KEYWORD    { puts("nil"); }
    | TRUE_KEYWORD   { puts("true"); }
    | FALSE_KEYWORD  { puts("false"); }
    | LOGICAL_NOT_OP expr { puts("LOGICAL_NOT_OP"); }
    | BIN_ONES_COMPLEMENT_OP expr { puts("BIN_ONES_COMPLEMENT_OP"); }
    | ARITHMETIC_PLUS_OP expr %prec UNARY_PLUS { puts("unary plus"); }
    | expr ARITHMETIC_POW_OP expr { puts("pow"); }
    | ARITHMETIC_MINUS_OP expr %prec UNARY_MINUS  { puts("unary minus"); }
    | expr ARITHMETIC_MUL_OP expr  { puts("mul"); }
    | expr ARITHMETIC_DIV_OP expr { puts("div"); }
    | expr ARITHMETIC_MOD_OP expr  { puts("mod"); }
    | expr ARITHMETIC_PLUS_OP expr { puts("plus"); }
    | expr ARITHMETIC_MINUS_OP expr { puts("minus"); }
    | expr BIN_LEFT_SHIFT_OP expr  { puts("left shift"); }
    | expr BIN_RIGHT_SHIFT_OP expr { puts("right shift"); }
    | expr BIN_AND_OP expr { puts("bin and"); }
    | expr BIN_OR_OP expr   { puts("bin or"); }
    | expr BIN_XOR_OP expr  { puts("bin xor"); }
    | expr GREATER_OP expr  { puts(" > "); }
    | expr LESS_OP expr      { puts(" < "); }
    | expr GREATER_OR_EQL_OP expr  { puts(" >= "); }
    | expr LESS_OR_EQL_OP expr      { puts(" <= "); }
    | expr COMB_COMPRASION_OP expr   { puts(" COMB_COMPRASION_OP "); }
    | expr EQL_OP expr          { puts(" EQL_OP "); }
    | expr CASE_EQL_OP expr     { puts(" CASE_EQL_OP "); }
    | expr NOT_EQL_OP expr      { puts("NOT_EQL_OP"); }
    | expr LOGICAL_AND_OP expr  { puts("LOGICAL_AND_OP"); }
    | expr LOGICAL_OR_OP expr   { puts("LOGICAL_OR_OP"); }
    | expr INCLUSIVE_RANGE_OP expr  { puts("INCLUSIVE_RANGE_OP"); }
    | expr EXCLUSIVE_RANGE_OP expr  { puts("EXCLUSIVE_RANGE_OP"); }
    | expr ASSIGN_OP expr           { puts("assign"); }
    | expr MOD_ASSIGN_OP expr               { puts("MOD_ASSIGN_OP"); }
    | expr DIV_ASSIGN_OP expr       { puts("DIV_ASSIGN_OP"); }
    | expr SUB_ASSIGN_OP expr        { puts("SUB_ASSIGN_OP"); }
    | expr ADD_ASSIGN_OP expr         { puts("SUB_ASSIGN_OP"); }
    | expr MUL_ASSIGN_OP expr           { puts("MUL_ASSIGN_OP"); }
    | expr POW_ASSIGN_OP expr       { puts("POW_ASSIGN_OP"); }
    | DEFINED_KEYWORD expr          { puts("DEFINED_KEYWORD"); }
    | NOT_KEYWORD expr               { puts("NOT_KEYWORD"); }
    | expr AND_KEYWORD expr         { puts("AND_KEYWORD"); }
    | expr OR_KEYWORD expr          { puts("OR_KEYWORD"); }
    | OPEN_ROUND_BRACKET expr CLOSE_ROUND_BRACKET    { puts(" expr in round brackets "); }
	| OPEN_SQUARE_BRACKET expr CLOSE_SQUARE_BRACKET     { puts(" expr in square brackets "); }
    | method_call_stmt                       { puts("method call"); }
    | VAR_METHOD_NAME  { puts("var"); }     
    | INSTANCE_VAR_NAME     { puts("instance var"); }
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

stmt: expr stmt_ends { puts("stmt"); }
    | stmt_block    { puts("stmt block"); }
    | stmt_block stmt_ends
    | if_stmt       { puts("if stmt"); }
    | if_stmt stmt_ends    { puts("if stmt"); }
    | for_stmt       { puts("for stmt"); }
    | for_stmt stmt_ends
    | while_stmt         { puts("while stmt"); }
    | while_stmt stmt_ends       { puts("while stmt"); }
    | while_modifier_stmt /* maybe binary opertaor with N/A association */ { puts("while modifer stmt"); }
    | while_modifier_stmt stmt_ends /* maybe binary opertaor with N/A association */ { puts("while modifer stmt"); }
    | until_stmt    { puts("until stmt"); }
    | until_stmt stmt_ends   { puts("until stmt"); }
    | until_modifier_stmt /* maybe binary opertaor with N/A association */ { puts("until modifer stmt"); }
    | until_modifier_stmt stmt_ends /* maybe binary opertaor with N/A association */ { puts("until modifer stmt"); }
    | def_method_stmt   { puts("def method"); }
    | def_method_stmt stmt_ends { puts("def method"); }
    ;

stmt_list_not_empty: stmt  { puts("list from one stmt"); }
    | stmt_list_not_empty stmt { puts("add stmt to list"); }
    ;

stmt_list: /* empty */ { puts("empty stmt list"); }
    | stmt_list_not_empty  { puts("stmt list"); }
    ;

stmt_block: BEGIN_KEYWORD stmt_list END_KEYWORD  { puts("begin without stmt ends"); }
    | BEGIN_KEYWORD stmt_ends stmt_list END_KEYWORD { puts("begin with stmt ends"); }
    ;

if_start_stmt: IF_KEYWORD expr stmt_ends stmt_list { puts("if without then"); }
    | IF_KEYWORD expr THEN_KEYWORD stmt_list { puts("if with then"); }
    | IF_KEYWORD expr THEN_KEYWORD stmt_ends stmt_list { puts("if with then"); }
    ;

elsif_stmt: ELSIF_KEYWORD expr stmt_ends stmt_list { puts("elsif without then");  } 
    | ELSIF_KEYWORD expr THEN_KEYWORD stmt_list { puts("elsif with then");  } 
    | ELSIF_KEYWORD expr THEN_KEYWORD stmt_ends stmt_list { puts("elsif with then");  } 
    ;

elsif_stmt_list: elsif_stmt 
    | elsif_stmt_list elsif_stmt
    ;

if_stmt: if_start_stmt END_KEYWORD
    | if_start_stmt ELSE_KEYWORD stmt_list END_KEYWORD 
    | if_start_stmt ELSE_KEYWORD stmt_ends stmt_list END_KEYWORD 
    | if_start_stmt elsif_stmt_list END_KEYWORD
    | if_start_stmt elsif_stmt_list ELSE_KEYWORD stmt_list END_KEYWORD
    | if_start_stmt elsif_stmt_list ELSE_KEYWORD stmt_ends stmt_list END_KEYWORD
    ;

for_stmt: FOR_KEYWORD VAR_METHOD_NAME IN_KEYWORD expr stmt_ends stmt_list END_KEYWORD 
    | FOR_KEYWORD INSTANCE_VAR_NAME IN_KEYWORD expr stmt_ends stmt_list END_KEYWORD
	| FOR_KEYWORD VAR_METHOD_NAME IN_KEYWORD expr DO_KEYWORD stmt_list END_KEYWORD
    | FOR_KEYWORD VAR_METHOD_NAME IN_KEYWORD expr DO_KEYWORD stmt_ends stmt_list END_KEYWORD
    | FOR_KEYWORD INSTANCE_VAR_NAME IN_KEYWORD expr DO_KEYWORD stmt_list END_KEYWORD
    | FOR_KEYWORD INSTANCE_VAR_NAME IN_KEYWORD expr DO_KEYWORD stmt_ends stmt_list END_KEYWORD
	;

while_stmt: WHILE_KEYWORD expr stmt_ends stmt_list END_KEYWORD
	| WHILE_KEYWORD expr DO_KEYWORD stmt_list END_KEYWORD
    | WHILE_KEYWORD expr DO_KEYWORD stmt_ends stmt_list END_KEYWORD
	;

while_modifier_stmt: expr WHILE_KEYWORD expr
	;

until_stmt: UNTIL_KEYWORD expr stmt_ends stmt_list END_KEYWORD
	| UNTIL_KEYWORD expr DO_KEYWORD stmt_list END_KEYWORD
    | UNTIL_KEYWORD expr DO_KEYWORD stmt_ends stmt_list END_KEYWORD
	;

until_modifier_stmt: expr UNTIL_KEYWORD expr
	;

method_param: VAR_METHOD_NAME
	| VAR_METHOD_NAME ASSIGN_OP expr
	;

method_params_list: /* empty */
	| method_params_list_not_empty
	;

method_params_list_not_empty: method_param
	| method_params_list_not_empty COMMA_SYMBOL method_param
	;

def_method_stmt: DEF_KEYWORD VAR_METHOD_NAME stmt_ends stmt_list END_KEYWORD  
    | DEF_KEYWORD VAR_METHOD_NAME OPEN_ROUND_BRACKET method_params_list CLOSE_ROUND_BRACKET stmt_list END_KEYWORD
    ;

method_call_param_list: /* empty */
	| method_call_param_list_not_empty
	;

method_call_param_list_not_empty: expr
	| method_call_param_list_not_empty COMMA_SYMBOL expr
	;

method_call_stmt: VAR_METHOD_NAME OPEN_ROUND_BRACKET method_call_param_list CLOSE_ROUND_BRACKET
	; /* Есть еще вариант без скобочек, не знаю, есть ли смысл его рассматривать */

%%

void main(int argc, char **argv ){
	yyin = fopen(argv[1], "r" );

    yyparse();
    return;
}