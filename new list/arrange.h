#pragma once
#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100
#define ERROR -1
#define SUCCESS 1;
//typedef int Status;
typedef int ElemType;
typedef struct sqlist *point;
typedef struct sqlist{
	ElemType* elem;
	int length;
}SqList;

point InitList() {
	point L = (point)malloc(sizeof * L);
	if (L) {
		L->elem = (ElemType*)malloc(MAXSIZE * sizeof(MAXSIZE));
		L->length = 0;
	}
	else {
		printf("malloc error,we try against");
		InitList();
	}
	return L;
}

void DestroyList(point L) {
	if (L) {
		free(L);
	}
}

ElemType ListPlace(point L) {
	if (L->length == 0) {
		return 0;
	}
		return L->length;
}

void GetElem(point L, int i, ElemType *e) {
	if (!ListPlace(L)) {
		exit(ERROR);
	}
	if(L){
		*e = L->elem[i - 1];
	}
}

int LocateElem(point L, ElemType* e) {
	if (L) {
		for (int i = 0; i < L->length; i++) {
			if (L->elem[i] == *e) {
				return i + 1;
			}
		}
	}
	return 0;
}

int ListInsert(point L, ElemType x, int i) {
	if (i<1 || i>L->length+1) {
		return ERROR;
	}
	if (L->length == MAXSIZE) {
		return ERROR;
	}
	if(L) {
		for (int j = L->length-1; j >= i - 1; j--) {
			L->elem[j + 1] = L->elem[j];
		}
		L->elem[i - 1] = x;
		L->length++;
	}
	return SUCCESS;
}

int DeleteList(point L, int i) {
	if (i<1 || i>L->length) {
		return ERROR;
	}
	if(L) {
		for (int j = i; j <= L->length-1; j++) {
			L->elem[j - 1] = L->elem[j];
		}
		L->length--;
	}
	return SUCCESS;
}

void TravelseList(point L) {
	if (L) {
		for (int i = 0; i < L->length; i++) {
			printf("%5d", L->elem[i]);
		}
	}
}