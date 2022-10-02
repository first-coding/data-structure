#include"ArrayStack.h"

int main() {
	stackpoint s = StackInit();
	int e;
	for (int i = 1; i <= 5; i++) {
		Push(i, s);
	}
	LengthStack(s);
	for (int i = 1; i <= 5; i++) {
		Pop(s, &e);
	}
	GetElem(s);
	return 0;
}