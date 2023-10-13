#pragma once
#include"Queue.h"

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

typedef char BTDataType;
typedef struct BinaryTree
{
	BTDataType data;
	BinaryTree* left;
	BinaryTree* right;
}BTNode;

BTNode* BuyNode(BTDataType x);
BTNode* CreatBinaryTree();
//遍历
void PrevOrder(BTNode* node);//前序遍历
void InOrder(BTNode* node);//中序遍历
void PostOrder(BTNode* node);//后续遍历
void LevelOrder(BTNode* node);//层序遍历 
int TreeSize(BTNode* node);//总结点数量
int TreeLeafSize(BTNode* node);//叶子结点的数量
int TreeLevelSize(BTNode* node,int k);//第k层结点的数量
BTNode* Findnode(BTNode* root, BTDataType x);//查找值为x的结点
int Max(int a, int b);//求最大值
int BinaryTreeMaxDepth(BTNode* root);//求深度