#pragma once
#include<stdio.h>
#include<stdlib.h>

typedef struct ufset* UFset;
typedef struct ufset {
	int* components;
	int n;
}UFS;

UFset UFinit(int size) {
	UFset U = (UFset)malloc(sizeof * U);
	if (U) {
		U->components = (int*)malloc((size + 1) * sizeof(int));
		for (int e = 0; e <= size; e++) {
			U->components[e-1] = e;
		}
		U->n = size;
	}
	return U;
}

int UFfind(int e, UFset U) {
	return U->components[e];
}

int UFunion(int i, int j, UFset U) {
	for(int k=1;k<=U->n;k++)
		if (U->components[k] == j) {
			U->components[k] = i;
		}
	return i;
}
