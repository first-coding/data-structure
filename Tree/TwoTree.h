#pragma once
#include<stdio.h>
#include<stdlib.h>

typedef int TreeItem;
typedef TreeItem* Treeaddr;

void TreeItemShow(TreeItem x) {
	printf("%d ",x);
}

typedef struct btnode* btlink;
struct btnode {
	TreeItem element;
	btlink left;
	btlink right;
}Btnode;
typedef struct binarytree* BinartTree;
typedef struct binarytree {
	btlink root;
}BTree;

btlink TreeNewNode() {
	return (btlink)malloc(sizeof(Btnode));
}

BinartTree BinaryInit() {
	BinartTree T = (BinartTree)malloc(sizeof * T);
	T->root = 0;
	return T;
}

int BinartEmpty(BinartTree T) {
	return T->root == 0;
}

TreeItem Root(BinartTree T) {
	if (BinartEmpty(T))return 0;
	return T->root->element;
}

void MakeTree(TreeItem x, BinartTree T, BinartTree L, BinartTree R) {
	T->root = TreeNewNode();
	T->root->element = x;
	T->root->left = L->root;
	T->root->right = R->root;
	L->root = R->root = 0;
}

TreeItem BreakTree(BinartTree T, BinartTree L, BinartTree R) {
	if (!T->root) return 0;
	TreeItem x = T->root->element;
	L->root = T->root->left;
	R->root = T->root->right;
	T->root = 0;
	return x;
}

void PreOrder(void(*visit)(btlink u), btlink t) {
	if (t) {
		(*visit)(t);
		PreOrder(visit, t->left);
		PreOrder(visit, t->right);
	}
}

void InOrder(void(*visit)(btlink u), btlink t) {
	if (t) {
		InOrder(visit, t->left);
		(*visit)(t);
		InOrder(visit, t->right);
	}
}

void PostOrder(void(*visit)(btlink u), btlink t) {
	if (t) {
		PostOrder(visit, t->left);
		PostOrder(visit, t->right);
		(*visit)(t);
	}
}


void outnode(btlink t) {
	TreeItemShow(t->element);
}

void PreOut(BinartTree T) {
	PreOrder(outnode, T->root);
}

void InOut(BinartTree T) {
	InOrder(outnode, T->root);
}

void PostOut(BinartTree T) {
	PostOrder(outnode, T->root);
}

int Height(btlink t) {
	int hl, hr;
	if (!t)return -1;
	hl = Height(t->left);
	hr = Height(t->right);
	if (hl > hr)return ++hl;
	else return ++hr;
}

