#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int QueueDataType;//定义数据类型
typedef struct QueueNode {
	QueueNode* next;
	QueueDataType data;
}QNode;//定义结点
typedef struct Queue
{
	QueueNode* head;
	QueueNode* tail;
	int size;
}Queue;

void InitQueue(Queue* pq);//初始化
void DestroyQueue(Queue* pq);//销毁
void PrintQueue(Queue* pq);//打印
void PushQueue(Queue* pq, QueueDataType x);//插入（尾插）
void PopQueue(Queue* pq);//删除
QueueDataType FrontQueue(Queue* pq);//返回头部数据
QueueDataType BackQueue(Queue* pq);//返回尾部数据
int SizeQueue(Queue* pq);//返回有效元素的个数
bool EmptyQueue(Queue* pq);//判空
