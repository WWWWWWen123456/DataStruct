#define _CRT_SECURE_NO_WARNINGS 1 
#include"BinaryTree.h"

BTNode* BuyNode(BTDataType x) {
	BTNode* newnode = (BTNode*)malloc(sizeof(BTNode));
	assert(newnode);
	newnode->left = newnode->right = NULL;
	newnode->data = x;
	return newnode;
}
BTNode* CreatBinaryTree() {
	BTNode* node1 = BuyNode('A');
	BTNode* node2 = BuyNode('B');
	BTNode* node3 = BuyNode('C');
	BTNode* node4 = BuyNode('D');
	BTNode* node5 = BuyNode('E');
	BTNode* node6 = BuyNode('F');
	BTNode* node7 = BuyNode('G');

	node1->left = node2;
	node1->right = node3;
	node2->left = node4;
	node2->right = node5;
	node3->right = node6;
	node5->left = node7;
	return node1;
}
void PrevOrder(BTNode* node) {
	if (node == NULL) {
		printf("# ");
		return;
	}
	
	printf("%c ", node->data);
	PrevOrder(node->left);
	PrevOrder(node->right);
}
void InOrder(BTNode* node) {
	if (node == NULL) {
		printf("# ");
		return;
	}
	InOrder(node->left);
	printf("%c ", node->data);
	InOrder(node->right);
}
void PostOrder(BTNode* node) {
	if (node == NULL) {
		printf("# ");
		return;
	}
	PostOrder(node->left);
	PostOrder(node->right);
	printf("%c ", node->data);
}
void LevelOrder(BTNode* node) {
	Queue q;
	InitQueue(&q);
	PushQueue(&q, node);
	while (!EmptyQueue(&q)) {
		BTNode* front = FrontQueue(&q);
		printf("%c ", front->data);
		PopQueue(&q);
		if (front->left != NULL) {
			PushQueue(&q, front->left);
		}
		if (front->right != NULL) {
			PushQueue(&q, front->right);
		}
	}
	DestroyQueue(&q);
}
int TreeSize(BTNode* node) {
	if (node == NULL) return 0;

	return TreeSize(node->left) + TreeSize(node->right) + 1;
}
int TreeLeafSize(BTNode* node) {
	if (node == NULL) return 0;
	if (node->left == NULL && node->right == NULL) return 1;
	return TreeLeafSize(node->left) + TreeLeafSize(node->right);
}
int TreeLevelSize(BTNode* node , int k) {
	if (node == NULL||k<1) return 0;
	if (k == 1) return 1;
 	return TreeLevelSize(node->left, k - 1) + TreeLevelSize(node->right, k - 1);
}
BTNode* Findnode(BTNode* root, BTDataType x) {
	if (root == NULL) return NULL;
	if (root->data == x) return root;
	
	BTNode* leftnode = Findnode(root->left, x);
	if (leftnode) return leftnode;
	
	BTNode* rightnode = Findnode(root->right, x);
	if (rightnode) return rightnode;
}
int Max(int a, int b) {
	return a > b ? a : b;
}
int BinaryTreeMaxDepth(BTNode* root) {
	if (root == NULL) return 0;
	return Max(BinaryTreeMaxDepth(root->left), BinaryTreeMaxDepth(root->right))+1;
}