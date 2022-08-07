#pragma once
#include<stdio.h>
#include<stdlib.h>

typedef int SetItem;
#define key(A) (A)
#define less(A,B) (key(A) < key(B))
#define swap(A,B) {ltlink t= A;A=B;B=t;}

typedef struct HBLTNode* ltlink;
typedef struct HBLTNode {
	int s;
	SetItem element;
	ltlink left,
		right;
}HBLTNode;

typedef struct hblt* MinHBLT;
typedef struct hblt {
	ltlink root;
}HBLT;

ltlink NewHBLTnode(SetItem x, int s) {
	ltlink p = (ltlink)malloc(sizeof(HBLTNode));
	p->element = x;
	p->s = s;
	p->left = 0;
	p->right = 0;
	return p;
}


MinHBLT HBLTInit() {
	MinHBLT H = (MinHBLT)malloc(sizeof * H);
	H->root = 0;
	return H;
}

ltlink Concatenate(ltlink x, ltlink y) {
	if (!y)return x;
	if (!x)return y;
	if (less(y->element, x->element)) {
		swap(x,y)
	}
	x->right = Concatenate(x->right, y);
	if (!x->left) {
		x->left = x->right;
		x->right = 0;
		x->s = 1;
	}
	else {
		if (x->left->s > x->right->s)swap(x->left, x->right);
		x->s = x->right->s + 1;
	}
	return x;
}

	