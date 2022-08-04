#pragma once
#include<stdio.h>
#include<stdlib.h>

typedef unsigned short SetItem;
typedef struct atab {
	int arraysize;
	int last;
	SetItem* data;
}Atab,*Table;

Table TableInit(int size) {
	Table T = (Table)malloc(sizeof * T);
	T->arraysize = size;
	T->last = 0;
	T->data = (SetItem*)malloc(size * sizeof(SetItem));
	return T;
}

int TableMember(SetItem x, Table T) {
	for (int i = 0; i < T->last; i++) {
		if (T->data[i] == x)return 1;
	}
	return 0;
}

void TableInsert(SetItem x, Table T) {
	if (!TableMember(x, T) && T->last < T->arraysize)T->data[T->last++] = x;
}

void TableDelete(SetItem x, Table T) {
	int i = 0;;
	if (T->last > 0) {
		while (T->data[i] != x && i < T->last)i++;
		if (i < T->last && T->data[i] == x)T->data[i] = T->data[--T->last];
  	}  
}   