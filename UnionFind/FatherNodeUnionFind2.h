#pragma once
#include<stdio.h>
#include<stdlib.h>

typedef struct ufset* UFset;
typedef struct ufset {
	int* parent;
	int* root;
}UFS;

UFset UFinit(int size) {
	UFset U = (UFset)malloc(sizeof * U);
	U->parent = (int*)malloc((size + 1) * sizeof(int));
	U->root = (int*)malloc((size + 1) * sizeof(int));
	for (int e = 1; e <= size; e++) {
		U->parent[e] = 1;
		U->root[e] = 1;
	}
	return U;
}

int UFfind(int e, UFset U) {
	while (!U->root[e])e = U->parent[e];
	return e;
}

int UFunion(int i, int j, UFset U) {
	if (i == j)return i;
	if (U->parent[i] < U->parent[j]) {
		U->parent[j] += U->parent[i];
		U->root[i] = 0;
		U->parent[i] = j;
		return j;
	}
	else {
		U->parent[i] += U->parent[j];
		U->root[j] = 0;
		U->parent[j] = i;
		return i;
	}
}

int UFfind2(int e, UFset U) {
	int i, j = e;
	while (!U->root[j]) {
		j = U->parent[j];
	}
	while (j != e) {
		i = U->parent[e];
		U->parent[e] = j;
		e = i;
	}
	return j;
}

void UFfree(UFset U) {
	free(U->parent);
	free(U->root);
	free(U);
}