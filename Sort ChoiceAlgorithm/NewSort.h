#pragma once
#include <stdio.h>
#include<stdio.h>
typedef int Item;
void quicksort(int* a, int left, int right);
void swap(int* a, int i, int j);
int randpartition(int* a, int left, int right);

void ItemShows(Item* a, int r) {
	for (int i = 0; i < r; i++) {
		printf("%d\n", a[i]);
	}
}

void swap(int* a, int i, int j)
{
	int temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}

int partition(int* a, int left, int right)
{
	int x = a[right];
	int p = left - 1;
	for (int i = left; i < right; i++) {
		if (a[i] <= x) {
			p++;
			swap(a, p, i);
		}
	}
	swap(a, p + 1, right);
	return p + 1;

}
int randpartition(int* a, int left, int right)
{
	int r = rand() % (right);
	swap(a, right, r);
	return partition(a, left, right);
}

void quicksort(int* a, int left, int right)
{
	if (left < right)
	{
		int p = randpartition(a, left, right);
		quicksort(a, left, p - 1);
		quicksort(a, p + 1, right);
	}
}