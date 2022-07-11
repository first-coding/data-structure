#pragma once
typedef int Item;
#include<stdio.h>
#define Big_Head(A,B) (A<B)
#define Small_Head(A,B) (A>B)
#define less(A,B) (A<B)
#define swap(A,B) {Item t=A;A=B;B=t;}
#define big_swap(A,B) if(Big_Head(A,B))swap(A,B)
#define small_swap(A,B) if(Small_Head(A,B))swap(A,B)

void ItemShow(Item *a,int r) { 
	for (int i = 0; i < r; i++) {
		printf("%d\n", a[i]);
	}
}
void BubbleSort_big(Item * a,int r) {
	for (int i = 0; i < r-1; i++) {
		for (int j = 0; j < r - 1 - i; j++) {
			big_swap(a[j], a[j + 1]);
		}
	}
}

void BubbleSort_small(Item* a, int r) {
	for (int i = 0; i < r - 1; i++) {
		for (int j = 0; j < r - 1 - i; j++) {
			small_swap(a[j], a[j + 1]);
		}
	}
}

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

//void QuickSort(Item* a, int l, int r) {
//	if (r <= 1) return;
//	Item x = a[0];
//	int j = r - 1;
//	int i = l;
//	for (j; j >= 0; j--) {
//		if (a[j] < x) {
//			for (i; i < r; i++) {
//				if (i == j) {
//					swap(a[i], a[0]);
//					break;
//				}
//				if (a[i] > x) {
//					break;
//				}
//			}
//			break;
//		}
//	}
//	printf("%d %d", i, j);
//}

void quicksort(int left,Item *a, int right) {
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
	quicksort(left,a,i - 1);
	quicksort(i + 1,a,right);
}


