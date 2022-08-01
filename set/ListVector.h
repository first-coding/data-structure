#pragma once
#include<stdio.h>
#include<stdlib.h>

typedef int SetItem;
typedef struct node* link;
typedef struct node {
	SetItem element;
	link next;
}Node;
typedef  struct list {
	link  first;
}LSet,*Set;

link NewNode() {
	return (link)malloc(sizeof(Node));
}
Set SetInit() {
	Set S = (Set)malloc(sizeof * S);
	S->first = 0;
	return S;
}

int SetEmpty(Set S)
{
	return  S->first == 0;
}

int SetSize(Set S) {
	link current = S->first;
	int len = 0;
	while (current) {
		len++;
		current = current->next;
	}
	return len;
}

void SetAssign(Set A, Set B) {
	link a, b, c;
	b = B->first;
	A->first = 0;
	if (b) {
		A->first = NewNode();
		a = A->first;
		a->element = b->element;
		a->next = 0;
		b = b->next;
	}
	while (b) {
		c = NewNode();
		c->element = b->element;
		c->next = 0;
		b = b->next;
		a->next = c;
		a = c;
	}
}

Set SetInter(Set A,Set B) {
	Set tmp = SetInit();
	link a = A->first;
	link b = B->first;
	link p = NewNode();
	link q = p;
	while (a && b) {
		if (a->element == b->element) {
			link  r = NewNode();
			r->element = a->element;
			r->next = 0;
			p->next = r;
			p = r;
			a = a->next;
			b = b->next;
		}
		else if (a->element < b->element)a = a->next;
		else b = b->next;
	}
	if (p != q)tmp->first = q->next;
	free(q);
	return tmp;
}

void SetInsert(SetItem x, Set S) {
	link p = S->first;
	link q = p;
	while (p && p->element < x) {
		q = p;
		p = p->next;
	}
	if (p && p->element == x)return;
	link r = NewNode();
	r->element = x;
	r->next = p;
	if (p == q)S->first = r;
	else q->next = r;
}

