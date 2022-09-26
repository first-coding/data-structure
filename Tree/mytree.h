#include<stdio.h>
#include<stdlib.h>

typedef int TreeData;
typedef struct tree* Treelink;
typedef struct tree {
	TreeData data;
	Treelink left;
	Treelink right;
}Tree;

typedef struct node* Nodelink;
typedef struct node {
	Treelink root;
}Node;

Treelink CreateNode() {
	return (Treelink)malloc(sizeof(Tree));
}

Nodelink InitTree() {
	Nodelink T = (Nodelink)malloc(sizeof * T);
	if (T!=NULL) {
		T->root = 0;
	}
	else {
		printf("create memory error.");
	}
	return T;
}

Nodelink MakeTree(Nodelink T, TreeData data,int flag) {
	if (T->root == 0) {
		Treelink root = CreateNode();
		if (root != NULL) {
			root->data = data;
			root->left = root->right = NULL;
		}
	}
	else {
		if (flag == 0) {
			Treelink left = CreateNode();
			if (left != NULL) {
				left->data = data;
				left->left = left->right = NULL;
			}
		}
		else {
			Treelink right = CreateNode();
			if (right != NULL) {
				right->data = data;
				right->left = right->right = NULL;
			}
		}
	}
	return T;
}