#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
#pragma warning(disable:6031)
#define MVNum 100                              
typedef struct ArcNode {
	int adjvex;
	struct ArcNode* nextarc;
}ArcNode;

typedef struct VNode {
	char data;
	ArcNode* firstarc;
}VNode, AdjList[MVNum];

typedef struct {
	AdjList vertices;
	int vexnum, arcnum;
}ALGraph;

void CreatMGraph(ALGraph* G);
void printGraph(ALGraph G);

void CreatMGraph(ALGraph* G)
{
	int i, j, k;
	ArcNode* s;
	scanf("%d%d", &G->vexnum, &G->arcnum);
	for (i = 0; i < G->vexnum; i++) {
		scanf(" %c", &G->vertices[i].data);
	}
	for (i = 0; i < G->vexnum; i++) {
		G->vertices[i].firstarc = NULL;
	}
	for (k = 0; k < G->arcnum; k++) {
		scanf("%d%d", &i, &j);
		s = (ArcNode*)malloc(sizeof(ArcNode));
		s->adjvex = j;
		s->nextarc = G->vertices[i].firstarc;
		G->vertices[i].firstarc = s;
		s = (ArcNode*)malloc(sizeof(ArcNode));
		s->adjvex = i;
		s->nextarc = G->vertices[j].firstarc;
		G->vertices[j].firstarc = s;
	}
}
void printGraph(ALGraph G)
{
	int i, j;
	ArcNode* p;
	for (i = 0; i < G.vexnum; i++) {
		printf("%c:", G.vertices[i].data);
		for (p = G.vertices[i].firstarc; p; p = p->nextarc) {
			printf(" %d", p->adjvex);
		}
		printf("\n");
	}
}


int main()
{
	ALGraph G;
	CreatMGraph(&G);
	printGraph(G);
	return 0;
}