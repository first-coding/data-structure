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
		s->stacksize = 0;
		s->bottom = (SEleType*)malloc(sizeof(SEleType)*MAXSIZE);
		s->top = s->bottom;
	}
	return s;
}

int Push(SEleType x, stackpoint s) {
	if (s->top - s->bottom == MAXSIZE)return ERROR;
	*s->top++ = x;
	s->stacksize++;
	return SUCCESS;
}

int Pop(stackpoint s,SEleType *e) {
	if (s->bottom == s->top)return ERROR;
	s->top = s->top--;
	*e = *s->top;
	s->stacksize--;
	return SUCCESS;
}

int GetElem(stackpoint s) {
	return *s->top-1;
}

int LengthStack(stackpoint s) {
	return s->stacksize;
}

void StackTravels(stackpoint s) {
	for (int i = 0; i < LengthStack(s); i++) {
		printf("%3d", s->bottom[i]);
	}
}



