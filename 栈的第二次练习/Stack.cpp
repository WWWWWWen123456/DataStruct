#define _CRT_SECURE_NO_WARNINGS 1 
#include"Stack.h"

void InitStack(st* ps) {
	assert(ps);

	ps->a = NULL;
	ps->top = ps->capacity = 0;
}

void DestroyStack(st* ps) {
	assert(ps);

	free(ps->a);
	ps->a = NULL;
	ps->top = ps->capacity = 0;
}

void PrintStack(st* ps) {
	assert(ps);

	for (int i = 0; i < ps->top; i++) {
		printf("%d ", ps->a[i]);
	}
	printf("\n");
}
void PushStack(st* ps, StackDataType x) {
	assert(ps);
	//À©ÈÝ
	if (ps->top == ps->capacity) {
		int newCapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		StackDataType* tmp = (StackDataType*)realloc(ps->a, sizeof(StackDataType) * newCapacity);
		assert(tmp);

		ps->capacity = newCapacity;
		ps->a = tmp;

		printf("À©ÈÝ³É¹¦\n");
	}

	ps->a[ps->top] = x;
	ps->top++;
}
void PopStack(st* ps) {
	assert(ps);
	assert(ps->top > 0);

	ps->top--;
}
StackDataType TopStack(st* ps) {
	assert(ps);
	assert(ps->top > 0);

	return ps->a[ps->top - 1];
}
int SizeStack(st* ps) {
	assert(ps);

	return ps->top;
}
bool EmptyStack(st* ps) {
	assert(ps);

	return ps->top > 0;
}