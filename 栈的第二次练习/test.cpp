#define _CRT_SECURE_NO_WARNINGS 1 

#include"Stack.h"

void test() {
	st s;
	InitStack(&s);
	PushStack(&s, 1);
	PushStack(&s, 2);
	PushStack(&s, 3);
	PushStack(&s, 4);
	PushStack(&s, 5);
	PrintStack(&s);

	PopStack(&s);
	PopStack(&s);
	PopStack(&s);
	PrintStack(&s);

	printf("栈顶元素是：%d \n",TopStack(&s));
	printf("栈内元素个数有：%d 个\n", SizeStack(&s));
	
	if (EmptyStack(&s)) printf("栈不为空\n");
	else printf("栈为空\n");

	DestroyStack(&s);
}

int main() {
	test();
	return 0;
}