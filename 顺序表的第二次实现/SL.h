#pragma once

#include<assert.h>
#include<stdio.h>
#include<stdlib.h>

typedef int SLDataType;//数据类型
typedef struct SequenceList {
	SLDataType* a;
	int size;
	int capacity;//动态扩容
}SL;
//初始化销毁和打印
void InitSL(SL* ps);
void DestroySL(SL* ps);
void PrintSL(SL* ps);
//容量检测和各种插入
void CheckCapacity(SL* ps);
void PushBackSL(SL* ps,SLDataType x);
void PushFrontSL(SL* ps,SLDataType x);
void InsertSL(SL* ps, SLDataType x,int pos);
//删除
void PopBackSL(SL* ps);
void PopFrontSL(SL* ps);
void EraseSL(SL* ps, int pos);
//查找和修改
int FindSL(SL* ps, SLDataType x);
void ModifySL(SL* ps, int pos, SLDataType x);
