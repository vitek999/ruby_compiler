#include "dot.h"

void run_dot(const char* dot_path, const char* dot_file_path) {
	_spawnl(_P_NOWAIT, dot_path, "dot", "-O", "-Tsvg", dot_file_path, 0);
}