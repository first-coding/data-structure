#include"prefect.h"

int main() {
	Graph G;
	Create(&G);
	printf("\n");
	OutPut(&G);
	DFStraverse(G);
	BFS(G);
	return 0;
}