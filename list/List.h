#pragma once
#include<stdio.h>
#include<stdlib.h>
typedef int ListItem;
typedef struct alist* List;
typedef struct alist {
	int n, curr;
	int maxsize;
	ListItem* table;
}Alist;

List ListInit(int size); //list init
int ListEmpty(List L);//test List isnull
int ListLength(List L);//ListLength
ListItem ListRetrieve(int k, List L);//return location k element in the L
int ListLocate(ListItem x, List L);//return element x in the List L location
void ListInsert(int k, ListItem x, List L);//insert element x to List location k
ListItem ListDelete(int k, List L);// delete location k element in the List L
void PrintList(List L);
List resize(List L);