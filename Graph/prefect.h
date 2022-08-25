#pragma once
#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable:6031)
#pragma warning(disable:4996)
#pragma warning(disable:4172)

typedef char VertexType;
typedef int EdgeType;

#define MAX 10
#define INFINTTY 65535
#define TRUE 1
#define FALSE 0
typedef int Boole;
Boole visited[MAX];  

typedef struct graph {
	VertexType vexs[MAX];
	EdgeType arcs[MAX][MAX];
	int TopNums, SideNums;
}Graph;

int* NodeIndex(Graph *G, VertexType NodeChar,VertexType NodeChar_2) {
	int L[2] = {0};
	for (int i = 0; i < G->TopNums; i++) {
		if (G->vexs[i] == NodeChar) {
			L[0] = i;
		}
		if (G->vexs[i] == NodeChar_2) {
			L[1] = i;
		}
	}
	return L;
}

void Create(Graph* G) {
	printf("please input TopNums and SideNums: ");
	scanf("%d%d", &G->TopNums, &G->SideNums);
	for (int i = 0; i < G->TopNums; i++) {
		printf("please input Numbers %d TopNode: ",i+1); 
		scanf(" %c", &G->vexs[i]);
	}
	for (int j = 0; j < G->SideNums; j++) {
		for (int k = 0; k < G->SideNums; k++) {
			G->arcs[j][k] = INFINTTY;
		}
	}
	VertexType NodeChar,NodeChar_2;
	int* L,weight;
	for (int N = 0; N < G->SideNums; N++) {
		printf("please input numbers %d Two Node: ",N+1);
		scanf(" %c %c", &NodeChar, &NodeChar_2);
		L = NodeIndex(G, NodeChar, NodeChar_2);
		int x = L[0], y = L[1];
		printf("please input weight: ");
		scanf("%d", &weight);
		G->arcs[x][y] = weight;
		G->arcs[y][x] = weight;
	}
}

void OutPut(Graph* G) {
	int i, j,count=0;
	printf("Adjacency matrix show that\n");
	for (i = 0; i < G->TopNums; i++) {
		printf("\t%c", G->vexs[i]);
	}
	printf("\n");
	for (i = 0; i < G->TopNums; i++) {
		printf("%4c", G->vexs[i]);
		for (j = 0; j < G->TopNums; j++) {
			printf("\t%d", G->arcs[i][j]);
			count++;
			if (count % G->TopNums == 0) {
				printf("\n");
			}
		}
	}
}

void DFS(Graph G, int i) {
	int j;
	visited[i] = TRUE;
	printf("%c->", G.vexs[i]);
	for (j = 0; j < G.TopNums; j++) {
		if (G.arcs[i][j] == 1 && !visited[j]) {
			DFS(G, j);
		}
	}
}

void DFStraverse(Graph G) {
	printf("DFS: ");
	int i;
	for (i = 0; i < G.TopNums; i++) {
		visited[i] = FALSE;
	}
	for (i = 0; i < G.TopNums; i++) {
		if (!visited[i]) {
			DFS(G, i);
		}
	}
}

