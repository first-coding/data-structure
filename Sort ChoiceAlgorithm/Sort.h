#pragma once
typedef int Item;

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<math.h>
#include "../stack/PointStack.h"
#include "../list/PointList.h"

typedef link QItem;
typedef QItem* Qaddr;
typedef struct qnode* qlink;
typedef struct qnode {
	QItem element;
	qlink next;
}Qnode;
typedef struct lqueue* Queue;
typedef struct lqueue {
	qlink first;
	qlink last;
}Lqueue;

#define push2(A,B,s) Push(B,s);Push(A,s);
#define M 15
#define eq(A,B) (!less(A,B) && !less(B,A))
#define Big_Head(A,B) (A<B)
#define Small_Head(A,B) (A>B)
#define key(A) (A)
#define less(A,B) (key(A)<key(B))
#define swap(A,B) {Item t=A;A=B;B=t;}
#define compswap(A,B) if(less(B,A))swap(A,B);
#define big_swap(A,B) if(Big_Head(A,B))swap(A,B)
#define small_swap(A,B) if(Small_Head(A,B))swap(A,B)


void ItemShows(Item *a,int r) { 
	for (int i = 0; i < r; i++) {
		printf("%d\n", a[i]);
	}
} 
//Show element
void BubbleSort_big(Item * a,int r) {
	for (int i = 0; i < r-1; i++) {
		for (int j = 0; j < r - 1 - i; j++) {
			big_swap(a[j], a[j + 1]);
		}
	}
}
//The first element is bigger than any element in the array.

void BubbleSort_small(Item* a, int r) {
	for (int i = 0; i < r - 1; i++) {
		for (int j = 0; j < r - 1 - i; j++) {
			small_swap(a[j], a[j + 1]);
		}
	}
}
//The first element is smaller than any element in the array.

void Insert_sort(Item* a,int r) {
	for (int i = 1; i < r; i++) {
		int element = a[i];
		int j = i - 1;
		while (j >= 0 && (a[j] > element)) {
			a[j+1] = a[j];
			j--;
		}
		a[j + 1] = element;
	}
}
//InsertSort

void ChoiceSort(Item* a, int r) {
	for (int i = 0; i <= r - 1; i++) {
		Item element = a[i];
		Item z = i;
		for (int j = i+1; j < r; j++) {
			if (a[j] < element) {
				element = a[j];
				z = j;
			}
		}
		swap(a[i], a[z]);
	}
}
//ChoiceSort

void quicksort_1(int left,Item *a, int right) {
	int i, j, t, temp;
	if (left > right)
		return;
	temp = a[left]; 
	i = left;
	j = right;
	while (i != j) { 
		while (a[j] >= temp && i < j)
			j--;
		while (a[i] <= temp && i < j)
			i++;
		if (i < j)
		{
			t = a[i];
			a[i] = a[j];
			a[j] = t;
		}
	}
	a[left] = a[i];
	a[i] = temp;
	quicksort_1(left,a,i - 1);
	quicksort_1(i+1,a,right);
}
//QuickSort of first method


void Swap(int a[], int left, int right)
{
	int tmp;
	tmp = a[left];
	a[left] = a[right];
	a[right] = tmp;
}
//The function is that Swap element in the a[left] and a[right]

int Partition(int a[], int p, int r)
{
	int i = p, j = r + 1;
	int x = a[p];
	while (1)
	{
		while (a[++i] < x && i < r);
		while (a[--j] > x);
		if (i >= j) break;
		Swap(a, i, j);
	}
	a[p] = a[j];
	a[j] = x;
	return j;
}
//QuickSort is important with first function 

int RandomizedPartition(int a[], int p, int r)
{
	srand(time(NULL));
	int i = rand() % (r - p) + p;
	Swap(a, i, p);
	return Partition(a, p, r);
}
//Find a elment between a[p] and a[r];

void RandomizedQuickSort(int a[], int p, int r)
{
	if (p < r)
	{
		int q = RandomizedPartition(a, p, r);
		RandomizedQuickSort(a, p, q - 1);
		RandomizedQuickSort(a, q + 1, r);
	}
}
//RandomSort of first method

void QuickSort(int a[], int p, int r)
{
	if (p < r)
	{
		int q = Partition(a, p, r);
		QuickSort(a, p, q - 1);
		QuickSort(a, q + 1, r);
	}
}
//QuickSort of second method

int partition(Item* a, int l, int r) {
	int i = l - 1, j = r;
	Item v = a[r];
	for (;;) {
		while (less(a[++i], v));
		while (less(v, a[--j]))if (j == l)break;
		if (i >= j)break;
		swap(a[i], a[j]);
	}
	swap(a[i], a[r]);
	return i;
}
//QuickSort is important with second function.

void QuickSortStack(Item* a, int l, int r) { 
	Stack s = StackInit();
	push2(l, r, s);
	while (!StackEmpty(s)) {
		l = Pop(s);
		r = Pop(s);
		if (r <= l)continue;
		int i = partition(a, l, r);
		if (i - l > r - i) {
			push2(l, i - 1, s);
			push2(i + 1, r, s);
		}
		else {
			push2(i + 1, r, s);
			push2(l, i - 1, s);
		}
	}
}
//Mock Stack to use function.

