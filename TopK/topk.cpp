#define _CRT_SECURE_NO_WARNINGS 1 
#include"topk.h"
//取出前k大的数字 建小堆
void AdjustDown(int* a, int size, int parent) {
	int child = 2 * parent + 1;
	while (child<size)
	{
		if (child + 1 < size && a[child + 1] < a[child]) {
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
void Swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
void TopK(int* a, int n, int k)
{
	//建立一个数组
	int* KMin = (int*)malloc(sizeof(k));
	assert(KMin);
	for (int i = 0; i < k; i++) {
		KMin[i] = a[i];
	}

	//将该数组建立成小堆
	for (int i = (k - 1 - 1) / 2; i >= 0; i--) {
		AdjustDown(a,k, 0);
	}

	//将剩下的元素与堆顶比较 符合条件进堆并且调整
	for (int i = k; i < n; i++) {
		if (a[i] > KMin[0]) {
			KMin[0] = a[i];
			AdjustDown(KMin, k, 0);
		}
	}

	//打印出来检测一下
	for (int i = 0; i < k; i++) {
		printf("%d ", KMin[i]);
	}
	printf("\n");
}
void Print(int* a, int size) {
	for (int i = 0; i < size; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
}