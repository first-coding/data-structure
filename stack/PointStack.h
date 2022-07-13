#pragma once
#include<stdio.h>
#include<stdlib.h>
typedef int StackItem;
typedef struct snode* slink;
typedef struct snode {
	StackItem element;
	slink next;
}Snode;
typedef struct lstack* Stack;
typedef struct lstack {
	slink top;
}Lstack;

slink NewStackNode() {
	return (slink)malloc(sizeof(Snode));
}

Stack StackInit() {
	Stack S = (Stack)malloc(sizeof * S);
	S->top = 0;
	return S;
}

int StackEmpty(Stack S) {
	return S->top == 0;
}

StackItem StackTop(Stack S) {
	if (StackEmpty(S)) return 0;
	return S->top->element;
}

void Push(StackItem x, Stack S) {
	slink p = NewStackNode();
	p->element = x;
	p->next = S->top;
	S->top = p;
}

StackItem Pop(Stack S) {
	if (StackEmpty(S)) return 0;
	StackItem x = S->top->element;
	slink p = S->top;
	S->top = p->next;
	free(p);
	return x;
}

void StackShow(StackItem x) {
	printf("%d\n", x);
}

void ItemShow(Stack S) {
	slink p = S->top;
	while (p) {
		StackShow(p->element);
		p = p->next;
	}
}