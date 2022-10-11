#include"list.h"

int main() {
	gpoint L = InitGenList();
	GenListInsert(L, 1, 1);
	GenListInsert(L, 2, 0);
	GenListInsert(L, 1, 2);
	GenListInsert(L, 1, 3);
	GenListInsert(L, 1, 4);
	GenListDestory(L);
}