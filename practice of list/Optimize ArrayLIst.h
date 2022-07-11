#pragma once
#include<stdio.h>
#include<stdlib.h>

typedef int ListItem;
typedef ListItem* addr;
typedef struct alist* List;
typedef struct alist {
	int n, curr;
	int maxsize;
	ListItem* table;
}Alist;

List ListInit();
int ListEmpty(List L);
void ItemShow(ListItem x);
int ListLength(List L);
ListItem ListRetrieve(int k, List L);
int ListLocate(ListItem x, List L);
void ListInsert(int k, ListItem x, List L);
void ListDelete(int k, List L);
void PrintList(List L);

void ItemShow(ListItem x) {
	printf("%d\n", x);
}

void PrintList(List L) {
	for (int j = 0; j < L->n; j++) ItemShow(L->table[j]);
}

List ListInit() {
	List L = (List)malloc(sizeof * L);
	L->maxsize = 1;
	L->table = (ListItem*)malloc(L->maxsize * sizeof(ListItem));
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
	for (int i = 0; i < L->n ; i++) {
		if (L->table[i] == x) {
			return i++;
		}
		else {
			return 0;
		}
	}
	return 0;
}


void ListInsert(int k, ListItem x, List L) {
	if (L->maxsize == L->n) {
		L->maxsize *= 2;
		ListItem* NewTable = (ListItem*)malloc(L->maxsize*sizeof(ListItem));
		for (int i = 0;i<L->n; i++) {
			NewTable[i] = L->table[i];
		}
		free(L->table);
		for (int j = L->n; j >= k; j--) {
			NewTable[j] = NewTable[j-1];
		}
		NewTable[k-1] = x;
		L->n++;
		L->table = NewTable;
	}
	else {
		for (int i = L->n - 1; i >= k; i--) {
			L->table[i + 1] = L->table[i];
		}
		L->table[k - 1] = x;
		L->n++;
	}
}

void ListDelete(int k, List L) {
	for (int i = k; i < L->n; i++) {
		L->table[i - 1] = L->table[i];
	}
	L->n--;
	if ((L->n <= L->maxsize/4) && L->maxsize>1) {
		L->maxsize = L->maxsize / 2;
		ListItem* NewTable = (ListItem*)malloc(L->maxsize * sizeof(ListItem));
		for (int i = 0; i < L->n; i++) {
			NewTable[i] = L->table[i];
		}
		free(L->table);
		L->table = NewTable;
	}
}