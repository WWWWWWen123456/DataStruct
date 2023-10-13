#define _CRT_SECURE_NO_WARNINGS 1 
#include"BinaryTree.h"
void test() {
	BTNode* node = CreatBinaryTree();
	printf("前序遍历：");
	PrevOrder(node);
	printf("\n");

	printf("中序遍历：");
	InOrder(node);
	printf("\n");

	printf("后序遍历：");
	PostOrder(node);
	printf("\n");

	printf("层序遍历： ");
	LevelOrder(node);
	printf("\n");

	printf("树总结点个数：%d ", TreeSize(node));
	printf("\n");

	printf("叶子结点的个数：%d ", TreeLeafSize(node));
	printf("\n");

	printf("第%d层结点的个数为:%d ", 3, TreeLevelSize(node, 3));
	printf("\n");

	printf("二叉树的深度为：%d ", BinaryTreeMaxDepth(node));
	printf("\n");


}
int main() {
	test();
	return 0;
}