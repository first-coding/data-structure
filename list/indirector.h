#pragma once
#include<stdio.h>
#include<stdlib.h>
typedef struct indlist* List;
typedef int ListItem;
typedef ListItem* addr;
typedef struct indlist {
	int n, curr;
	int maxsize;
	addr *table;
};
addr NewNode();
List ListInit(int size);
int ListEmpty(List L);
int ListLength(List L);
ListItem ListRetrieve(int k, List L);
int ListLocate(ListItem x, List L);
void ListInsert(int k, ListItem x, List L);
ListItem ListDelete(int k, List L);
void PrintList(List L);