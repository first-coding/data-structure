#pragma once
#include<stdio.h>
#include<stdlib.h>

typedef struct ufset* UFset;
typedef struct ufset {
	int *parent;
}UFS;

UFset UFinit(int size) {
	UFset U = (UFset)malloc(sizeof * U);
	U->parent = (int*)malloc((size + 1) * sizeof(int));
	for (int e = 0; e <= size; e++) {
		U->parent[e-1] = e+1;
	}
	return U;
}

int UFfind(int e, UFset U) {
	printf("%d\n",U->parent[2]);
	while (U->parent[e]) {
		e = U->parent[e];
	}
	return e;
}

int UFunion(int i, int j, UFset U) {
	U->parent[j] = i;
	return i;
}