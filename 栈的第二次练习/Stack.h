#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int StackDataType;
typedef struct Stack {
	StackDataType* a;
	int top;
	int capacity;
}st;

void InitStack(st* ps);//初始化
void DestroyStack(st* ps);//销毁
void PrintStack(st* ps);//打印
void PushStack(st* ps, StackDataType x);//入栈
void PopStack(st* ps);//出栈
StackDataType TopStack(st* ps);//返回栈顶元素
int SizeStack(st* ps);//返回有效元素的个数
bool EmptyStack(st* ps);//判断栈是否为空
