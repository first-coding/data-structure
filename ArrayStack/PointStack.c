#include"PointStack.h"

int main() {
	StackPoint s = StackInit();
	s = StackInsert(10, s);
	s = StackInsert(5, s);
	s = StackInsert(15, s);
	//s = StackPop(s);
	StackElem x = GetTop(s);
	return 0;
}