#include "BitVector.h"

int main() {
	Set S = SetInit(20);
	for (int i = 0; i < 20; i++) {
		Insert(i, i + 1, S);
	}
	for (int i = 0; i < 20; i++) {
		printf("%d\n", S->v[i]);
	}
	return 0;
}