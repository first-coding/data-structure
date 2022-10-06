#pragma once
#include<stdio.h>
#include<stdlib.h>
#define MAXQSIZE 100
#define QEletype int 

typedef struct arrayqueue* queuepoint;
typedef struct arrayqueue {
	QEletype* base;
	int front;
	int rear;
}ArrayQueue;

queuepoint QueueInit() {
	queuepoint q = (queuepoint)malloc(sizeof(ArrayQueue));
	if (q) {
		q->base = (QEletype*)malloc(sizeof(QEletype) * MAXQSIZE);
		q->front = q->rear = 0;
	}
	return q;
}

int QueueEmpty(queuepoint q) {
	return (q->front == 0 && q->rear==0);
}

int QueueLength(queuepoint q) {
	return (q->rear - q->front);
}

QEletype FrontElem(queuepoint q) {
	return q->base[q->front];
}

void InsertQueue(queuepoint q,QEletype x) {
	q->base[q->rear] = x;
	q->rear++;
}

void DeleteQueue(queuepoint q) {
	q->base[q->front] = 0;
	q->front++;
}

void TravelQuque(queuepoint q) {
	int length = QueueLength(q);
	int j = q->front;
	for (int i = 0; i < length; i++) {
		printf("%3d", q->base[j]);
		j++;
	}
}