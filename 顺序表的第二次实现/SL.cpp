#define _CRT_SECURE_NO_WARNINGS 1 
#include"SL.h"
//初始化销毁和打印
void InitSL(SL* ps) {
	assert(ps);//指针判空

	ps->a = NULL;
	ps->size = ps->capacity = 0;//初始化
}
void DestroySL(SL* ps) {
	assert(ps);

	free(ps->a);
	ps->a = NULL;
	ps->size = ps->capacity = 0;
}
void PrintSL(SL* ps) {
	assert(ps);
	//遍历
	for (int i = 0; i < ps->size; i++) {
		printf("%d ", ps->a[i]);
	}
	printf("\n");
}

void CheckCapacity(SL* ps) {
	assert(ps);
	//如果size和capacity相等说明不能再放入元素了，也就是说容量达到了上限
	if (ps->size == ps->capacity) {
		int newCapacity = ps->capacity == 0 ? 4 : 2 * ps->capacity;
		SLDataType* tmp = (SLDataType*)realloc(ps->a, sizeof(SLDataType) * newCapacity);
		assert(tmp);

		ps->capacity = newCapacity;
		ps->a = tmp;
		printf("扩容成功\n");
	}

	
}
void PushBackSL(SL* ps, SLDataType x) {
	assert(ps);
	CheckCapacity(ps);
	ps->a[ps->size] = x;
	ps->size++;
}
void PushFrontSL(SL* ps, SLDataType x) {
	assert(ps);
	CheckCapacity(ps);
	//从后往前把前一个位置的数据移动到后一个位置
	for (int i = ps->size - 1; i >= 0; i--) {
		ps->a[i+1] = ps->a[i];
	}
	ps->a[0] = x;

	ps->size++;
}
void InsertSL(SL* ps, SLDataType x, int pos) {
	assert(ps);

	CheckCapacity(ps);
	for (int i = ps->size - 1; i >= pos; i--) {
		ps->a[i + 1] = ps->a[i];
	}
	ps->a[pos] = x;

	ps->size++;
}

void PopBackSL(SL* ps) {
	assert(ps);
	assert(ps->size > 0);

	ps->size--;
}
void PopFrontSL(SL* ps) {
	assert(ps);
	assert(ps->size > 0);

	if (ps->size == 1) {
		ps->size--;
	}
	//从前往后移动覆盖 后一个位置的元素覆盖前一个位置
	for (int i = 0; i < ps->size; i++) {
		ps->a[i] = ps->a[i+1];
	}

	ps->size--;
}
void EraseSL(SL* ps, int pos) {
	assert(ps);
	assert(pos >= 0 && pos < ps->size);

	for (int i = pos; i < ps->size; i++) {
		ps->a[i] = ps->a[i+1];
	}
	
	ps->size--;
}

int FindSL(SL* ps, SLDataType x) {
	assert(ps);

	for (int i = 0; i < ps->size; i++) {
		if (ps->a[i] == x) return i;
	}

	return -1;
}
void ModifySL(SL* ps, int pos, SLDataType x) {
	assert(ps);
	assert(pos >= 0 && pos < ps->size);

	ps->a[pos] = x;

}