#pragma once
#include<stdio.h>
#include<stdlib.h>

typedef int TreeElem;
typedef struct node* Tpoint;
typedef struct head* Hpoint;
typedef struct head {
	Tpoint root;
}Head;

typedef struct node {
	Tpoint left;
	TreeElem data;
	Tpoint right;
}Node;


Tpoint NewNode() {
	return (Tpoint)malloc(sizeof(Node));
}

void RootNode(Hpoint t, int data) {
	Tpoint Root = NewNode();
	Root->data = data;
	Root->left = Root->right = NULL;
	t->root = Root;
}

Hpoint InitTree() {
	Hpoint t = (Hpoint)malloc(sizeof(Head));
	if (t) {
		t->root = NULL; 
	}
	RootNode(t, 0);
	return t;
}


void DestroyTree(Hpoint t) {
	
}

void CreateTree(Tpoint t,TreeElem leftdata,TreeElem rightdata) {
	Tpoint left = NewNode();
	left->data = leftdata;
	Tpoint right = NewNode();
	right->data = rightdata;
	left->left = left->right = right->left = right->right = NULL;
	t->left = left;
	t->right = right;
}


Tpoint Newroot(int tag,Tpoint p) {
	if (tag == 0) {
		return p->left;
	}
	else {
		return p->right;
	}
}
 
int EmptyTree(Hpoint t) {
	return 0;
}	

int TreeDepth(Hpoint t) { 
	return 0;
}

