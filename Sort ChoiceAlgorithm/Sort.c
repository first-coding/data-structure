#include "Sort.h"

int main() {
	clock_t start, stop;
	int s[10] = { 10,2,3,88,22,10,30,80,90,20 };
	start = clock();
	sort(s, 0, 9);
	ItemShows(s, 10);
	stop = clock();
	double duration = ((double)(stop - start)) / CLK_TCK;
	printf("%f\n", duration);
	return 0;
}



