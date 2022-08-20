#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
#define MVNum 100     
typedef struct ArcNode* arcnode;
typedef struct ArcNode {                		
    int adjvex;                                   
    arcnode nextarc;       
}ArcNode;

typedef struct VNode {
    char data;                    	     
    arcnode firstarc;        
}VNode, AdjList[MVNum];             

typedef struct {
    AdjList vertices;             
    int vexnum, arcnum;    
}ALGraph;

void PointGraph(ALGraph *G) {
	//ArcNode* s;
	printf("please input TopNode and SideNode");
	scanf("%d%d", &G->vexnum, &G->arcnum);
	for (int i = 0; i < G->vexnum; i++) {   		
		scanf("%c", &G->vertices[i].data);  
	}
	for (int i = 0; i < G->vexnum; i++) {
		G->vertices[i].firstarc = NULL;   	
	}
}

int main() {
	ALGraph G;
	PointGraph(&G);
	return 0;
}