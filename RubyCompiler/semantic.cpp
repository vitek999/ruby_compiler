#include "semantic.h"

void fillTable(program_struct* program) {
	Clazz * clazz = new Clazz();
	clazz->name = "__PROGRAM__";
	clazz->pushConstant(Constant::Utf8("Code"));
	clazz->pushConstant(Constant::Class(clazz->pushConstant(Constant::Utf8(clazz->name))));

	Method* mainMethod = new Method();
	mainMethod->name = "main";
	clazz->methods[mainMethod->name] = mainMethod;

	if (program->items != 0) {
		program_item_struct* c = program->items->first;
		while (c != 0) {
			switch (c->type) {
			case def_method_t:
				fillTable(clazz, c->def_method_f);
				break;
			case pi_stmt_t:
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

	clazzesList[clazz->name] = clazz;
	//TODO: Deafult constructor...
	clazz->pushConstant(Constant::Utf8("<init>"));
}

void fillTable(class_declaration_struct* class_decl) {
	Clazz* clazz = new Clazz(); 
	clazz->name = class_decl->name;
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

	clazzesList[clazz->name] = clazz;
	//TODO: Deafult constructor...
	clazz->pushConstant(Constant::Utf8("<init>"));
}

void fillTable(Clazz* clazz, def_method_stmt_struct* method) {
	Method * m = new Method();
	m->name = method->name;
	m->body = method->body;
	
	if (clazz->name != "__PROGRAM__") { // not static...
		m->local_variables.push_back("this");
	}
	
	int params_counter = 0;
	if (method->params != 0) {
		method_param_struct* c = method->params->first;
		while (c != 0) {
			params_counter++;
			m->local_variables.push_back(c->name);
			// TODO: ��������� ��������.
			c = c->next;
		}
	}
	
	m->number = clazz->pushOrFindMethodRef(m->name, params_counter);
	
	fillTable(clazz, m, method->body);

	// �������� ������ � ������� ������� ������...
	clazz->methods[m->name] = m;
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
		existsId(clazz, method, stmt->for_stmt_f->condition);
		fillTable(clazz, method, stmt->for_stmt_f->condition);
		fillTable(clazz, method, stmt->for_stmt_f->body);
		break;
	case while_stmt_t:
		existsId(clazz, method, stmt->while_stmt_f->condition);
		fillTable(clazz, method, stmt->while_stmt_f->condition);
		fillTable(clazz, method, stmt->while_stmt_f->body);
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
	case Boolean:
		clazz->pushConstant(Constant::Integer(expr->int_val));
		break;
	case Float:
		clazz->pushConstant(Constant::Float(expr->float_val));
		break;
	case String:
		clazz->pushConstant(Constant::String(clazz->pushConstant(Constant::Utf8(expr->str_val))));
		break;
	case var_or_method:
		if (std::find(method->local_variables.begin(), method->local_variables.end(), expr->str_val) == method->local_variables.end()) {
			method->local_variables.push_back(expr->str_val);
		}
		break;
	case instance_var:
		clazz->addField(expr->str_val, "L__BASE__;");
		break;
	case assign:
	case mod_assign:
	case div_assign:
	case sub_assign:
	case add_assign:
	case mul_assign:
	case pow_assign:
		existsId(clazz, method, expr->right);
		break;
	case logical_not:
	case bin_ones_complement:
	case unary_plus:
	case unary_minus:
	case defined:
	case not_keyword:
		existsId(clazz, method, expr->left);
		break;
	case pow_:
	case mul:
	case div_:
	case mod:
	case plus:
	case minus:
	case bin_left_shift:
	case bin_right_shift:
	case bin_and_op:
	case bin_or_op:
	case bin_xor_op:
	case greater:
	case less:
	case greater_eql:
	case comb_comprassion:
	case equal:
	case case_equal:
	case not_equal:
	case logical_and:
	case logical_or:
	case inclusive_range:
	case exclusive_range:
	case and_keyword:
	case or_keyword:
	case member_access:
	case field_call:
		existsId(clazz, method, expr->left);
		existsId(clazz, method, expr->right);
		break;
	case method_call:
		existsId(clazz, method, expr->left);
		if (expr->list != 0) {
			existsIds(clazz, method, expr->list);
		}
		break;
	case array:
		if (expr->list != 0) {
			existsIds(clazz, method, expr->list);
		}
		break;
	case member_access_and_assign:
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
}

bool existsId(Clazz* clazz, Method* method, expr_struct* expr) {
	if (expr != 0 && expr->type == var_or_method) {
		if (std::find(method->local_variables.begin(), method->local_variables.end(), expr->str_val) == method->local_variables.end()) {
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

std::string method_descriptor(int size) {
	std::string str = "(";
	for (int i = 0; i < size; ++i) {
		str += "L__BASE__;";
	}
	str += ")L__BASE__;";
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