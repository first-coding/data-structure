#include "FatherNodeUnionFind2.h"

int main() {
	UFset U = UFinit(20);
	int x = UFfind(10, U);
	int y = UFunion(1, 10, U);
	UFfree(U);
	return 0;
}