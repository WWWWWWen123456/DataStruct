#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

void Swap(int* a, int* b);
//调整算法
void AdjustDown(int* a, int n, int parent);
void AdjustUp(int* a, int child);
//堆排序
void HeapSort(int* a,int size);
//向上调整建堆
void InitHeapUp(int* a,int size);
//向下调整建堆
void InitHeapDown(int* a, int size);
void Print(int* a,int size);
