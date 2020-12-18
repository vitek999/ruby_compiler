#include "print_tree.h"

void PrintProgram(struct program_struct* smts, FILE* file) {
	fprintf(file, "digraph G {\n");
	fprintf(file, "Id%p [label=\"program\"]\n", smts);
	if (smts->items != 0) {
		PrintProgramItemsList(smts->items, smts, file);
	}
	fprintf(file, "}");
}

void PrintStmt(struct stmt_struct* stmt, FILE* file) {
	fprintf(file, "Id%p [label=\"stmt\"]\n", stmt);
	switch (stmt->type) {
	case expr_stmt_t:
		PrintExpr(stmt->expr_f, file);
		fprintf(file, "Id%p->Id%p\n", stmt, stmt->expr_f);
		break;
	case for_stmt_t:
		PrintFor(stmt->for_stmt_f, file);
		fprintf(file, "Id%p->Id%p\n", stmt, stmt->for_stmt_f);
		break;
	case while_stmt_t:
		PrintWhile(stmt->while_stmt_f, file);
		fprintf(file, "Id%p->Id%p\n", stmt, stmt->while_stmt_f);
		break;
	case until_stmt_t:
		PrintUntil(stmt->until_stmt_f, file);
		fprintf(file, "Id%p->Id%p\n", stmt, stmt->until_stmt_f);
		break;
	case if_stmt_t:
		PrintIf(stmt->if_stmt_f, file);
		fprintf(file, "Id%p->Id%p\n", stmt, stmt->if_stmt_f);
		break;
	case block_stmt_t:
		PrintBlock(stmt->block_stmt_f, file);
		fprintf(file, "Id%p->Id%p\n", stmt, stmt->block_stmt_f);
		break;
	case return_stmt_t:
		PrintReturnStmt(stmt, file);
		fprintf(file, "Id%p->IdName%p\n", stmt, stmt);
		break;
	default:
		break;
	}
}

void PrintStmtList(struct stmt_list_struct* list, void* parent, FILE* file) {
	struct stmt_struct* current = list->first;
	while (current != 0) {
		PrintStmt(current, file);
		fprintf(file, "Id%p->Id%p\n", parent, current);
		current = current->next;
	}
}

void PrintProgramItemsList(struct program_item_list_struct* list, void* parent, FILE* file) {
	struct program_item_struct* current = list->first;
	while (current != 0) {
		switch (current->type) {
		case def_method_t: 
			PrintDefMethod(current->def_method_f, file);
			fprintf(file, "Id%p->Id%p\n", parent, current->def_method_f);
			break;
		case pi_stmt_t:
			PrintStmt(current->stmt_f, file);
			fprintf(file, "Id%p->Id%p\n", parent, current->stmt_f);
			break;

		case class_declaration_t:
			PrintClassDeclaration(current->class_declaration_f, file);
			fprintf(file, "Id%p->Id%p\n", parent, current->class_declaration_f);
			break;
		default:
			break;
		}
		current = current->next;
	}
}

void PrintBranch(struct if_part_stmt_struct* branch, FILE* file) {
	fprintf(file, "Id%p [label=\"branch\"]\n", branch);
	PrintExpr(branch->condition, file);
	fprintf(file, "Id%p->Id%p  [label=\"condition\"]\n", branch, branch->condition);

	fprintf(file, "IdBody%p [label=\"body\"]\n", branch);
	struct stmt_struct* current_body = branch->body->first;
	while (current_body != 0) {
		PrintStmt(current_body, file);
		fprintf(file, "IdBody%p->Id%p\n", branch, current_body);
		current_body = current_body->next;
	}
	fprintf(file, "Id%p->IdBody%p\n", branch, branch);
}

