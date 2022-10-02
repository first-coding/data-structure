#pragma once
#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100
#define SEleType int
#define ERROR -1
#define SUCCESS 1;

typedef struct astack* stackpoint;
typedef struct astack {
	SEleType* top;
	SEleType* bottom;
	int stacksize;
}Astack;

stackpoint StackInit() {
	stackpoint s = (stackpoint)malloc(sizeof(Astack));
	if (s) {
		s->stacksize = MAXSIZE;
		s->bottom = (SEleType*)malloc(sizeof(SEleType)*MAXSIZE);
		s->top = s->bottom;
	}
	return s;
}

int Push(SEleType x, stackpoint s) {
	if (s->top - s->bottom == s->stacksize)return ERROR;
	*s->top++ = x;
	return SUCCESS;
}

int Pop(stackpoint s,SEleType *e) {
	if (s->bottom == s->top)return ERROR;
	*e = *--s->top;
	return SUCCESS;
}

int GetElem(stackpoint s) {
	return *s->top-1;
}

int LengthStack(stackpoint s) {
	int counts = 1;
	SEleType* p = s->bottom;
	while (p != -842150) {
		p = p++;
	}
	return 0;
}



