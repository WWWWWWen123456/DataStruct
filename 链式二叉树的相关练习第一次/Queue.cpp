#define _CRT_SECURE_NO_WARNINGS 1 
#include"Queue.h"

void InitQueue(Queue* pq) {
	assert(pq);

	pq->head = pq->tail = NULL;
	pq->size = 0;
	printf("初始化成功！\n");
}
void DestroyQueue(Queue* pq) {
	assert(pq);

	QNode* cur = pq->head;
	while (cur) {
		pq->head = cur->next;
		free(cur);
		cur = NULL;
		cur = pq->head;
	}
	printf("清理成功！\n");
}
//void PrintQueue(Queue* pq) {
//	assert(pq);
//
//	QNode* cur = pq->head;
//	while (cur) {
//		printf("%c ", cur->data);
//		cur = cur->next;
//	}
//	printf("\n");
//}
void PushQueue(Queue* pq, QueueDataType x) {
	assert(pq);
	//创建新节点
	QNode* newnode = (QNode*)malloc(sizeof(QNode));
	assert(newnode);
	newnode->next = NULL;
	newnode->data = x;
	if (pq->tail == NULL) {
		pq->head = pq->tail = newnode;
	}
	else {
		pq->tail->next = newnode;
		pq->tail = newnode;
	}
}
void PopQueue(Queue* pq) {
	assert(pq);
	assert(!EmptyQueue(pq));//为空不能删除
	if (pq->head->next == NULL) {
		free(pq->tail);
		pq->tail = pq->head = NULL;
	}
	else {
		QNode* cur = pq->head;
		pq->head = cur->next;
		free(cur);
		cur = NULL;
	}
	pq->size--;
}
QueueDataType FrontQueue(Queue* pq) {
	assert(pq);
	assert(!EmptyQueue(pq));
	return pq->head->data;
}
QueueDataType BackQueue(Queue* pq) {
	assert(!EmptyQueue(pq));
	assert(pq);
	return pq->tail->data;
}
int SizeQueue(Queue* pq) {
	assert(pq);
	return pq->size;
}
bool EmptyQueue(Queue* pq) {
	assert(pq);
	return pq->tail == NULL;
}