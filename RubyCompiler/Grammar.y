%define parse.error verbose

%{
#include <stdio.h>
#include "tree_nodes.h"
#include <malloc.h>

void yyerror(const char* message) {
    fprintf(stderr, message);
}
int yylex();
int yyparse();
extern FILE* yyin;

struct expr_struct * create_const_integer_expr(enum expr_type type, int val);
struct expr_struct * create_const_float_expr(float val);
struct expr_struct * create_const_string_expr(enum expr_type type, char * val);
struct expr_struct * create_op_expr(enum expr_type type, struct expr_struct * left, struct expr_struct * right);
struct stmt_list_struct * create_stmt_list(struct stmt_struct * val);
struct stmt_list_struct * add_to_stmt_list(struct stmt_list_struct * list, struct stmt_struct * val);

%}

%union {
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
}

%type <expr_un> expr
%type <stmt_un> stmt
%type <stmt_list_un> stmt_list

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

%token <string_un> STRING 
%token <int_un> INTEGER_NUMBER
%token <float_un> FLOAT_NUMBER

%token <var_name_un> VAR_METHOD_NAME
%token <instance_var_name_un> INSTANCE_VAR_NAME
%token <class_name_un> CLASS_NAME
%token <class_var_name_un> CLASS_VAR_NAME

%start program

%left UNTIL_KEYWORD WHILE_KEYWORD
%left AND_KEYWORD OR_KEYWORD
%right NOT_KEYWORD
%left DEFINED_KEYWORD
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
%nonassoc OPEN_ROUND_BRACKET CLOSE_ROUND_BRACKET

%%
program: stmt_list  { puts("program"); }

