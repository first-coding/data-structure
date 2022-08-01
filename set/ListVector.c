#include "ListVector.h"

int main() {
	Set S = SetInit();
	Set S2 = SetInit();
	for (int i = 0; i < 10; i++) {
		SetInsert(i + 1, S);
		SetInsert(i + 2, S2);
	}
	Set  tmp = SetInter(S, S2);
	int  len = SetSize(S);
	printf("%d\n", len);
	Set S3 = SetInit();
	SetAssign(S3, S2);
	return 0;
}