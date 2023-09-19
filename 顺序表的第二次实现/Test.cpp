#define _CRT_SECURE_NO_WARNINGS 1 
#include"SL.h"

void test() {
	SL s;
	InitSL(&s);


	PushBackSL(&s, 1);
	PushBackSL(&s, 1);
	PushBackSL(&s, 1);
	PushBackSL(&s, 1);
	PushBackSL(&s, 1);
	PushBackSL(&s, 1);
	PushBackSL(&s, 1);
	PushBackSL(&s, 1);
	PushBackSL(&s, 1);
	PushBackSL(&s, 1);
	PushBackSL(&s, 1);
	PushBackSL(&s, 1);
	PrintSL(&s);

	PushFrontSL(&s, 1);
	PushFrontSL(&s, 2);
	PushFrontSL(&s, 1);
	PushFrontSL(&s, 2);
	PushFrontSL(&s, 1);
	PushFrontSL(&s, 2);
	PushFrontSL(&s, 1);
	PushFrontSL(&s, 2);
	PrintSL(&s);

	InsertSL(&s, 9, 3);
	InsertSL(&s, 9, 3);
	InsertSL(&s, 9, 3);
	InsertSL(&s, 9, 3);
	InsertSL(&s, 9, 3);
	InsertSL(&s, 9, 3);
	InsertSL(&s, 9, 3);
	PrintSL(&s);

	PopBackSL(&s);
	PopBackSL(&s);
	PopBackSL(&s);
	PopBackSL(&s);
	PopBackSL(&s);
	PopBackSL(&s);
	PopBackSL(&s);
	PopBackSL(&s);
	PopBackSL(&s);
	PopBackSL(&s);
	PopBackSL(&s);
	PopBackSL(&s);
	PopBackSL(&s);
	PopBackSL(&s);
	PopBackSL(&s);
	PopBackSL(&s);
	PopBackSL(&s);
	PopBackSL(&s);
	PopBackSL(&s);
	PopBackSL(&s);
	PopBackSL(&s);
	PopBackSL(&s);
	PopBackSL(&s);
	PopBackSL(&s);
	PopBackSL(&s);
	PrintSL(&s);

	printf("找到对应元素的下表位置是：%d \n",FindSL(&s, 1));
	ModifySL(&s, 1, 9);
	PrintSL(&s);
	DestroySL(&s);
}

int main() {
	test();
	return 0;
}