#include"doubleList.h"

int main() {
	List L = ListInit();
	for (int i = 1; i < 10; i++) {
		ListInsert(L, i, i + 1);
	}
	PrintLeft(L);
	printf("\n");
	ListItem x = ListRetrieve(9, L);
	printf("element is %d\n", x);
	printf("\n");

	printf("%d\n", L->n);
	int index = ListLocate(10, L);
	printf("index is %d\n", index);
	printf("\n");
	PrintRight(L);
	printf("\n");
	ListDelete(L, 3);
	PrintLeft(L);
	printf("\n");
	PrintRight(L);
	return 0;
}