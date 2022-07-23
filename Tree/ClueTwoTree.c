#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef char dataType;
typedef struct node
{
	dataType data; 
	struct node* lchild; 
	struct node* rchild; 
	int ltag; 
	int rtag; 
}BiTree;

BiTree* creat()  
{
	dataType value;
	BiTree* t;

	scanf("%c", &value);

	if (value == '#')
	{
		t = NULL;
	}
	else
	{
		t = (BiTree*)malloc(sizeof(BiTree));
		t->data = value;
		t->ltag = 0;
		t->rtag = 0;
		t->lchild = creat();
		t->rchild = creat();
	}
	return t;
}

void InThreaded(BiTree* p)
{
	static BiTree* pre = NULL;
	if (p)
	{
		InThreaded(p->lchild);

		if (!p->lchild)
		{
			p->ltag = 1;
			p->lchild = pre;
		}

		if (pre && !pre->rchild)
		{
			pre->rtag = 1;
			pre->rchild = p;
		}
		pre = p;

		InThreaded(p->rchild);
	}
}

BiTree* Next(BiTree* t) 
{
	if (t->rtag == 1) 
	{
		t = t->rchild;
	}
	else 
	{
		t = t->rchild;
		while (t->ltag == 0)
		{
			t = t->lchild;
		} 
	}
	return t;
}

BiTree* Prior(BiTree* t)
{
	if (t->ltag == 1)
	{
		t = t->lchild;
	}
	else
	{
		t = t->lchild;
		while (t->rtag == 0)
		{
			t = t->rchild;
		}
	} 

	return t;
}

void InorderTraverse(BiTree* t)
{
	if (!t)
	{
		return;
	}

	while (t->ltag == 0)
	{               
		t = t->lchild;
	}
	printf("%c ", t->data);
	while (t->rchild)
	{             
		t = Next(t);
		printf("%c ", t->data);
	}
}

//int main()
//{
//	BiTree* root;
//
//	printf("Input:");
//	root = creat();
//	printf("\n");
//
//	printf("Threading Binary Tree!\n");
//	InThreaded(root);
//	printf("\n");
//
//	printf("Inorder traverse:");
//	InorderTraverse(root);
//	printf("\n");
//	return 0;
//}
