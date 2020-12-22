#include <stdio.h>
#include "tree_nodes.h"
#include "semantic.h"
#include "generate.h"

extern "C" FILE * yyin;
extern "C" int yyparse();
extern "C" struct program_struct * root;
extern "C" void PrintProgram(struct program_struct* smts, FILE * file);
extern "C" void run_dot(const char* dot_path, const char* dot_file_path);

int main(int argc, char** argv) {
    yyin = fopen(argv[1], "r");

    FILE* tree = fopen("tree.dot", "w");

    yyparse();
    transformTree(root);
    PrintProgram(root, tree);
    fillTable(root);
    generate(root, clazzesList);

    run_dot("../dot/dot.exe", "../RubyCompiler/tree.dot");
    return 0;
}