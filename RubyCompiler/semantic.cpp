#include "semantic.h"

void fillTable(program_struct* program) {
	Clazz * clazz = new Clazz();
	clazz->name = "__PROGRAM__";
	clazzesList[clazz->name] = clazz;
	clazz->pushConstant(Constant::Utf8("Code"));
	clazz->number = clazz->pushConstant(Constant::Class(clazz->pushConstant(Constant::Utf8(clazz->name))));

	int parent_class_name = clazz->pushConstant(Constant::Utf8("Ljava/lang/Object;"));
	clazz->parend_number = clazz->pushConstant(Constant::Class(parent_class_name));

	Method* mainMethod = new Method();
	mainMethod->name = "main";
	mainMethod->nameNumber = clazz->pushConstant(Constant::Utf8(mainMethod->name));
	mainMethod->descriptorNumber = clazz->pushConstant(Constant::Utf8("([Ljava/lang/String;)V"));
	mainMethod->number = clazz->pushOrFindMethodRef(clazz->name , mainMethod->name, "([Ljava/lang/String;)V");
	mainMethod->isStatic = true;
	mainMethod->local_variables.push_back("args");
	clazz->methods[mainMethod->name] = mainMethod;
	mainMethod->body = 0;

	if (program->items != 0) {
		program_item_struct* c = program->items->first;
		while (c != 0) {
			switch (c->type) {
			case def_method_t:
				fillTable(clazz, c->def_method_f);
				break;
			case pi_stmt_t:
				if (mainMethod->body == 0) {
					mainMethod->body = create_stmt_list(c->stmt_f);
				}
				else {
					add_to_stmt_list(mainMethod->body, c->stmt_f);
				}
				fillTable(clazz, mainMethod, c->stmt_f);
				break;
			case class_declaration_t:
				fillTable(c->class_declaration_f);
				break;
			default:
				break;
			}
			c = c->next;	
		}
	}

	Method* initMethod = new Method();
	initMethod->name = "<init>";
	initMethod->nameNumber = clazz->pushConstant(Constant::Utf8(initMethod->name));
	initMethod->descriptorNumber = clazz->pushConstant(Constant::Utf8("()V"));
	initMethod->local_variables.push_back("this");
	initMethod->body = 0;
	initMethod->number = clazz->pushOrFindMethodRef(clazz->name, initMethod->name, "()V");
	initMethod->self_method_ref = clazz->pushOrFindMethodRef("java/lang/Object", initMethod->name, "()V");
	clazz->methods[initMethod->name] = initMethod;
}

void fillTable(class_declaration_struct* class_decl) {
	Clazz* clazz = new Clazz(); 
	clazz->name = class_decl->name;
	clazzesList[clazz->name] = clazz;
	clazz->pushConstant(Constant::Utf8("Code"));
	clazz->pushConstant(Constant::Class(clazz->pushConstant(Constant::Utf8(clazz->name))));

	// TODO: Parent;
	if (class_decl->parent != 0) {
		if (clazzesList.find(class_decl->parent) != clazzesList.end()) {
			clazz->parent = clazzesList[class_decl->parent];
		}
		else {
			// ERROR: class not found;
			printf("SEMANTIC ERROR: parent class %s for class %s not found\n", class_decl->parent, class_decl->name);
		}
	}

	if (class_decl->body != 0) {
		def_method_stmt_struct* c = class_decl->body->first;
		while (c != 0) {
			fillTable(clazz, c);
			c = c->next;
		}
	}

	//TODO: Deafult constructor...
	clazz->pushConstant(Constant::Utf8("<init>"));
}

void fillTable(Clazz* clazz, def_method_stmt_struct* method) {
	Method * m = new Method();
	m->name = method->name;
	m->nameNumber = clazz->pushConstant(Constant::Utf8(m->name));
	m->isStatic = true;

	int params_counter = 0;
	if (method->params != 0) {
		method_param_struct* c = method->params->first;
		while (c != 0) {
			params_counter++;
			m->local_variables.push_back(c->name);
			c->local_var_num = m->local_variables.size() - 1;
			// TODO: дефолтные значения.
			c = c->next;
		}
	}
	std::string m_d = method_descriptor(params_counter);
	m->descriptorNumber = clazz->pushConstant(Constant::Utf8(m_d));
	m->number = clazz->pushOrFindMethodRef(clazz->name, m->name, m_d);
	method->id = m->number;
	m->body = method->body;
	m->nill_class_id = clazz->pushConstant(Constant::Class(clazz->pushConstant(Constant::Utf8("__BASE__"))));
	m->nill_constructor_mr = clazz->pushOrFindMethodRef("__BASE__", "<init>", "()V");
	clazz->methods[m->name] = m;
	
	fillTable(clazz, m, method->body);
	
}

