#include"List.h"

void TestList1()
{
	LTNode* plist = LTInit();
	LTPushBack(plist, 1);
	LTPushBack(plist, 2);
	LTPushBack(plist, 3);
	LTPushBack(plist, 4);
	LTPrint(plist);

	LTPopBack(plist);
	LTPopBack(plist);
	LTPrint(plist);

	LTPushFront(plist, 1);
	LTPushFront(plist, 2);
	LTPushFront(plist, 3);
	LTPushFront(plist, 4);
	LTPrint(plist);
}

int main()
{
	TestList1();

	return 0;
}