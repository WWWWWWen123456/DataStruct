#define _CRT_SECURE_NO_WARNINGS 1 
#include"Sort.h"
void testInsertSort() {
	int a[10] = { 10,9,8,7,6,5,4,3,2,1 };
	int sz = 10;
	Print(a, sz);
	InsertSort(a, sz);
	Print(a, sz);
}
void testShellSort() {
	int a[10] = { 10,9,8,7,6,5,4,3,2,1 };
	int sz = 10;
	Print(a, sz);
	ShellSort(a, sz);
	Print(a, sz);
}
int main() {
	testShellSort();
	return 0;
}