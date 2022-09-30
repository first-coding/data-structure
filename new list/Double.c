#include"DoubleList.h"

int main() {
	hdlist L = ListInit();
	for (int i = 1; i <= 10; i++) {
		InsertList(L, i + 1, i);
	}
	int a,i,Length = LengthList(L);
	GetElem(L, 5, &a);
	LocateElem(L, 5, &i);
	DeleteList(L, 1);
	DeleteList(L, LengthList(L));
	DeleteList(L, 5);
	TravelseList(L);
	return 0;
}