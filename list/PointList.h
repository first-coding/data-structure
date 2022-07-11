#pragma once
#include<stdio.h>
#include<stdlib.h>

typedef int ListItem;
typedef struct node* link;
typedef struct node {
	ListItem element;
	link next;
}Node;

typedef struct llist* List;
typedef struct llist {
	link first, curr, last;
}Llist;

link NewNode() {
	return (link)malloc(sizeof(Node));
}

List ListInit();
int ListEmpty(List L);
int ListLength(List L);
ListItem ListRetrieve(int k, List L);
int ListLocate(ListItem x, List L);
void ListInsert(int k, ListItem x, List L);
ListItem ListDelete(int k, List L);
void PrintList(List L);