#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

void AdjustDown(int* a, int size, int parent);//向下调整算法
void AdjustUp(int* a, int child);//向上调整算法
void Swap(int* a, int* b);//交换
void InitHeap(int* a, int size);//建堆
void HeapSort(int* a, int size);//排序
void Print(int* a, int size);//打印

