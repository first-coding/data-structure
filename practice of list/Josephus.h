#pragma once
#include<stdio.h>
#include<stdlib.h>

typedef int ListItem;
typedef struct node* link;
typedef struct node {
	ListItem element;
	link next;
}Node;

typedef struct clist* List;
typedef struct clist {
	int n;
	link last,
		curr;
}Clist;



link NewNode() {
	return (link)malloc(sizeof(Node));
}

List ListInit() {
	List L = (List)malloc(sizeof * L);
	link y = NewNode();
	y->next = y;
	L->last = y;
	L->n = 0;
	return L;
}

void ListInsert(int k, ListItem x, List L) {
	if (k<0 || k>L->n) return;
	link p = L->last->next;
	for (int i = 1; i <= k; i++) p = p->next;
	link y = NewNode();
	y->element = x;
	y->next = p->next;
	p->next = y;
	if (k == L->n)L->last = y;
	L->n++;
}

void IterInit(List L) {
	L->curr = L->last->next;
}

void IterNext(List L) {
	L->curr = L->curr->next;
	if (L->curr == L->last) L->curr = L->curr->next;
}

ListItem DeleteCurr(List L) {
	link q = L->curr;
	link p = q->next;
	q->next = p->next;
	if (p == L->last) {
		L->last = q; L->curr = L->curr->next;
	}
	ListItem x = p->element;
	free(p);
	L->n--;
	return x;
}

ListItem* CurrItem(List L) {
	if (L->n == 0)return 0;
	else return &L->curr->next->element;
}

void Josephus(int n, int m) {
	List l = ListInit();
	for (int i = 1; i <= n; i++)ListInsert(i - 1, i, l);
	IterInit(l);
	for (int i = 1; i < n; i++) {
		for (int j = 1; j < m; j++)IterNext(l);
		ListItem x = DeleteCurr(l);
		printf("delete complete %d\n", x);
	}
	printf("complete %d win \n", *CurrItem(l));
}