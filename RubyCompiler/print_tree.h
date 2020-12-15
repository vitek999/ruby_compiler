#pragma once

#include "tree_nodes.h"
#include <stdio.h>

void PrintProgram(struct program_struct* smts, FILE* file);
void PrintStmt(struct stmt_struct* stmt, FILE* file);
void PrintExpr(struct expr_struct* expr, FILE* file);
void PrintFor(struct for_stmt_struct* for_s, FILE* file);
void PrintWhile(struct while_stmt_struct* while_s, FILE* file);
void PrintUntil(struct until_stmt_struct* until_s, FILE* file);
void PrintStmtList(struct stmt_list_struct* list, void* parent, FILE* file);
void PrintProgramItemsList(struct program_item_list_struct* list, void* parent, FILE* file);
void PrintBlock(struct stmt_block_struct* block, FILE* file);
void PrintIf(struct if_stmt_struct * if_s, FILE * file);
void PrintReturnStmt(struct stmt_struct* stmt, FILE * file);
void PrintDefMethod(struct def_method_stmt_struct * method, FILE* file);
void PrintClassDeclaration(struct class_declaration_struct* class_decl, FILE* file);