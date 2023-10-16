#define _CRT_SECURE_NO_WARNINGS 1 
#include"SingList.h"

SLNode* BuyListNode(SLDataType x) {
	SLNode* newnode = (SLNode*)malloc(sizeof(SLNode));
	assert(newnode);
	newnode->data = x;
	newnode->next = NULL;
	return newnode;
}
void Print(SLNode** pplist) {
	assert(*pplist);
	SLNode* cur = *pplist;
	while (cur != NULL) {
		printf("%d -> ", cur->data);
		cur = cur->next;
	}
	printf("NULL");
	printf("\n");
}
void DestroyList(SLNode** pplist) {
	assert(*pplist);
	SLNode* cur = *pplist;
	SLNode* next = cur->next;
	while (cur->next!= NULL) {
		free(cur);
		cur = NULL;
		cur = next;
		next = cur->next;
	}
	printf("销毁成功！\n");
}
void PushBack(SLNode** pplist, SLDataType x) {
	assert(*pplist);
	SLNode* newnode = BuyListNode(x);
	if ((*pplist) == NULL) {
		(*pplist) = newnode;
	}
	else {
		SLNode* tail = *pplist;
		while (tail->next != NULL) {
			tail = tail->next;
		}
		tail->next = newnode;
	}
	
}
void PushFront(SLNode** pplist, SLDataType x) {
	assert(*pplist);
	SLNode* newnode = BuyListNode(x);
	newnode->next = *pplist;
	*pplist = newnode;

}
void InsertAfterPos(SLNode** pplist, SLDataType x, SLNode* pos) {
	assert(*pplist);
	assert(pos);
	SLNode* newnode = BuyListNode(x);
	newnode->next = pos;
	pos->next = newnode;
}
void InsertBeforePos(SLNode** pplist, SLDataType x, SLNode* pos) {
	assert(*pplist);
	assert(pos);
	SLNode* newnode = BuyListNode(x);
	if (pos==*pplist) {
		newnode->next = *pplist;
		*pplist = newnode;
	}
	else {
		SLNode* prev = *pplist;
		while (prev->next != pos) {
			prev = prev->next;
		}
		prev->next = newnode;
		newnode->next = pos;
	}
}
void PopBack(SLNode** pplist) {
	assert(*pplist);
	assert(!Empty(pplist));
	if ((*pplist)->next == NULL) {
		free(*pplist);
		*pplist = NULL;
	}
	else {
		SLNode* prev = *pplist;
		SLNode* tail = prev->next;
		while (tail->next != NULL) {
			prev = tail;
			tail = tail->next;
		}
		free(tail);
		tail = NULL;
		prev->next = tail;
	}
}
void PopFront(SLNode** pplist) {
	assert(*pplist);
	assert(!Empty(pplist));
	//记录当前结点的位置
	SLNode* tmp = *pplist;
	*pplist = (*pplist)->next;
	free(tmp);
	tmp = NULL;
}
void PopAfterPos(SLNode** pplist, SLNode* pos) {
	assert(*pplist);
	assert(!Empty(pplist));
	assert(pos->next != NULL);
	SLNode* next = pos->next;
	pos->next = next->next;
	free(next);
	next = NULL;
}
void PopPos(SLNode** pplist, SLNode* pos) {
	assert(pplist);
	assert(pos);
	assert(!Empty(pplist));
	if (pos == (*pplist)) {
		*pplist = pos->next;
		free(pos);
		pos = NULL;
	}
	else {
		SLNode* prev = *pplist;
		while (prev->next != pos) {
			pos = pos->next;
		}
		prev->next = pos -> next;
		free(pos);
		pos = NULL;
	}
}
bool Empty(SLNode** pplist) {
	assert(*pplist);
	return *pplist == NULL;
}
int Size(SLNode** pplist) {
	assert(*pplist);
	SLNode* cur = *pplist;
	int count = 0;
	while (cur->next!= NULL) {
		cur = cur->next;
		count++;
	}
	return count;
}