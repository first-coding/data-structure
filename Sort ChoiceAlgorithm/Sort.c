#include "Sort.h"
int main() {
	int s[10] = { 10,2,3,88,22,10,30,80,90,20 };
	mergeSort(s, 0, 9);
	ItemShows(s, 10);
	return 0;
}



