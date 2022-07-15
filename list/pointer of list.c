#include "PointList.h"

int main() {
	List L = ListInit();
	for (int i = 0; i <= 10; i++) {
		ListInsert(i, i + 1, L);
	}
	PrintList(L);
	printf("\n");
	if (ListEmpty(L) != 0) {
		return 0;
	}
	else {
		int length = ListLength(L);
	}
	for (int j = 0; j <= 10; j++) {
		ListItem element = ListRetrieve(j, L);
		int element_2 = ListLocate(j + 1, L);
		printf("%d\n", element);
		printf("%d\n", element_2);
	}
	return 1;
}

