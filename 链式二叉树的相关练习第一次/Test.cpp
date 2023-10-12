#define _CRT_SECURE_NO_WARNINGS 1 
#include"BinaryTree.h"
void test() {
	BTNode* node=CreatBinartTree();
	printf("前序遍历：");
	BinaryPrevOrder(node);
	printf("\n");

	printf("中序遍历：");
	BinaryInOrder(node);
	printf("\n");

	printf("后序遍历：");
	BinaryPostOrder(node);
	printf("\n");

	printf("层序遍历： ");
	BinaryLevelOrder(node);
	printf("\n");

	printf("树总结点个数：%d ",BinaryTreeSize(node));
	printf("\n");

	printf("叶子结点的个数：%d ", BinartTreeLeafSize(node));
	printf("\n");

	printf("第%d层结点的个数为:%d ", 3,BInaryTreeLevelSize(node, 3));
	printf("\n");
	
	printf("二叉树的深度为：%d ", BinaryTreeMaxDepth(node));
	printf("\n");

	
}
int main() {
	test();
	return 0;
}