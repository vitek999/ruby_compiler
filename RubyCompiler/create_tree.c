#include "create_tree.h"

struct expr_struct* create_const_integer_expr(enum expr_type type, int val) {
    struct expr_struct* result = (struct expr_struct*)malloc(sizeof(struct expr_struct));
    result->type = type;
    result->int_val = val;
    return result;
}

struct expr_struct* create_const_float_expr(float val) {
    struct expr_struct* result = (struct expr_struct*)malloc(sizeof(struct expr_struct));
    result->type = Float;
    result->float_val = val;
    return result;
}

struct expr_struct* create_const_string_expr(enum expr_type type, char* val) {
    struct expr_struct* result = (struct expr_struct*)malloc(sizeof(struct expr_struct));
    result->type = type;
    result->str_val = val;
    return result;
}

struct expr_struct* create_op_expr(enum expr_type type, struct expr_struct* left, struct expr_struct* right) {
    struct expr_struct* result = (struct expr_struct*)malloc(sizeof(struct expr_struct));
    result->type = type;
    result->left = left;
    result->right = right;
    return result;
}

struct stmt_struct* create_expr_stmt(struct expr_struct* val) {
    struct stmt_struct* result = (struct stmt_struct*)malloc(sizeof(struct stmt_struct));
    result->type = expr_stmt_t;
    result->expr_f = val;
    return result;
}

struct stmt_list_struct* create_stmt_list(struct stmt_struct* val) {
    struct stmt_list_struct* res = (struct stmt_list_struct*)malloc(sizeof(struct stmt_list_struct));
    res->first = val;
    res->last = val;
    val->next = 0;
    return res;
}

struct stmt_list_struct* add_to_stmt_list(struct stmt_list_struct* list, struct stmt_struct* val) {
    list->last->next = val;
    list->last = val;
    val->next = 0;
    return list;
}

struct expr_list_struct* create_expr_list(struct expr_struct* val) {
    struct expr_list_struct* res = (struct expr_list_struct*)malloc(sizeof(struct expr_list_struct));
    res->first = val;
    res->last = val;
    val->next = 0;
    return res;
}

struct expr_list_struct* add_to_expr_list(struct expr_list_struct* list, struct expr_struct* val) {
    list->last->next = val;
    list->last = val;
    val->next = 0;
    return list;
}

struct stmt_struct* create_for_stmt(char* iterable_var, struct expr_struct* condition, struct stmt_list_struct* body) {
    struct for_stmt_struct* for_s = (struct for_stmt_struct*)malloc(sizeof(struct for_stmt_struct));
    for_s->iterable_var = iterable_var;
    for_s->condition = condition;
    for_s->body = body;

    struct stmt_struct* result = (struct stmt_struct*)malloc(sizeof(struct stmt_struct));
    result->type = for_stmt_t;
    result->for_stmt_f = for_s;
    return result;
}

struct stmt_struct* create_while_stmt(struct expr_struct* condition, struct stmt_list_struct* body) {
    struct while_stmt_struct* while_s = (struct while_stmt_struct*)malloc(sizeof(struct while_stmt_struct));
    while_s->condition = condition;
    while_s->body = body;

    struct stmt_struct* result = (struct stmt_struct*)malloc(sizeof(struct stmt_struct));
    result->type = while_stmt_t;
    result->while_stmt_f = while_s;
    return result;
}

struct stmt_struct* create_until_stmt(struct expr_struct* condition, struct stmt_list_struct* body) {
    struct until_stmt_struct* while_s = (struct until_stmt_struct*)malloc(sizeof(struct until_stmt_struct));
    while_s->condition = condition;
    while_s->body = body;

    struct stmt_struct* result = (struct stmt_struct*)malloc(sizeof(struct stmt_struct));
    result->type = until_stmt_t;
    result->until_stmt_f = while_s;
    return result;
}

struct expr_struct* create_method_call_expr(char* method_name, struct expr_list_struct* list) {
    struct expr_struct* result = (struct expr_struct*)malloc(sizeof(struct expr_struct));
    result->type = method_call;
    result->str_val = method_name;
    result->list = list;
    return result;
}

struct expr_struct* create_field_call_expr(struct expr_struct* left, char* right) {
    struct expr_struct* result = (struct expr_struct*)malloc(sizeof(struct expr_struct));
    result->type = field_call;
    result->str_val = right;
    result->left = left;
    return result;
}

struct if_part_stmt_struct* create_if_part_struct(struct expr_struct* condition, struct stmt_list_struct* body) {
    struct if_part_stmt_struct* result = (struct if_part_stmt_struct*)malloc(sizeof(struct if_part_stmt_struct));
    result->condition = condition;
    result->body = body;
    return result;
}

