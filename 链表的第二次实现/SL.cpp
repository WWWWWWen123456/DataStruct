#define _CRT_SECURE_NO_WARNINGS 1 
#include"SL.h"

//创建结点
SLNode* BuyNode(SLDataType x) {
	SLNode* newnode = (SLNode*)malloc(sizeof(SLDataType));
	assert(newnode);
	newnode->next = NULL;
	newnode->data = x;
	return newnode;
}
//插入
void PushBack(SLNode** pplist, SLDataType x) {
	assert(pplist);
	//创建一个新的结点
	SLNode* newnode = BuyNode(x);
	//防止对空指针的解引用
	if(*pplist==NULL){
		//如果是空链表直接将结点接入
		*pplist = newnode;
	}
	else {
		//如果是有数据的找到尾巴后链接进去
		SLNode* tail = *pplist;
		while (tail->next != NULL) {
			tail = tail->next;
		}
		tail->next = newnode->next;
	}
}
void PushFront(SLNode** pplist, SLDataType x) {
	assert(pplist);

	SLNode* newnode = BuyNode(x);//创建一个结点
	newnode->next = *pplist;
	*pplist = newnode;
}
void InsertAfterPos(SLNode** pplist, SLNode* pos, SLDataType x) {
	assert(pplist);
	SLNode* newnode = BuyNode(x);//创建一个结点
	//如果为NULL链表 直接插入
	if (*pplist==NULL) {
		*pplist = newnode;
	}
	else {
		newnode->next = pos->next;
		pos->next = newnode;
	}

}
void InsertBeforePos(SLNode** pplist, SLNode* pos, SLDataType x) {
	assert(pos && pplist);

	SLNode* newnode = BuyNode(x);//创建一个结点
	
	//如果是头结点（包含了只有一个结点的情况） 避免对空指针的解引用 相当于头插
	if(pos==*pplist){
		newnode->next = *pplist;
		*pplist = newnode;
	}
	else {
		SLNode* prev = *pplist;
		while (prev->next != pos) {
			prev = prev->next;
		}
		newnode->next = prev->next;
		prev->next = newnode;
	}
}
//删除
void PopBack(SLNode** pplist) {
	assert(*pplist);//链表不能为空
	//如果只有一个结点
	if ((*pplist)->next == NULL) {
		free(*pplist);
		*pplist = NULL;
	}
	else {
		SLNode* prev = *pplist;
		SLNode* tail = prev->next;
		//找尾
		while (tail->next != NULL) {
			prev = tail;
			tail = tail->next;
		}
		prev->next = tail->next;
		free(tail);
		tail = NULL;
	}

}
void PopFront(SLNode** pplist) {
	assert(*pplist);//该链表不能为空
	//本质上是改变头结点会找不到之前的位置 因为有两种方法记录
	//1记录新的头
	/*SLNode* newhead = *pplist;
	newhead = (*pplist)->next;
	free(*pplist);
	*pplist = NULL;
	*pplist=newhead;*/

	//2记录之前释放的位置
	SLNode* tmp = *pplist;
	*pplist = (*pplist)->next;
	free(tmp);
	tmp = NULL;
}
//要头指针因为要pos之前的结点
void ErasePos(SLNode** pplist, SLNode* pos) {
	assert(pos && (*pplist));//不为空链表并且该位置不为空

	if((*pplist)==pos){
		*pplist = pos->next;//头重新定义
		free(pos);
		pos = NULL;
	}
	else {
		SLNode* prev = *pplist;
		while (prev->next != pos) {
			prev = prev->next;
		}
		prev->next = pos->next;
		free(pos);
		pos = NULL;
	}
}
//不需要头指针 因为只用找pos之后的
void EraseAfterPos(SLNode* pos) {
	assert(pos);//该链表不能为空
	//只有一个结点 直接删除该节点
	if (pos->next == NULL) {
		free(pos);
		pos = NULL;
	}
	else {
		SLNode* next = pos->next;
		pos->next = next->next;
		free(next);
		next = NULL;
	}
}
//查找
SLNode* FindNode(SLNode** pplist, SLDataType x) {
	assert(*pplist);

	while (( * pplist)->next != NULL) {
		if ((*pplist)->data == x) {
			return *pplist;
		}
	}
	return NULL;
}
//修改指定位置的值
//不需要头指针
void ModifyNode(SLNode* pos, SLDataType x) {
	assert(pos);
	pos->data = x;
}