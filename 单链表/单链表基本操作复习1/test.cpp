#define _CRT_SECURE_NO_WARNINGS 1 
#include"SingList.h"
void test() {
	SLNode* pplist = BuyListNode(-1);
	assert(pplist);
	PushBack(&pplist,1);
	PushBack(&pplist, 2);
	Print(&pplist);
	printf("节点个数:%d ", Size(&pplist));
	PopBack(& pplist);
	PopBack(&pplist);
	Print(&pplist);
}
int main() {
	test();
	return 0;
}