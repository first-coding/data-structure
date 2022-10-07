#pragma once
#include<stdio.h>
#include<stdlib.h>
#define QEleType int

typedef struct qnode* QPoint;
typedef struct head* HPoint;
typedef struct qnode {
	QEleType data;
	QPoint next;
}QNode;
typedef struct head {
	QPoint front;
	QPoint rear;
}Head;

QPoint NewNode() {
	return (QPoint)malloc(sizeof(QNode));
}

HPoint QueueInit() {
	HPoint Q = (HPoint)malloc(sizeof(Head));
	if (Q) {
		Q->front = Q->rear = NULL;
	}
	return Q;
}

void DestoryQueue(HPoint Q) {
	if (Q->front != NULL) {
		QPoint bing = Q->front;
		Q->front = bing->next;
		free(bing);
		DestoryQueue(Q);
	}
}

int LengthQueue(HPoint Q) {
	int counts = 0;
	QPoint q = Q->front;
	while (q!=NULL) {
		q = q->next;
		counts++;
	}
	return counts;
}

int EmptyQueue(HPoint Q) {
	int Length = LengthQueue(Q);
	if (Length== 0) {
		return 0;
	}
	else {
		return 1;
	}
}

QEleType FrontElem(HPoint Q) {
	return Q->front->data;
}

void QueueInsert(HPoint Q,QEleType x) {
	QPoint New = NewNode();
	New->data = x;
	New->next = NULL;
	if (Q->rear != NULL) {
		Q->rear->next = New;
		Q->rear = New;
	}
	else {
		Q->front = New;
		Q->rear = New;
	}
}

void QueueDelete(HPoint Q) {
	QPoint p = Q->front;
	Q->front = p->next;
	free(p);
}

void TravelQueue(HPoint Q) {
	QPoint q = Q->front;
	do {
		printf("%3d", q->data);
		q = q->next;
	} while (q != NULL);
}