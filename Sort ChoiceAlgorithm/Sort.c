#include "NewSort.h"

int main() {
	int s[10] = { 10,2,3,88,22,10,30,80,90,20 };
	quicksort(s, 0, 9);
	printf("\n");
	ItemShows(s, 10);
	return 0;

}



