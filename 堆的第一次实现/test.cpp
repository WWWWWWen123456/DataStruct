#define _CRT_SECURE_NO_WARNINGS 1 
#include"Heap.h"

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
	PopHeap(&hp);
	PopHeap(&hp);
	PopHeap(&hp);
	PopHeap(&hp);

	PrintHeap(&hp);
	Destroy(&hp);

}

int main() {
	test();
	return 0;
}