#pragma once
#include<stdio.h>
#include<stdlib.h>
#define HEAD 0
#define ATOM 1
#define CHILDLIST 2
#define AtomType int
typedef struct glnode* gpoint;
typedef struct glnode {
	int tag;
	union {
		AtomType atom;
		gpoint hp;
	};
	gpoint tp;
}GLNode;


gpoint  InitGenList() {
	gpoint L = (gpoint)malloc(sizeof(GLNode));
	if (L) {
		L->tag = HEAD;
		L->tp = NULL;
	}
	return L;
}


