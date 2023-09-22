#define _CRT_SECURE_NO_WARNINGS 1 
#include"Heap.h"
//以小堆为例子
void InitHeap(Heap* ph) {
	assert(ph);//判空

	ph->a = NULL;
	ph->size = ph->capacity = 0;//初始化
}
void Destroy(Heap* ph) {
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
		printf("扩容成功\n");
	}
}
void AdjustDown(HeapDataType* a, int size, int parent) {
	//先假设左孩子是最小的
	int child = 2 * parent + 1;
	while (child < size) {
		//每一次循环找出左右孩子中较小的结点
		//如果有意义并且右孩子的值小于左孩子
		if (child + 1 < size && a[child + 1] < a[child]) {
			child += 1;
		}
		//建小堆 要把大的换到下面 小的换到上面，也就是说如果父亲比孩子大，就把孩子换上来
		if (a[child] < a[parent]) {
			Swap(&a[child], &a[parent]);
			parent = child;//原先child的位置作为新的parent的位置
			child = 2 * parent + 1;
		}
		else {
			break;
		}

	}


}
void AdjustUp(HeapDataType*a, int child) {
	int parent = (child - 1) / 2;
	//建小堆 因此小的数据在上面 大的数据在下面 因此如果子小于父 需要交换
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
//插入后需要向上调整
//删除后需要向下调整
void PushHeap(Heap* ph, HeapDataType x) {
	assert(ph);
	CheckCapacity(ph);
	ph->a[ph->size] = x;
	ph->size++;
	AdjustUp(ph->a, ph->size - 1);
}
void PopHeap(Heap* ph){
	assert(ph);
	//将第一个位置和最后一个位置进行交换（仍然保证除了第一个位置之外左右子树为堆）
	Swap(&ph->a[0], &ph->a[ph->size - 1]);
	//删除最后一个位置的数据
	ph->size--;
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
int SizeHeap(Heap* ph){
	assert(ph);
	return ph->size;