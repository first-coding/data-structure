#include"PointList.h"

int main() {
	hlist L = ListInit();
	for (int i = 1; i <= 10; i++) {
		ListInsert(L, i + 1, i);
	}
	int Length = ListLength(L);
	ElemType e;
	GetElem(L, 2, &e);
	TravelseList(L);
}