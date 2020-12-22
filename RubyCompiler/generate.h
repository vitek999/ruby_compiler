#pragma once

#include <string>
#include <map>
#include "tree_nodes.h"
#include "semantic.h"

void generate(program_struct* program, const std::map<std::string, Clazz *> & clazzList);