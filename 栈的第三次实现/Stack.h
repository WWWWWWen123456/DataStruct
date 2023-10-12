#pragma once

#include<stdlib.h>
#include<assert.h>
#include<stdio.h>

typedef int StackDataType;
typedef struct Stack
{
	int* a;
	int capacity;
	int top;
}Stack;

void InitStack(Stack* ps);//初始化
void DestroyStack(Stack* ps);//销毁
void Print(Stack* ps);//打印
void CheckCapacity(Stack* ps);//检查容量
void Push(Stack* ps, StackDataType x);//插入
void Pop(Stack* ps);//删除
bool Empty(Stack* ps);//判断是否为空
int Size(Stack* ps);//判断有效元素的个数