expr: INTEGER_NUMBER { $$=create_const_integer_expr(Integer, $1); /* puts("integer"); */ }
    | FLOAT_NUMBER { $$=create_const_float_expr($1); /* puts("float"); */}
    | STRING { $$=create_const_string_expr(String, $1); /* puts("string"); */ }
    | NIL_KEYWORD { puts("nil"); }
    | TRUE_KEYWORD { $$=create_const_integer_expr(Boolean, 1); /* puts("true"); */ }
    | FALSE_KEYWORD { $$=create_const_integer_expr(Boolean, 0); /* puts("false"); */ }
    | LOGICAL_NOT_OP expr { $$=create_op_expr(logical_not, $2, 0); /* puts("LOGICAL_NOT_OP"); */ }
    | BIN_ONES_COMPLEMENT_OP expr { $$=create_op_expr(bin_ones_complement, $2, 0); /* puts("BIN_ONES_COMPLEMENT_OP"); */ }
    | ARITHMETIC_PLUS_OP expr %prec UNARY_PLUS { $$=create_op_expr(unary_plus, $2, 0); /* puts("unary plus"); */ }
    | expr ARITHMETIC_POW_OP expr {  $$=create_op_expr(pow, $1, $3); /*  puts("pow"); */ }
    | ARITHMETIC_MINUS_OP expr %prec UNARY_MINUS { $$=create_op_expr(unary_minus, $2, 0); /*  puts("unary minus"); */ }
    | expr ARITHMETIC_MUL_OP expr { $$=create_op_expr(mul, $1, $3); /* puts("mul"); */ }
    | expr ARITHMETIC_DIV_OP expr {  $$=create_op_expr(div, $1, $3); /* puts("div"); */ }
    | expr ARITHMETIC_MOD_OP expr {  $$=create_op_expr(mod, $1, $3); /* puts("mod"); */ }
    | expr ARITHMETIC_PLUS_OP expr {  $$=create_op_expr(plus, $1, $3); /* puts("plus"); */ }
    | expr ARITHMETIC_MINUS_OP expr { $$=create_op_expr(minus, $1, $3); /* puts("minus"); */ }
    | expr BIN_LEFT_SHIFT_OP expr { $$=create_op_expr(bin_left_shift, $1, $3); /* puts("left shift"); */ }
    | expr BIN_RIGHT_SHIFT_OP expr { $$=create_op_expr(bin_right_shift, $1, $3); /* puts("right shift"); */ }
    | expr BIN_AND_OP expr { $$=create_op_expr(bin_and_op, $1, $3); /* puts("bin and"); */ }
    | expr BIN_OR_OP expr { $$=create_op_expr(bin_or_op, $1, $3); /* puts("bin or"); */ }
    | expr BIN_XOR_OP expr { $$=create_op_expr(bin_xor_op, $1, $3); /* puts("bin xor"); */ }
    | expr GREATER_OP expr { $$=create_op_expr(greater, $1, $3); /* puts(" > "); */ }
    | expr LESS_OP expr { $$=create_op_expr(less, $1, $3); /* puts(" < "); */ }
    | expr GREATER_OR_EQL_OP expr { $$=create_op_expr(greater_eql, $1, $3); /* puts(" >= "); */ }
    | expr LESS_OR_EQL_OP expr { $$=create_op_expr(less_eql, $1, $3); /* puts(" <= "); */ }
    | expr COMB_COMPRASION_OP expr { $$=create_op_expr(comb_comprassion, $1, $3); /* puts(" COMB_COMPRASION_OP "); */ }
    | expr EQL_OP expr { $$=create_op_expr(equal, $1, $3); /* puts(" EQL_OP "); */ }
    | expr CASE_EQL_OP expr {  $$=create_op_expr(case_equal, $1, $3); /* puts(" CASE_EQL_OP "); */ }
    | expr NOT_EQL_OP expr { $$=create_op_expr(not_equal, $1, $3); /* puts("NOT_EQL_OP"); */ }
    | expr LOGICAL_AND_OP expr { $$=create_op_expr(logical_and, $1, $3); /* puts("LOGICAL_AND_OP"); */ }
    | expr LOGICAL_OR_OP expr { $$=create_op_expr(logical_or, $1, $3); /* puts("LOGICAL_OR_OP");  */ }
    | expr INCLUSIVE_RANGE_OP expr { $$=create_op_expr(inclusive_range, $1, $3); /* puts("INCLUSIVE_RANGE_OP"); */ }
    | expr EXCLUSIVE_RANGE_OP expr { $$=create_op_expr(exclusive_range, $1, $3); /* puts("EXCLUSIVE_RANGE_OP"); */ }
    | expr ASSIGN_OP expr { $$=create_op_expr(assign, $1, $3); /* puts("assign"); */ }
    | expr MOD_ASSIGN_OP expr { $$=create_op_expr(mod_assign, $1, $3); /* puts("MOD_ASSIGN_OP"); */ }
    | expr DIV_ASSIGN_OP expr { $$=create_op_expr(div_assign, $1, $3); /* puts("DIV_ASSIGN_OP"); */ }
    | expr SUB_ASSIGN_OP expr { $$=create_op_expr(sub_assign, $1, $3); /* puts("SUB_ASSIGN_OP"); */ }
    | expr ADD_ASSIGN_OP expr { $$=create_op_expr(add_assign, $1, $3); /* puts("SUB_ASSIGN_OP"); */ }
    | expr MUL_ASSIGN_OP expr { $$=create_op_expr(mul_assign, $1, $3); /* puts("MUL_ASSIGN_OP"); */ }
    | expr POW_ASSIGN_OP expr { $$=create_op_expr(pow_assign, $1, $3); /* puts("POW_ASSIGN_OP"); */ }
    | expr UNTIL_KEYWORD expr {}  
    | expr WHILE_KEYWORD expr {}  
    | DEFINED_KEYWORD expr { $$=create_op_expr(defined, $2, 0); /* puts("DEFINED_KEYWORD"); */ }
    | NOT_KEYWORD expr { $$=create_op_expr(not_keyword, $2, 0); /* puts("NOT_KEYWORD");  */ }
    | expr AND_KEYWORD expr { $$=create_op_expr(and_keyword, $1, $3); /* puts("AND_KEYWORD"); */ }
    | expr OR_KEYWORD expr { $$=create_op_expr(or_keyword, $1, $3); /* puts("OR_KEYWORD"); */ }
    | OPEN_ROUND_BRACKET expr CLOSE_ROUND_BRACKET { $$=$2; /* puts(" expr in round brackets "); */ }
	| OPEN_SQUARE_BRACKET expr CLOSE_SQUARE_BRACKET { puts(" expr in square brackets "); }
    | VAR_METHOD_NAME OPEN_ROUND_BRACKET method_call_param_list CLOSE_ROUND_BRACKET { puts("method call"); /*!!!! ВОПРОС !!!!*/ }
    | VAR_METHOD_NAME { $$=create_const_string_expr(var_or_method, $1); /* puts("var"); */ }     
    | INSTANCE_VAR_NAME { $$=create_const_string_expr(instance_var, $1); /* puts("instance var"); */ }
    ;

