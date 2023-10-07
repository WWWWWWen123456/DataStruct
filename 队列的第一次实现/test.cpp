#define _CRT_SECURE_NO_WARNINGS 1 
#include"Queue.h"

void test() {
	Queue q;
	InitQueue(&q);
	PushQueue(&q, 1);
	PushQueue(&q, 2);
	PushQueue(&q, 3);
	PushQueue(&q, 4);
	PushQueue(&q, 5);
	PrintQueue(&q);
	PopQueue(&q);
	PrintQueue(&q);
	PopQueue(&q);
	PrintQueue(&q);
	PopQueue(&q);
	PrintQueue(&q);
	PopQueue(&q);
	PrintQueue(&q);
	PopQueue(&q);
	PrintQueue(&q);
	DestoryQueue(&q);
	
	
}

int main() {
	test();
	return 0;
}