#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<assert.h>

void AdjustDown(int* a, int size, int parent);//向下调整
void Swap(int* a, int* b);//交换
void TopK(int* a, int n, int k);//TopK
void Print(int* a, int size);//打印
