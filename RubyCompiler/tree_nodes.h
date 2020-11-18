enum expr_type { 
	Integer,
	Float,
	String,
	Boolean,
	logical_not,
	bin_ones_complement,
	unary_plus,
	pow,
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
	instance_var
};

struct expr_struct {
	enum expr_type type;
	char * str_val; /* For var names and string literal */
	int int_val; /* For integer and boolean values */
	float float_val;
	struct expr_struct * left;
	struct expr_struct* right;
};