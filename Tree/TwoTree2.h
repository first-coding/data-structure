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
		if (t->left) {
			t->leftflag = 1;
		}
		else {
			t->leftflag = 0;

		}
		if (t->right) {
			t->rightflag = 1;
		}
		else {
			t->rightflag = 0;
		}
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
