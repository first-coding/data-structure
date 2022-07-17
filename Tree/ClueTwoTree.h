#pragma once
#include<stdio.h>
#include<stdlib.h>
#include <windows.h>

//typedef int TreeItem;
//typedef struct tbtnode* tbtlink;
//typedef struct tbtnode {
//	TreeItem element;
//	tbtlink left;
//	tbtlink right;
//	int leftThread,
//		rightThread;
//}ThreadedNode;
//
//tbtlink NewBNode() {
//	return (tbtlink)malloc(sizeof(ThreadedNode));
//}
//
//typedef struct binarytree* TBinaryTree;
//typedef struct binarytree {
//	tbtlink root;
//}TRTree;
//
//TBinaryTree ClueTreeInit() {
//	TBinaryTree T = (TBinaryTree)malloc(sizeof * T);
//	T->root = 0;
//	return T;
//}


typedef enum { Linked, Thread } PointTag;
typedef struct Node {
	char data;
	struct Node* lchild;
	struct Node* rchild;
	PointTag ltag;
	PointTag rtag;
}BitNode, * BiTree;


void CreateBiTree(BiTree* T) {
	char ch = 0;
	scanf("%c", &ch);
	if (ch == ' ') {
		*T = NULL;
	}
	else {
		*T = (BiTree)malloc(sizeof(BitNode));
		if (!(*T)) {
			exit(-1);
		}
		(*T)->data = ch;
		CreateBiTree(&((*T)->lchild));
		CreateBiTree(&((*T)->rchild));
	}
}

BiTree pre; 
void InThreading(BiTree T) {
	if (T) {
		InThreading(T->lchild);
		if (!T->lchild) {
			T->ltag = Thread;
			T->lchild = pre;
		}
		else {
			T->ltag = Linked;
		}
		if (!pre->rchild) {
			pre->rtag = Thread;
			pre->rchild = T;
		}
		else {
			pre->rtag = Linked;
		}
		pre = T;
		InThreading(T->rchild);
	}
}

void InOrderThreading(BiTree* Thrt, BiTree T) {
	if (!T) {
		return;
	}
	*Thrt = (BiTree)malloc(sizeof(BitNode));
	if (!(*Thrt)) {
		exit(-1);
	}
	(*Thrt)->ltag = Linked;
	(*Thrt)->rtag = Thread;
	(*Thrt)->lchild = T;
	(*Thrt)->rchild = *Thrt;
	
	pre = *Thrt;

	InThreading(T);
	
	pre->rtag = Thread;
	pre->rchild = *Thrt;
	(*Thrt)->rchild = pre;
}

void InOrderTraverse(BiTree Thrt) {
	BiTree p = Thrt->lchild;
	while (p != Thrt) {
		while (p->ltag == Linked) {
			p = p->lchild;
		}
		printf("%2c", p->data);
		while (p->rtag == Thread && p->rchild != Thrt) {
			p = p->rchild;
			printf("%2c", p->data);
		}
		p = p->rchild;
	}
	printf("\n");
}

BiTree InOrderPre(BiTree T) {
	if (T->ltag == Thread) {
		return T->lchild;
	}
	BiTree p = T->lchild;
	while (p->rtag == Linked) {
		p = p->rchild;
	}
	return p;
}

BiTree InOrderNext(BiTree T) {
	if (T->rtag == Thread) {
		return T->rchild;
	}
	BiTree p = T->rchild;
	while (p->ltag == Linked) {
		p = p->lchild;
	}
	return p;
}

void Destroy(BiTree* Thrt) {
	BiTree p = (*Thrt)->lchild;
	BiTree adjust = p;
	while (p != *Thrt) { 
		while (p->ltag == Linked) {
			p = p->lchild;
		}
		while (p->rtag == Thread && p->rchild != *Thrt) {
			adjust = p;
			p = p->rchild;
			free(adjust);
		}
		adjust = p;
		p = p->rchild;
		free(adjust);
	}
	free(*Thrt);
	*Thrt = NULL;
	adjust = p = NULL;
}