void fillTable(Clazz* clazz, Method* method, stmt_list_struct* body) {
	if (body != 0) {
		stmt_struct* c = body->first;
		while (c != 0) {
			fillTable(clazz, method, c);
			c = c->next;
		}
	}
}

void fillTable(Clazz* clazz, Method* method, stmt_struct* stmt) {
	switch (stmt->type) {
	case expr_stmt_t:
		fillTable(clazz, method, stmt->expr_f);
		break;
	case for_stmt_t:
		method->local_variables.push_back(stmt->for_stmt_f->iterable_var);
		stmt->for_stmt_f->iterable_var_local_num = method->local_variables.size() - 1;
		existsId(clazz, method, stmt->for_stmt_f->condition);
		fillTable(clazz, method, stmt->for_stmt_f->condition);
		fillTable(clazz, method, stmt->for_stmt_f->body);
		break;
	case while_stmt_t:
		existsId(clazz, method, stmt->while_stmt_f->condition);
		fillTable(clazz, method, stmt->while_stmt_f->condition);
		fillTable(clazz, method, stmt->while_stmt_f->body);
		stmt->while_stmt_f->bool_field_mr = clazz->pushOrFindFieldRef("__BASE__", "__bVal", "Z");
		break;
	case until_stmt_t:
		existsId(clazz, method, stmt->until_stmt_f->condition);
		fillTable(clazz, method, stmt->until_stmt_f->condition);
		fillTable(clazz, method, stmt->until_stmt_f->body);
		break;
	case if_stmt_t:
		fillTable(clazz, method, stmt->if_stmt_f->if_branch);
		existsId(clazz, method, stmt->if_stmt_f->if_branch->condition);
		if (stmt->if_stmt_f->elsif_branches != 0) {
			if_part_stmt_struct* c = stmt->if_stmt_f->elsif_branches->first;
			while (c != 0) {
				existsId(clazz, method, c->condition);
				fillTable(clazz, method, c);
				c = c->next;
			}
		}
		if (stmt->if_stmt_f->else_branch != 0) {
			fillTable(clazz, method, stmt->if_stmt_f->else_branch);
		}
		stmt->if_stmt_f->bool_field_mr = clazz->pushOrFindFieldRef("__BASE__", "__bVal", "Z");
		break;
	case block_stmt_t:
		fillTable(clazz, method, stmt->block_stmt_f->list);
		break;
	case return_stmt_t:
		existsId(clazz, method, stmt->expr_f);
		fillTable(clazz, method, stmt->expr_f);
		break;
	default:
		break;
	}
}

void fillTable(Clazz* clazz, Method* method, if_part_stmt_struct* if_branch_stmt) {
	fillTable(clazz, method, if_branch_stmt->condition);
	fillTable(clazz, method, if_branch_stmt->body);
}

