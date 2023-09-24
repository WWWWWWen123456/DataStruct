#define _CRT_SECURE_NO_WARNINGS 1 
#include"HeapSort.h"

void InitHeap(Heap* ph) {
	assert(ph);

	ph->a = NULL;
	ph->size = ph->capacity = 0;
}

void DestroyHeap(Heap* ph) {
	assert(ph);

	free(ph->a);
	ph->a = NULL;
	ph->size = ph->capacity = 0;
}
void PrintHeap(Heap* ph) {
	assert(ph);

	for (int i = 0; i < ph->size; i++) {
		printf("%d ", ph->a[i]);
	}
	printf("\n");
}
void AdjustDown(int* a, int n, int parent) {
	int child = 2 * parent + 1;
	while (child < n) {
		if (a[child + 1] < a[child] && child + 1 < n) {
			child += 1;
		}

		if (a[child] < a[parent]) {
			Swap(&a[child], &a[parent]);
			parent = child;
			child = 2 * parent + 1;
		}
		else {
			break;
		}
	}
}
void AdjustUp(int* a, int child) {
	int parent = (child - 1) / 2;
	while (child > 0) {
		if (a[child] < a[parent]) {
			Swap(&a[child], &a[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else {
			break;
		}
	}
}
void Swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
void CheckCapacity(Heap* ph) {
	assert(ph);
	if (ph->size == ph->capacity) {
		int newCapacity = ph->capacity == 0 ? 4 : 2 * ph->capacity;
		HeapDataType* tmp = (HeapDataType*)realloc(ph->a, sizeof(HeapDataType) * newCapacity);
		assert(tmp);

		ph->capacity = newCapacity;
		ph->a = tmp;
		printf("À©ÈÝ³É¹¦\n");
	}
}
void PushHeap(Heap* ph, HeapDataType x) {
	assert(ph);

	CheckCapacity(ph);

	ph->a[ph->size] = x;
	ph->size++;

	AdjustUp(ph->a,ph-> size - 1);
}
void PopHeap(Heap* ph) {
	assert(ph);

	Swap(&ph->a[0], &ph->a[ph->size - 1]);
	ph->size--;
	AdjustDown(ph->a, ph->size, 0);
}
HeapDataType TopHeap(Heap* ph) {
	assert(ph);

	return ph->a[ph->size - 1];
}
bool EmptyHeap(Heap* ph) {
	assert(ph);

	return ph->size == 0;
}
int SizeHeap(Heap* ph) {
	assert(ph);
	return ph->size;
}
void HeapSort(int* a,int n) {
	//½¨¶Ñ
	for (int i = (n-1-1)/2; i >= 0; i--) {
		AdjustUp(a, i);
	}
	
	for (int i = n - 1; i >= 0; i--) {
		Swap(&a[0], &a[i]);
		AdjustDown(a, i, 0);
	}
}
void PrintTopK(int* a, int n, int k) {
	int* KMax = (int*)malloc(sizeof(int) * n);
	assert(KMax);
	for (int i = 0; i < k; i++) {
		KMax[i] = a[i];
	}
	
	for (int i = (n-1-1)/2; i >= 0; i--) {
		AdjustDown(KMax, k, 0);
	}

	for (int i = k; i < n; i++) {
		if (a[i] > KMax[0]) {
			KMax[0] = a[i];
			AdjustDown(KMax, k, 0);
		}
	}

	for (int i = 0; i < k; i++) {
		printf("%d ", KMax[i]);
	}
	printf("\n");
}