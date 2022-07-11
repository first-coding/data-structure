#include "PointStack.h"

int main() {
	Stack S = StackInit();
	for (int i = 0; i < 20; i++) {
		Push(i, S);
	}
	ItemShow(S);
	for (int i = 0; i < 10; i++) {
		Pop(S);
	}
	printf("\n");
	ItemShow(S);
}