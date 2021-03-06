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

List ListInit() {
	List L = (List)malloc(sizeof * L);
	L->first = 0;
	return L;
} //InitList

int ListEmpty(List L) {// test List is null
	return L->first == 0;
}

int ListLength(List L) {//culculate list length
	int len = 0;
	link p = L->first;
	while (p) {
		len++;
		p = p->next;
	}
	return len;
}
ListItem ListRetrieve(int k, List L) {//return element k in the List L
	if (k < 1)return 0;
	link p = L->first;
	int i = 1;
	while (i < k && p) {
		p = p->next;
		i++;
	}
	return p->element;
}
int ListLocate(ListItem x, List L) {//return element x  index in the List L
	int i = 1;
	link p = L->first;
	while (p && p->element != x) {
		p = p->next;
		i++;
	}
	return i;
}
void ListInsert(int k, ListItem x, List L) {//Insert element x in index k List L
	if (k < 0)return;
	link p = L->first;
	for (int i = 1; i < k && p; i++) {
		p = p->next;
	}
	link y = NewNode();
	y->element = x;
	if (k) {
		y->next = p->next;
		p->next = y;
	}
	else {
		y->next = L->first;
		L->first = y;
	}
}
ListItem ListDelete(int k, List L) {
	if (k < 1 || !L->first) return 0;
	link p = L->first;
	if (k == 1) L->first = p->next;
	else {
		link q = L->first;
		for (int i = 1; i < k - 1 && q; i++) {
			q = q->next;
		}
		p = q->next;
		q->next = p->next;
	}
	ListItem x = p->element;
	free(p);
	return x;
}

void ItemShowList(ListItem x) {
	printf("%d\n", x);
}

void PrintList(List L) {
	for (link p = L->first; p; p = p->next) ItemShowList(p->element);
}