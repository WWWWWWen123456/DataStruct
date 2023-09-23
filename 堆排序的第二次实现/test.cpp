#define _CRT_SECURE_NO_WARNINGS 1 
#include"HeapSort.h"

void test() {
	int a[] = { 18, 49, 25, 37, 28, 15, 34, 65, 19, 27, 1, 0 };
	int size = sizeof(a) / sizeof(int);

	InitHeap(a, size);
	Print(a, size);
	HeapSort(a, size);
	Print(a, size);
}

int main() {
	test();
	return 0;
}