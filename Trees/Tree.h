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

void CreateTree(Hpoint t,TreeElem data,int flag) {
	Tpoint News = NewNode();
	News->data = data;
	News->left = News->right = NULL;
	if (t->root == NULL) {
		t->root = News;
	}
	else {
		if (flag == 0) {
			 
		}
		else {

		}
	}
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

