#define _CRT_SECURE_NO_WARNINGS 1 
#include"Stack.h"

void InitStack(Stack* ps) {
	assert(ps);
	ps->a = NULL;
	ps->capacity = ps->top = 0;
}
void DestroyStack(Stack* ps) {
	assert(ps);
	free(ps->a);
	ps->a = NULL;
	ps->capacity = ps->top = 0;

}
void Print(Stack* ps) {
	assert(ps);
	for (int i = 0; i < ps->top; i++) {
		printf("%d ", ps->a[i]);
	}
	printf("\n");
}
void CheckCapacity(Stack* ps) {
	assert(ps);
	if (ps->capacity == ps->top) {
		int newcapacity = ps->capacity == 0 ? 4 : 2 * ps->capacity;
		StackDataType* tmp = (StackDataType*)realloc(ps->a, sizeof(StackDataType) * newcapacity);
		assert(tmp);

		ps->capacity = newcapacity;
		ps->a = tmp;
		printf("À©ÈÝ³É¹¦\n");
	}
	
}
void Push(Stack* ps, StackDataType x) {
	assert(ps);
	CheckCapacity(ps);
	ps->a[ps->top] = x;
	ps->top++;
}
void Pop(Stack* ps) {
	assert(ps);
	assert(!Empty(ps));
	ps->top--;
}
bool Empty(Stack* ps) {
	assert(ps);
	return ps->top == 0;
}
int Size(Stack* ps) {
	assert(ps);
	return ps->top - 1;
}