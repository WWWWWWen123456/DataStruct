#pragma once

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<time.h>

typedef int HeapDataType;
struct Heap
{
	HeapDataType* a;
	int size;
	int capacity;
};

void InitHeap(Heap* ph);//初始化
void DestroyHeap(Heap* ph);//销毁
void PrintHeap(Heap* ph);//打印
void AdjustDown(int* a, int n,int parent);//向下调整
void AdjustUp(int* a, int child);//向上调整
void Swap(int* a, int* b);//交换
void CheckCapacity(Heap* ph);
void PushHeap(Heap* ph, HeapDataType x);//插入
void PopHeap(Heap* ph );//删除
HeapDataType TopHeap(Heap* ph);//找到堆顶数
bool EmptyHeap(Heap* ph);//判空
int SizeHeap(Heap* ph);//返回数组有效数据的个数
void HeapSort(int*a,int n);//堆排序
void PrintTopK(int* a, int n, int k);//TopK问题
