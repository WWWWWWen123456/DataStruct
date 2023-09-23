#define _CRT_SECURE_NO_WARNINGS 1 
#include"Heap.h"
//以小堆为例子
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
void AdjustUp(int* a, int child) {
	int parent = (child - 1) / 2;
	while (child > 0) {
		if (a[child] < a[parent]) {
			Swap(&a[child], &a[parent]);//如果孩子比父亲要小 孩子就要交换上去
			child = parent;
			parent = (child - 1) / 2;
		}
		else {
			break;
		}
	}
}
void AdjustDown(int* a, int size, int parent) {
	int child = parent * 2 + 1;//先假设是左孩子
	while(child<size){
		//如果右孩子比左孩子要小 就交换 取出左右孩子中较小的那个
		if (child+1<size&&a[child + 1] < a[child]) {
			child += 1;
		}

		if (a[child] < a[parent]) {
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else {
			break;
		}
	}
}
void Swap(HeapDataType* a, HeapDataType* b) {
	HeapDataType tmp = *a;
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
		printf("扩容成功！\n");
	}
}
void PushHeap(Heap* ph, HeapDataType x) {
	assert(ph);
	CheckCapacity(ph);

	ph->a[ph->size] = x;
	ph->size++;

	AdjustUp(ph->a, ph->size - 1);
}
void PopHeap(Heap* ph) {
	assert(ph);
	assert(ph->size > 0);
	//第一个位置和最后一个位置交换
	Swap(&ph->a[0], &ph->a[ph->size - 1]);
	//把交换过后的最后一个元素的位置上的元素删除（原先是第一个元素）
	ph->size--;
	//对交换上去的进行调整
	AdjustDown(ph->a, ph->size, 0);
}
HeapDataType TopHeap(Heap* ph) {
	assert(ph);

	return ph->a[0];

}
bool EmptyHeap(Heap* ph) {
	assert(ph);
	return ph->size == 0;
}
int SizeHeap(Heap* ph) {
	assert(ph);

	return ph->size;
}