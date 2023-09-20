#define _CRT_SECURE_NO_WARNINGS 1 
#include"sequenceList.h"

void SLInit(SL* ps) {
	assert(ps);//指针判空

	ps->a = NULL;
	ps->size = ps->capacity = 0;//初始化
}
void SLDestroy(SL* ps) {
	assert(ps);

	free(ps->a);
	ps->a = NULL;//避免空指针
	ps->size = ps->capacity = 0;
}
void CheckCapacity(SL* ps) {
	//如果size和capacity的值相等 说明容量达到了上限 如果再次插入就会超过capacity 因此需要进行扩容
	if (ps->size == ps->capacity) {
		int newCapacity = ps->capacity == 0 ? 4 : 2 * ps->capacity;//1 刚开始capacity为0特殊处理 2 二倍扩容
		SLDataType* tmp = (SLDataType*)realloc(ps->a, sizeof(SLDataType) * newCapacity);
		assert(tmp);//扩容失败则直接终止 没有足够的内存操作了

		ps->capacity = newCapacity;
		ps->a = tmp;
		printf("扩容成功！\n");
	}
}
void SLPrint(SL* ps) {
	assert(ps);

	for (int i = 0; i < ps->size; i++) {
		printf("%d ", ps->a[i]);
	}

	printf("\n");
}
void SLInsert(SL* ps, SLDataType x,int pos) {
	assert(ps);

	CheckCapacity(ps);
	//从后往前移动元素 将元素整体移动到后一个位置
	for (int i = ps->size - 1; i >= pos; i--) {
		ps->a[i+1] = ps->a[i];
	}
	ps->a[pos] = x;//插入数据

	ps->size++;
}
void SLPushBack(SL* ps, SLDataType x) {
	
	SLInsert(ps, x, ps->size);
}
void SLPushFront(SL* ps, SLDataType x) {
	SLInsert(ps, x, 0);
}
void SLErase(SL* ps,int pos) {
	assert(ps);
	assert(pos >= 0 && pos < ps->size);

	//从前往后移动数据 用后一个位置的数据覆盖前一个位置
	for (int i = pos; i < ps->size; i++) {
		ps->a[i] = ps->a[i+1];
	}

	ps->size--;

}
void SLPopBack(SL* ps) {
	SLErase(ps, ps->size - 1);
}
void SLPopFront(SL* ps) {
	SLErase(ps, 0);
}