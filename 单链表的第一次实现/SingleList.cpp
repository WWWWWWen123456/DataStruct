#define _CRT_SECURE_NO_WARNINGS 1 
#include"SingleList.h"
//一般指针修改是从后往前进行修改 要不有些修改了就会导致找不到后一个结点的位置
//功能函数
void PrintSL(SLNode** pplistnode) {
	assert(pplistnode);

	SLNode* cur = *pplistnode;
	while (cur->next != NULL) {
		printf("%d ->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}
SLNode* BuyListNode(SLDataType x) {
	SLNode* node =(SLNode*) malloc(sizeof(SLNode));
	assert(node);
	
	node->data = x;
	node->next = NULL;

	return node;
}
//插入
void PushFrontSL(SLNode** pplistnode, SLDataType x) {
	assert(pplistnode);

	SLNode* node = BuyListNode(x);//创建一个结点
	node->next = *pplistnode;//改变指向链接到最开始的位置
	*pplistnode = node;//改变头指针

}
void PushBackSL(SLNode** pplistnode, SLDataType x) {
	assert(pplistnode);
	
	//创建一个结点
	SLNode* node = BuyListNode(x);
	//如果是空链表 避免对空指针解引用
	if (*pplistnode == NULL) {
		*pplistnode = node;
	}
	else {
		//找尾
		SLNode* tail = *pplistnode;
		while (tail->next != NULL) {
			tail = tail->next;
		}
		//将结点接入链表 并且释放结点
		node->next = tail->next;
		tail->next = node;
	}
}
void InsertBeforeNode(SLNode** pplistnode, SLDataType x, SLNode* pos) {
	assert(pplistnode&&pos);
	//创建新结点
	SLNode* node=BuyListNode(x);
	//如果插入的位置是头结点的位置 那么相当于头插 因为后者循环根本进不去
	if (pos==*pplistnode) {
		node->next = pos;
		*pplistnode = node;
	}
	else {
		//找到插入位置的前一个位置
		SLNode* prev = *pplistnode;
		while (prev->next != pos) {
			prev = prev->next;
		}
		node->next = pos;
		prev->next = node;
	}
}
//在特定结点之后和之前插入就没有空链表这种情况的判定了
void InsertAfterNode(SLNode** pplistnode, SLDataType x, SLNode* pos) {
	assert(pplistnode);
	SLNode* node = BuyListNode(x);//创建一个结点
	node->next = pos->next;
	pos->next = node;
}
//删除
void PopFrontSL(SLNode** pplistnode) {
	assert(pplistnode);
	if (*pplistnode == NULL) {
		return;//空节点不能删除
	}
	else {
		SLNode* tmp = *pplistnode;
		*pplistnode = (*pplistnode)->next;
		free(tmp);
		tmp = NULL;
	}
	
}
void PopBackSL(SLNode** pplistnode) {
	assert(pplistnode);
	//凡是涉及到prev的都要检查是否只有一个结点或者头结点
	//链表为空
	if (*pplistnode == NULL) {
		return;
	}
	//只有一个结点
	else if ((*pplistnode)->next == NULL) {
		free(*pplistnode);
		*pplistnode = NULL;
	}
	else {
		SLNode* prev = *pplistnode;
		SLNode* tail = prev->next;
		while (tail->next != NULL) {
			prev = tail;
			tail = tail->next;
		}
		prev->next = tail->next;
		free(tail);
		tail = NULL;
	}
}
void ErasePosSL(SLNode** pplistnode,SLNode* pos){
	assert(pos && pplistnode);//该位置不能为空
	//如果删除的是头结点
	if (pos==*pplistnode) {
		*pplistnode = (*pplistnode)->next;
		free(pos);
		pos = NULL;
	}
	else {
		SLNode* prev = *pplistnode;
		while (prev->next != pos) {
			prev = prev->next;	
		}
		prev->next = pos->next;
		free(pos);
		pos = NULL;
	}
}
void EraseAfterPosSL(SLNode* pos) {
	assert(pos);//该位置不能为空 
	//如果是最后一个结点就不删除了
	if (pos->next == NULL) {
		return;
	}
	else {
		SLNode* after = pos->next;
		pos->next = after->next;
		free(after);
		after = NULL;
	}

}
//查找
SLNode* FindNode(SLNode** pplistnode, SLDataType x) {
	SLNode* cur = *pplistnode;
	while (cur != NULL) {
		if (cur->data == x) {
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
	
}
//修改数据
void ModifyNode(SLNode* pos, SLDataType x) {
	assert(pos);
	pos->data = x;
}