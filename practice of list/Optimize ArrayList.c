#include "Optimize ArrayLIst.h"

int main() {
	List L = ListInit();
	for (int i = 1; i < 10; i++) {
		ListInsert(i, i + 1, L);
	}
	PrintList(L);
	ListDelete(2, L);
	printf("\n");
	PrintList(L);
	return 0;
}