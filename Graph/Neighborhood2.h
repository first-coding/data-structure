#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

typedef struct graph* Graph;
typedef struct graph
{
	int NoEdge;		
	int n;	
	int e;	
	int** a; 
}AWDgraph;

Graph GraphInit(int n, int noEdge)
{
	Graph G = (Graph)malloc(sizeof(AWDgraph));
	if (G) {
		G->n = n;
		G->e = 0;
		G->NoEdge = noEdge;
		G->a = (int**)malloc(sizeof(int*) * (n + 1)); 
	}
	for (int i = 0; i <= n; i++)   
		G->a[i] = (int*)malloc(sizeof(int) * (n + 1));
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			G->a[i][j] = G->NoEdge;
	return G;
}

int GraphEdges(Graph G)  
{
	return G->e;
}

int GraphVertices(Graph G)  
{
	return G->n;
}

int GraphExits(int i, int j, Graph G)  
{
	if (i < 1 || j<1 || j>G->n || G->a[i][j] == G->NoEdge)
		return 0;   
	return 1;
}

void GraphAdd(int i, int j, int w, Graph G)
{
	if (i<1 || j<1 || i>G->n || j>G->n || i == j || G->a[i][j] != G->NoEdge) {
		printf("Bad Input");
		exit(0);
	}
	G->a[i][j] = w;
	G->e++;
}

void GraphDelete(int i, int j, Graph G)
{
	if (i<1 || j<1 || i>G->n || i>G->n || G->a[i][j] == G->NoEdge) {
		printf("Bad Input");
		exit(0);
	}
	G->a[i][j] = G->NoEdge;
	G->e--;
}
int OutDegree(int i, Graph G)  
{
	int j, sum = 0;
	if (i<1 || i>G->n) {
		printf("Bad Input");
		exit(0);
	}
	for (j = 1; j <= G->n; j++)
		if (G->a[i][j] != G->NoEdge)
			sum++;
	return sum;
}

int InDegree(int i, Graph G) 
{
	int j, sum = 0;
	if (i<1 || i>G->n) {
		printf("Bad Input");
		exit(0);
	}
	for (j = 1; j <= G->n; j++)
		if (G->a[j][i] != G->NoEdge)
			sum++;
	return sum;
}

void GraphPrint(Graph G) 
{
	int i, j;
	for (i = 1; i <= G->n; i++)
	{
		for (j = 1; j <= G->n; j++)
			printf("%d ", G->a[i][j]);
		printf("\n");
	}
}

void Delete(Graph G)   
{
	int m = G->n;      
	for (int i = 0; i < m; i++)
		free(G->a[i]);
	free(G->a);
}