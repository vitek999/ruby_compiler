#pragma once

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include "tree_nodes.h"
#include "semantic.h"
#include "Constant.h"
#include "Commands.h"

void generate(program_struct* program, const std::map<std::string, Clazz *> & clazzList);
void generate(Constant constant);
void generate(Method* method);
std::vector<char> generateConstructor(Method * m);
std::vector<char> generate(expr_struct * expr);
std::vector<char> generate(stmt_list_struct* list);

std::vector <char> intToBytes(int value);

std::vector<char> flToBytes(float value);

bool cmp(std::pair<Constant, int>& a, std::pair<Constant, int>& b);