void PrintDefMethod(struct def_method_stmt_struct* method, FILE* file) {
	fprintf(file, "Id%p [label=\"def_method\"]\n", method);
	fprintf(file, "IdName%p [label=\"%s\"]\n", method, method->name);
	fprintf(file, "Id%p->IdName%p [label = \"name\"]\n", method, method);
	if (method->params != 0) {
		fprintf(file, "Id%p [label=\"params\"]\n", method->params);
		struct method_param_struct* current = method->params->first;
		while (current != 0) {
			fprintf(file, "Id%p [label=\"param\"]\n", current);
			fprintf(file, "Id%p->Id%p\n", method->params, current);
			fprintf(file, "IdNameVal%p [label=\"%s\"]\n", current, current->name);
			fprintf(file, "Id%p->IdNameVal%p [label=\"name\"]\n", current, current);

			if (current->default_value != 0) {
				PrintExpr(current->default_value, file);
				fprintf(file, "Id%p->Id%p [label=\"default value\"]\n", current, current->default_value);
			}
			current = current->next;
		}
		fprintf(file, "Id%p->Id%p\n", method, method->params);
	}
	fprintf(file, "Id%p [label=\"body\"]\n", method->body);
	PrintStmtList(method->body, method->body, file);
	fprintf(file, "Id%p->Id%p\n", method, method->body);
}

void PrintClassDeclaration(struct class_declaration_struct* class_decl, FILE* file) {
	fprintf(file, "Id%p [label=\"class\"]\n", class_decl);

	fprintf(file, "IdName%p [label=\"%s\"]\n", class_decl, class_decl->name);
	fprintf(file, "Id%p->IdName%p [label=\"name\"]\n", class_decl, class_decl);
	
	if (class_decl->parent != 0) {
		fprintf(file, "IdParent%p [label=\"%s\"]\n", class_decl, class_decl->parent);
		fprintf(file, "Id%p->IdParent%p [label=\"parent\"]\n", class_decl, class_decl);
	}
	
	if (class_decl->body != 0) {
		fprintf(file, "Id%p [label=\"body\"]\n", class_decl->body);
		fprintf(file, "Id%p->Id%p\n", class_decl, class_decl->body);
		struct def_method_stmt_struct* current = class_decl->body->first;
		while (current != 0) {
			PrintDefMethod(current, file);
			fprintf(file, "Id%p->Id%p\n", class_decl->body, current);
			current = current->next;
		}
	}
}

void PrintIf(struct if_stmt_struct* if_s, FILE* file) {
	fprintf(file, "Id%p [label=\"if_stmt\"]\n", if_s);
	PrintBranch(if_s->if_branch, file);
	fprintf(file, "Id%p->Id%p\n", if_s, if_s->if_branch);


	if (if_s->elsif_branches != 0) {
		struct if_part_stmt_struct* current = if_s->elsif_branches->first;
		while (current != 0) {
			PrintBranch(current, file);
			fprintf(file, "Id%p->Id%p\n", if_s, current);
			current = current->next;
		}
	}

	if (if_s->else_branch != 0) {
		fprintf(file, "IdElse%p [label=\"else_branch\"]\n", if_s->else_branch);
		struct stmt_struct* current_body = if_s->else_branch->first;
		while (current_body != 0) {
			PrintStmt(current_body, file);
			fprintf(file, "IdElse%p->Id%p\n", if_s->else_branch, current_body);
			current_body = current_body->next;
		}
		fprintf(file, "Id%p->IdElse%p\n", if_s, if_s->else_branch);
	}
}

void PrintReturnStmt(struct stmt_struct* stmt, FILE* file) {
	fprintf(file, "IdName%p [label=\"return\"]\n", stmt);
	if (stmt->expr_f != 0) {
		PrintExpr(stmt->expr_f, file);
		fprintf(file, "IdName%p->Id%p [label=\"value\"]\n", stmt, stmt->expr_f);
	}
}

void PrintWhile(struct while_stmt_struct* while_s, FILE* file) {
	fprintf(file, "Id%p [label=\"while\"]\n", while_s);
	PrintExpr(while_s->condition, file);
	fprintf(file, "Id%p->Id%p [label=\"condition\"]\n", while_s, while_s->condition);

	fprintf(file, "Id%p [label=\"body\"]\n", while_s->body);
	fprintf(file, "Id%p->Id%p\n", while_s, while_s->body);
	PrintStmtList(while_s->body, while_s->body, file);
}

