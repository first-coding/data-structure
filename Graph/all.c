//#include <stdio.h>
//#include<stdlib.h>
//#pragma warning(disable:4996)
//#define OK 1
//#define ERROR 0
//#define MaxInt 32767
//#define MVNum 100
//typedef int Status;
//typedef char VerTexType;     //��������
//typedef int ArcType;         //�ߵ�Ȩֵ����
//int visited[MVNum];
//
////ͼ���ڽӾ���洢��ʾ 
//typedef struct
//{
//	VerTexType vexs[MVNum];   //����� 
//	ArcType arcs[MVNum][MVNum];   //�ڽӾ��� 
//	int vexnum, arcnum;           //ͼ��ǰ�Ķ������ͱ��� 
//}AMGraph;
//
////��λ�����λ��
//int LocateVex(AMGraph G, char v)   //v��ʾ����
//{
//	for (int i = 0; i < G.vexnum; i++)
//		if (G.vexs[i] == v)
//			return i;
//}
//
////�ڽӾ����ʾ������������
//Status CreateUDN(AMGraph* G)
//{
//	int i, j, ii, jj, k, w;
//	char v1, v2;
//	//��ʼ��
//	printf("�����붥�����ͱ�����");
//	scanf("%d %d", &((*G).vexnum), &((*G).arcnum));   //���붨�����ͱ���
//	printf("������%d������ֵ: ", (*G).vexnum);
//	for (i = 0; i < (*G).vexnum; i++)             //Ϊ�����ֵ 
//		scanf(" %c", &((*G).vexs[i]));
//	for (i = 0; i < (*G).vexnum; i++)            //��ʼ���ߵ�ȨֵΪ����ֵMaxInt=32767 
//		for (j = 0; j < (*G).vexnum; j++)
//			(*G).arcs[i][j] = MaxInt;
//	//����֮��ı߸�Ȩ 
//	for (k = 0; k < (*G).arcnum; k++)
//	{
//		printf("���������㼰��֮��Ȩֵ��");
//		scanf(" %c%c%d", &v1, &v2, &w);   //�����������㼰��֮��Ȩֵ 
//		ii = LocateVex(*G, v1);             //��λv1�����Ȩֵ
//		jj = LocateVex(*G, v2);            //��λv2�����Ȩֵ 
//		(*G).arcs[ii][jj] = w;              //�ö��㵽��һ�������Ȩֵ 
//		(*G).arcs[jj][ii] = (*G).arcs[ii][jj];   //����ͼ����һ�����㵽�ö����Ȩֵ 
//	}
//	return OK;
//}
//
////��õ�v������ĵ�һ�ڽӵ�
//int FirstAdjVex(AMGraph G, int v)
//{
//	for (int i = 0; i < G.vexnum; i++)
//		if (G.arcs[v][i]) return i;
//	return -1;
//}
//
////��õ�v����������ڵ�w���ڽӵ����һ���ڽӵ�
//int NextAdjVex(AMGraph G, int v, int w)
//{
//	for (int i = w + 1; i < G.vexnum; i++)
//		if (G.arcs[v][i]) return i;
//	return -1;
//}
//
////��ͨͼ������ȱ���
//void DFS(AMGraph G, int v)
//{
//	printf("%c", G.vexs[v]);    //����ö��� 
//	visited[v] = 1;      //�ڸ����������־�ö����ѱ����ʹ� 
//	for (int w = FirstAdjVex(G, v); w >= 0; w = NextAdjVex(G, v, w))      //���������ڽӵ� 
//		if (!visited[w]) DFS(G, w);  //�ݹ���� 
//}
//
////�ڽӾ����ʾͼ��������ȱ���
//void DFS_AM(AMGraph G, int v)
//{
//	//��ʼ����������
//	for (int i = 0; i < G.vexnum; i++)
//		visited[i] = 0;
//	//��ʼ����
//	printf("%c", G.vexs[v]);   //�����ڶ��� 
//	visited[v] = 1;       //����ڶ����λ���ڸ����������־Ϊ1����һ�α��������ᱻ���� 
//	for (int w = 0; w < G.vexnum; w++)        //���ڽӾ���ͼ�ĵ�v������Ѱvexs[v]���ڽӵ㡪��������ֵΪ1���ڸ��������ﲻΪ1���Ǹ��ڽӵ� 
//		if ((G.arcs[v][w] != 32767) && (!visited[w])) DFS(G, w);
//}
//
//int main()
//{
//	AMGraph G;
//	CreateUDN(&G);
//	printf("\n�ڽӾ������ͼ��\n");
//	for (int i = 0; i < G.vexnum; i++)
//	{
//		for (int j = 0; j < G.vexnum; j++)
//		{
//			printf("%6d ", G.arcs[i][j]);
//		}
//		printf("\n");
//	}
//	printf("\n�ڽӾ������ͼ������ȱ��������");
//	DFS_AM(G, 2);
//	return 0;
//}
