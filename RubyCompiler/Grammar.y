%define parse.error verbose

%{
#include <stdio.h>
#include "tree_nodes.h"
#include "print_tree.h"
#include <malloc.h>

void yyerror(const char* message) {
    fprintf(stderr, message);
}
int yylex();
int yyparse();
extern FILE* yyin;

struct program_struct * root;

struct expr_struct * create_const_integer_expr(enum expr_type type, int val);
struct expr_struct * create_const_float_expr(float val);
struct expr_struct * create_const_string_expr(enum expr_type type, char * val);
struct expr_struct * create_op_expr(enum expr_type type, struct expr_struct * left, struct expr_struct * right);
struct expr_struct * create_method_call_expr(char * method_name, struct expr_list_struct * list);
struct stmt_struct * create_expr_stmt(struct expr_struct * val);
struct stmt_struct * create_for_stmt(char * iterable_var, struct expr_struct * condition, struct stmt_list_struct* body);
struct stmt_struct * create_while_stmt(struct expr_struct * condition, struct stmt_list_struct* body);
struct stmt_struct * create_until_stmt(struct expr_struct * condition, struct stmt_list_struct* body);
struct stmt_struct * create_if_stmt(struct if_part_stmt_struct* if_branch, struct elsif_stmt_list* elsif_branches, struct stmt_list_struct* else_branch);
struct stmt_struct * create_block_stmt(struct stmt_block_struct * val);
struct stmt_struct * create_def_method_stmt(char* name, struct method_param_list* params, struct stmt_list_struct* body);
struct stmt_list_struct * create_stmt_list(struct stmt_struct * val);
struct stmt_list_struct * add_to_stmt_list(struct stmt_list_struct * list, struct stmt_struct * val);
struct expr_list_struct * create_expr_list(struct expr_struct * val);
struct expr_list_struct * add_to_expr_list(struct expr_list_struct * list, struct expr_struct * val);
struct if_part_stmt_struct * create_if_part_struct(struct expr_struct * condition, struct stmt_list_struct * body);
struct elsif_stmt_list * create_elsif_stmt_list(struct if_part_stmt_struct * val);
struct elsif_stmt_list * add_to_elsif_stmt_list(struct elsif_stmt_list * list, struct if_part_stmt_struct * val);
struct stmt_block_struct * create_stmt_block_struct(struct stmt_list_struct * list);
struct method_param_struct * create_method_param_struct(char * name, struct expr_struct * default_value);
struct method_param_list * create_method_param_list(struct method_param_struct * val);
struct method_param_list * add_to_method_param_list(struct method_param_list * list, struct method_param_struct * val);
struct program_struct * create_program_struct(struct stmt_list_struct * stmts);

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
    struct expr_list_struct * expr_list_un;
    struct if_part_stmt_struct * if_part_un;
    struct elsif_stmt_list * elsif_list_un;
    struct stmt_block_struct* block_un;
    struct method_param_struct* method_param_un;
    struct method_param_list* method_param_list_un;
    struct program_struct * program_un;
}

%type <expr_un> expr
%type <stmt_un> stmt
%type <stmt_un> for_stmt
%type <stmt_un> while_stmt
%type <stmt_un> until_stmt
%type <stmt_un> if_stmt 
%type <stmt_un> def_method_stmt
%type <stmt_list_un> stmt_list
%type <stmt_list_un> stmt_list_not_empty
%type <expr_list_un> method_call_param_list_not_empty
%type <expr_list_un> method_call_param_list
%type <if_part_un> if_start_stmt 
%type <if_part_un> elsif_stmt
%type <elsif_list_un> elsif_stmt_list
%type <block_un> stmt_block
%type <method_param_un> method_param
%type <method_param_list_un> method_params_list_not_empty
%type <method_param_list_un> method_params_list
%type <program_un> program

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
program: stmt_list  { root=create_program_struct($1); puts("program"); }

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
    | expr UNTIL_KEYWORD expr { $$=create_op_expr(until_op, $1, $3); }  
    | expr WHILE_KEYWORD expr { $$=create_op_expr(while_op, $1, $3); }  
    | DEFINED_KEYWORD expr { $$=create_op_expr(defined, $2, 0); /* puts("DEFINED_KEYWORD"); */ }
    | NOT_KEYWORD expr { $$=create_op_expr(not_keyword, $2, 0); /* puts("NOT_KEYWORD");  */ }
    | expr AND_KEYWORD expr { $$=create_op_expr(and_keyword, $1, $3); /* puts("AND_KEYWORD"); */ }
    | expr OR_KEYWORD expr { $$=create_op_expr(or_keyword, $1, $3); /* puts("OR_KEYWORD"); */ }
    | OPEN_ROUND_BRACKET expr CLOSE_ROUND_BRACKET { $$=$2; /* puts(" expr in round brackets "); */ }
	| OPEN_SQUARE_BRACKET expr CLOSE_SQUARE_BRACKET { puts(" expr in square brackets "); }
    | VAR_METHOD_NAME OPEN_ROUND_BRACKET method_call_param_list CLOSE_ROUND_BRACKET { $$=create_method_call_expr($1, $3); puts("method call"); /*!!!! ВОПРОС !!!!*/ }
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