void PrintUntil(struct until_stmt_struct* until_s, FILE* file) {
	fprintf(file, "Id%p [label=\"until\"]\n", until_s);
	PrintExpr(until_s->condition, file);
	fprintf(file, "Id%p->Id%p [label=\"condition\"]\n", until_s, until_s->condition);

	fprintf(file, "Id%p [label=\"body\"]\n", until_s->body);
	fprintf(file, "Id%p->Id%p\n", until_s, until_s->body);
	PrintStmtList(until_s->body, until_s->body, file);
}

void PrintFor(struct for_stmt_struct* for_s, FILE* file) {
	fprintf(file, "Id%p [label=\"for\"]\n", for_s);
	fprintf(file, "IdItersName%p [label=\"%s\"]\n", for_s, for_s->iterable_var);
	fprintf(file, "Id%p->IdItersName%p  [label=\"iterable var\"]\n", for_s, for_s);
	PrintExpr(for_s->condition, file);
	fprintf(file, "Id%p->Id%p  [label=\"condition\"]\n", for_s, for_s->condition);
	fprintf(file, "IdBody%p [label=\"body\"]\n", for_s);
	struct stmt_struct* current = for_s->body->first;
	while (current != 0) {
		PrintStmt(current, file);
		fprintf(file, "IdBody%p->Id%p\n", for_s, current);
		current = current->next;
	}
	fprintf(file, "Id%p->IdBody%p\n", for_s, for_s);
}

void PrintBlock(struct stmt_block_struct* block, FILE* file) {
	fprintf(file, "Id%p [label=\"block\"]\n", block);
	PrintStmtList(block->list, block, file);
}

