#define _CRT_SECURE_NO_WARNINGS 1 
#include"Sort.h"
//单趟排序
//将数组末尾的数据插入到前面n-1个数据的有效数组中
//并且保证前n-1个数据继续是有序的
//那么就可以保证插入是有序的
//外层循环是一共比较的趟数：最后一个位置是size-1 
//那么就需要比较size-1-1趟
void InsertSort(int* a, int size) {
	//排升序
	//时间复杂度O(n^2) 空间复杂度O(1)
	//i 用于记录end位置 外层循环是比较趟数
	for (int i = 0; i < size - 1; i++) {
		//单趟排序
		int end = i;
		int tmp = a[end + 1];
		while (end >= 0) {
			if (tmp < a[end]) {
				a[end + 1] = a[end];
				end--;
			}
			/*1 找到了合适的跳出循环
			2 如果tmp比数组中任何一个数据都要小*/
			else {
				break;
			}
		}
		a[end + 1] = tmp;
	}
}

//预排序+直接插入排序
//预排序减少时间复杂度，使数列有序或者接近有序
//最后一次直接插入排序确保数列是有序的
//时间复杂度O(NlogN) 空间复杂度O(1)
void ShellSort(int* a, int size) {
	int gap = size;
	while (gap > 1) {
		gap = gap / 3 + 1;//保证最后一次是1
		for (int i = 0; i < size - gap; i++) {
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

void Print(int* a, int size) {
	for (int i = 0; i < size; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
}