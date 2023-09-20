#pragma once

#include<assert.h>
#include<stdlib.h>
#include<stdio.h>

typedef int SLDataType;//定义数据类型
typedef struct sequenceList
{
	SLDataType* a;
	int size;
	int capacity;
}SL;

//本次代码练习主要是针对Insert和Erase复用来实现头插 头删和尾插 尾删
void SLInit(SL* ps);//初始化
void SLDestroy(SL* ps);//销毁
void SLPrint(SL* ps);//打印
void CheckCapacity(SL* ps);//容量检测
void SLInsert(SL* ps,SLDataType x,int pos);//插入
void SLPushBack(SL* ps,SLDataType x);//尾插
void SLPushFront(SL* ps, SLDataType x);//头插
void SLErase(SL* ps,int pos);//任意位置删除
void SLPopBack(SL* ps);//尾删
void SLPopFront(SL* ps);//头删