stmt_ends: SEMICOLON_SYMBOL
    | NEW_LINE_SYMBOL
    | SEMICOLON_SYMBOL stmt_ends
    | NEW_LINE_SYMBOL stmt_ends
    ;

stmt_ends_op: /* empty */
    | stmt_ends
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
    | until_stmt    { puts("until stmt"); }
    | until_stmt stmt_ends   { puts("until stmt"); }
    | def_method_stmt   { puts("def method"); }
    | def_method_stmt stmt_ends { puts("def method"); }
    ;

stmt_list_not_empty: stmt  { puts("list from one stmt"); }
    | stmt stmt_list_not_empty { puts("add stmt to list"); }
    ;

stmt_list: /* empty */ { puts("empty stmt list"); }
    | stmt_list_not_empty  { puts("stmt list"); }
    ;

stmt_block: BEGIN_KEYWORD stmt_ends_op stmt_list END_KEYWORD  { puts("begin without stmt ends"); }
    ;

if_start_stmt: IF_KEYWORD expr stmt_ends stmt_list { puts("if without then"); }
    | IF_KEYWORD expr THEN_KEYWORD stmt_ends_op stmt_list { puts("if with then"); }
    ;

elsif_stmt: ELSIF_KEYWORD expr stmt_ends stmt_list { puts("elsif without then");  } 
    | ELSIF_KEYWORD expr THEN_KEYWORD stmt_ends_op stmt_list { puts("elsif with then");  } 
    ;

elsif_stmt_list: elsif_stmt 
    | elsif_stmt elsif_stmt_list
    ;

if_stmt: if_start_stmt END_KEYWORD
    | if_start_stmt ELSE_KEYWORD stmt_ends_op stmt_list END_KEYWORD 
    | if_start_stmt elsif_stmt_list END_KEYWORD
    | if_start_stmt elsif_stmt_list ELSE_KEYWORD stmt_ends_op stmt_list END_KEYWORD
    ;

for_stmt: FOR_KEYWORD VAR_METHOD_NAME IN_KEYWORD expr stmt_ends stmt_list END_KEYWORD 
    | FOR_KEYWORD INSTANCE_VAR_NAME IN_KEYWORD expr stmt_ends stmt_list END_KEYWORD
	| FOR_KEYWORD VAR_METHOD_NAME IN_KEYWORD expr DO_KEYWORD stmt_ends_op stmt_list END_KEYWORD
    | FOR_KEYWORD INSTANCE_VAR_NAME IN_KEYWORD expr DO_KEYWORD stmt_ends_op stmt_list END_KEYWORD
	;

while_stmt: WHILE_KEYWORD expr stmt_ends stmt_list END_KEYWORD
	| WHILE_KEYWORD expr DO_KEYWORD stmt_ends_op stmt_list END_KEYWORD
	;

until_stmt: UNTIL_KEYWORD expr stmt_ends stmt_list END_KEYWORD
	| UNTIL_KEYWORD expr DO_KEYWORD stmt_ends_op stmt_list END_KEYWORD
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

%%

struct expr_struct * create_const_integer_expr(enum expr_type type, int val) {
    struct expr_struct * result = (struct expr_struct *) malloc(sizeof(struct expr_struct));
    result->type = type;
    result->int_val = val;
    return result;
}

struct expr_struct * create_const_float_expr(float val) {
    struct expr_struct * result = (struct expr_struct *) malloc(sizeof(struct expr_struct));
    result->type = Float ;
    result->float_val = val;
    return result;
}

struct expr_struct * create_const_string_expr(enum expr_type type, char * val) {
    struct expr_struct * result = (struct expr_struct *) malloc(sizeof(struct expr_struct));
    result->type = type;
    result->str_val = val;
    return result;
}

struct expr_struct * create_op_expr(enum expr_type type, struct expr_struct * left, struct expr_struct * right) {
    struct expr_struct * result = (struct expr_struct *) malloc(sizeof(struct expr_struct));
    result->type = type;
    result->left = left;
    result->right = right;
}

struct stmt_list_struct * create_stmt_list(struct stmt_struct * val) {
    struct stmt_list_struct * res = (struct stmt_list_struct *) malloc(sizeof(struct stmt_list_struct));
    res->first = val;
    res->last = val;
    return res;
}

struct stmt_list_struct * add_to_stmt_list(struct stmt_list_struct * list, struct stmt_struct * val) {
    list->last->next = val;
    list->last = val;
    return list;
}

void main(int argc, char **argv ){
	yyin = fopen(argv[1], "r" );

    yyparse();
    return;
}