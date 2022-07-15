#pragma once
#include<stdio.h>
#include<stdlib.h>
typedef struct aqueue* Queue;
//typedef int QItem;
typedef struct aqueue {
	int maxsize;
	int front;
	int rear;
	QItem* queue;
}Aqueue;


void QItemShow(QItem x) {
	printf("%d\n", x);
}


Queue QueueInit(int size) {//Init Queue Q.
	Queue Q = (Queue)malloc(sizeof * Q);
	Q->queue = (QItem*)malloc(size * sizeof(QItem));
	Q->maxsize = size;
	Q->front = Q->rear = 0;
	return Q;
}

int QueueEmpty(Queue Q) {//judge Queue is Empty.
	return Q->front == Q->rear;
}

int QueueFull(Queue Q) {//judge Queue is Full.
	return (((Q->rear + 1) % Q->maxsize == Q->front) ? 1 : 0);
}

QItem QueueFirst(Queue Q) {//return Queue first element.
	if (QueueEmpty(Q)) return 0;
	return Q->queue[(Q->front + 1) % Q->maxsize];
}

QItem QueueLast(Queue Q) {//return Queue last element.
	if (QueueEmpty(Q)) return 0;
	return Q->queue[Q->rear];
}

void EnterQueue(Queue Q,QItem x) {//insert x to Queue Q.
	if(QueueFull(Q)) return;
	Q->rear = (Q->rear + 1) % Q->maxsize;
	Q->queue[Q->rear] = x;
}

void DeleteQueue(Queue Q) {//delete element in Queue Q.
	if (QueueEmpty(Q)) return ;
	Q->front = (Q->front + 1) % Q->maxsize;
}


