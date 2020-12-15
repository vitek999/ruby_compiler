#pragma once

#include "tree_nodes.h"
#include <malloc.h>

struct expr_struct* create_const_integer_expr(enum expr_type type, int val);
struct expr_struct* create_const_float_expr(float val);
struct expr_struct* create_const_string_expr(enum expr_type type, char* val);
struct expr_struct* create_op_expr(enum expr_type type, struct expr_struct* left, struct expr_struct* right);
struct expr_struct* create_method_call_expr(char* method_name, struct expr_list_struct* list);
struct stmt_struct* create_expr_stmt(struct expr_struct* val);
struct stmt_struct* create_for_stmt(char* iterable_var, struct expr_struct* condition, struct stmt_list_struct* body);
struct stmt_struct* create_while_stmt(struct expr_struct* condition, struct stmt_list_struct* body);
struct stmt_struct* create_until_stmt(struct expr_struct* condition, struct stmt_list_struct* body);
struct stmt_struct* create_if_stmt(struct if_part_stmt_struct* if_branch, struct elsif_stmt_list* elsif_branches, struct stmt_list_struct* else_branch);
struct stmt_struct* create_block_stmt(struct stmt_block_struct* val);
struct stmt_struct* create_def_method_stmt(char* name, struct method_param_list* params, struct stmt_list_struct* body);
struct stmt_list_struct* create_stmt_list(struct stmt_struct* val);
struct stmt_list_struct* add_to_stmt_list(struct stmt_list_struct* list, struct stmt_struct* val);
struct expr_list_struct* create_expr_list(struct expr_struct* val);
struct expr_list_struct* add_to_expr_list(struct expr_list_struct* list, struct expr_struct* val);
struct if_part_stmt_struct* create_if_part_struct(struct expr_struct* condition, struct stmt_list_struct* body);
struct elsif_stmt_list* create_elsif_stmt_list(struct if_part_stmt_struct* val);
struct elsif_stmt_list* add_to_elsif_stmt_list(struct elsif_stmt_list* list, struct if_part_stmt_struct* val);
struct stmt_block_struct* create_stmt_block_struct(struct stmt_list_struct* list);
struct method_param_struct* create_method_param_struct(char* name, struct expr_struct* default_value);
struct method_param_list* create_method_param_list(struct method_param_struct* val);
struct method_param_list* add_to_method_param_list(struct method_param_list* list, struct method_param_struct* val);
struct program_struct* create_program_struct(struct stmt_list_struct* stmts);