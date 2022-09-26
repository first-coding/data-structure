#include"arrange.h"

int main() {
	point L = InitList();
	for (int i = 1; i <= 10; i++) {
		ListInsert(L, i + 1, i);
	}
	int Length = ListPlace(L);
	ElemType e;
	GetElem(L, 2, &e);
	printf("GetElem:%d", e);
	int elem = LocateElem(L, &e);
	printf("LocateElem:%d", e);
	int flag = DeleteList(L, 5);
	TravelseList(L);
	DestroyList(L);
}