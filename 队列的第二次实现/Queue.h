#pragma once

#include<assert.h>
#include<stdlib.h>
#include<stdio.h>

typedef int QueueDataType;//定义数据类型
typedef struct QueueNode
{
	QueueNode* next;
	QueueDataType data;//数据域和指针域
}QNode;//用链表来实现队列，定义结点

typedef struct Queue
{
	QNode* head;
	QNode* tail;
	int size;
}Queue;//定义队列的结构

void InitQueue(Queue* pq);//初始化
void DestroyQueue(Queue* pq);//销毁
void PrintQueue(Queue* pq);//打印
void PushQueue(Queue* pq, QueueDataType x);//插入（尾插）
void PopQueue(Queue* pq);//删除（头删）
QueueDataType FrontQueue(Queue* pq);//头元素
QueueDataType BackQueue(Queue* pq);//尾元素
bool EmptyQueue(Queue* pq);//判空
int SizeQueue(Queue* pq);//返回有效元素的个数
