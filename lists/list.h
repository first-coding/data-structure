#pragma once
#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable:6001)
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

gpoint NewNode() {
	return (gpoint)malloc(sizeof(GLNode));
}

gpoint InitGenList() {
	gpoint L = (gpoint)malloc(sizeof(GLNode));
	if (L) {
		L->tag = HEAD;
		L->tp = NULL;
		L->hp = NULL;
	}
	return L;
}

void GenListInsert(gpoint L,int tag, int x) {
	gpoint New = NewNode();
	if (tag == 1) {
		New->atom = x;
		New->tag = 1;
		New->tp = NULL;
		if (L->hp == NULL) {
			L->hp = New;
		}
		else {
			gpoint p2 = L->hp;
			gpoint p1 = p2;
			while (p2 != NULL) {
				if (p2->tag == 2) {
					if (p2->hp == NULL) {
						p2->hp = New;
						break;
					}
					else {
						p2 = p2->hp;
					}
				}
				else {
					p1 = p2;
					p2 = p2->tp;
					if (p2 == NULL) {
						p1->tp = New;
						break;
					}
				}
			}
		}
	}
	if (tag == 2) {
		New->hp = NULL;
		New->tp = NULL;
		New->tag = 2;
		if (L->hp == NULL) {
			L->hp = New;
		}
		else {
			gpoint p2 = L->hp;
			gpoint p1 = p2;
			while (p2 != NULL) {
				p1 = p2;
				p2 = p2->tp;
				if (p2!=NULL && p2->tag == 2) {
					p2 = p2->hp;
				}
			}
			p1->tp = New;
		}
	}
}

void GenListDestory(gpoint L) {
	gpoint p2 = L->hp;
	gpoint p1 = p2;
	while (p2 != NULL) {
		p1 = p2;
		p2 = p2->tp;
		free(p1);
		if (p2!=NULL && p2->tag == 2) {
			p2 = p2->hp;
		}
	}
}


