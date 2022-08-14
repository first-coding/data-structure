#pragma once
#include<stdio.h>
#include<stdlib.h>

typedef struct lnode* glink;
struct lnode {
	int v;
	glink next;
};

glink NewLNode(int v, glink next) {
	glink x = (glink)malloc(sizeof * x);
	if (x) {
		x->v = v;
		x->next = next;
	}
	return x;
}

typedef struct graph* Graph;
typedef struct graph {
	int n;
	int e;
	glink* adj;
}Ldgraph;

Graph Graphinit(int v) {
	Graph G = (Graph)malloc(sizeof * G);
	if (G) {
		G->n = v;
		G->e = 0;
		if (v) {
			G->adj = (glink*)malloc((v+1) * sizeof(glink));
		}
		if (G->adj) {
			for (int i = 0; i <= v; i++) {
					G->adj[i] = 0;
			}
		}
	}
	return G;
}

int GraphEdges(Graph G) {
	return G->e;
}

int GraphVertices(Graph G) {
	return G->n;
}

int GraphExist(int i, int j, Graph G) {
	if (i<1 || j<1 || i>G->n || j>G->n)return 0;
	glink p = G->adj[i];
	while (p && p->v != j) {
		p = p->next;
	}
	if (p)return 1;
	else return 0;
}

void GraphAdd(int i, int j, Graph G) {
	if (i < 1 || j<1 || i>G->n || j>G->n || i == j || GraphExist(i, j, G))return;
	G->adj[i] = NewLNode(j, G->adj[i]);
	G->e++;
}

void GraphDelete(int i, int j, Graph G) {//删除边
	glink p, q;
	if (i<1 || j<1 || i>G->n || j>G->n || !GraphExist(i, j, G)) return;
	p = G->adj[i];
	if (p->v == j) {
		G->adj[i] = p->next;
		free(p);
	}
	else {
		while (p && p->next->v != j) {
			p = p->next;
		}
		if (p) {
			q = p->next;
			p->next = q->next;
			free(q);
		}
	}
	G->e--;
}

int OutDegree(int i, Graph G) {//出度
	int j = 0;
	if (i<1 || i>G->n) return 1;
	glink p = G->adj[i];
	while (p) {
		j++;
		p = p->next;
	}
	return j;
}

int InDegree(int i, Graph G) {//入度
	int sum = 0;
	if (i<1 || i>G->n) return 1;
	for (int j = 1; j <= G->n; j++) {
		if (GraphExist(j, i, G)) sum++;
	}
	return sum;
}

void GraphOut(Graph G) {
	for (int i = 1; i <= G->n; i++) {
		glink p = G->adj[i];
		while (p) {
			printf("%d  ", p->v);
			p = p->next;
		}
		printf("\n");
	}
}


