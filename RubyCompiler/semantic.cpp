#include "semantic.h"

void fillTable(program_struct* program) {

}

void fillTable(Clazz* clazz, def_method_stmt_struct* method) {
	Method * m = new Method();
	m->name = method->name;
	m->body = method->body;
	
	if (true) { // TODO: is not static (возможно им€ класса не main....)
		m->local_variables.push_back("this");
	}
	
	int params_counter = 0;
	if (method->params != 0) {
		method_param_struct* c = method->params->first;
		while (c != 0) {
			params_counter++;
			m->local_variables.push_back(c->name);
			// TODO: дефолтные значени€.
			c = c->next;
		}
	}
	
	int name_id = clazz->pushConstant(Constant::Utf8(method->name));
	int descriptor_id = clazz->pushConstant(Constant::Utf8(method_descriptor(params_counter)));

	int name_and_type_id = clazz->pushConstant(Constant::NameAndType(name_id, descriptor_id));
	int class_name_id = clazz->pushConstant(Constant::Utf8(clazz->name));
	int class_id = clazz->pushConstant(Constant::Class(class_name_id));
	int method_ref_id = clazz->pushConstant(Constant::MethodRef(class_id, name_and_type_id));
	
	m->number = method_ref_id; // TODO: ƒобавить адекватный номер
	
	// TODO: пройтись по телу (добавить локальные перменные в method->local_variables и пол€ класса в класс). 
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
		fillTable(clazz, method, stmt->for_stmt_f->condition);
		fillTable(clazz, method, stmt->for_stmt_f->body);
		break;
	case while_stmt_t:
		fillTable(clazz, method, stmt->while_stmt_f->condition);
		fillTable(clazz, method, stmt->while_stmt_f->body);
		break;
	case until_stmt_t:
		fillTable(clazz, method, stmt->until_stmt_f->condition);
		fillTable(clazz, method, stmt->until_stmt_f->body);
		break;
	case if_stmt_t:
		fillTable(clazz, method, stmt->if_stmt_f->if_branch);
		if (stmt->if_stmt_f->elsif_branches != 0) {
			if_part_stmt_struct* c = stmt->if_stmt_f->elsif_branches->first;
			while (c != 0) {
				fillTable(clazz, method, c);
				c = c->next;
			}
		}
		fillTable(clazz, method, stmt->if_stmt_f->else_branch);
		break;
	case block_stmt_t:
		fillTable(clazz, method, stmt->block_stmt_f->list);
		break;
	case return_stmt_t:
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
		int utf8_id = clazz->pushConstant(Constant::Utf8(expr->str_val));
		clazz->pushConstant(Constant::String(utf8_id));
		break;
	default:
		break;
	}
}

std::string method_descriptor(int size) {
	std::string str = "(";
	for (int i = 0; i < size; ++i) {
		str += "L__BASE__;";
	}
	str += ")L__BASE__;";
	return str;
}

bool operator==(const Constant& l, const Constant& r) {
	if (l.type != r.type) return false;
	switch (l.type)
	{
	case Constant::Type::Utf8:
		return l.sVal == r.sVal;
	case Constant::Type::Integer:
		return l.iVal == r.iVal;
	case Constant::Type::Float:
		return l.fVal == r.fVal;
	case Constant::Type::String:
	case Constant::Type::Class:
		return l.utf8_id == r.utf8_id;
	case Constant::Type::NameAndType:
		return l.name_id == r.name_id && l.type_id == r.type_id;
	case Constant::Type::Methodref:
	case Constant::Type::Fieldref:
		return l.name_and_type_id == r.name_and_type_id && l.class_id == r.class_id;
	}
	return false;
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