stmt: expr stmt_ends { $$=create_expr_stmt($1); puts("stmt"); }
    | stmt_block    { $$=create_block_stmt($1); puts("stmt block"); }
    | stmt_block stmt_ends { $$=create_block_stmt($1); }
    | if_stmt       { $$=$1; puts("if stmt"); }
    | if_stmt stmt_ends    { $$=$1; puts("if stmt"); }
    | for_stmt       { $$=$1; puts("for stmt"); }
    | for_stmt stmt_ends { $$=$1; puts("for stmt with ends"); }
    | while_stmt         { $$=$1; puts("while stmt"); }
    | while_stmt stmt_ends       { $$=$1; puts("while stmt"); }
    | until_stmt    { $$=$1; puts("until stmt"); }
    | until_stmt stmt_ends   { $$=$1; puts("until stmt"); }
    | def_method_stmt   { $$=$1; puts("def method"); }
    | def_method_stmt stmt_ends { $$=$1; puts("def method"); }
    ;

stmt_list_not_empty: stmt  { $$=create_stmt_list($1); puts("list from one stmt"); }
    | stmt_list_not_empty stmt { $$=add_to_stmt_list($1, $2); puts("add stmt to list"); }
    ;

stmt_list: /* empty */ { $$=0; puts("empty stmt list"); }
    | stmt_list_not_empty  { $$=$1; puts("stmt list"); }
    ;

stmt_block: BEGIN_KEYWORD stmt_ends_op stmt_list END_KEYWORD  { $$=create_stmt_block_struct($3); puts("begin without stmt ends"); }
    ;

if_start_stmt: IF_KEYWORD expr stmt_ends stmt_list { $$=create_if_part_struct($2, $4); puts("if without then"); }
    | IF_KEYWORD expr THEN_KEYWORD stmt_ends_op stmt_list { $$=create_if_part_struct($2, $5); puts("if with then"); }
    ;

elsif_stmt: ELSIF_KEYWORD expr stmt_ends stmt_list { $$=create_if_part_struct($2, $4); puts("elsif without then");  } 
    | ELSIF_KEYWORD expr THEN_KEYWORD stmt_ends_op stmt_list { $$=create_if_part_struct($2, $5); puts("elsif with then");  } 
    ;

elsif_stmt_list: elsif_stmt { $$=create_elsif_stmt_list($1); } 
    | elsif_stmt_list elsif_stmt { $$=add_to_elsif_stmt_list($1, $2); }
    ;

if_stmt: if_start_stmt END_KEYWORD { $$=create_if_stmt($1, 0, 0); }
    | if_start_stmt ELSE_KEYWORD stmt_ends_op stmt_list END_KEYWORD { $$=create_if_stmt($1, 0, $4); }
    | if_start_stmt elsif_stmt_list END_KEYWORD { $$=create_if_stmt($1, $2, 0); }
    | if_start_stmt elsif_stmt_list ELSE_KEYWORD stmt_ends_op stmt_list END_KEYWORD { $$=create_if_stmt($1, $2, $5); }
    ;

for_stmt: FOR_KEYWORD VAR_METHOD_NAME IN_KEYWORD expr stmt_ends stmt_list END_KEYWORD { $$=create_for_stmt($2, $4, $6); } 
    | FOR_KEYWORD INSTANCE_VAR_NAME IN_KEYWORD expr stmt_ends stmt_list END_KEYWORD { $$=create_for_stmt($2, $4, $6); } 
	| FOR_KEYWORD VAR_METHOD_NAME IN_KEYWORD expr DO_KEYWORD stmt_ends_op stmt_list END_KEYWORD { $$=create_for_stmt($2, $4, $7); } 
    | FOR_KEYWORD INSTANCE_VAR_NAME IN_KEYWORD expr DO_KEYWORD stmt_ends_op stmt_list END_KEYWORD { $$=create_for_stmt($2, $4, $7); }
	;

