#pragma once

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

typedef int HeapDataType;
struct Heap
{
	HeapDataType* a;
	int size;
	int capacity;
};

void InitHeap(Heap* ph);//初始化
void Destroy(Heap* ph);//销毁
void PrintHeap(Heap* ph);//打印
void Swap(HeapDataType* a, HeapDataType* b);//交换
void CheckCapacity(Heap* ph);//容量检测
void AdjustUp(HeapDataType* a, int child);//向上调整算法
void AdjustDown(HeapDataType* a, int size, int parent);//向下调整算法
void PushHeap(Heap* ph, HeapDataType x);//插入
void PopHeap(Heap* ph);//删除元素
HeapDataType TopHeap(Heap* ph);//获取堆顶元素
bool EmptyHeap(Heap* ph);//判空
int SizeHeap(Heap* ph);//返回有效数据个数


