#pragma once
#include<stdio.h>
#include<stdlib.h>
typedef int ListItem;
typedef struct node* link;
typedef struct node {
	ListItem element;
	link next;
}Node;

typedef struct clist {
	int n;
	link last;
}Clist;
typedef struct clist* List;

link NewNode() {
	return (link)malloc(sizeof(Node));
}


List ListInit() {
	List L = (List)malloc(sizeof * L);
	L->n = 0;
	link y = NewNode();
	y->next = y;
	L->last = y;
	return L;
}

ListItem ListRetrieve(int k, List L) {
	int i = 1;
	if (k<1 || k>L->n) return 0;
	link p = L->last->next->next;
	while (i < k) {
		p = p->next;
		i++;
	}
	return p->element;
}

int ListLocate(ListItem x, List L) {
	int i = 1;
	link p = L->last->next->next;
	while (p->element != x) {
		p = p->next;
		i++;
	}
	return i;
}

void ListInsert(int k, ListItem x, List L) {
	if (k<0 || k>L->n) return;
	link p = L->last->next;
	for (int i = 1; i <= k; i++) p = p->next;
	link y = NewNode();
	y->element = x;
	y->next = p->next;
	p->next = y;
	if (k == L->n) L->last = y;
	L->n++;
}

void ListDelete(int k, List L) {
	if (k <1  || k > L->n) return;
	link q = L->last->next;
	for (int i = 1; i < k - 1; i++) q = q->next;
	link p = q->next;
	q->next = p->next;
	if (k == L->n) L->last = q;
	free(p);
	L->n--;
}

void ItemShow(ListItem x) {
	printf("%d\n", x);
}
void PrintList(List L) {
	for (link p = L->last->next->next; p != L->last->next; p = p->next)
		ItemShow(p->element);
}