while_stmt: WHILE_KEYWORD expr stmt_ends stmt_list END_KEYWORD { $$=create_while_stmt($2, $4); }
	| WHILE_KEYWORD expr DO_KEYWORD stmt_ends_op stmt_list END_KEYWORD { $$=create_while_stmt($2, $5); }
	;

until_stmt: UNTIL_KEYWORD expr stmt_ends stmt_list END_KEYWORD { $$=create_until_stmt($2, $4); }
	| UNTIL_KEYWORD expr DO_KEYWORD stmt_ends_op stmt_list END_KEYWORD { $$=create_until_stmt($2, $5); }
	;

method_param: VAR_METHOD_NAME { $$=create_method_param_struct($1, 0); }
	| VAR_METHOD_NAME ASSIGN_OP expr { $$=create_method_param_struct($1, $3); }
	;

method_params_list: /* empty */ { $$=0; }
	| method_params_list_not_empty { $$=$1; }
	;

method_params_list_not_empty: method_param { $$=create_method_param_list($1); }
	| method_params_list_not_empty COMMA_SYMBOL method_param { $$=add_to_method_param_list($1, $3); }
	;

def_method_stmt: DEF_KEYWORD VAR_METHOD_NAME stmt_ends stmt_list END_KEYWORD { $$=create_def_method_stmt($2, 0, $4); }
    | DEF_KEYWORD VAR_METHOD_NAME OPEN_ROUND_BRACKET method_params_list CLOSE_ROUND_BRACKET stmt_ends_op stmt_list END_KEYWORD { $$=create_def_method_stmt($2, $4, $7); }
    ;

method_call_param_list: /* empty */ { $$=0; }
	| method_call_param_list_not_empty {$$=$1; }
	;

method_call_param_list_not_empty: expr { $$=create_expr_list($1); }
	| method_call_param_list_not_empty COMMA_SYMBOL expr { $$=add_to_expr_list($1, $3); }
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
    return result;
}

struct stmt_struct * create_expr_stmt(struct expr_struct * val) {
    struct stmt_struct * result = (struct stmt_struct *) malloc(sizeof(struct stmt_struct));
    result->type = expr_stmt_t;
    result->expr_f = val;
    return result;
}

struct stmt_list_struct * create_stmt_list(struct stmt_struct * val) {
    struct stmt_list_struct * res = (struct stmt_list_struct *) malloc(sizeof(struct stmt_list_struct));
    res->first = val;
    res->last = val;
    val->next = 0;
    return res;
}

struct stmt_list_struct * add_to_stmt_list(struct stmt_list_struct * list, struct stmt_struct * val) {
    list->last->next = val;
    list->last = val;
    val->next = 0;
    return list;
}

struct expr_list_struct * create_expr_list(struct expr_struct * val) {
    struct expr_list_struct * res = (struct expr_list_struct *) malloc(sizeof(struct expr_list_struct));
    res->first = val;
    res->last = val;
    val->next = 0;
    return res;
}

struct expr_list_struct * add_to_expr_list(struct expr_list_struct * list, struct expr_struct * val) {
    list->last->next = val;
    list->last = val;
    val->next = 0;
    return list;
}

struct stmt_struct * create_for_stmt(char * iterable_var, struct expr_struct * condition, struct stmt_list_struct* body) {
    struct for_stmt_struct * for_s = (struct for_stmt_struct *) malloc(sizeof(struct for_stmt_struct));
    for_s->iterable_var = iterable_var;
    for_s->condition = condition;
    for_s->body = body;

    struct stmt_struct * result = (struct stmt_struct *) malloc(sizeof(struct stmt_struct));
    result->type = for_stmt_t;
    result->for_stmt_f = for_s;
    return result;
}

struct stmt_struct * create_while_stmt(struct expr_struct * condition, struct stmt_list_struct* body) {
    struct while_stmt_struct * while_s = (struct while_stmt_struct *) malloc(sizeof(struct while_stmt_struct));
    while_s->condition = condition;
    while_s->body = body;

    struct stmt_struct * result = (struct stmt_struct *) malloc(sizeof(struct stmt_struct));
    result->type = while_stmt_t;
    result->while_stmt_f = while_s;
    return result;
}

