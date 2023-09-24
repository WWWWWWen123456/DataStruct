#define _CRT_SECURE_NO_WARNINGS 1 
#include"HeapSort.h"

void test() {
	Heap hp;
	InitHeap(&hp);
	//½¨ÑÔpush
	PushHeap(&hp, 18);
	PushHeap(&hp, 49);
	PushHeap(&hp, 25);
	PushHeap(&hp, 37);
	PushHeap(&hp, 28);
	PushHeap(&hp, 15);
	PushHeap(&hp, 34);
	PushHeap(&hp, 65);
	PushHeap(&hp, 19);
	PushHeap(&hp, 27);
	PushHeap(&hp, 1);
	PushHeap(&hp, 0);
	HeapSort(hp.a,hp.size);
	PrintHeap(&hp);

	PopHeap(&hp);
	PopHeap(&hp);
	PopHeap(&hp);
	PopHeap(&hp);
	PopHeap(&hp);
	PopHeap(&hp);
	PopHeap(&hp);



	PrintHeap(&hp);
	DestroyHeap(&hp);

}
void testtopK() {
	int n = 10000;
	int* a = (int*)malloc(sizeof(int) * n);
	srand(time(0));
	for (size_t i = 0; i < n; ++i)
	{
		a[i] = rand() % 1000000;
	}
	a[5] = 1000000 + 1;
	a[1231] = 1000000 + 2;
	a[531] = 1000000 + 3;
	a[5121] = 1000000 + 4;
	a[115] = 1000000 + 5;
	a[2335] = 1000000 + 6;
	a[9999] = 1000000 + 7;
	a[76] = 1000000 + 8;
	a[423] = 1000000 + 9;
	a[3144] = 1000000 + 10;
	PrintTopK(a, n, 10);
}
int main() {
	testtopK();
	return 0;
}