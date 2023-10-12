#define _CRT_SECURE_NO_WARNINGS 1 
#include"Sequence.h"

void test() {
	Sequence s;
	InitSequence(&s);
	PushFront(&s, 1);
	PushFront(&s, 2);
	PushFront(&s, 3);
	PushFront(&s, 4);
	PushFront(&s, 5);
	Print(&s);
	PushBack(&s, 1);
	PushBack(&s, 1);
	PushBack(&s, 1);
	PushBack(&s, 1);
	PushBack(&s, 1);
	Print(&s);
	Insert(&s, 8, 3);
	Print(&s);
	Erase(&s, 3);
	Print(&s);
	DestroySequence(&s);
}

int main() {
	test();
	return 0;
}