struct stmt_struct * create_until_stmt(struct expr_struct * condition, struct stmt_list_struct* body) {
    struct until_stmt_struct * while_s = (struct until_stmt_struct *) malloc(sizeof(struct until_stmt_struct));
    while_s->condition = condition;
    while_s->body = body;

    struct stmt_struct * result = (struct stmt_struct *) malloc(sizeof(struct stmt_struct));
    result->type = until_stmt_t;
    result->until_stmt_f = while_s;
    return result;
}

struct expr_struct * create_method_call_expr(char * method_name, struct expr_list_struct * list) {
    struct expr_struct * result = (struct expr_struct *) malloc(sizeof(struct expr_struct));
    result->type = method_call;
    result->str_val = method_name;
    result->list = list;
    return result;
}

struct if_part_stmt_struct * create_if_part_struct(struct expr_struct * condition, struct stmt_list_struct * body) {
    struct if_part_stmt_struct * result = (struct if_part_stmt_struct *) malloc(sizeof(struct if_part_stmt_struct));
    result->condition = condition;
    result->body = body;
    return result;
}

struct elsif_stmt_list * create_elsif_stmt_list(struct if_part_stmt_struct * val) {
    struct elsif_stmt_list * result = (struct elsif_stmt_list *) malloc(sizeof(struct elsif_stmt_list));
    result->first = val;
    result->last = val;
    val->next = 0;
    return result;
}

struct elsif_stmt_list * add_to_elsif_stmt_list(struct elsif_stmt_list * list, struct if_part_stmt_struct * val) {
    list->last->next = val;
    list->last = val;
    val->next = 0;
    return list;
}

struct stmt_struct * create_if_stmt(struct if_part_stmt_struct* if_branch, struct elsif_stmt_list* elsif_branches, struct stmt_list_struct* else_branch) {
    struct if_stmt_struct * if_s = (struct if_stmt_struct *) malloc(sizeof(struct if_stmt_struct));
    if_s->if_branch = if_branch;
    if_s->elsif_branches = elsif_branches;
    if_s->else_branch = else_branch;

    struct stmt_struct * result = (struct stmt_struct *) malloc(sizeof(struct stmt_struct));
    result->type = if_stmt_t;
    result->if_stmt_f = if_s;
    return result;
}

struct stmt_block_struct * create_stmt_block_struct(struct stmt_list_struct * list) {
    struct stmt_block_struct * result = (struct stmt_block_struct * ) malloc(sizeof(struct stmt_block_struct));
    result->list = list;
    return result;
}

struct stmt_struct * create_block_stmt(struct stmt_block_struct * val) {
    struct stmt_struct * result = (struct stmt_struct *) malloc(sizeof(struct stmt_struct));
    result->type = block_stmt_t;
    result->block_stmt_f = val;
    return result;
}

struct method_param_struct * create_method_param_struct(char * name, struct expr_struct * default_value) {
    struct method_param_struct * result = (struct method_param_struct *) malloc(sizeof(struct method_param_struct));
    result->name = name;
    result->default_value = default_value;
    return result;
}

struct method_param_list * create_method_param_list(struct method_param_struct * val) {
    struct method_param_list * result = (struct method_param_list *) malloc(sizeof(struct method_param_list));
    result->first = val;
    result->last = val;
    val->next = 0;
    return result;
}

struct method_param_list * add_to_method_param_list(struct method_param_list * list, struct method_param_struct * val) {
    list->last->next = val;
    list->last = val;
    val->next = 0;
    return list;
}

struct stmt_struct * create_def_method_stmt(char* name, struct method_param_list* params, struct stmt_list_struct* body) {
    struct def_method_stmt_struct * method_def_s = (struct def_method_stmt_struct *) malloc(sizeof(struct def_method_stmt_struct));
    method_def_s->name = name;
    method_def_s->params = params;
    method_def_s->body = body;

    struct stmt_struct * result = (struct stmt_struct *) malloc(sizeof(struct stmt_struct));
    result->type = def_method_t;
    result->def_method_f = method_def_s;
    return result;
}

struct program_struct * create_program_struct(struct stmt_list_struct * stmts) {
    struct program_struct * result = (struct program_struct *) malloc(sizeof(struct program_struct));
    result->stmts = stmts;
    return result;
}

void main(int argc, char **argv ){
	yyin = fopen(argv[1], "r" );

    FILE * tree = fopen("tree.dot", "w");

    yyparse();
    PrintProgram(root, tree);
    return;
}