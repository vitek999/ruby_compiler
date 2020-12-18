#pragma once

#include "tree_nodes.h"

void transformTree(program_struct* program);
void transform(expr_struct* expr);
void transform(stmt_struct* stmt);
void transform(stmt_list_struct* stmt_list);
void transform(if_stmt_struct* stmt);
void transform(program_item_struct* item);
void transform(def_method_stmt_struct* def_method);
void transform(class_declaration_struct* cls);