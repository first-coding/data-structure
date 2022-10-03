#pragma once
#include<stdio.h>
#include<stdlib.h>
#define ERROR -1
#define SUCCESS 1

typedef int StackElem;
typedef struct stacknode* StackPoint;
typedef struct stacknode {
	StackElem data;
	StackPoint next;
}StackNode;


StackPoint StackInit() {
	StackPoint s = NULL;
	return s;
}

StackPoint StackInsert(StackElem x, StackPoint s) {
	StackPoint New = (StackPoint)malloc(sizeof(StackNode));
	if (New) {
		New->data = x;
		New->next = s;
	}
	s = New;
	return s;
}

StackPoint StackPop(StackPoint s) {
	if (s == NULL) {
		return s;
	}
	StackPoint p = s;
	s = s->next;
	free(p);
	return s;
}

StackElem GetTop(StackPoint s) {
	if (s != NULL) {
		return s->data;
	}
}