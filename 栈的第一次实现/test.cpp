#define _CRT_SECURE_NO_WARNINGS 1 
#include"Stack.h"

void test() {
	Stack stack;
	InitStack(&stack);
	PushStack(&stack, 1);
	PushStack(&stack, 2);
	PushStack(&stack, 3);
	PushStack(&stack, 4);
	PushStack(&stack, 5);
	printf("栈内元素个数：%d\n", SizeStack(&stack));
	while (!EmptyStack(&stack)) {
		printf("%d ", TopStack(&stack));
		PopStack(&stack);
	}
	printf("栈内元素个数：%d\n", SizeStack(&stack));
	DestroyStack(&stack);
}

int main() {
	test();
	return 0;
}