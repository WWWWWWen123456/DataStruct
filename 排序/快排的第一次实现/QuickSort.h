#pragma once

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<stack>
using namespace std;

void Swap(int* a, int* b);
void QuickSort1(int* a, int begin,int end);//Hoare法
void QuickSort2(int* a, int begin, int end);//挖坑法
void QuickSort3(int* a, int begin, int end);//双指针法

//优化
//三数取中
int GetMidIndex(int* a, int left, int right);
//小区间插入排序
void InsertSort(int* a, int sz);
//非递归
int Part1(int* a, int begin, int end);
void QuickSortNonR(int* a, int left, int right);


