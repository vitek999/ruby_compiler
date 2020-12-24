#pragma once

#include <string>
#include <map>
#include <vector>
#include "tree_nodes.h"
#include "semantic.h"

void generate(program_struct* program, const std::map<std::string, Clazz *> & clazzList);

std::vector <char> intToBytes(int value);

std::vector<char> flToBytes(float value);