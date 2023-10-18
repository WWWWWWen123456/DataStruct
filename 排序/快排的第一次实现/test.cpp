#define _CRT_SECURE_NO_WARNINGS 1 
#include"QuickSort.h"
void test() {
	int a[10] = { 10,9,8,7,6,5,4,3,2,1 };
	int sz = 10;
	QuickSortNonR(a, 0, sz - 1);
	for (int i = 0; i < sz; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
}
int main() {
	test();
	return 0;
}