#pragma once
#include<stdio.h>
#include<stdlib.h>

typedef int ElemType;
typedef struct head* LpFirst;
typedef struct loop* LpPoint;
typedef struct loop {
	ElemType data;
	LpPoint next;
}Loop;
typedef struct head {
	LpPoint first;
}Head;
int ListLength(LpFirst L);
LpFirst ListInit();
LpPoint NewNode();
void DestroyList(LpFirst L);
void ListInsert(LpFirst L, int i, ElemType x);
void DeleteList(LpFirst L, int i);
int ListLength(LpFirst L);
void TravelseList(LpFirst L);
void GetElem(LpFirst L, int i, ElemType* e);
int LocateElem(LpFirst L, ElemType x);

LpFirst ListInit() {
	LpFirst L = (LpFirst)malloc(sizeof(Head));
	if (L){
		L->first = NULL;
}
	return L;
}

LpPoint NewNode() {
	return (LpPoint)malloc(sizeof(Loop));
}

void DestroyList(LpFirst L) {
	for (int i = 1; i <= ListLength(L); i++) {
		DeleteList(L, i);
	}
}

void ListInsert(LpFirst L,int i,ElemType x) {
	if (i==1) {
		LpPoint New = NewNode();
		New->data = x;
		LpPoint p = L->first;
		if (p == NULL) {
			L->first = New;
			New->next = L->first;
		}
		else {
			L->first = New;
			New->next = p;
		}
	}
	else {
		LpPoint p = L->first;
		LpPoint q = L->first;
		while (i > 2) {
			p = p->next;
			i--;
		}
		LpPoint News_2 = NewNode();
		q = p->next;
		if (q == L->first) {
			News_2->data = x;
			p->next = News_2;
			News_2->next = L->first;
		}
		else {
			News_2->data = x;
			News_2->next = q;
			p->next = News_2;
		}
	}
}

void DeleteList(LpFirst L, int i) {
	if (i > ListLength(L)) {
		exit(0);
	}
	if (i == 1) {
		LpPoint p = L->first;
		L->first = L->first->next;
		LpPoint q = L->first;
		while (q->next!=p) {
			q = q->next;
		}
		q->next = p->next;
		free(p);
	}
	else {
		LpPoint p = L->first;
		if (i == ListLength(L)) {
			while (p->next->next != L->first) {
				p = p->next;
			}
			LpPoint q = p->next->next;
			if (q == L->first) {
				free(p->next);
				p->next = q;
			}
		}
		else {
			LpPoint p = L->first;
			LpPoint q;
			int counts = 1;
			while (counts != i - 1) {
				p = p->next;
				counts++;
			}
			q = p->next;
			p->next = p->next->next;
			free(q);
		}
	}
}

int ListLength(LpFirst L) {
	int counts = 1;
	LpPoint p = L->first;
	while (p->next!=L->first) {
		counts++;
		p = p->next;
	}
	return counts;
}

void TravelseList(LpFirst L) {
	LpPoint p = L->first;
	do {
		printf("%5d", p->data);
		p = p->next;
	} while (p!=L->first);
}

void GetElem(LpFirst L, int i, ElemType* e) {
	if (i <= ListLength(L)) {
		int counts = 1;
		LpPoint p = L->first;
		while (counts != i) {
			p = p->next;
			counts++;
		}
		*e = p->data;
	}
}

int LocateElem(LpFirst L, ElemType x) {
	int counts = 1;
	LpPoint p = L->first;
	while (p->data != x) {
		p = p->next;
		counts++;
	}
	return counts;
}