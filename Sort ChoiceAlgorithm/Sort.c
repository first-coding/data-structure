#include "Sort.h"
int main()
{
	List L = ListInit();
	int s[10] = { 10,2,3,88,22,10,30,80,90,20 };
	for (int i = 0; i < 10; i++) {
		ListInsert(i, s[i], L);
	}
	PrintList(L);
	link c = mergesort(L->first);
	printf("\n");
	for (int i = 0; i < 10; i++) {
		printf("%d\n", c->element);
		c = c->next;
	}
	return 0;
}


