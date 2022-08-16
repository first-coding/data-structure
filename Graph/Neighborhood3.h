#pragma once
#include"Neighborhood.h"

void Graphadd(int i, int j, Graph G) {
	if (i<1 || j<1 || i>G->n || j>G->n || i == j || GraphExist(i, j, G)) return;
	G->adj[i] = NewLNode(j, G->adj[i]);
	G->adj[j] = NewLNode(i, G->adj[j]);
	G->e++;
}

void Graphdelete(int i, int j, Graph G) {
	glink p, q;
	if (i<1 || j<1 || i>G->n || j>G->n || !GraphExist(i, j, G)) return;
	p = G->adj[i];
	if (p->v == j) {
		G->adj[i] = p->next;
		free(p);
	}
	else {
		while (p && p->next->v != j)p = p->next;
		if (p) {
			q = p->next;
			p->next = q->next;
			free(q);
		}
	}
	p = G->adj[j];
	if (p->v == i) {
		G->adj[j] = p->next;
		free(p);
	}
	else {
		while (p && p->next->v != i)p = p->next;
		if (p) {
			q = p->next;
			p->next = q->next;
			free(q);
		}
	}
	G->e--;
}