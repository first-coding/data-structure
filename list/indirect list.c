#include "indirector.h"


void ItemShow(ListItem x) {
	printf("%d\n", x);
}
addr NewNode() {
	return (addr)malloc(sizeof(addr));
}

List ListInit(int size) {
	List L = (List)malloc(sizeof * L);
	L->n = 0;
	L->maxsize = size;
	L->table = (addr*)malloc(size * sizeof(addr));
	return L;
}

int ListEmpty(List L) {
	return L->n == 0;
}

int ListLength(List L) {
	return L->n;
}

ListItem ListRetrieve(int k, List L) {
	if (k<1 || k>L->n) return 0;
	return *L->table[k - 1];
}

int ListLocate(ListItem x, List L) {
	for(int i=0;i<L->n;i++){
		if (*L->table[i] == x) return ++i;
	}
	return 0;
}

void ListInsert(int k, ListItem x, List L) {
	if (k<0 || k>L->n)return;
	for (int i = L->n - 1; i >= k; i--) L->table[i + 1] = L->table[i];
	L->table[k] = NewNode();
	*L->table[k] = x;
	L->n++;
}

ListItem ListDelete(int k, List L) {
	if (k<1 || k>L->n) return 0;
	addr p = L->table[k - 1];
	ListItem x = *p;
	for (int i = k; i < L->n; i++) L->table[i - 1] = L->table[i];
	L->n--;
	free(p);
	return x;
}

void PrintList(List L) {
	for (int i = 0; i < L->n; i++) ItemShow(*L->table[i]);
}

//int main() {
//	List L = ListInit(20);
//	for (int k = 0; k <= 20; k++) {
//		ListInsert(k, k + 1, L);
//	}
//	PrintList(L);
//	int len = ListLength(L);
//	printf("\n");
//	printf("%d", len);
//
//}