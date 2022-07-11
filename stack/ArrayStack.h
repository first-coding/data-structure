#pragma once
#include<stdio.h>
#include<stdlib.h>
typedef int StackItem;
typedef StackItem* addr;
typedef struct astack* Stack;
typedef struct astack {
	int top, maxtop;
	StackItem* data;
}Astack;

void StackShow(StackItem x) {
	printf("%d\n", x);
}

Stack StackInit(int size) {
	Stack S = (Stack)malloc(sizeof * S);
	S->data = (StackItem*)malloc(size * sizeof(StackItem));
	S->maxtop = size;
	S->top = -1;
	return S;
}

int StackEmpty(Stack S) {
	return S->top < 0;
}

int StackFull(Stack S) {
	return S->top >= S->maxtop;
}

StackItem StackTop(Stack S) {
	if (StackEmpty(S)) return 0;
	return S->data[S->top];
}

void Push(StackItem x, Stack S) {
	if (StackFull(S)) return ;
	S->data[++S->top] = x;
}

StackItem Pop(Stack S) {
	if (StackEmpty(S)) return 0;
	return S->data[S->top--];
}

void StackFree(Stack S) {
	free(S->data);
	free(S);
}

void ItemShow(Stack S) {
	for(int i =S->top;i>-1; i--) {
		StackShow(S->data[i]);
	}
}