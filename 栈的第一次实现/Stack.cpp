#define _CRT_SECURE_NO_WARNINGS 1 
#include"Stack.h"

void InitStack(Stack* ps) {
	assert(ps);//指针解引用操作 因此判空

	ps->a = NULL;
	//top标识元素的下一个位置相当于顺序表中的size
	ps->top = ps->capacity = 0;
}
void DestroyStack(Stack* ps) {
	assert(ps);

	free(ps->a);
	ps->a = NULL;
	ps->top = ps->capacity = 0;
}
void PushStack(Stack* ps, StackDataType x)
{
	assert(ps);
	//容量检测
	if (ps->top == ps->capacity) {
		int newCapacity = ps->capacity == 0 ? 4 : 2 * ps->capacity;
		StackDataType* tmp = (StackDataType*)realloc(ps->a, sizeof(StackDataType) * newCapacity);
		assert(tmp);

		ps->capacity = newCapacity;
		ps->a = tmp;
		printf("扩容成功\n");
	}

	ps->a[ps->top] = x;
	ps->top++;
}
void PopStack(Stack* ps) {
	assert(ps);
	assert(ps->top > 0);//不为空才能出栈

	ps->top--;
}
StackDataType TopStack(Stack* ps) {
	assert(ps);
	assert(ps->top > 0);

	int pos = ps->top - 1;
	return ps->a[pos];
}
bool EmptyStack(Stack* ps) {
	assert(ps);

	return ps->top == 0;//为0则空 返回true 否则false
}
int SizeStack(Stack* ps){
	assert(ps);

	return ps->top;
}