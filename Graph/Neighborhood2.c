#include "Neighborhood2.h"

int main()
{
	int noEdge = 0;
	Graph G;
	G = GraphInit(10, 0);
	GraphAdd(1, 3, 10, G);
	GraphAdd(2, 4, 6, G);
	GraphAdd(3, 4, 5, G);
	GraphAdd(1, 5, 12, G);
	GraphAdd(5, 2, 321, G);
	GraphPrint(G);
	return 0;
}