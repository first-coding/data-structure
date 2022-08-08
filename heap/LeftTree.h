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
	if (less(y->element, x->element)) {//this is bug
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

void HBLTInsert(SetItem x, MinHBLT H) {
	ltlink q = NewHBLTnode(x, 1);
	H->root = Concatenate(H->root, q);
}

SetItem HBLTMin(MinHBLT H) {
	if (H->root == 0)return 0;
	return H->root->element;
}

SetItem DeleteMin(MinHBLT H) {
	if (H->root == 0)return 0;
	SetItem x = H->root->element;
	ltlink L = H->root->left;
	ltlink R = H->root->right;
	free(H->root);
	H->root = Concatenate(L, R);
	return x;
}


typedef struct qnode* qlink;
typedef struct qnode {
	ltlink element;
	qlink next;
}Qnode;

typedef struct lqueue* Queue;
typedef struct lqueue {
	qlink first;
	qlink last;
}Lqueue;

qlink NewNode() {
	return (qlink)malloc(sizeof(Qnode));
}

int QueueEmpty(Queue Q) {
	return Q->first == 0;
}



Queue QueueInit() {
	Queue Q = (Queue)malloc(sizeof * Q);
	Q->first = Q->last = 0;
	return Q;
}

void EnterQueue(ltlink x, Queue Q) {
	qlink news = NewNode();
	news->element = x;
	news->next = 0;
	if (Q->first == 0) {
		Q->first = news;
		Q->last = news;
	}
	else {
		Q->last->next = news;
		Q->last = news;
	}
}

ltlink DeleteQueue(Queue Q) {
	if (QueueEmpty(Q)) return 0;
	ltlink x = Q->first->element;
	qlink q = Q->first;
	Q->first = q->next;
	free(q);
	return x;
}

MinHBLT BuildHBLT(SetItem a[], int n) {
	Queue Q = QueueInit();
	MinHBLT H = HBLTInit();
	for (int i = 1; i <= n; i++) {
		ltlink q = NewHBLTnode(a[i], 1);
		EnterQueue(q,Q);	
	}
	for (int i = 1; i <= n - 1; i++) {
		ltlink b = DeleteQueue(Q);
		ltlink c = DeleteQueue(Q);
		b = Concatenate(b, c);
		EnterQueue(b, Q);
	}
	if (n) {
		H->root = DeleteQueue(Q);
	}
	return H;
}

	