#define _CRT_SECURE_NO_WARNINGS 1 
#include"Sequence.h"

void InitSequence(Sequence* ps) {
	assert(ps);
	ps->a = NULL;
	ps->size = ps->capacity = 0;
	printf("初始化成功！\n");
}
void DestroySequence(Sequence* ps) {
	assert(ps);
	free(ps->a);
	ps->a = NULL;
	ps->capacity = ps->size = 0;
	printf("清理成功！\n");
}
void Print(Sequence* ps) {
	assert(ps);
	for (int i = 0; i < ps->size; i++) {
		printf("%d ", ps->a[i]);
	}
	printf("\n");
}
void CheckCapacity(Sequence* ps) {
	assert(ps);
	if (ps->size == ps->capacity) {
		int newcapacity = ps->capacity == 0 ? 4 : 2 * ps->capacity;
		SDataType* tmp = (SDataType*)realloc(ps->a, sizeof(SDataType)*newcapacity);
		assert(tmp);
		ps->capacity = newcapacity;
		ps->a = tmp;
		printf("扩容成功！\n");
	}
	
}
void PushFront(Sequence* ps, SDataType x) {
	Insert(ps, x, 0);
}
void PushBack(Sequence* ps, SDataType x) {
	Insert(ps, x, ps->size);
}
void Insert(Sequence* ps, SDataType x, int pos) {
	assert(ps);
	/*if (ps->size == ps->capacity) {
		int newcapacity = ps->capacity == 0 ? 4 : 2 * ps->capacity;
		SDataType* tmp = (SDataType*)realloc(ps->a, sizeof(SDataType) * newcapacity);
		assert(tmp);
		ps->a = tmp;
		ps->capacity = newcapacity;
		printf("扩容成功！\n");
	}*/
	CheckCapacity(ps);
	for (int i = ps->size-1; i >= pos; i--) {
		ps->a[i + 1] = ps->a[i];
	}
	ps->a[pos] = x;
	ps->size++;
}

void PopFront(Sequence* ps) {
	/*assert(ps);
	assert(!Empty(ps));
	for (int i = 0; i < ps->size - 1; i++) {
		ps->a[i] = ps->a[i + 1];
	}
	ps->size--;*/
	Erase(ps, 0);
}
void PopBack(Sequence* ps) {
	/*assert(ps);
	assert(!Empty(ps));
	ps->size--;*/
	Erase(ps, ps->size - 1);
}
void Erase(Sequence* ps,int pos) {
	assert(ps);
	assert(!Empty(ps));
	assert(pos >= 0 && pos < ps->size);

	for (int i = pos; i < ps->size; i++) {
		ps->a[i] = ps->a[i + 1];
	}
	ps->size--;
}

bool Empty(Sequence* ps) {
	assert(ps);
	return ps->size == 0;
}
int Size(Sequence* ps) { 
	assert(ps);
	return ps->size;
}