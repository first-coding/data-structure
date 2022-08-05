#pragma once
#include<stdio.h>
#include<stdlib.h>
#include "../list/PointList.h"
typedef struct open* OpenHashTable;
typedef unsigned short SetItem;
typedef struct open {
	int size;
	int(*hf)(SetItem x);
	List* ht;
}Open;


OpenHashTable HTInit(int nbuckets, int(*hashf)(SetItem x)) {
	OpenHashTable H = (OpenHashTable)malloc(sizeof * H);
	H->size = nbuckets;;
	H->hf = hashf;
	H->ht = (List*)malloc(20 * sizeof(List));
	for (int i = 0; i<H ->size; i++) {
		H->ht[i] = ListInit();
	}
	return H;
}

int HTmember(SetItem x, OpenHashTable H) {
	int i = (*H->hf)(x) % H->size;
	return (ListLocate(x, H->ht[i]) > 0);
}

void HTinsert(SetItem x, OpenHashTable H) {
	if (HTmember(x, H))return;
	int i = (*H->hf)(x) % H->size;
	ListInsert(0, x, H->ht[i]);
}

void HTDelete(SetItem x, OpenHashTable H) {
	int i, k;
	i = (*H->hf)(x) % H->size;
	if (k = ListLocate(x, H->ht[i]))ListDelete(k, H->ht[i]);
}