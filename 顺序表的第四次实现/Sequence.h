#pragma once

#include<stdlib.h>
#include<assert.h>
#include<stdio.h>


typedef int SDataType;
typedef struct Sequence {
	int size;
	int capacity;
	int* a;
}Sequence;

void InitSequence(Sequence* ps);//初始化
void DestroySequence(Sequence* ps);//销毁
void Print(Sequence* ps);//打印

void CheckCapacity(Sequence* ps);
void PushFront(Sequence* ps,SDataType x);//头插
void PushBack(Sequence* ps, SDataType x);//尾插
void Insert(Sequence* ps, SDataType x, int pos);//pos位置插入

void PopFront(Sequence* ps);//头删
void PopBack(Sequence* ps);//尾删
void Erase(Sequence* ps,int pos);//任意位置删除

bool Empty(Sequence* ps);//判空
int Size(Sequence* ps);//有效元素个数
