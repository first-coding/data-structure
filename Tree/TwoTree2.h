#pragma once
#include<stdio.h>
#include<stdlib.h>
typedef int TreeItem;
typedef TreeItem* Treeaddr;

typedef struct treeNode* Treelink;
typedef struct treeNode {
	TreeItem element;
	Treelink left;
	Treelink right;
	int leftflag, rightflag;
}TreeNode;

typedef struct treeroot* rootaddr;
typedef struct treeroot {
	Treelink root;
}Treeroot;


void TreeItemShow(TreeItem x) {
	printf("%d ", x);
}

Treelink TreeNewNode() {
	return (Treelink)malloc(sizeof(TreeNode));
}

rootaddr TreeInit() {
	rootaddr T = (rootaddr)malloc(sizeof * T);
	T->root = 0;
	return T;
}

int TreeEmpty(rootaddr T) {
	return T->root == 0;
}

TreeItem Root(rootaddr T) {
	if (TreeEmpty(T))return 0;
	return T->root->element;
}

rootaddr MakeTree(TreeItem x, rootaddr T, rootaddr L,rootaddr R){
	if (L != 0 && R != 0) {
		T->root = TreeNewNode();
		T->root->element = x;
		T->root->left = L->root;
		T->root->right = R->root;
		L->root = R->root = 0;
		return T;
	}
	else {
		T->root = TreeNewNode();
		T->root->element = x;
		T->root->left = T->root->right = 0;
		T->root->left = T->root->right = 0;
		return T;
	}
}

void PreOrder(void(*visit)(Treelink u), Treelink t) {
	if (t) {
		(*visit)(t);
		PreOrder(visit, t->left);
		PreOrder(visit, t->right);
	}
}

void InOrder(void(*visit)(Treelink u), Treelink t) {
	if (t) {
		InOrder(visit, t->left);
		(*visit)(t);
		InOrder(visit, t->right);
	}
}

void PostOrder(void(*visit)(Treelink u), Treelink t) {
	if (t) {
		PostOrder(visit, t->left);
		PostOrder(visit, t->right);
		(*visit)(t);
	}
}

void outnode(Treelink t) {
	TreeItemShow(t->element);
}

void PreOut(rootaddr T) {
	PreOrder(outnode, T->root);
}

void InOut(rootaddr T) {
	InOrder(outnode, T->root);
}

void PostOut(rootaddr T) {
	PostOrder(outnode, T->root);
}

void firstOut(rootaddr T) {
	Treelink FirstStack[15];
	int top = -1;
	Treelink p = T->root;
	while (p != NULL || top != -1) {
		if (p != NULL) {
			FirstStack[++top] = p;
			if (p->left != NULL) {
				p->leftflag = 1;
			}
			else {
				p->leftflag = 0;
			}
			if (p->right != NULL) {
				p->rightflag = 1;
			}
			else {
				p->rightflag = 0;
			}
			printf("%d  ", p->element);
			p = p->left;
		}
		else {
			p = FirstStack[top--];
			p = p->right;
		}
	}
}


void middleOut(rootaddr T) {
	Treelink MiddleStacks[15];
	int top = -1;
	Treelink p = T->root;
	while (p != NULL || top != -1) {
		if (p != NULL) {
			MiddleStacks[++top] = p;
			p = p->left;
		}
		else {
			p = MiddleStacks[top--];
			printf("%d  ", p->element);
			p = p->right;
		}
	}
}

void lastOut(rootaddr T) {
	Treelink LastStacks[15];
	int LastStacksFlag[15];
	int top = -1;
	Treelink p = T->root;
	while (p != NULL || top != -1) {
		if (p != NULL) {
			LastStacks[++top] = p;
			//printf("%d  ", p->element);
			LastStacksFlag[top] = 1;
			p = p->left;
		}
		else {
			if (LastStacksFlag[top] == 1) {
				p = LastStacks[top];
				//printf("%d  ", p->element);
				LastStacksFlag[top] = 2;
				p = p->right;
			}
			else {
				p = LastStacks[top--];
				printf("%d  ", p->element);
				p = NULL;
			}
		}
	}
}