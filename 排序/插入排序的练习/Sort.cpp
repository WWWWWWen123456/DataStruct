#define _CRT_SECURE_NO_WARNINGS 1 

#include"Sort.h"

void Print(int* a, int sz) {
	for (int i = 0; i < sz; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
}
//以排升序为例子
void InsertSort(int* a, int sz) {
	//i<sz-1 此时end最大为sz-1(最后一个位置)-1
	//那么tmp为end的后一个位置 刚好覆盖整个数组
	for (int i = 0; i < sz - 1; i++) {
		int end = i;
		int tmp = a[end + 1];
		//end>=0 end==0的时候 排第一个
		while (end >= 0) {
			//排升序 前面的数字尽可能要小 
			//因此如果tmp小就需要移到前面
			if (tmp<a[end]) {
				//从后往前移动数字，该位置覆盖下一个位置
				a[end + 1] = a[end];
				end--;
			}
			else {
				break;
			}
		}
		a[end + 1] = tmp;
	}
}
void ShellSort(int* a, int sz) {
	int gap = sz;
	//gap>1 因为在循环内部可以保证gap==1
	//如果是gap>0那么由于gap最后一次取1 就会死循环
	while (gap > 1) {
		gap = gap / 3 + 1;//预排序和直接插入排序，保证最后一次一定是1
		for (int i = 0; i < sz - gap; i++) {
			int end = i;
			int tmp = a[end + 1];
			while (end >= 0) {
				if (tmp < a[end]) {
					a[end+1] = a[end];
					end--;
				}
				else {
					break;
				}
			}
			a[end + 1] = tmp;
		}
	}
}
void InsertSort1(int* a, int sz) {
	for (int i = 0; i < sz - 1; i++) {
		int end = i;
		int tmp = a[end + 1];
		while (end >= 0) {
			if (tmp < a[end]) {
				a[end + 1] = a[end];
				end--;
			}
			else {
				break;
			}
		}
		a[end + 1] = tmp;
	}
}
void ShellSort1(int* a, int sz) {
	int gap = sz;
	while (gap>1)
	{
		gap = gap / 3 + 1;
		for (int i = 0; i < sz - gap; i++) {
			int end = i;
			int tmp = a[end + 1];
			while (end >= 0) {
				if (tmp < a[end]) {
					a[end + 1] = a[end];
					end--;
				}
				else {
					break;
				}
			}
			a[end + 1] = tmp;
		}
	}
}