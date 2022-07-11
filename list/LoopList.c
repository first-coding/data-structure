#include "LoopList.h"

int main() {
	List L = ListInit();
	for (int i = 0; i < 10; i++) {
		ListInsert(i, i + 1, L);
	}
	PrintList(L);
	int len = L->n;
	printf("%d\n",len);
	int data = ListRetrieve(2, L);
	int data_2 = ListLocate(5, L);
	ListDelete(0, L);
	printf("\n");
	printf("%d\n", data);
	printf("%d\n", data_2);
	int len_2 = L->n;
	printf("%d\n", len_2);
	printf("\n");
	PrintList(L);
	return 0;
}