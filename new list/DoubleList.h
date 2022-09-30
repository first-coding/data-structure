#pragma once
#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable:6031)
#pragma warning(once:4996)
#define ERROR -1
#define SUCCESS 1;
typedef int ElemType;
typedef struct head* hdlist;
typedef struct doublelist* dblist;
typedef struct doublelist {
	ElemType data;
	dblist left;
	dblist right;
}DoubleList;
typedef struct head {
	dblist head;
}Head;
hdlist ListInit();
void DestroyList(hdlist L);
void ClearList(hdlist L);
int LengthList(hdlist L);
int EmptyList(hdlist L);
dblist NewNode();
int GetElem(hdlist L, int i, ElemType* e);
void LocateElem(hdlist L, ElemType x, int* i);
void InsertList(hdlist L, ElemType x, int i);
void DeleteList(hdlist L, int i);
void TravelseList(hdlist L);

hdlist ListInit() {
	hdlist L = (hdlist)malloc(sizeof(Head));
	if (L) {
		L->head = NULL;
	}
	return L;
}

dblist NewNode() {
	return (dblist)malloc(sizeof(DoubleList));
}

void DestroyList(hdlist L) {
	if (L->head) {
		dblist p = L->head;
		L->head = p->right;
		free(p);
		DestroyList(L);
	}
}

int LengthList(hdlist L) {
	dblist p = L->head;
	int counts = 0;
	while (p) {
		counts++;
		p = p->right;
	}
	return counts;
}

void ClearList(hdlist L) {
	int Length = LengthList(L),i=1;
	dblist p = L->head;
	while (Length != 0) {
		scanf("please input %d element %d against:", &i,&p->data);
		p = p->right;
		Length--;
		i++;
	}
}

int EmptyList(hdlist L) {
	return (L->head==NULL);
}

int GetElem(hdlist L, int i, ElemType* e) {
	if (1 > i) {
		return ERROR;
	}
	else {
		int counts = 1;
		dblist p = L->head;
		while (counts != i) {
			p = p->right;
			counts++;
		}
		*e = p->data;
	}
	return SUCCESS;
}

void LocateElem(hdlist L,ElemType x,int *i) {
	int counts = 1;
	dblist p = L->head;
	while (p) {
		if (p->data == x) {
			*i = counts;
			break;
		}
		else {
			p = p->right;
			counts++;
		}
	}
}

void InsertList(hdlist L, ElemType x, int i) {
	if (i == 1) {
		dblist New = NewNode();
		New->data = x;
		dblist p = L->head;
		if (p == NULL) {
			L->head = New;
			New->left = New->right = NULL;
		}
		else {
			L->head = New;
			New->right = p;
			p->left = New;
			New->left = NULL;
		}
	}
	else {
		dblist p = L->head;
		dblist q = L->head;
		while (i > 2) {
			p = p->right;
			i--;
		}
		dblist News_2 = NewNode();
		if(p->right!=NULL){
			News_2->data = x;
			p->right = News_2;
			News_2->left = p;
			News_2->right = q;
			q->left = News_2;
		}
		else {
			News_2->data = x;
			News_2->right = NULL;
			News_2->left = p;
			p->right = News_2;
		}
	}
}

void DeleteList(hdlist L, int i) {
	if (i == 1) {
		dblist p = L->head;
		L->head = p->right;
		L->head->left = NULL;
		free(p);
	}
	else {
		int counts = 1;
		dblist p = L->head;
		while (counts != i-1) {
			p = p->right;
			counts++;
		}
		if (counts == LengthList(L)-1) {
			free(p->right);
			p->right = NULL;
		}
		else {
			dblist q = p->right;
			p->right = q->right;
			q->right->left = p;
			free(q);
		}
	}
}

void TravelseList(hdlist L) {
	dblist p = L->head;
	do {
		printf("%3d", p->data);
		p = p->right;
	} while (p);
}