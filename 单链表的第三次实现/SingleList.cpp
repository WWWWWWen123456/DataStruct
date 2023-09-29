#define _CRT_SECURE_NO_WARNINGS 1 
#include"SingList.h"

SLNode* BuyNode(SLDataType x) {
	SLNode* newnode = (SLNode*)malloc(sizeof(SLNode));
	assert(newnode);
	newnode->next = NULL;
	newnode->data = x;
	return newnode;
}
//插入
void PushBack(SLNode** pplist, SLDataType x) {
	SLNode* newnode = BuyNode(x);//创建一个结点
	//如果链表为空 单独进行处理
	if (*pplist == NULL) {
		*pplist = newnode;
	}
	else {
		//找尾
		SLNode* tail = *pplist;
		while (tail->next != NULL) {
			tail = tail->next;
		}
		//修改链接关系
		tail->next = newnode;
	}
}
void PushFront(SLNode** pplist, SLDataType x) {
	SLNode* newnode = BuyNode(x);//创建一个结点
	newnode->next = *pplist;
	*pplist = newnode;
}
void InsertBeforePos(SLNode** pplist,SLDataType x, SLNode* pos) {
	assert(pos);
	SLNode* newnode = BuyNode(x);//创建一个新的结点
	//只有一个结点的情况需要单独进行考虑(头指针）
	if (*pplist==pos) {
		newnode->next = *pplist;
		*pplist = newnode;
	} {
		//找到pos前的一个位置的结点
		SLNode* prev = *pplist;
		while (prev->next != pos) {
			prev = prev->next;
		}
		//修改链接关系
		newnode->next = prev->next;
		prev->next = newnode;
	}
}
void InsertAfterPos(SLDataType x, SLNode* pos) {
	assert(pos);
	SLNode* newnode = BuyNode(x);//创建一个结点
	newnode->next = pos->next;
	pos->next = newnode;
}
void PopBack(SLNode** pplist) {
	assert(!EmptySL(pplist));//链表不为空
	if ((*pplist)->next == NULL) {
		free(*pplist);
		*pplist = NULL;//只有一个结点相当于头删
	}
	else {
		SLNode* prev = *pplist;
		SLNode* tail = prev->next;
		while (tail->next!=NULL)
		{
			prev = tail;
			tail = tail->next;
		}
		free(tail);
		tail = NULL;
		prev->next = NULL;//将倒数第二个结点的指针域置空，使其成为新的尾结点（防止只能删除一次的情况）
	}
}
void PopFront(SLNode** pplist) {
	assert(!EmptySL(pplist));
	//记录下一个结点的位置
	/*SLNode* next = (*pplist)->next;
	free(*pplist);
	*pplist = next;*/

	SLNode* tmp = *pplist;
	*pplist = (*pplist)->next;
	free(tmp);
	tmp = NULL;
}
void PopPos(SLNode** pplist, SLDataType x, SLNode* pos) {
	assert(pos);
	if (*pplist == pos) {
		*pplist = pos->next;
		free(pos);
		pos = NULL;
	}
	else {
		SLNode* prev = *pplist;
		while (prev->next != NULL) {
			prev = prev->next;
		}
		prev->next = pos->next;
		free(pos);
		pos = NULL;
	}
}
void PopAfterPos(SLDataType x, SLNode* pos){
	assert(pos);//删除的节点不为空
	assert(pos->next != NULL);//不为最后一个结点的位置
	SLNode* after = pos->next;
	pos->next = after->next;
	free(after);
	after = NULL;
}
//判空
bool EmptySL(SLNode** pplist) {
	assert(*pplist);
	return *pplist == NULL;
}
//判断有效元素的个数
int SizeSL(SLNode** pplist) {
	int count = 0;
	SLNode* cur = *pplist;
	while (cur->next != NULL) {
		count++;
		cur = cur->next;
	}
	return count;
}
void PrintSL(SLNode** pplist) {
	SLNode* cur = *pplist;
	while (cur->next != NULL) {
		printf("%d -> ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}