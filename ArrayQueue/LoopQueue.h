#pragma once
#include<stdio.h>
#include<stdlib.h>
#define QueueElem int
#define MAXSIZE 100

typedef struct loopqueue* LoopPoint;
typedef struct loopqueue {
	QueueElem* base;
	int front;
	int rear;
}LoopQueue;

LoopPoint LoopInit() {
	LoopPoint Q = (LoopPoint)malloc(sizeof(LoopQueue));
	if (Q) {
		Q->rear = Q->front = 0;
		Q->base = (QueueElem*)malloc(sizeof(QueueElem) * MAXSIZE);
	}
	return Q;
}

void DestoryLoop(LoopPoint Q) {
	free(Q->base);
	free(Q);
}



int LoopEmpty(LoopPoint Q) {
	return Q->front == Q->rear;
}

int LoopLength(LoopPoint Q) {
	return Q->rear - Q->front + MAXSIZE;
}

QueueElem FrontLoop(LoopPoint Q) {
	return Q->base[Q->front];
}

void LoopInsert(LoopPoint Q,QueueElem x) {
	Q->base[Q->rear] = x;
	Q->rear = (Q->rear + 1) % MAXSIZE;
}

void LoopDelete(LoopPoint Q) {
	Q->base[Q->front] = 0;
	Q->front++;
}

void TravelQuque(LoopPoint Q) {
	int length = LoopLength(Q);
	int j = Q->front;
	for (int i = 0; i < length; i++) {
		printf("%3d", Q->base[j]);
		j++;
	}
}