#pragma once
#include<stdio.h>
#include<stdlib.h>

#define key(A) (A)
#define less(A,B) (key(A) < key(B))
typedef int SetItem;
typedef struct minheap* Heap;
typedef struct minheap {
	int last, maxsize;
	SetItem* heap;
}Minheap;

Heap MinHeapInit(int HeapSize) {
	Heap H = (Heap)malloc(sizeof * H);
	H->maxsize = HeapSize;
	H->heap = (SetItem*)malloc((H->maxsize + 1) * sizeof(SetItem));
	H->last = 0;
	return H;
}

void HeapInsert(SetItem x, Heap H) {
	if (H->last == H->maxsize) return;
	int i = ++H->last;
	while (i != 1 && less(x, H->heap[i / 2])) {
		H->heap[i] = H->heap[i / 2];
		i /= 2;
	}
	H->heap[i] = x;
}

SetItem DeleteMin(Heap H) {
	if (H->last == 0)return 0;
	SetItem  x = H->heap[1];

	SetItem y = H->heap[H->last--];
	int i = 1, ci = 2;
	while (ci <= H->last) {
		if (ci < H->last && less(H->heap[ci + 1], H->heap[ci])) ci++;
		if (!less(H->heap[ci], y)) break;
		H->heap[i] = H->heap[ci];
		i = ci;
		ci *= 2;
	}
	H->heap[i] = y;
	return x;
}

void test(SetItem a[]) {
	for (int i = 0; i < 10; i++) {
		printf("%d", a[i]);
	}
}

Heap BuildHeap(SetItem a[], int size, int arraysize) {
	Heap H = MinHeapInit(arraysize);
	H->heap = a;
	H->last = size;
	H->maxsize = arraysize;
	for (int i = H->last / 2; i >= 1; i--) {
		SetItem y = H->heap[i];
		int c = 2 * i;
		while (c <= H->last) {
			if (c < H->last && less(H->heap[c + 1], H->heap[c]))c++;
			if (!less(H->heap[c], y))break;
			H->heap[c / 2] = H->heap[c];
			c *= 2;
		}
		H->heap[c / 2] = y;
	}
	return H;
}

void HeapSort(SetItem a[], int n) {
	Heap H = BuildHeap(a, n, n);
	for (int i = n - 1; i >= 1; i--) {
		SetItem x = DeleteMin(H);
		a[i + 1] = x;
	}
}