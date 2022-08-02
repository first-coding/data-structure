#include "BitVector.h"

int main() {
	Set S = SetInit(20);
	Set S2 = SetInit(20);
	SetInsert(12, S);
	SetInsert(13, S2);
	//for (int i = 0; i < 20; i++) {
		printf("%d\n", S2->v[0]);
		printf("%d\n", S->v[0]);
	//}
	Set tmp = SetUnion(S, S2);
	for (int j = 0; j < 20; j++) {
		printf("%d\n", tmp->v[j]);
	}
	return 0;
}