#include "LeftTree.h"

int main() {
	MinHBLT H = (MinHBLT)malloc(sizeof * H);
	HBLTInsert(10, H);
	HBLTInsert(20, H);
	HBLTInsert(30, H);
	SetItem a = HBLTMin(H);
	printf("%d\n", a);
	return 0;
}