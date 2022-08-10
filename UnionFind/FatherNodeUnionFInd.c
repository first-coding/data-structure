#include "FatherNodeUnionFind.h"

int main() {
	UFset U = UFinit(20);
	int x = UFfind(2, U);
	int y = UFunion(1, 10, U);
	return 0;
}