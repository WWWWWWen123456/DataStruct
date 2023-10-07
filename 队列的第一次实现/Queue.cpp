#define _CRT_SECURE_NO_WARNINGS 1 
#include"Queue.h"

void InitQueue(Queue* pq) {
	assert(pq);

	pq->head = pq->tail = NULL;
	pq->size = 0;
}
void DestoryQueue(Queue* pq) {
	assert(pq);
	QNode* cur = pq->head;
	while (cur) {
		QNode* next = cur->next;
		free(cur);
		cur = NULL;
		cur = next;
	}
	pq->head = pq->tail = NULL;
}
void PushQueue(Queue* pq, QueueDataType x) {
	assert(pq);
	//创建新的结点
	QNode* newnode = (QNode*)malloc(sizeof(QNode));
	assert(newnode);
	newnode->data = x;
	newnode->next = NULL;
	//插入第一个（防止空指针的解引用)
	if (pq->head == NULL) {
		pq->head = pq->tail = newnode;
	}
	//正常情况插入
	else {
		//改变指向
		pq->tail->next = newnode;
		//改变尾结点
		pq->tail = newnode;
	}
	pq->size++;
}
void PopQueue(Queue* pq) {
	assert(pq);
	//1 为空不能删除
	assert(!EmptyQueue(pq));
	//2 如果是只有一个结点 防止尾结点被释放后的解引用
	if (pq->head->next==NULL) {
		free(pq->head);
		pq->head = pq->tail = NULL;
	}
	//3 正常情况删除
	else {
	QNode* next = pq->head->next;
	free(pq->head);
	pq->head = next;
	}
	pq->size--;
}
void PrintQueue(Queue* pq) {
	assert(pq);
	QNode* cur = pq->head;
	while (cur) {
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}
QueueDataType FrontQueue(Queue* pq) {
	assert(pq);
	return pq->head->data;
}
QueueDataType BackQueue(Queue* pq) {
	assert(pq);
	return pq->tail->data;
}
bool EmptyQueue(Queue* pq) {
	assert(pq);
	return pq->tail == NULL;//head或者tail一个为NULL即可
}
int SizeQueue(Queue* pq) {
	assert(pq);
	return pq->size;
}