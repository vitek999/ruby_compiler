%{
	#include <stdio.h>
	#include <malloc.h>
%}


%token NEW_LINE
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
%token CLOSE_ROUND_BRACKET
%token OPEN_CURLY_BRACKET
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

expr: INT
    | ID /* не знаю надо ли... наверное, надо*/
	| STRING
	| TRUE_KEYWORD
	| FALSE_KEYWORD
	| NIL_KEYWORD
	| expr ARITHMETIC_PLUS_OP expr
	| expr ARITHMETIC_MINUS_OP expr
	| expr ARITHMETIC_MUL_OP expr
	| expr ARITHMETIC_DIV_OP expr
	| expr ARITHMETIC_MOD_OP expr
	| expr ARITHMETIC_POW_OP expr
	| expr EQL_OP expr
	| expr NOT_EQL_OP expr
	| expr GREATER_OP expr
	| expr LESS_OP expr
	| expr GREATER_OR_EQL_OP expr
	| expr LESS_OR_EQL_OP expr
	| expr COMB_COMPRASION_OP expr
	| expr CASE_EQL_OP expr
	| expr RECEIVER_EQL_OP expr
	| expr OBJ_ID_EQL_OP expr
	| expr ASSIGN_OP expr
	| expr ADD_ASSIGN_OP expr
	| expr SUB_ASSIGN_OP expr
	| expr MUL_ASSIGN_OP expr
	| expr DIV_ASSIGN_OP expr
	| expr MOD_ASSIGN_OP expr
	| expr POW_ASSIGN_OP expr
	| expr BIN_AND_OP expr
	| expr BIN_OR_OP expr 
	| expr BIN_XOR_OP expr
	| expr LOGICAL_AND_OP expr
	| expr LOGICAL_OR_OP expr
	| expr INCLUSIVE_RANGE_OP expr
	| expr EXCLUSIVE_RANGE_OP expr 
	| OPEN_ROUND_BRACKET expr CLOSE_ROUND_BRACKET 
	| OPEN_SQUARE_BRACKET expr CLOSE_SQUARE_BRACKET 
	| expr AND_KEYWORD expr
	| expr OR_KEYWORD expr
	| LOGICAL_NOT_OP expr
	| ARITHMETIC_MINUS_OP expr
	| ARITHMETIC_PLUS_OP expr
	| expr QUESTION_SYMBOL expr COLON_SYMBOL expr 
	| BIN_ONES_COMPLEMENT_OP expr
	| DEFINED_KEYWORD expr
	| DOUBLE_COLON_SYMBOL expr
	| method_call_stmt
	;


stmt: /* !!!!! пока думаем !!!!*/ 
	| if_stmt
	| for_stmt
	| while_stmt
	| while_modifier_stmt
	| stmt_block
	| until_stmt
	| until_modifier_stmt
	| def_method_stmt /* Не уверен =( */
	;

stmt_block: BEGIN_KEYWORD stmt_list END_KEYWORD
	;

stmt_list: /* empty */
	| stmt_list_not_empty
	;

stmt_list_not_empty: stmt
	| stmt_list_not_empty COMMA_SYMBOL stmt
	| stmt_list_not_empty NEW_LINE_SYMBOL stmt
	;

if_start_stmt: IF_KEYWORD expr COMMA_SYMBOL stmt_list
	| IF_KEYWORD expr NEW_LINE_SYMBOL stmt_list
	| IF_KEYWORD expr THEN_KEYWORD stmt_list
	; 

elsif_stmt: ELSIF_KEYWORD expr COMMA_SYMBOL stmt_list
	| ELSIF_KEYWORD expr NEW_LINE_SYMBOL stmt_list
	| ELSIF_KEYWORD expr THEN_KEYWORD stmt_list
	;

elsif_stmt_list: elsif_stmt
	| elsif_stmt_list COMMA_SYMBOL elsif_stmt
	| elsif_stmt_list NEW_LINE_SYMBOL elsif_stmt
	;

if_stmt: if_start_stmt END_KEYWORD
	| if_start_stmt ELSE_KEYWORD stmt_list END_KEYWORD 
	| if_start_stmt elsif_stmt_list END_KEYWORD
	| if_start_stmt elsif_stmt_list ELSE_KEYWORD stmt_list END_KEYWORD
	;

for_stmt: FOR_KEYWORD ID IN_KEYWORD expr COMMA_SYMBOL stmt_list END_KEYWORD
	| FOR_KEYWORD ID IN_KEYWORD expr NEW_LINE_SYMBOL stmt_list END_KEYWORD
	| FOR_KEYWORD ID IN_KEYWORD expr DO_KEYWORD stmt_list END_KEYWORD
	;

while_stmt: WHILE_KEYWORD expr COMMA_SYMBOL stmt_list END_KEYWORD
	| WHILE_KEYWORD expr NEW_LINE_SYMBOL stmt_list END_KEYWORD
	| WHILE_KEYWORD expr DO_KEYWORD stmt_list END_KEYWORD
	;

while_modifier_stmt: stmt WHILE_KEYWORD expr
	;

until_stmt: UNTIL_KEYWORD expr COMMA_SYMBOL stmt_list END_KEYWORD
	| UNTIL_KEYWORD expr NEW_LINE_SYMBOL stmt_list END_KEYWORD
	| UNTIL_KEYWORD expr DO_KEYWORD stmt_list END_KEYWORD
	;

until_modifier_stmt: stmt UNTIL_KEYWORD expr
	;

method_param: ID
	| ID ASSIGN_OP expr
	;

method_params_list: /* empty */
	| method_params_list_not_empty
	;

method_params_list_not_empty: method_param
	| method_params_list_not_empty COMMA_SYMBOL method_param
	;

def_method_stmt: DEF_KEYWORD ID stmt_list COMMA_SYMBOL END_KEYWORD
	| DEF_KEYWORD ID NEW_LINE_SYMBOL stmt_list END_KEYWORD
	| DEF_KEYWORD ID OPEN_ROUND_BRACKET method_params_list CLOSE_ROUND_BRACKET stmt_list END_KEYWORD
	;

method_call_param_list: /* empty */
	| method_call_param_list_not_empty
	;

method_call_param_list_not_empty: expr
	| method_call_param_list_not_empty COMMA_SYMBOL expr
	;

method_call_stmt: ID OPEN_ROUND_BRACKET method_call_param_list CLOSE_ROUND_BRACKET
	; /* Есть еще вариант без скобочек, не знаю, есть ли смысл его рассматривать */


class_decloration: 
	;

%% 

