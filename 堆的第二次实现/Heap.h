#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

//Heap结构
typedef int HeapDataType;
struct Heap {
	HeapDataType* a;
	int size;
	int capacity;
};

void InitHeap(Heap* ph);//初始化
void DestroyHeap(Heap* ph);//销毁
void PrintHeap(Heap* ph);//打印
void AdjustUp(int* a, int child);//向上调整算法
void AdjustDown(int* a, int size, int parent);//向下调整算法
void Swap(HeapDataType* a, HeapDataType* b);//交换
void CheckCapacity(Heap* ph);//检查容量
void PushHeap(Heap* ph,HeapDataType x);//插入
void PopHeap(Heap* ph);//打印
HeapDataType TopHeap(Heap* ph);//打印顶端元素
bool EmptyHeap(Heap* ph);//判空
int SizeHeap(Heap* ph);//返回有效元素

