#pragma once

#include "tree_nodes.h"
#include "Constant.h"
#include <string>
#include <vector>
#include <map>

struct Field {
	bool isStatic;
	std::string name;
	int number;
};

struct Method {
	bool isStatic;
	std::string name;
	std::map<std::string, Field> local_variables;
	stmt_struct* body;
	int number;
};

class Clazz {
public:
	int number;
	int parent;

	std::map<int, Constant> constants;
	std::map<std::string, Method> methods;
	std::map<std::string, Field> fields;
};

void fillTable(program_struct* program);

void transformTree(program_struct* program);
void transform(expr_struct* expr);
void transform(stmt_struct* stmt);
void transform(stmt_list_struct* stmt_list);
void transform(if_stmt_struct* stmt);
void transform(program_item_struct* item);
void transform(def_method_stmt_struct* def_method);
void transform(class_declaration_struct* cls);