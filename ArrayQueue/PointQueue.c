#include"PointArray.h"

int main() {
	HPoint H = QueueInit();
	for (int i = 1; i <= 10; i++) {
		QueueInsert(H, i);
	}
	TravelQueue(H);
	QEleType x1 = FrontElem(H);
	int i1 = EmptyQueue(H);
	int length1 = LengthQueue(H);
	QueueDelete(H);
	TravelQueue(H);
	QEleType x2 = FrontElem(H);
	int i2 = EmptyQueue(H);
	int length2 = LengthQueue(H);
	return 0;
}