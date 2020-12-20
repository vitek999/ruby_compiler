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
	std::vector<std::string> local_variables;
	stmt_list_struct* body;
	int number;
};

class Clazz {
public:
	int number;
	int parent;

	std::string name;

	std::map<Constant, int> constants;
	std::map<std::string, Method *> methods;
	std::map<std::string, Field> fields;

	int pushConstant(const Constant& c) {
		// TODO: Если константа есть, то вернуть ее.
		auto iter = constants.find(c);
		if (iter == constants.end()) {
			++_ID;
			constants[c] = _ID;
			return _ID;
		}
		return iter->second;
	}

private:
	long long _ID = 0;
};

inline std::map<std::string, Clazz*> clazzesList;

std::string method_descriptor(int size);

void fillTable(program_struct* program);
void fillTable(Clazz* clazz, def_method_stmt_struct * method);
void fillTable(Clazz* clazz, Method * method, stmt_list_struct* body);
void fillTable(Clazz* clazz, Method* method, stmt_struct* stmt);
void fillTable(Clazz* clazz, Method* method, expr_struct* expr);
void fillTable(Clazz* clazz, Method* method, if_part_stmt_struct * if_branch_stmt);
void fillTable(class_declaration_struct* class_decl);

void transformTree(program_struct* program);
void transform(expr_struct* expr);
void transform(stmt_struct* stmt);
void transform(stmt_list_struct* stmt_list);
void transform(if_stmt_struct* stmt);
void transform(program_item_struct* item);
void transform(def_method_stmt_struct* def_method);
void transform(class_declaration_struct* cls);