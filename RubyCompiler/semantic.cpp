#include "semantic.h"

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