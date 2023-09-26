#pragma once

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

//定义结点结构
typedef int SLDataType;
typedef struct SLNode {
	struct SLNode* next;//下一个结点的位置
	SLDataType data;//数据
}SLNode;

//功能函数
void PrintSL(SLNode** pplistnode);//打印
SLNode* BuyListNode(SLDataType x);//创建
//插入
void PushFrontSL(SLNode** pplistnode, SLDataType x);//头插
void PushBackSL(SLNode** pplistnode, SLDataType x);//尾插
void InsertBeforeNode(SLNode** pplistnode, SLDataType x, SLNode* pos);//在pos位置之前插入
void InsertAfterNode(SLNode** pplistnode, SLDataType x, SLNode* pos);//在pos位置之前插入
//删除
void PopFrontSL(SLNode** pplistnode);//头删
void PopBackSL(SLNode** pplistnode);//尾删
void ErasePosSL(SLNode** pplistnodec);//在特定位置删除
void EraseAfterPosSL(SLNode* pos);//在特定位置之后删除
//查找
SLNode* FindNode(SLNode** pplistnode, SLNode* x);//查找特定位置的结点
//修改
void ModifyNode(SLNode*pos,SLDataType x);//修改特定位置的结点
