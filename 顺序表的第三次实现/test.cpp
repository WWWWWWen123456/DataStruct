#define _CRT_SECURE_NO_WARNINGS 1 
#include"sequenceList.h"

void test() {
	SL s;
	SLInit(&s);//初始化
	SLDestroy(&s);//销毁

	SLInsert(&s, 1, 0);
	SLInsert(&s, 2, 0);
	SLInsert(&s, 3, 0);
	SLInsert(&s, 4, 0);
	SLInsert(&s, 5, 0);
	SLPrint(&s);

	//尾插检测
	SLPushBack(&s, 9);
	SLPushBack(&s, 9);
	SLPushBack(&s, 9);
	SLPushBack(&s, 9);
	SLPushBack(&s, 9);
	SLPushBack(&s, 9);
	SLPushBack(&s, 9);
	SLPrint(&s);

	//头插
	SLPushFront(&s, 8);
	SLPushFront(&s, 8);
	SLPushFront(&s, 8);
	SLPushFront(&s, 8);
	SLPushFront(&s, 8);
	SLPrint(&s);
	//任意位置删除
	SLErase(&s, 0);
	SLErase(&s, 0);
	SLErase(&s, 0);
	SLErase(&s, 0);
	SLErase(&s, 0);
	SLErase(&s, 0);
	SLErase(&s, 0);
	SLErase(&s, 0);
	SLErase(&s, 0);
	SLPrint(&s);
	//尾删
	SLPopBack(&s);
	SLPopBack(&s);
	SLPopBack(&s);
	SLPopBack(&s);
	SLPopBack(&s);
	SLPrint(&s);
	//头删
	SLPopFront(&s);
	SLPopFront(&s);
	SLPrint(&s);
		
}

int main() {
	test();
	return 0;
}