void fillTable(Clazz* clazz, Method* method, expr_struct* expr) {

	switch (expr->type)
	{
	case Integer:
		expr->value_id = clazz->pushConstant(Constant::Integer(expr->int_val));
		expr->id = clazz->pushOrFindMethodRef("__BASE__", "<init>", "(I)V");
		expr->class_id = clazz->pushConstant(Constant::Class(clazz->pushConstant(Constant::Utf8("__BASE__"))));
		break;
	case Boolean:
		expr->value_id = clazz->pushConstant(Constant::Integer(expr->int_val));
		expr->id = clazz->pushOrFindMethodRef("__BASE__", "<init>", "(Z)V");
		expr->class_id = clazz->pushConstant(Constant::Class(clazz->pushConstant(Constant::Utf8("__BASE__"))));
		break;
	case Float:
		expr->value_id = clazz->pushConstant(Constant::Float(expr->float_val));
		expr->id = clazz->pushOrFindMethodRef("__BASE__", "<init>", "(F)V");
		expr->class_id = clazz->pushConstant(Constant::Class(clazz->pushConstant(Constant::Utf8("__BASE__"))));
		break;
	case String:
		expr->value_id = clazz->pushConstant(Constant::String(clazz->pushConstant(Constant::Utf8(expr->str_val))));
		expr->id = clazz->pushOrFindMethodRef("__BASE__", "<init>", "(Ljava/lang/String;)V");
		expr->class_id = clazz->pushConstant(Constant::Class(clazz->pushConstant(Constant::Utf8("__BASE__"))));
		break;
	case var_or_method:
		if (contains(method->local_variables, expr->str_val)) {
			expr->local_var_num = std::find(method->local_variables.begin(), method->local_variables.end(), expr->str_val) - method->local_variables.begin();
		}
		break;
	case instance_var:
		clazz->addField(expr->str_val, "L__BASE__;");
		break;
	case assign:
		if (expr->left->type == var_or_method && std::find(method->local_variables.begin(), method->local_variables.end(), expr->left->str_val) == method->local_variables.end()) {
			method->local_variables.push_back(expr->left->str_val);
		}
		existsId(clazz, method, expr->right);
		break;
	case logical_not:
		expr->id = clazz->pushOrFindMethodRef("__not__", ("(L__BASE__;)L__BASE__;"));
		existsId(clazz, method, expr->left);
		break;
	case unary_plus:
		expr->id = clazz->pushOrFindMethodRef("__unary_plus__", "()L__BASE__;");
		existsId(clazz, method, expr->left);
		break;
	case unary_minus:
		expr->id = clazz->pushOrFindMethodRef("__unary_minus__", "()L__BASE__;");
		existsId(clazz, method, expr->left);
		break;
	case mod_assign:
	case div_assign:
	case sub_assign:
	case add_assign:
	case mul_assign:
	case pow_assign:
		existsId(clazz, method, expr->right);
		break;
	case bin_ones_complement:
	case defined:
	case not_keyword:
		existsId(clazz, method, expr->left);
		break;
	case mul:
		expr->id = clazz->pushOrFindMethodRef("__BASE__", "__mul__", "(L__BASE__;)L__BASE__;");
		existsId(clazz, method, expr->left);
		existsId(clazz, method, expr->right);
		break;
	case div_:
		expr->id = clazz->pushOrFindMethodRef("__BASE__", "__div__", "(L__BASE__;)L__BASE__;");
		existsId(clazz, method, expr->left);
		existsId(clazz, method, expr->right);
		break;
	case plus:
		expr->id = clazz->pushOrFindMethodRef("__BASE__", "__add__", "(L__BASE__;)L__BASE__;");
		existsId(clazz, method, expr->left);
		existsId(clazz, method, expr->right);
		break;
	case minus:
		expr->id = clazz->pushOrFindMethodRef("__BASE__", "__sub__", "(L__BASE__;)L__BASE__;");
		existsId(clazz, method, expr->left);
		existsId(clazz, method, expr->right);
		break;
	case mod:
		expr->id = clazz->pushOrFindMethodRef("__BASE__", "__mod__", "(L__BASE__;)L__BASE__;");
		existsId(clazz, method, expr->left);
		existsId(clazz, method, expr->right);
		break;
	case equal:
		expr->id = clazz->pushOrFindMethodRef("__BASE__", "__eql__", "(L__BASE__;)L__BASE__;");
		existsId(clazz, method, expr->left);
		existsId(clazz, method, expr->right);
		break;
	case not_equal:
		expr->id = clazz->pushOrFindMethodRef("__BASE__", "__not_eql__", "(L__BASE__;)L__BASE__;");
		existsId(clazz, method, expr->left);
		existsId(clazz, method, expr->right);
		break;
	case less:
		expr->id = clazz->pushOrFindMethodRef("__BASE__", "__les__", "(L__BASE__;)L__BASE__;");
		existsId(clazz, method, expr->left);
		existsId(clazz, method, expr->right);
		break;
	case greater:
		expr->id = clazz->pushOrFindMethodRef("__BASE__", "__greater__", "(L__BASE__;)L__BASE__;");
		existsId(clazz, method, expr->left);
		existsId(clazz, method, expr->right);
		break;
	case greater_eql:
		expr->id = clazz->pushOrFindMethodRef("__BASE__", "__greater_or_eql__", "(L__BASE__;)L__BASE__;");
		existsId(clazz, method, expr->left);
		existsId(clazz, method, expr->right);
		break;
	case less_eql:
		expr->id = clazz->pushOrFindMethodRef("__BASE__", "__les_or_eql__", "(L__BASE__;)L__BASE__;");
		existsId(clazz, method, expr->left);
		existsId(clazz, method, expr->right);
		break;
	case pow_:
		expr->id = clazz->pushOrFindMethodRef("__BASE__", "__pow__", "(L__BASE__;)L__BASE__;");
		existsId(clazz, method, expr->left);
		existsId(clazz, method, expr->right);
		break;
	case logical_and:
		expr->id = clazz->pushOrFindMethodRef("__BASE__", "__logical_and__", "(L__BASE__;)L__BASE__;");
		existsId(clazz, method, expr->left);
		existsId(clazz, method, expr->right);
		break;
	case logical_or:
		expr->id = clazz->pushOrFindMethodRef("__BASE__", "__logical_or__", "(L__BASE__;)L__BASE__;");
		existsId(clazz, method, expr->left);
		existsId(clazz, method, expr->right);
		break;
	case member_access:
		expr->id = clazz->pushOrFindMethodRef("__BASE__", "__member_access__", "(L__BASE__;)L__BASE__;");
		existsId(clazz, method, expr->left);
		existsId(clazz, method, expr->right);
		break;
	case bin_left_shift:
	case bin_right_shift:
	case bin_and_op:
	case bin_or_op:
	case bin_xor_op:
	case comb_comprassion:
	case case_equal:
	case inclusive_range:
	case exclusive_range:
	case and_keyword:
	case or_keyword:
	case field_call:
		existsId(clazz, method, expr->left);
		existsId(clazz, method, expr->right);
		break;
	case method_call:
		if (expr->list != 0) {
			expr_struct* c = expr->list->first;
			while (c != 0) {
				if (existsId(clazz, method, c) && c->type == var_or_method) {
					c->local_var_num = std::find(method->local_variables.begin(), method->local_variables.end(), c->str_val) - method->local_variables.begin();
				}
				c = c->next;
			}
		}

		if (strcmp(expr->str_val,"print") == 0) {
			expr->id = clazz->pushOrFindMethodRef("__BASE__", "print", "(L__BASE__;)V");
		}
		else if (strcmp(expr->str_val, "println") == 0) {
			expr->id = clazz->pushOrFindMethodRef("__BASE__", "println", "(L__BASE__;)V");
		}
		else {
			existsMethod(expr->str_val);
			expr->id = clazz->pushOrFindMethodRef(expr->str_val, method_descriptor(count_exprs(expr->list)));
		}

		break;
	case array:
		if (expr->list != 0) {
			existsIds(clazz, method, expr->list);
		}
		expr->array_list_class_id = clazz->pushConstant(Constant::Class(clazz->pushConstant(Constant::Utf8("java/util/ArrayList"))));
		expr->array_list_constructor_mr = clazz->pushOrFindMethodRef("java/util/ArrayList", "<init>", "(Ljava/util/Collection;)V");
		expr->list_constructor_mr = clazz->pushOrFindMethodRef("java/util/Arrays", "asList", "([Ljava/lang/Object;)Ljava/util/List;");
		expr->id = clazz->pushOrFindMethodRef("__BASE__", "<init>", "(Ljava/util/ArrayList;)V");
		expr->class_id = clazz->pushConstant(Constant::Class(clazz->pushConstant(Constant::Utf8("__BASE__"))));
		break;
	case member_access_and_assign:
		expr->id = clazz->pushOrFindMethodRef("__BASE__", "__member_access_assign__", "(L__BASE__;L__BASE__;)L__BASE__;");
		existsId(clazz, method, expr->left);
		existsId(clazz, method, expr->right);
		existsId(clazz, method, expr->index);
		break;
	case object_method_call:
		existsId(clazz, method, expr->left);
		if (expr->list != 0) {
			existsIds(clazz, method, expr->list);
		}
		break;
	default:
		break;
	}

	if (expr->left != 0) fillTable(clazz, method, expr->left);
	if (expr->right != 0) fillTable(clazz, method, expr->right);
	if (expr->index != 0) fillTable(clazz, method, expr->index);
	if (expr->list != 0) {
		expr_struct* c = expr->list->first;
		while (c != 0) {
			fillTable(clazz, method, c);
			c = c->next;
		}
	}
}

