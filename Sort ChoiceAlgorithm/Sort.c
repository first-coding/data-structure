#include "Sort.h"
int main()
{
	int s[10] = { 10,2,3,88,22,10,30,80,90,20 };
	int* sorted_arr = (int*)malloc(sizeof(int) * 10);
	countsort(s, sorted_arr, 10);
	ItemShows(sorted_arr, 10);
	return 0;
}


