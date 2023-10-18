#define _CRT_SECURE_NO_WARNINGS 1 
#include"QuickSort.h"
void Swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
int GetMidIndex(int* a, int left, int right)
{
	int mid = left + (right - left) / 2;
	if (a[mid] > a[left])
	{
		if (a[mid] < a[right])
			return mid;
		else if (a[left] > a[right])
			return left;
		else
			return right;
	}
	else
	{
		if (a[mid] > a[right])
			return mid;
		else if (a[left] > a[right])
			return right;
		else
			return left;
	}
}
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
			if (tmp < a[end]) {
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
void QuickSort1(int* a, int begin,int end) {
	//排升序
	if (begin >= end) return;//只有一个数据或者区间无效不操作
	
	int left = begin;
	int right =end;
	int keyi = begin;
	
	//左边为keyi 右边先走 
	while (left < right) {
		//不要越界 右边找小
		while (left<right && a[right]>=a[keyi]) {
			right--;
		}
		while (left < right && a[left] <= a[keyi]) {
			left++;
		}
		//keyi左边都是小的 keyi右边都是大的
		Swap(&a[left], &a[right]);
	}
	
	

	Swap(&a[keyi], &a[left]);//最后将keyi放到对应的位置上

	QuickSort1(a, begin,keyi-1);
	QuickSort1(a ,keyi+1,end);
}
void QuickSort2(int* a, int begin, int end) {
	if (begin >= end) return;
	
	int midIndex = GetMidIndex(a, begin, end);//获取大小居中的数的下标
	Swap(&a[begin], &a[midIndex]);//将该数与序列最左端的数据交换

	int left = begin;
	int right = end;
	int key = a[left];//只有key是作为一个值的时候 而非下标的时候 才能这样操作

	if (end - begin + 1 > 20) {
		while (left < right) {
			if (left < right && a[right] >= key) {
				right--;
			}
			a[left] = a[right];

			if (left < right && a[left] <= key) {
				left++;
			}
			a[right] = a[left];
		}

		int meeti = left;
		a[meeti] = key;
		QuickSort2(a, begin, meeti - 1);
		QuickSort2(a, meeti + 1, end);
	}
	else {
		InsertSort(a + begin, end - begin + 1);
	}
}
void QuickSort3(int* a, int begin, int end) {
	if (begin >= end) return;
	
	int prev = begin;
	int cur = prev + 1;
	int keyi = prev;
	while (cur <= end) {
		//排升序 cur的位置的值比key小 并且prev和cur隔开才做交换
		if (a[cur] < a[keyi] && ++prev != cur) {
			Swap(&a[prev],& a[cur]);
		}
		cur++;
	}

	Swap(&a[prev], &a[keyi]);
	QuickSort3(a, begin, keyi - 1);
	QuickSort3(a, keyi + 1, end);
}
int Part1(int* a, int begin, int end) {
	//排升序
	int left = begin;
	int right = end;
	int keyi = begin;

	//左边为keyi 右边先走 
	while (left < right) {
		//不要越界 右边找小
		while (left < right && a[right] >= a[keyi]) {
			right--;
		}
		while (left < right && a[left] <= a[keyi]) {
			left++;
		}
		//keyi左边都是小的 keyi右边都是大的
		Swap(&a[left], &a[right]);
	}

	Swap(&a[keyi], &a[left]);//最后将keyi放到对应的位置上
	return keyi;

}
void QuickSortNonR(int* a, int left, int right) {
	stack<int>st;
	st.push(left);
	st.push(right);

	while (!st.empty()) {
		int right = st.top();
		st.pop();
		int left = st.top();
		st.pop();
		int keyi = Part1(a, left, right);

		if (left < keyi - 1) {
			st.push(left);
			st.push(keyi - 1);
		}
		if (keyi + 1 < right) {
			st.push(keyi + 1);
			st.push(right);
		}
		
	}

}

