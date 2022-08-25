//#include <stdio.h>
//#include<stdlib.h>
//#pragma warning(disable:4996)
//#define OK 1
//#define ERROR 0
//#define MaxInt 32767
//#define MVNum 100
//typedef int Status;
//typedef char VerTexType;     //顶点类型
//typedef int ArcType;         //边的权值类型
//int visited[MVNum];
//
////图的邻接矩阵存储表示 
//typedef struct
//{
//	VerTexType vexs[MVNum];   //顶点表 
//	ArcType arcs[MVNum][MVNum];   //邻接矩阵 
//	int vexnum, arcnum;           //图当前的顶点数和边数 
//}AMGraph;
//
////定位顶点的位置
//int LocateVex(AMGraph G, char v)   //v表示顶点
//{
//	for (int i = 0; i < G.vexnum; i++)
//		if (G.vexs[i] == v)
//			return i;
//}
//
////邻接矩阵表示法创建无向网
//Status CreateUDN(AMGraph* G)
//{
//	int i, j, ii, jj, k, w;
//	char v1, v2;
//	//初始化
//	printf("请输入顶点数和边数：");
//	scanf("%d %d", &((*G).vexnum), &((*G).arcnum));   //输入定点数和边数
//	printf("请输入%d个顶点值: ", (*G).vexnum);
//	for (i = 0; i < (*G).vexnum; i++)             //为顶点表赋值 
//		scanf(" %c", &((*G).vexs[i]));
//	for (i = 0; i < (*G).vexnum; i++)            //初始化边的权值为极大值MaxInt=32767 
//		for (j = 0; j < (*G).vexnum; j++)
//			(*G).arcs[i][j] = MaxInt;
//	//两点之间的边赋权 
//	for (k = 0; k < (*G).arcnum; k++)
//	{
//		printf("请输入两点及其之间权值：");
//		scanf(" %c%c%d", &v1, &v2, &w);   //输入两个顶点及其之间权值 
//		ii = LocateVex(*G, v1);             //定位v1顶点的权值
//		jj = LocateVex(*G, v2);            //定位v2顶点的权值 
//		(*G).arcs[ii][jj] = w;              //该顶点到另一个顶点的权值 
//		(*G).arcs[jj][ii] = (*G).arcs[ii][jj];   //无向图里另一个顶点到该顶点的权值 
//	}
//	return OK;
//}
//
////获得第v个顶点的第一邻接点
//int FirstAdjVex(AMGraph G, int v)
//{
//	for (int i = 0; i < G.vexnum; i++)
//		if (G.arcs[v][i]) return i;
//	return -1;
//}
//
////获得第v个顶点相对于第w个邻接点的下一个邻接点
//int NextAdjVex(AMGraph G, int v, int w)
//{
//	for (int i = w + 1; i < G.vexnum; i++)
//		if (G.arcs[v][i]) return i;
//	return -1;
//}
//
////连通图深度优先遍历
//void DFS(AMGraph G, int v)
//{
//	printf("%c", G.vexs[v]);    //输出该顶点 
//	visited[v] = 1;      //在辅助数组里标志该顶点已被访问过 
//	for (int w = FirstAdjVex(G, v); w >= 0; w = NextAdjVex(G, v, w))      //继续查找邻接点 
//		if (!visited[w]) DFS(G, w);  //递归调用 
//}
//
////邻接矩阵表示图的深度优先遍历
//void DFS_AM(AMGraph G, int v)
//{
//	//初始化辅助数组
//	for (int i = 0; i < G.vexnum; i++)
//		visited[i] = 0;
//	//开始遍历
//	printf("%c", G.vexs[v]);   //输出入口顶点 
//	visited[v] = 1;       //将入口顶点的位置在辅助数组里标志为1，下一次遍历将不会被访问 
//	for (int w = 0; w < G.vexnum; w++)        //在邻接矩阵图的第v行里搜寻vexs[v]的邻接点——矩阵里值为1且在辅助数组里不为1的那个邻接点 
//		if ((G.arcs[v][w] != 32767) && (!visited[w])) DFS(G, w);
//}
//
//int main()
//{
//	AMGraph G;
//	CreateUDN(&G);
//	printf("\n邻接矩阵表视图：\n");
//	for (int i = 0; i < G.vexnum; i++)
//	{
//		for (int j = 0; j < G.vexnum; j++)
//		{
//			printf("%6d ", G.arcs[i][j]);
//		}
//		printf("\n");
//	}
//	printf("\n邻接矩阵表视图深度优先遍历结果：");
//	DFS_AM(G, 2);
//	return 0;
//}