void PrintExpr(struct expr_struct* expr, FILE* file) {
	switch (expr->type) {
	case Integer:
		fprintf(file, "Id%p [label=\"INT\"]\n", expr);
		fprintf(file, "IdVal%p [label=\"%d\"]\n", expr, expr->int_val);
		fprintf(file, "Id%p->IdVal%p\n", expr, expr);
		break;
	case Float:
		fprintf(file, "Id%p [label=\"FLOAT\"]\n", expr);
		break;
	case String:
		fprintf(file, "Id%p [label=\"STRING\"]\n", expr);
		fprintf(file, "IdVal%p [label=\"%s\"]\n", expr, expr->str_val);
		fprintf(file, "Id%p->IdVal%p\n", expr, expr);
		break;
	case Boolean:
		fprintf(file, "Id%p [label=\"BOOLEAN\"]\n", expr);
		if (expr->int_val == 0) {
			fprintf(file, "IdVal%p [label=\"false\"]\n", expr);
		}
		else {
			fprintf(file, "IdVal%p [label=\"true\"]\n", expr);
		}
		fprintf(file, "Id%p->IdVal%p\n", expr, expr);
		break;
	case logical_not:
		fprintf(file, "Id%p [label=\"!\"]\n", expr);
		PrintExpr(expr->left, file);
		fprintf(file, "Id%p->Id%p\n", expr, expr->left);
		break;
	case bin_ones_complement:
		fprintf(file, "Id%p [label=\"unary ~\"]\n", expr);
		PrintExpr(expr->left, file);
		fprintf(file, "Id%p->Id%p\n", expr, expr->left);
		break;
	case unary_plus:
		fprintf(file, "Id%p [label=\"unary +\"]\n", expr);
		PrintExpr(expr->left, file);
		fprintf(file, "Id%p->Id%p\n", expr, expr->left);
		break;
	case pow_:
		fprintf(file, "Id%p [label=\"**\"]\n", expr);
		PrintExpr(expr->left, file);
		PrintExpr(expr->right, file);
		fprintf(file, "Id%p->Id%p\n", expr, expr->left);
		fprintf(file, "Id%p->Id%p\n", expr, expr->right);
		break;
	case unary_minus:
		fprintf(file, "Id%p [label=\"unary -\"]\n", expr);
		PrintExpr(expr->left, file);
		fprintf(file, "Id%p->Id%p\n", expr, expr->left);
		break;
	case mul:
		fprintf(file, "Id%p [label=\"*\"]\n", expr);
		PrintExpr(expr->left, file);
		PrintExpr(expr->right, file);
		fprintf(file, "Id%p->Id%p\n", expr, expr->left);
		fprintf(file, "Id%p->Id%p\n", expr, expr->right);
		break;
	case div:
		fprintf(file, "Id%p [label=\"/\"]\n", expr);
		PrintExpr(expr->left, file);
		PrintExpr(expr->right, file);
		fprintf(file, "Id%p->Id%p\n", expr, expr->left);
		fprintf(file, "Id%p->Id%p\n", expr, expr->right);
		break;
	case mod:
		fprintf(file, "Id%p [label=\"%%\"]\n", expr);
		PrintExpr(expr->left, file);
		PrintExpr(expr->right, file);
		fprintf(file, "Id%p->Id%p\n", expr, expr->left);
		fprintf(file, "Id%p->Id%p\n", expr, expr->right);
		break;
	case plus:
		fprintf(file, "Id%p [label=\"+\"]\n", expr);
		PrintExpr(expr->left, file);
		PrintExpr(expr->right, file);
		fprintf(file, "Id%p->Id%p\n", expr, expr->left);
		fprintf(file, "Id%p->Id%p\n", expr, expr->right);
		break;
	case minus:
		fprintf(file, "Id%p [label=\"-\"]\n", expr);
		PrintExpr(expr->left, file);
		PrintExpr(expr->right, file);
		fprintf(file, "Id%p->Id%p\n", expr, expr->left);
		fprintf(file, "Id%p->Id%p\n", expr, expr->right);
		break;
	case bin_left_shift:
		fprintf(file, "Id%p [label=\"<<\"]\n", expr);
		PrintExpr(expr->left, file);
		PrintExpr(expr->right, file);
		fprintf(file, "Id%p->Id%p\n", expr, expr->left);
		fprintf(file, "Id%p->Id%p\n", expr, expr->right);
		break;
	case bin_right_shift:
		fprintf(file, "Id%p [label=\">>\"]\n", expr);
		PrintExpr(expr->left, file);
		PrintExpr(expr->right, file);
		fprintf(file, "Id%p->Id%p\n", expr, expr->left);
		fprintf(file, "Id%p->Id%p\n", expr, expr->right);
		break;
	case bin_and_op:
		fprintf(file, "Id%p [label=\"&\"]\n", expr);
		PrintExpr(expr->left, file);
		PrintExpr(expr->right, file);
		fprintf(file, "Id%p->Id%p\n", expr, expr->left);
		fprintf(file, "Id%p->Id%p\n", expr, expr->right);
		break;
	case bin_or_op:
		fprintf(file, "Id%p [label=\"|\"]\n", expr);
		PrintExpr(expr->left, file);
		PrintExpr(expr->right, file);
		fprintf(file, "Id%p->Id%p\n", expr, expr->left);
		fprintf(file, "Id%p->Id%p\n", expr, expr->right);
		break;
	case bin_xor_op:
		fprintf(file, "Id%p [label=\"^\"]\n", expr);
		PrintExpr(expr->left, file);
		PrintExpr(expr->right, file);
		fprintf(file, "Id%p->Id%p\n", expr, expr->left);
		fprintf(file, "Id%p->Id%p\n", expr, expr->right);
		break;
	case greater:
		fprintf(file, "Id%p [label=\">\"]\n", expr);
		PrintExpr(expr->left, file);
		PrintExpr(expr->right, file);
		fprintf(file, "Id%p->Id%p\n", expr, expr->left);
		fprintf(file, "Id%p->Id%p\n", expr, expr->right);
		break;
	case less:
		fprintf(file, "Id%p [label=\"<\"]\n", expr);
		PrintExpr(expr->left, file);
		PrintExpr(expr->right, file);
		fprintf(file, "Id%p->Id%p\n", expr, expr->left);
		fprintf(file, "Id%p->Id%p\n", expr, expr->right);
		break;
	case greater_eql:
		fprintf(file, "Id%p [label=\">=\"]\n", expr);
		PrintExpr(expr->left, file);
		PrintExpr(expr->right, file);
		fprintf(file, "Id%p->Id%p\n", expr, expr->left);
		fprintf(file, "Id%p->Id%p\n", expr, expr->right);
		break;
	case less_eql:
		fprintf(file, "Id%p [label=\"<=\"]\n", expr);
		PrintExpr(expr->left, file);
		PrintExpr(expr->right, file);
		fprintf(file, "Id%p->Id%p\n", expr, expr->left);
		fprintf(file, "Id%p->Id%p\n", expr, expr->right);
		break;
	case comb_comprassion:
		fprintf(file, "Id%p [label=\"<=>\"]\n", expr);
		PrintExpr(expr->left, file);
		PrintExpr(expr->right, file);
		fprintf(file, "Id%p->Id%p\n", expr, expr->left);
		fprintf(file, "Id%p->Id%p\n", expr, expr->right);
		break;
	case equal:
		fprintf(file, "Id%p [label=\"==\"]\n", expr);
		PrintExpr(expr->left, file);
		PrintExpr(expr->right, file);
		fprintf(file, "Id%p->Id%p\n", expr, expr->left);
		fprintf(file, "Id%p->Id%p\n", expr, expr->right);
		break;
	case case_equal:
		fprintf(file, "Id%p [label=\"===\"]\n", expr);
		PrintExpr(expr->left, file);
		PrintExpr(expr->right, file);
		fprintf(file, "Id%p->Id%p\n", expr, expr->left);
		fprintf(file, "Id%p->Id%p\n", expr, expr->right);
		break;
	case not_equal:
		fprintf(file, "Id%p [label=\"!=\"]\n", expr);
		PrintExpr(expr->left, file);
		PrintExpr(expr->right, file);
		fprintf(file, "Id%p->Id%p\n", expr, expr->left);
		fprintf(file, "Id%p->Id%p\n", expr, expr->right);
		break;
	case logical_and:
		fprintf(file, "Id%p [label=\"&&\"]\n", expr);
		PrintExpr(expr->left, file);
		PrintExpr(expr->right, file);
		fprintf(file, "Id%p->Id%p\n", expr, expr->left);
		fprintf(file, "Id%p->Id%p\n", expr, expr->right);
		break;
	case logical_or:
		fprintf(file, "Id%p [label=\"||\"]\n", expr);
		PrintExpr(expr->left, file);
		PrintExpr(expr->right, file);
		fprintf(file, "Id%p->Id%p\n", expr, expr->left);
		fprintf(file, "Id%p->Id%p\n", expr, expr->right);
		break;
	case inclusive_range:
		fprintf(file, "Id%p [label=\"..\"]\n", expr);
		PrintExpr(expr->left, file);
		PrintExpr(expr->right, file);
		fprintf(file, "Id%p->Id%p\n", expr, expr->left);
		fprintf(file, "Id%p->Id%p\n", expr, expr->right);
		break;
	case exclusive_range:
		fprintf(file, "Id%p [label=\"...\"]\n", expr);
		PrintExpr(expr->left, file);
		PrintExpr(expr->right, file);
		fprintf(file, "Id%p->Id%p\n", expr, expr->left);
		fprintf(file, "Id%p->Id%p\n", expr, expr->right);
		break;
	case assign:
		fprintf(file, "Id%p [label=\"=\"]\n", expr);
		PrintExpr(expr->left, file);
		PrintExpr(expr->right, file);
		fprintf(file, "Id%p->Id%p\n", expr, expr->left);
		fprintf(file, "Id%p->Id%p\n", expr, expr->right);
		break;
	case mod_assign:
		fprintf(file, "Id%p [label=\"%=\"]\n", expr);
		PrintExpr(expr->left, file);
		PrintExpr(expr->right, file);
		fprintf(file, "Id%p->Id%p\n", expr, expr->left);
		fprintf(file, "Id%p->Id%p\n", expr, expr->right);
		break;
	case div_assign:
		fprintf(file, "Id%p [label=\"/=\"]\n", expr);
		PrintExpr(expr->left, file);
		PrintExpr(expr->right, file);
		fprintf(file, "Id%p->Id%p\n", expr, expr->left);
		fprintf(file, "Id%p->Id%p\n", expr, expr->right);
		break;
	case sub_assign:
		fprintf(file, "Id%p [label=\"-=\"]\n", expr);
		PrintExpr(expr->left, file);
		PrintExpr(expr->right, file);
		fprintf(file, "Id%p->Id%p\n", expr, expr->left);
		fprintf(file, "Id%p->Id%p\n", expr, expr->right);
		break;
	case add_assign:
		fprintf(file, "Id%p [label=\"+=\"]\n", expr);
		PrintExpr(expr->left, file);
		PrintExpr(expr->right, file);
		fprintf(file, "Id%p->Id%p\n", expr, expr->left);
		fprintf(file, "Id%p->Id%p\n", expr, expr->right);
		break;
	case mul_assign:
		fprintf(file, "Id%p [label=\"*=\"]\n", expr);
		PrintExpr(expr->left, file);
		PrintExpr(expr->right, file);
		fprintf(file, "Id%p->Id%p\n", expr, expr->left);
		fprintf(file, "Id%p->Id%p\n", expr, expr->right);
		break;
	case pow_assign:
		fprintf(file, "Id%p [label=\"**=\"]\n", expr);
		PrintExpr(expr->left, file);
		PrintExpr(expr->right, file);
		fprintf(file, "Id%p->Id%p\n", expr, expr->left);
		fprintf(file, "Id%p->Id%p\n", expr, expr->right);
		break;
	case defined:
		fprintf(file, "Id%p [label=\"defined?\"]\n", expr);
		PrintExpr(expr->left, file);
		fprintf(file, "Id%p->Id%p\n", expr, expr->left);
		break;
	case not_keyword:
		fprintf(file, "Id%p [label=\"not\"]\n", expr);
		PrintExpr(expr->left, file);
		fprintf(file, "Id%p->Id%p\n", expr, expr->left);
		break;
	case and_keyword:
		fprintf(file, "Id%p [label=\"and\"]\n", expr);
		PrintExpr(expr->left, file);
		PrintExpr(expr->right, file);
		fprintf(file, "Id%p->Id%p\n", expr, expr->left);
		fprintf(file, "Id%p->Id%p\n", expr, expr->right);
		break;
	case or_keyword:
		fprintf(file, "Id%p [label=\"or\"]\n", expr);
		PrintExpr(expr->left, file);
		PrintExpr(expr->right, file);
		fprintf(file, "Id%p->Id%p\n", expr, expr->left);
		fprintf(file, "Id%p->Id%p\n", expr, expr->right);
		break;
	case var_or_method:
		fprintf(file, "Id%p [label=\"var or method\"]\n", expr);
		fprintf(file, "IdVal%p [label=\"%s\"]\n", expr, expr->str_val);
		fprintf(file, "Id%p->IdVal%p\n", expr, expr);
		break;
	case instance_var:
		fprintf(file, "Id%p [label=\"instance var\"]\n", expr);
		fprintf(file, "IdVal%p [label=\"%s\"]\n", expr, expr->str_val);
		fprintf(file, "Id%p->IdVal%p\n", expr, expr);
		break;
	case until_op:
		fprintf(file, "Id%p [label=\"until\"]\n", expr);
		PrintExpr(expr->left, file);
		PrintExpr(expr->right, file);
		fprintf(file, "Id%p->Id%p\n", expr, expr->left);
		fprintf(file, "Id%p->Id%p\n", expr, expr->right);
		break;
	case while_op:
		fprintf(file, "Id%p [label=\"while\"]\n", expr);
		PrintExpr(expr->left, file);
		PrintExpr(expr->right, file);
		fprintf(file, "Id%p->Id%p\n", expr, expr->left);
		fprintf(file, "Id%p->Id%p\n", expr, expr->right);
		break;
	case method_call:
		fprintf(file, "Id%p [label=\"method_call\"]\n", expr);
		fprintf(file, "IdMethodNameVal%p [label=\"%s\"]\n", expr, expr->str_val);
		fprintf(file, "Id%p->IdMethodNameVal%p [label=\"name\"]\n", expr, expr);
		if (expr->list != 0) {
			fprintf(file, "Id%p [label=\"params\"]\n", expr->list);
			fprintf(file, "Id%p->Id%p\n", expr, expr->list);
			struct expr_struct* current = expr->list->first;
			while (current != 0) {
				PrintExpr(current, file);
				fprintf(file, "Id%p->Id%p\n", expr->list, current);
				current = current->next;
			}
		}
		break;
	case array:
		fprintf(file, "Id%p [label = \"array\"]\n", expr);
		if (expr->list != 0) {
			struct expr_struct* current = expr->list->first;
			while (current != 0) {
				PrintExpr(current, file);
				fprintf(file, "Id%p->Id%p\n", expr, current);
				current = current->next;
			}
		}
		break;
	case member_access:
		fprintf(file, "Id%p [label = \"member access\"]\n", expr);
		PrintExpr(expr->left, file);
		PrintExpr(expr->right, file);
		fprintf(file, "Id%p->Id%p [label = \"array\"]\n", expr, expr->left);
		fprintf(file, "Id%p->Id%p [label = \"index\"]\n", expr, expr->right);
		break;
	case field_call:
		fprintf(file, "Id%p [label=\".\"]", expr);
		PrintExpr(expr->left, file);
		fprintf(file, "Id%p->Id%p [label = \"object\"]\n", expr, expr->left);
		fprintf(file, "Id%p [label = \"%s\"]\n", expr->str_val, expr->str_val);
		fprintf(file, "Id%p->Id%p [label = \"field\"]\n", expr, expr->str_val);
		break;
	case object_method_call:
		fprintf(file, "Id%p [label=\".\"]\n", expr);
		PrintExpr(expr->left, file);
		PrintExpr(expr->right, file);
		fprintf(file, "Id%p->Id%p [label = \"object\"]\n", expr, expr->left);
		fprintf(file, "Id%p->Id%p [label = \"method\"]\n", expr, expr->right);
		break;
	case self_field_call: 
		fprintf(file, "Id%p [label=\"self.\"]\n", expr);
		fprintf(file, "Id%p [label = \"%s\"]\n", expr->str_val, expr->str_val);
		fprintf(file, "Id%p->Id%p [label = \"field\"]\n", expr, expr->str_val);
		break;
	case self_method_call:
		fprintf(file, "Id%p [label=\"self.\"]\n", expr);
		PrintExpr(expr->right, file);
		fprintf(file, "Id%p->Id%p [label = \"method\"]\n", expr, expr->right);
		break;
	case member_access_and_assign:
		fprintf(file, "Id%p [label=\"[]=\"]\n", expr);
		PrintExpr(expr->left, file);
		fprintf(file, "Id%p->Id%p [label = \"array\"]\n", expr, expr->left);
		PrintExpr(expr->index, file);
		fprintf(file, "Id%p->Id%p [label = \"index\"]\n", expr, expr->index);
		PrintExpr(expr->right, file);
		fprintf(file, "Id%p->Id%p [label = \"val\"]\n", expr, expr->right);
		break;
	default:
		fprintf(file, "Id%p [label=\"expr\"]\n", expr);
		break;
	}
}