bool existsId(Clazz* clazz, Method* method, expr_struct* expr) {
	if (expr != 0 && expr->type == var_or_method) {	
		bool inClazz = std::find(method->local_variables.begin(), method->local_variables.end(), expr->str_val) != method->local_variables.end();
		std::vector<std::string> mainMethodLocalVars = clazzesList["__PROGRAM__"]->methods["main"]->local_variables;
		bool inMainClazz = std::find(mainMethodLocalVars.begin(), mainMethodLocalVars.end(), expr->str_val) != mainMethodLocalVars.end();

		if (!(inClazz || inMainClazz)) {
			printf("SEMANTIC ERROR: local variable %s is not defined\n", expr->str_val);
			return false;
		}
	}
	if (expr != 0 && expr->type == instance_var) {
		if (clazz->fields.find(expr->str_val) == clazz->fields.end()) {
			printf("SEMANTIC ERROR: class field %s is not defined\n", expr->str_val);
			return false;
		}
	}
	return true;
}

bool existsIds(Clazz* clazz, Method* method, expr_list_struct* exprList) {
	expr_struct* c = exprList->first;
	while (c != 0) {
		if (!existsId(clazz, method, c)) return false;
		c = c->next;
	}
	return true;
}

bool existsMethod(const std::string& methodName) {
	for (auto i : clazzesList) {
		if (i.second->methods.find(methodName) != i.second->methods.end()) {
			return true;
		}
	}
	printf("SEMANTIC ERROR: method %s is not defined\n", methodName.c_str());
	return false;
}

