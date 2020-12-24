#pragma once

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include "tree_nodes.h"
#include "semantic.h"
#include "Constant.h"

void generate(program_struct* program, const std::map<std::string, Clazz *> & clazzList);
void generate(Constant constant);

std::vector <char> intToBytes(int value);

std::vector<char> flToBytes(float value);