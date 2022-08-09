#include "LeftTree.h"

int main() {
	MinHBLT H = HBLTInit();
	HBLTInsert(10, H);
	HBLTInsert(20, H);
	HBLTInsert(30, H);
	SetItem a = HBLTMin(H);
	SetItem d[10] = { 10,90,80,5,60,10,3,2,1,100 };
	MinHBLT S = BuildHBLT(d, 8);
	printf("%d\n", a);
	return 0;
}