#pragma once
#include<stdio.h>
#include<stdlib.h>
#include "../list/PointList.h"
typedef struct open* OpenHashTable;
typedef unsigned short SetItem;
typedef struct open {
	int size;
	int(*hf)(SetItem x);
	List* hf;
}Open;
