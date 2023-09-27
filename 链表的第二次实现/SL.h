#pragma once

//1 是否需要传入头指针
//一般涉及到指定位置的 只有在指定位置之后的操作 不需要传入头指针
//2 prev的需要对链表为头结点的情况进行考虑

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int SLDataType;//数据类型
struct SLNode
{
	struct SLNode* next;//保存下一个结点的位置
	SLDataType data;//保存数据
};

//创建结点
SLNode* BuyNode(SLDataType x);
//插入
void PushBack(SLNode** pplist, SLDataType x);//尾插
void PushFront(SLNode** pplist, SLDataType x);//头插
void InsertAfterPos(SLNode** pplist, SLNode* pos, SLDataType x);//在指定位置之后插入
void InsertBeforePos(SLNode** pplist, SLNode* pos, SLDataType x);//在指定位置之前插入
//删除
void PopBack(SLNode** pplist);//尾删
void PopFront(SLNode** pplist);//头删
void ErasePos(SLNode** pplist, SLNode* pos);//删除指定位置的值
void EraseAfterPos(SLNode* pos);//删除指定位置之后的值
//查找
SLNode* FindNode(SLNode** pplist, SLDataType x);//查找指定位置值
//修改指定位置的值
void ModifyNode(SLNode* pos, SLDataType x);//修改指定位置的值