std::string method_descriptor(int size) {
	std::string str = "(";
	for (int i = 0; i < size; ++i) {
		str += "L__BASE__;";
	}
	str += ")L__BASE__;"; //!!!!!!!!!!!!!!!!!!!! TODO: FIX IT!!!!!!!!!!!!!!!!!
	return str;
}

void transformTree(program_struct* program) {
	if (program->items != 0) {
		program_item_struct* c = program->items->first;
		while (c != 0) {
			transform(c);
			c = c->next;
		}
	}
}
void transform(stmt_list_struct* stmt_list) {
	if (stmt_list != 0) {
		stmt_struct* c = stmt_list->first;
		while (c != 0) {
			transform(c);
			c = c->next;
		}
	}
}

void transform(stmt_struct * stmt) {
	switch (stmt->type) {
	case expr_stmt_t:
		transform(stmt->expr_f);
		break;
	case for_stmt_t:
		transform(stmt->for_stmt_f->condition);
		transform(stmt->for_stmt_f->body);
		break;
	case while_stmt_t:
		transform(stmt->while_stmt_f->condition);
		transform(stmt->while_stmt_f->body);
		break;
	case until_stmt_t:
		transform(stmt->until_stmt_f->condition);
		transform(stmt->until_stmt_f->body);
		break;
	case if_stmt_t:
		transform(stmt->if_stmt_f);
		break;
	case block_stmt_t: 
		transform(stmt->block_stmt_f->list);
		break;
	case return_stmt_t:
		if (stmt->expr_f != 0) transform(stmt->expr_f);
		break;
	default:
		break;
	}
}

void transform(program_item_struct* item) {
	switch (item->type)
	{
	case def_method_t:
		transform(item->def_method_f);
		break;
	case pi_stmt_t:
		transform(item->stmt_f);
		break;
	case class_declaration_t:
		transform(item->class_declaration_f);
		break;
	default:
		break;
	}
}

void transform(def_method_stmt_struct* def_method) {
	transform(def_method->body);
	if (def_method->params != 0) {
		method_param_struct* c = def_method->params->first;
		while (c != 0) {
			if (c->default_value != 0) transform(c->default_value);
			c = c->next;
		}
	}
}

void transform(class_declaration_struct* cls) {	
	if (cls->body != 0) {
		def_method_stmt_struct* c = cls->body->first;
		while (c != 0) {
			transform(c);
			c = c->next;
		}
	}
}

void transform(if_stmt_struct* stmt) {
	transform(stmt->if_branch->condition);
	transform(stmt->if_branch->body);

	if (stmt->elsif_branches != 0) {
		if_part_stmt_struct* c = stmt->elsif_branches->first;
		while (c != 0) {
			transform(c->condition);
			transform(c->body);
			c = c->next;
		}
	}

	if (stmt->else_branch != 0) {
		transform(stmt->else_branch);
	}
}

void transform(expr_struct* expr) {
	switch (expr->type)
	{
	case assign:
		if (expr->left->type == member_access) {
			expr->type = member_access_and_assign;
			expr->index = expr->left->right;
			expr->left = expr->left->left;
		}
		break;
	default:
		break;
	}
	if (expr->left != 0) transform(expr->left);
	if (expr->right != 0) transform(expr->right);
	if (expr->index != 0) transform(expr->index);	
}

int count_exprs(expr_list_struct* params) {
	if (params == 0) return 0;
	int count = 0;
	expr_struct* c = params->first;
	while (c != 0) {
		count++;
		c = c->next;
	}
	return count;
}