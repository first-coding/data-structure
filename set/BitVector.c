#include "BitVector.h"

int main() {
	Set S = SetInit(20);
	Set S2 = SetInit(20);
	SetInsert(12, S);
	SetAssign(S2, S);
	Set tmp = SetUnion(S, S2);
		printf("%d\n", tmp->v[0]);
	return 0;
}