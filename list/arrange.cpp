#include"List.h"
void ItemShow(ListItem x) {
	printf("%d \n", x);
}
List ListInit(int size) {
	List L = (List)malloc(sizeof * L);
	L->table = (ListItem*)malloc(size * sizeof(ListItem));
	L->maxsize = size;
	L->n = 0;
	return L;
}

int ListEmpty(List L) {
	return L->n == 0;
}

int ListLength(List L) {
	return L->n;
}

ListItem ListRetrieve(int k, List L) {
	if (k<0 || k>L->n) return 0;
	return L->table[k - 1];
}

int ListLocate(ListItem x, List L) {
	for (int i = 0; i < L->n; i++) {
		if (L->table[i] == x) {
			return ++i;
		}
	}
	return 0;
}

void ListInsert(int k, ListItem x, List L) {
	if (k<0 || k>L->n) return;
	for (int i = L->n - 1; i >= k; i--) {
		L->table[i + 1] = L->table[i];
	}
	L->table[k] = x;
	L->n++;
}

ListItem ListDelete(int k,List L) {
	if (k<0 || k>L->n) return 0; 
	ListItem x = L->table[k - 1];
	for (int i = k; i < L->n; i++) {
		L->table[i - 1] = L->table[i];
	}
	L->n--;
	return x;
}

void PrintList(List L) {
	for (int i = 0; i < L->n; i++)ItemShow(L->table[i]);
}

int main(void) {
	List L = ListInit(20);
	for (int i = 0; i < 10; i++) {
		ListInsert(i, i+1, L);
	}
	PrintList(L);
	printf("%d\n", ListLength(L));
	int element = ListDelete(5, L);
	printf("%d\n", ListLength(L));
	PrintList(L);
	return 0;
}