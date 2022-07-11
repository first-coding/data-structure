#pragma once
#include<stdio.h>
#include<stdlib.h>
typedef int ListItem;
typedef struct node* link;
typedef struct node {
	ListItem element;
	link left, right;
}Node;

typedef struct dlist* List;
typedef struct dlist {
	int n;
	link leftEnd, rightEnd;
}Dlist;

link NewNode() {
	return (link)malloc(sizeof(Node));
}

void ItemShow(ListItem x) {
	printf("%d\n",x);
}

List ListInit() {
	List L = (List)malloc(sizeof * L);
	L->n = 0;
	link left = NewNode();
	link right = NewNode();
	left->left = 0;
	left->right = right;
	L->leftEnd = left;
	right->left = left;
	right->right = 0;
	L->rightEnd = right;
	return L;
}

int ListEmpty(List L) {
	return L->n == 0;
}
ListItem ListRetrieve(int k, List L) {
	if (k < 1) return 0;
	link p = L->leftEnd->right;
	for (int i = 1; i < k; i++) p = p->right;
	return p->element;
}

int ListLocate(ListItem x, List L) {
	int i = 1;
	link p = L->leftEnd->right;
	for (int j = 1; j <L->n; j++,i++) {
		if (p->element == x) {
			break;
		}
		else {
			p = p->right;
		}
	}
	return i;
}

int ListLength(List L) {
	return L->n;
}

void ListInsert(List L, int k, ListItem x) {
	if (k<1) return;
	link news = NewNode();
	news->element = x;
	link p = L->leftEnd;
	for (int i = 1; i < k; i++) p = p->right;
	if (k == 1) {
		news->right = L->leftEnd->right;
		L->leftEnd->right->left = news;
		L->leftEnd->right = news;
		news->left = L->leftEnd;
	}
	else{
		news->right = p->right;
		p->right->left = news;
		p->right = news;
		news->left = p;
	}
	L->n++;
}

void ListDelete(List L, int k) {
	if (k < 1) return;
	link q = L->leftEnd->right;
	for (int j = 1; j < k; j++) q = q->right;
	if (k == 1) {
		L->leftEnd->right = q->right;
		q->right->left = L->leftEnd;
	}
	else {
		link p = q->left;
		p->right = q->right;
		q->right->left = p;
	}
	free(q);
	L->n--;
}

void PrintLeft(List L) {
	link p = L->leftEnd->right;
	for (int i = 1; i <= L->n; i++) {
		ItemShow(p->element);
		p = p->right;
	}
}

void PrintRight(List L) {
	link p = L->rightEnd->left;
	for (int i = 1; i <= L->n; i++) {
		ItemShow(p->element);
		p = p->left;
	}
}