void OptimalizeQuickSort(Item* a, int l, int r) {
	for (int i = l + 1; i <= r; i++)compswap(a[l], a[i]);
	for (int i = l + 2; i <= r; i++) {
		int j = i;
		Item v = a[i];
		while (less(v, a[j - 1])) {
			a[j] = a[j - 1];
			j--;
		}
		a[j] = v;
	}
}
//Optimize QuickSort first method.

//Optimize QuickSort second method.
void qsorts(Item* a, int l, int r) {
	if (r - l <= M) return;
	swap(a[(l + r) / 2], a[r - 1]);
	compswap(a[l], a[r - 1]);
	compswap(a[l], a[r]);
	compswap(a[r - 1], a[r]);
	int i = partition(a, l + 1, r - 1);
	qsorts(a, l, i - 1);
	qsorts(a, i + 1, r);
}

void sort(Item* a, int l, int r) {
	qsorts(a, l, r);
	OptimalizeQuickSort(a, l, r);
}

void ThreeDivideSort(Item* a, int l, int r) {
	int i = l - 1, j = r, p = l - 1, q = r;
	Item v = a[r];
	if (r <= 1)return;
	for (;;) {
		while (less(a[++i], v));
		while (less(v, a[--j]))if (j == l)break;
		if (i >= j)break;
		swap(a[i], a[j]);
		if (eq(a[i], v)) {
			p++;
			swap(a[p], a[i]);
		}
		if (eq(v, a[j])) {
			q--;
			swap(a[q], a[j]);
		}
	}
	swap(a[i], a[r]);
	j = i - 1;
	i = i + 1;
	for (int k = l; k < p; k++, j--) {
		swap(a[k], a[j]);
	}
	for (int k = r - 1; k > q; k--, i++) {
		swap(a[k], a[i]);
	}
	sort(a, l, j);
	sort(a, i, r);
}
//Three Quick Sort

//merge sort
void Merge(int a[], int left1, int right1, int left2, int right2)
{
	int i = left1;
	int j = left2;
 	int index = 0, b[10];
	while (i <= right1 && j <= right2)
	{
		if (a[i] > a[j])
			b[index++] = a[j++];
		else
			b[index++] = a[i++];
	}
	while (i <= right1)	b[index++] = a[i++];
	while (j <= right2)	b[index++] = a[j++];
	for (int i = 0; i < index; i++)
		a[left1 + i] = b[i];
}

void mergeSort(int a[], int left, int right)
{
	if (left < right)
	{
		int mid = (left + right) / 2;
		mergeSort(a, left, mid);
		mergeSort(a, mid + 1, right);
		Merge(a, left, mid, mid + 1, right);
	}
}

//PointerList mergesort
link merge(link a, link b) {
	Node head;
	link c = &head;
	while (a && b) {
		if (less(a->element, b->element)) {
			c->next = a; c = a; a = a->next;
		}
		else {
			c->next = b;
			c = b;
			b = b->next;
		}
	}
	c->next = (!a) ? b : a;
	return head.next;
}

link mergesort(link c) {
	link a, b;
	if (!c->next)return c;
	a = c;
	b = c->next;
	while (b && b->next) {
		c = c->next;
		b = b->next->next;
	}
	b = c->next;
	c->next = 0;
	return merge(mergesort(a), mergesort(b));
}

//PointList && PointQueue mergesort
Queue QueueInit() {
	Queue Q = (Queue)malloc(sizeof * Q);
	Q->first = Q->last = 0;
	return Q;
}

qlink NewNodes() {
	return (qlink)malloc(sizeof(Qnode));
}

void EnterQueue(QItem x, Queue Q) {
	qlink news = NewNodes();
	news->element = x;
	news->next = 0;
	if (Q->first == 0) {
		Q->first = news;
		Q->last = news;
	}
	else {
		Q->last->next = news;
		Q->last = news;
	}
}


int QueueEmpty(Queue Q) {
	return Q->first == 0;
}

QItem DeleteQueue(Queue Q) {
	if (QueueEmpty(Q)) return 0;
	QItem x = Q->first->element;
	qlink q = Q->first;
	Q->first = q->next;
	free(q);
	return x;
}


link mergesort2(link t) {
	link u;
	Queue q;
	for (q = QueueInit(); t; t = u) {
		u = t->next;
		t->next = 0;
		EnterQueue(t, q);
	}
	t = DeleteQueue(q);
	while (!QueueEmpty(q)) {
		EnterQueue(t, q);
		t= merge(DeleteQueue(q), DeleteQueue(q));
	}
	return t;
}

//CountSort

void countsort(int* arr, int* sorted_arr, int n)
{
	int* count_arr = (int*)malloc(sizeof(int) * 100);
	int i;
	for (i = 0; i < 100; i++)
		count_arr[i] = 0;
	for (i = 0; i < n; i++)
		count_arr[arr[i]]++;
	for (i = 1; i < 100; i++)
		count_arr[i] += count_arr[i - 1];
	for (i = n; i > 0; i--)
	{
		sorted_arr[count_arr[arr[i - 1]] - 1] = arr[i - 1];
		count_arr[arr[i - 1]]--;
	}
	free(count_arr);
}