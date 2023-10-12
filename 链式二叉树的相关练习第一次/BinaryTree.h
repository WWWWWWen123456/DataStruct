#pragma once

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include"Queue.h"

typedef char BTDataType;
typedef struct BTNode
{
	BTDataType x;
	BTNode* left;
	BTNode* right;
}BTNode;
//遍历
BTNode* BuyNode(BTDataType x);//创建结点
BTNode* CreatBinartTree();//创建二叉树
void BinaryPrevOrder(BTNode* root);//前序遍历
void BinaryInOrder(BTNode* root);//中序遍历
void BinaryPostOrder(BTNode* root);//后序遍历
void BinaryLevelOrder(BTNode* root);//层序遍历
int BinaryTreeSize(BTNode* root);//树的总结点个数
int BinartTreeLeafSize(BTNode* root);//叶子结点数量
int BInaryTreeLevelSize(BTNode* root, int k);//求k层结点的个数
BTNode* BinaryTreeFind(BTNode* root, BTDataType x);//求值为k的结点
int Max(int a, int b);//求最大值
int BinaryTreeMaxDepth(BTNode* root);//求深度
