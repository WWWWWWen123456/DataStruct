#pragma once
//双向循环带头链表的实现
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

typedef int STDataType;
struct STNode {
	struct STNode* next;
	struct STNode* prev;
	STDataType data;
};//定义双链表的结构

STNode* BuyListNode(STDataType x);//创建新节点
STNode* InitList(STNode* phead);//初始化链表
void DestoryList(STNode* phead);//销毁链表
void PrintList(STNode* phead);//打印链表
//插入
void PushFront(STNode* phead, STDataType x);//头插
void PushBack(STNode* phead, STDataType x);//尾插
void PushBeforePos(STNode* phead, STDataType x, STNode* pos);//在指定位置之前插入
//删除
void PopFront(STNode* phead);//头删
void PopBack(STNode* phead);//尾删
void ErasePos(STNode* phead, STNode* pos);//删除指定位置的节点
//判空
bool EmptyList(STNode* phead);//判断链表是否为空
int SizeList(STNode* phead);//返回有效元素个数
