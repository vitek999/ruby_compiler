#pragma once

enum expr_type {
	Integer,
	Float,
	String,
	Boolean,
	logical_not,
	bin_ones_complement,
	unary_plus,
	pow_,
	unary_minus,
	mul,
	div,
	mod,
	plus,
	minus,
	bin_left_shift,
	bin_right_shift,
	bin_and_op,
	bin_or_op,
	bin_xor_op,
	greater,
	less,
	greater_eql,
	less_eql,
	comb_comprassion,
	equal,
	case_equal,
	not_equal,
	logical_and,
	logical_or,
	inclusive_range,
	exclusive_range,
	assign,
	mod_assign,
	div_assign,
	sub_assign,
	add_assign,
	mul_assign,
	pow_assign,
	defined,
	not_keyword,
	and_keyword,
	or_keyword,
	var_or_method,
	instance_var,
	until_op,
	while_op,
	method_call,
	array,
	member_access,
	field_call,
	object_method_call,
	self_field_call,
	self_method_call
};

struct expr_struct {
	enum expr_type type;
	char * str_val; /* For var names and string literal */
	int int_val; /* For integer and boolean values */
	float float_val;
	struct expr_list_struct* list;
	struct expr_struct * left;
	struct expr_struct * right;
	struct expr_struct * next;
};

enum stmt_type {
	expr_stmt_t,
	for_stmt_t,
	while_stmt_t,
	until_stmt_t,
	if_stmt_t,
	block_stmt_t, 
	return_stmt_t
};

enum program_item_type {
	def_method_t,
	pi_stmt_t,
	class_declaration_t
};

struct class_declaration_struct {
	char* name;
	char* parent;
	struct def_method_stmt_list_struct* body;
};

struct program_item_struct {
	enum program_item_type type;
	struct def_method_stmt_struct* def_method_f;
	struct stmt_stuct * stmt_f;
	struct class_declaration_struct* class_declaration_f;
	struct program_item_struct* next;
};

struct program_item_list_struct {
	struct program_item_struct* first;
	struct program_item_struct* last;
};

struct stmt_struct {
	enum stmt_type type;
	struct expr_struct * expr_f;
	struct for_stmt_struct * for_stmt_f;
	struct while_stmt_struct * while_stmt_f;
	struct until_stmt_struct * until_stmt_f;
	struct if_stmt_struct* if_stmt_f;
	struct stmt_struct * next;
	struct stmt_block_struct* block_stmt_f;
};

struct stmt_list_struct
{
	struct stmt_struct * first;
	struct stmt_struct * last;
};

struct expr_list_struct {
	struct expr_struct * first;
	struct expr_struct * last;
};

struct for_stmt_struct {
	char * iterable_var;
	struct expr_struct * condition;
	struct stmt_list_struct* body;
};

struct while_stmt_struct {
	struct expr_struct * condition;
	struct stmt_list_struct* body;
};

struct until_stmt_struct {
	struct expr_struct* condition;
	struct stmt_list_struct* body;
};

struct if_part_stmt_struct {
	struct expr_struct* condition;
	struct stmt_list_struct* body;
	struct if_part_stmt_struct * next;
};

struct elsif_stmt_list {
	struct if_part_stmt_struct* first;
	struct if_part_stmt_struct* last;
};

struct if_stmt_struct {
	struct if_part_stmt_struct* if_branch;
	struct elsif_stmt_list* elsif_branches;
	struct stmt_list_struct* else_branch;
};

struct stmt_block_struct {
	struct stmt_list_struct * list;
};

struct method_param_struct {
	char * name;
	struct expr_struct * default_value;
	struct method_param_struct * next;
};

struct def_method_stmt_struct {
	char* name;
	struct method_param_list* params;
	struct stmt_list_struct* body;
	struct def_method_stmt_struct* next;
};

struct def_method_stmt_list_struct {
	struct def_method_stmt_struct* first;
	struct def_method_stmt_struct* last;
};

struct method_param_list {
	struct method_param_struct* first;
	struct method_param_struct* last;
};

struct program_struct {
	struct program_item_list_struct* items;
};