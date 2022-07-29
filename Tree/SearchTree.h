#pragma once
#include<stdio.h>
#include<stdlib.h>
#define key(A) (A)
#define less(A,B) (key(A)<key(B))
#define eq(A,B) (!less(A,B) && !less(B,A))
#define swap(A,B) {TreeItem t = A;A=B;B=t;}
#define compswap(A,B) if(less(B,A))swap(A,B)

typedef int TreeItem;
typedef struct btnode* btlink;
typedef TreeItem* Treeaddr;
typedef struct btnode {
	TreeItem element;
	btlink left;
	btlink right;
	btlink parent;
}Btnode;

typedef struct bstree* BinartTree;
typedef struct bstree {
	btlink root;
}Bstree;

btlink NewBNode() {
	return (btlink)malloc(sizeof(Btnode));
}

btlink NewBSnode(TreeItem x) {
	btlink r;
	r = NewBNode();
	r->element = x;
	r->left = 0;
	r->right = 0;
	r->parent = 0;
	return r;
}

void TreeItemShow(TreeItem x) {
	printf("%d \n", x);
}

btlink BSSearch(TreeItem x, BinartTree T) {
	btlink p = T->root;
	while (p)
		if (less(x, p->element))p = p->left;
		else if (less(p->element, x))p = p->right;
		else break;
	return p;
}

int BSMember(TreeItem x, BinartTree T) {
	return BSSearch(x, T) ? 1 : 0;
}

btlink BSInsert(TreeItem x, BinartTree T) {
	btlink p, r, pp = 0;
	p = T->root;
	while (p) {
		pp = p;
		if (less(x, p->element))p = p->left;
		else if (less(p->element, x)) p = p->right;
		else return 0;
	}
	r = NewBSnode(x);
	if (T->root) {
		if (less(x, pp->element))pp->left = r;
		else pp->right = r;
		r->parent = pp;
	}
	else T->root = r;
	return r;
}

btlink BSInsertVisit(TreeItem x, void(*visit)(TreeItem u), BinartTree T) {
	btlink p, r, pp = 0;
	p = T->root;
	while (p) {
		pp = p;
		if (less(x, p->element))p = p->left;
		else if (less(p->element, x))p = p->right;
		else { visit(p->element); return p; }
	}

	r = NewBSnode(x);
	if (T->root) {
		if (less(x, pp->element))pp->left = r;
		else pp->right = r;
		r->parent = pp;
	}
	else T->root = r;
	return r;
}

btlink BSDelete(TreeItem x, BinartTree T) {
	btlink c, p, s, ps, pp = 0;
	p = T->root;
	while (p && !eq(p->element, x)) {
		pp = p;
		if (less(x, p->element))p = p->left;
		else p = p->right;
	}
	if (!p)return 0;
	if (p->left && p->right) {
		s = p->left;
		ps = p;
		while (s->right) {
			ps = s;
			s = s->right;
		}

		p->element = s->element;
		p = s;
		pp = ps;
	}
	if (p->left)c = p->left;
	else c = p->right;
	if (p == T->root) {
		T->root = c;
		if (c)c->parent = 0;
	}
	else {
		if (p == pp->left) {
			pp->left = c;
			p->left = p;
		}
		else pp->right = c;
		if (c)c->parent = p->parent;
	}
	free(p);
	return c;
}