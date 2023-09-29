#pragma once

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

typedef int SLDataType;
struct SLNode {
	struct SLNode* next;
	SLDataType data;
};//定义链表结点的结构

SLNode* BuyNode(SLDataType x);//创建结点
//插入
void PushBack(SLNode** pplist, SLDataType x);//尾插
void PushFront(SLNode** pplist, SLDataType x);//头插
void InsertBeforePos(SLNode** pplist,SLDataType x, SLNode* pos);//在指定位置之前插入结点
void InsertAfterPos(SLDataType x, SLNode* pos);//在指定位置之后插入结点
//删除
void PopBack(SLNode** pplist);//尾删
void PopFront(SLNode** pplist);//头删
void PopPos(SLNode** pplist, SLDataType x, SLNode* pos);//在指定位置之前删除结点
void PopAfterPos(SLDataType x, SLNode* pos);//在指定位置之后删除结点
//判空
bool EmptySL(SLNode** pplist);
//判断有效元素的个数
int SizeSL(SLNode** pplist);
//打印
void PrintSL(SLNode** pplist);