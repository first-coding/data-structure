#pragma once
#include<stdio.h>
#include<stdlib.h>
#define ERROR -1
#define SUCCESS 1;
typedef int ElemType;
typedef struct pointlist* list;
typedef struct head* hlist;
typedef struct head {
	list head;
}Head;
typedef struct pointlist {
	ElemType data;
	list next;
}PointList;

hlist ListInit() {
	hlist L = (hlist)malloc(sizeof(Head));
	if (L) {
		L->head = NULL;
	}
	return L;
}

list NewNode() {
	return (list)malloc(sizeof(PointList));
}

void DestroyList(hlist L) {
	if (L->head) {
		list p = L->head;
		L->head = p->next;
		free(p);
		DestroyList(L);
	}
}

int CleanList(hlist L) {
	return L->head == NULL;
}

int ListLength(hlist L) {
	int counts = 1;
	list p = L->head;
	while (p) {
		counts++;
		p = p->next;
	}
	return counts;
}


void GetElem(hlist L, int i, ElemType* e) {
	if (1 > i && i>ListLength(L)) {
		return ;
	}
	int counts = 0;
	list p = L->head;
	while (counts<i-1) {
		p = p->next;
		counts++;
	}
	*e = p->data;
}

int ListInsert(hlist L, ElemType x,int i) {
	list New = NewNode();
		New->data = x;
		list p = L->head;
		if (i == 1) {
			New->next = L->head;
			L->head = New;
			return SUCCESS;
		}
		else {
			while (i > 2) {
				p = p->next;
				i--;
			}
			New->next = p->next;
			p->next = New;
			return SUCCESS;
	}
	return ERROR;
}

int DeleteList(hlist L, int i) {
	if (i == 1) {
		list p = L->head;
		L->head = L->head->next;
		free(p);
		return SUCCESS;
	}
	else {
		list p = L->head;
		list q;
		int counts = 1;
		while (counts != i-1) {
			p = p->next;
			counts++;
		}
		q = p->next;
		p->next = p->next->next;
		free(q);
		return SUCCESS;
	}
	return ERROR;
}

void TravelseList(hlist L) {
	list p = L->head;
	do {
		printf("%5d", p->data);
		p = p->next;
	} while (p);
}