struct elsif_stmt_list* create_elsif_stmt_list(struct if_part_stmt_struct* val) {
    struct elsif_stmt_list* result = (struct elsif_stmt_list*)malloc(sizeof(struct elsif_stmt_list));
    result->first = val;
    result->last = val;
    val->next = 0;
    return result;
}

struct elsif_stmt_list* add_to_elsif_stmt_list(struct elsif_stmt_list* list, struct if_part_stmt_struct* val) {
    list->last->next = val;
    list->last = val;
    val->next = 0;
    return list;
}

struct stmt_struct* create_if_stmt(struct if_part_stmt_struct* if_branch, struct elsif_stmt_list* elsif_branches, struct stmt_list_struct* else_branch) {
    struct if_stmt_struct* if_s = (struct if_stmt_struct*)malloc(sizeof(struct if_stmt_struct));
    if_s->if_branch = if_branch;
    if_s->elsif_branches = elsif_branches;
    if_s->else_branch = else_branch;

    struct stmt_struct* result = (struct stmt_struct*)malloc(sizeof(struct stmt_struct));
    result->type = if_stmt_t;
    result->if_stmt_f = if_s;
    return result;
}

struct stmt_block_struct* create_stmt_block_struct(struct stmt_list_struct* list) {
    struct stmt_block_struct* result = (struct stmt_block_struct*)malloc(sizeof(struct stmt_block_struct));
    result->list = list;
    return result;
}

struct stmt_struct* create_block_stmt(struct stmt_block_struct* val) {
    struct stmt_struct* result = (struct stmt_struct*)malloc(sizeof(struct stmt_struct));
    result->type = block_stmt_t;
    result->block_stmt_f = val;
    return result;
}

struct method_param_struct* create_method_param_struct(char* name, struct expr_struct* default_value) {
    struct method_param_struct* result = (struct method_param_struct*)malloc(sizeof(struct method_param_struct));
    result->name = name;
    result->default_value = default_value;
    return result;
}

struct method_param_list* create_method_param_list(struct method_param_struct* val) {
    struct method_param_list* result = (struct method_param_list*)malloc(sizeof(struct method_param_list));
    result->first = val;
    result->last = val;
    val->next = 0;
    return result;
}

struct method_param_list* add_to_method_param_list(struct method_param_list* list, struct method_param_struct* val) {
    list->last->next = val;
    list->last = val;
    val->next = 0;
    return list;
}

struct stmt_struct* create_return_stmt(struct expr_struct* val) {
    struct stmt_struct* result = (struct stmt_struct*)malloc(sizeof(struct stmt_struct));
    result->type = return_stmt_t;
    result->expr_f = val;
    return result;
}

struct program_struct* create_program_struct(struct program_item_list_struct* items) {
    struct program_struct* result = (struct program_struct*)malloc(sizeof(struct program_struct));
    result->items = items;
    return result;
}

struct expr_struct* create_array_struct(struct expr_list_struct* items) {
    struct expr_struct* result = (struct expr_struct*)malloc(sizeof(struct expr_struct));
    result->type = array;
    result->list = items;
    return result;
}

struct program_item_struct* create_def_method_program_item(char* name, struct method_param_list* params, struct stmt_list_struct* body) {
    struct def_method_stmt_struct* method_def_s = (struct def_method_stmt_struct*)malloc(sizeof(struct def_method_stmt_struct));
    method_def_s->name = name;
    method_def_s->params = params;
    method_def_s->body = body;

    struct program_item_struct* result = (struct program_item_struct*)malloc(sizeof(struct program_item_struct));
    result->type = def_method_t;
    result->def_method_f = method_def_s;
    return result;
}

struct program_item_struct* create_stmt_program_item(struct stmt_struct* stmt) {
    struct program_item_struct* result = (struct program_item_struct*)malloc(sizeof(struct program_item_struct));
    result->type = pi_stmt_t;
    result->stmt_f = stmt;
    return result;
}

struct program_item_struct* create_class_declaration_program_item(char* name, char * parent, struct program_item_list_struct* body) {
    struct program_item_struct* result = (struct program_item_struct*)malloc(sizeof(struct program_item_struct));
    struct class_declaration_struct* class_decl = (struct class_declaration_struct*)malloc(sizeof(struct class_declaration_struct));
    
    class_decl->name = name;
    class_decl->body = body;
    class_decl->parent = parent;

    result->type = class_declaration_t;
    result->class_declaration_f = class_decl;

    return result;
}

struct program_item_list_struct* create_program_item_list(struct program_item_struct* val) {
    struct program_item_list_struct* result = (struct program_item_list_struct*)malloc(sizeof(struct program_item_list_struct));
    result->first = val;
    result->last = val;
    val->next = 0;
    return result;
}

struct program_item_list_struct* add_to_program_item_list(struct program_item_list_struct* list, struct program_item_struct* val) {
    list->last->next = val;
    list->last = val;
    val->next = 0;
    return list;
}