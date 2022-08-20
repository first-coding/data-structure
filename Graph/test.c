//#include<stdio.h>
//#include<stdlib.h>
//#pragma warning(disable:4996)
//
//#include<stdio.h>
//#include<stdlib.h>
//
//#define MaxInt 32767
//#define MVNum 100
//typedef int Status;
//typedef char VerTexType;    
//typedef int ArcType;       
//int visited[MVNum];
//
//typedef struct
//{
//	VerTexType vexs[MVNum];   
//	ArcType arcs[MVNum][MVNum];   
//	int vexnum, arcnum;          
//}AMGraph;
//int LocateVex(AMGraph G, char v)   
//{
//	for (int i = 0; i < G.vexnum; i++)
//		if (G.vexs[i] == v)
//			return i;
//	return 0;
//}
//
//
//Status CreateUDN(AMGraph* G)
//{
//	int i, j, ii, jj, k, w;
//	char v1, v2;
//	printf("请输入顶点数和边数：");
//	scanf("%d %d", &((*G).vexnum), &((*G).arcnum)); 
//	printf("请输入%d个顶点值: ", (*G).vexnum);
//	for (i = 0; i < (*G).vexnum; i++)        
//		scanf(" %c", &((*G).vexs[i]));
//	for (i = 0; i < (*G).vexnum; i++)           
//		for (j = 0; j < (*G).vexnum; j++)
//			(*G).arcs[i][j] = MaxInt;
//	//两点之间的边赋权 
//	for (k = 0; k < (*G).arcnum; k++)
//	{
//		printf("请输入两点及其之间权值：");
//		scanf(" %c%c%d", &v1, &v2, &w);  
//		ii = LocateVex(*G, v1);             
//		jj = LocateVex(*G, v2);            
//		(*G).arcs[ii][jj] = w;              
//		(*G).arcs[jj][ii] = (*G).arcs[ii][jj];   
//	}
//	for (int l = 0; l < (*G).arcnum; l++) {
//		for (int z = 0; z < (*G).arcnum; z++) {
//			printf("%d ", (*G).arcs[l][z]);
//		}
//		printf("\n");
//	}
//	return 'ok';
//}
//
//int main() {
//	AMGraph G;
//	CreateUDN(&G);
//	return 0;
//}