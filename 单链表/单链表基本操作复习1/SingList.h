#pragma once

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

typedef int SLDataType;
typedef struct SingListNode
{
	SingListNode* next;
	SLDataType data;
}SLNode;

SLNode* BuyListNode(SLDataType x);//创建结点
void InitList(SLNode** pplist);//初始化
void DestroyList(SLNode** pplist);//销毁
void PushBack(SLNode** pplist, SLDataType x);//尾插
void PushFront(SLNode** pplist, SLDataType x);//头插
void InsertAfterPos(SLNode** pplist, SLDataType x, SLNode* pos);//在pos位置之后插入
void InsertBeforePos(SLNode** pplist, SLDataType x, SLNode* pos);//在pos位置之前插入
void PopBack(SLNode** pplist);//尾删
void PopFront(SLNode** pplist);//头删
void PopAfterPos(SLNode** pplist, SLNode* pos);//在pos位置之后删除
void PopPos(SLNode** pplist, SLNode* pos);//删除pos位置的值
bool Empty(SLNode** pplist);//判空
int Size(SLNode** pplist);//判断有效元素的个数
void Print(SLNode** pplist);//打印


