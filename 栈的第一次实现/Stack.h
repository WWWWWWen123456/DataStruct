#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int StackDataType;
struct Stack {
	StackDataType* a;
	int top;//只用在栈顶操作 区别于顺序表的size
	int capacity;//方便扩容
};

void InitStack(Stack* ps);//初始化
void DestroyStack(Stack* ps);//销毁
void PushStack(Stack* ps,StackDataType x);//入栈
void PopStack(Stack* ps);//出栈
StackDataType TopStack(Stack* ps);//返回栈顶元素
bool EmptyStack(Stack* ps);//判断是否为空
int SizeStack(Stack* ps);//有效元素个数
