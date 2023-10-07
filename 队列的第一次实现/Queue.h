#pragma once

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

typedef int QueueDataType;//定义数据类型
//结点定义
typedef struct QueueNode
{
	struct QueueNode* next;
	QueueDataType data;
}QNode;
//队列定义
typedef struct MyQueue
{
	QNode* head;
	QNode* tail;
	int size;
}Queue;

void InitQueue(Queue* pq);//初始化
void DestoryQueue(Queue* pq);//销毁
void PushQueue(Queue* pq,QueueDataType x);//插入
void PopQueue(Queue* pq);//删除
void PrintQueue(Queue* pq);//打印
QueueDataType FrontQueue(Queue* pq);//取出队头数据
QueueDataType BackQueue(Queue* pq);//取出队尾数据
bool EmptyQueue(Queue* pq);//判空
int SizeQueue(Queue* pq);//有效数据个数
