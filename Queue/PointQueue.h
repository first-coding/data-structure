#pragma once
#include<stdio.h>
#include<stdlib.h>

typedef struct qnode* qlink;
typedef int QItem;
typedef QItem* Qaddr;
typedef struct qnode {
	QItem element;
	qlink next;
}Qnode;

void QItemShow(QItem x) {
	printf("%d\n", x);
}

qlink NewNode() {
	return (qlink)malloc(sizeof(Qnode));
}
typedef struct lqueue* Queue;
typedef struct lqueue {
	qlink first;
	qlink last;
}Lqueue;

Queue QueueInit() {
	Queue Q = (Queue)malloc(sizeof * Q);
	Q->first = Q->last = 0;
	return Q;
}

int QueueEmpty(Queue Q){
	return Q->first == 0;
}

QItem QueueFirst(Queue Q) {
	if (QueueEmpty(Q))return 0;
	return Q->first->element;
}

QItem QueueLast(Queue Q) {
	if (QueueEmpty(Q)) return 0;
	return Q->last->element;
}

void EnterQueue(QItem x, Queue Q) {
	qlink news = NewNode();
	news->element = x;
	news->next = 0;
	if (Q->first == 0) {
		Q->first = news;
		Q->last = news;
	}
	else {
		Q->last->next = news;
		Q->last = news;
	}
}

void DeleteQueue(Queue Q) {
	if (QueueEmpty(Q)) return;
	qlink q = Q->first;
	Q->first = q->next;
	free(q);
}

void QueueItemShow(QItem x) {
	printf("%d\n", x);
}

void PrintItem(Queue Q) {
	qlink q = Q->first;
	while (q) {
		QueueItemShow(q->element);
		q = q->next;
	}
}