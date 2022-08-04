#pragma once
#include<stdio.h>
#include<stdlib.h>

typedef struct bitset* Set;
typedef struct bitset {
	int setsize;
	int arraysize;
	unsigned short* v;
}Bitset;

Set SetInit(int size) {
	Set S = (Set)malloc(sizeof * S);
	S->setsize = size;
	S->arraysize = (size + 15) >> 5;
	S->v = (unsigned short*)malloc(20 * sizeof(unsigned short));
	for (int i = 0; i < S->arraysize; i++) { 
		S->v[i] = 0;
	}	
	return S;
}

//set assignment
void SetAssign(Set A, Set B) {
	if (A->setsize != B->setsize) return;
	for (int i = 0; i < A->setsize; i++)A->v[i] = B->v[i];
}

int ArrayIndex(int x) {
	return x >> 4;
} 

unsigned short BitMask(int x) {
	return 1 << (x & 15);
}

//member attribute
int SetMember(int x, Set S) {
	if (x < 0 || x >= S->setsize) return 0;
	return S->v[ArrayIndex(x)] & BitMask(x);
}

//判断集合A和集合B是否相等
int SetEqual(Set A, Set B) {
	if (A->setsize != B->setsize) return 0;
	int retval = 1;
	for (int i = 0; i < A->arraysize; i++) {
		if (A->v[i] != B->v[i]) {
			retval = 0;
			break;
		}
	}
	return retval;
}

//SetUnion
Set SetUnion(Set A, Set B) {
	Set tmp = SetInit(A->setsize);
	for (int i = 0; i < A->arraysize; i++) {
		tmp->v[i] = A->v[i] | B->v[i];
	}
	return tmp;
}

//SetInterSection
Set SetInterSection(Set A, Set B) {
	Set tmp = SetInit(A->setsize);
	for (int i = 0; i < A->arraysize; i++) {
		tmp->v[i] = A->v[i] & B->v[i];
	}
	return tmp;
}

//SetDifference
Set SetDifference(Set A, Set B) {
	Set tmp = SetInit(A->setsize);
	for (int i = 0; i < A->arraysize; i++) {
		tmp->v[i] = A->v[i] ^ (B->v[i] & A->v[i]);
	}
	return tmp;
}

void SetInsert(int x, Set S) {
	if (x < 0 || x >= S->setsize) return;
	S->v[ArrayIndex(x)] |= BitMask(x);
}	


void SetDelete(int x, Set S) {
	if (x < 0 || x >= S->setsize) return;
	S->v[ArrayIndex(x)] &= ~BitMask(x);
}

