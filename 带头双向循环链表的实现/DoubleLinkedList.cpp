#define _CRT_SECURE_NO_WARNINGS 1 
#include"DoubleLinkedList.h"

STNode* BuyListNode(STDataType x) {
	STNode* newnode = (STNode*)malloc(sizeof(STDataType));
	assert(newnode);
	newnode->data = x;
	newnode->prev = NULL;
	newnode->next = NULL;
	return newnode;

}
STNode* InitList(STNode* phead) {
	assert(phead);

	STNode* newnode = BuyListNode(-1);//创建一个头结点
	newnode->next = newnode;//头尾指向自己
	newnode->prev = newnode;

	return newnode;
}
void DestoryList(STNode* phead) {
	assert(phead);

	STNode* cur = phead->next;
	STNode* after = cur->next;
	while (cur!= phead) {
		free(cur);
		cur = NULL;
		cur = after;
		after = after->next;
	}
	free(phead);//头结点也要被释放
	phead = NULL;
}
void PrintList(STNode* phead) {
	assert(phead);
	STNode* cur = phead->next;
	while (cur != phead) {
		printf("%d ->", cur->data);
		cur = cur->next;
	}
	printf("\n");
}
//插入
void PushFront(STNode* phead, STDataType x) {
	
	assert(phead);
	STNode* after = phead->next;
	STNode* newnode = BuyListNode(x);
	//建立新节点和after的关系
	newnode->next = after;
	after->prev = newnode;
	//建立新节点和头结点的关系
	phead->next = newnode;
	newnode->prev = phead;
}
void PushBack(STNode* phead, STDataType x) {
	assert(phead);

	STNode* tail = phead->prev;
	STNode* newnode = BuyListNode(x);
	//建立newnode和尾结点的关系
	tail->next = newnode;
	newnode->prev = tail;
	//建立newnode和头结点的关系
	newnode->next = phead;
	phead->prev = newnode;
}
void PushBeforePos(STNode* phead, STDataType x, STNode* pos) {
	assert(phead && pos);

	STNode* prev = pos->prev;
	STNode* newnode = BuyListNode(x);
	//建立newnode和prev的联系
	prev->next = newnode;
	newnode->prev = prev;
	//建立newnode和pos的联系
	newnode->next = pos;
	pos->prev = newnode;

}
//删除
void PopFront(STNode* phead) {
	assert(phead);
	assert(!EmptyList(phead));

	STNode* cur = phead->next;
	STNode* after = cur->next;
	//改变指针
	phead->next = after;
	after->prev = phead;
	//删除节点
	free(cur);
	cur = NULL;
}
void PopBack(STNode* phead) {
	assert(phead);
	assert(!EmptyList(phead));

	STNode* tail = phead->prev;
	STNode* prev = tail->prev;
	//重新建立连接关系
	prev->next = phead;
	phead->prev = prev;
	//释放尾结点
	free(tail);
	tail = NULL;
}
void ErasePos(STNode* phead, STNode* pos) {
	assert(phead && pos);
	assert(!EmptyList(phead));
	
	STNode* prev = pos->prev;
	STNode* next = pos->next;
	//改变链接关系
	prev->next = next;
	next->prev = prev;
	//释放该位置的结点
	free(pos);
	pos = NULL;
}
//判空
bool EmptyList(STNode* phead) {
	assert(phead);
	return phead->next == phead;
}
int SizeList(STNode* phead) {
	assert(phead);

	int count = 0;
	STNode* cur = phead->next;

	while (cur != phead) {
		cur = cur->next;
		count++;
	}
	return count;
}