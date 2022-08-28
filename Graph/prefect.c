#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100
#define INFINITY 65535

#pragma warning(disable:4996)
#pragma warning(disable:6262)
#pragma warning(disable:6031)
typedef struct {
    char vexs[MAX];
    int arc[MAX][MAX];
    int numVex, numEdg; 
}GRAPH, * PGRAPH;

typedef struct node {
    int index;
    struct node* next;
}NODE, * PNODE;

typedef struct {
    PNODE front;
    PNODE rear;
}QUEUE, * PQUEUE;

int visited[MAX]; 
void create(PGRAPH);
void traverse_bfs(GRAPH);
void init(PQUEUE pQ);
void en_queue(PQUEUE, int);
bool de_queue(PQUEUE, int*);

bool de_queue(PQUEUE pQ, int* pVal)
{
    //printf("de_queue...");
    PNODE tmp;

    if (pQ->front->next == NULL) {
        printf(" failed, queue empty!\n");
        return false;
    }

    tmp = pQ->front->next;
    *pVal = tmp->index;

    pQ->front->next = tmp->next;
    if (tmp->next == NULL)
        pQ->rear = pQ->front;
    free(tmp);

    //printf("success, value: %d\n", *pVal);
    return true;
}

void en_queue(PQUEUE pQ, int val)
{
    //printf("en_queue %d", val);
    PNODE pNew;
    pNew = (PNODE)malloc(sizeof(NODE));
    if (!pNew) {
        printf(" en_queue malloc error!\n");
        exit(-1);
    }
    pNew->index = val;
    pNew->next = NULL;

    pQ->rear->next = pNew;
    pQ->rear = pNew;

    //printf(" success.\n");
}

void init(PQUEUE pQ)
{

    pQ->front = pQ->rear = (PNODE)malloc(sizeof(NODE));
    if (!pQ->front) {
        printf("init malloc error!\n");
        exit(-1);
    }
    pQ->front->next = NULL;
}



void traverse_bfs(GRAPH graph)
{
    int i, j;
    QUEUE Q;

    init(&Q);

    for (i = 0; i < graph.numVex; i++) {
        visited[i] = 0;
    }


    for (i = 0; i < graph.numVex; i++) {
        if (!visited[i]) {
            visited[i] = 1;
            printf("%c ", graph.vexs[i]);
            en_queue(&Q, i);

            while (Q.front->next) {
                de_queue(&Q, &i);
                for (j = 0; j < graph.numVex; j++) {
                    if (!visited[j] && graph.arc[i][j] != INFINITY) {
                        visited[j] = 1;
                        printf("%c ", graph.vexs[j]);
                        en_queue(&Q, j);
                    }
                }
            }
        }
        printf("-_-");
    }
    putchar('\n');
}

void create(PGRAPH g)
{
    int i, j, k, w;
    printf("请输入顶点及边的个数:\n");
    scanf("%d %d", &g->numVex, &g->numEdg);
    printf("请一次性输入顶点的值:\n");
    getchar();
    for (i = 0; i < g->numVex; i++) {
        scanf("%c", &g->vexs[i]);
    }

    for (i = 0; i < g->numVex; i++) {
        for (j = 0; j < g->numVex; j++) {
            g->arc[i][j] = INFINITY;
        }
    }

    for (k = 0; k < g->numEdg; k++) {
        printf("请输入边的顶点下标和权：\n");
        scanf("%d %d %d", &i, &j, &w);
        g->arc[i][j] = g->arc[j][i] = w;
    }

}


int main(void)
{
    GRAPH graph;
    create(&graph);
    traverse_bfs(graph);
    return 0;
}

