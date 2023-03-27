typedef int DataType;
struct TreeNode
{
	struct TreeNode* firstChild1;
	struct TreeNode* pNextBrother;
	DataType data;
};
#define _CRT_SECURE_NO_WARNINGS 1
#include "Heap.h"

//int main()
//{
//	HP hp;
//	HeapInit(&hp);
//	HeapPush(&hp, 4);
//	HeapPush(&hp, 18);
//	HeapPush(&hp, 42);
//	HeapPush(&hp, 12);
//	HeapPush(&hp, 21);
//	HeapPush(&hp, 3);
//	HeapPush(&hp, 5);
//	HeapPush(&hp, 5);
//	HeapPush(&hp, 50);
//	HeapPush(&hp, 5);
//	HeapPush(&hp, 5);
//	HeapPush(&hp, 15);
//	HeapPush(&hp, 5);
//	HeapPush(&hp, 45);
//	HeapPush(&hp, 5);
//
//	int k = 0;
//	scanf("%d", &k);
//	while (!HeapEmpty(&hp) && k--)
//	{
//		printf("%d ", HeapTop(&hp));
//		HeapPop(&hp);
//	}
//	printf("\n");
//
//	return 0;
//}

// ������ -- ����� -- O(N*logN)
void HeapSort(int* a, int n)
{
	// ���� -- ���ϵ������� -- O(N*logN)
	/*for (int i = 1; i < n; ++i)
	{
		AdjustUp(a, i);
	}*/

	// ���� -- ���µ������� -- O(N)
	for (int i = (n - 1 - 1) / 2; i >= 0; --i)
	{
		AdjustDown(a, n, i);
	}

	// �Լ���ʵ�� -- O(N*logN)
	int end = n - 1;
	while (end > 0)
	{
		Swap(&a[end], &a[0]);
		AdjustDown(a, end, 0);

		--end;
	}
}

void PrintTopK(const char* file, int k)
{
	// 1. ����--��a��ǰk��Ԫ�ؽ�С��
	int* topk = (int*)malloc(sizeof(int) * k);
	assert(topk);

	FILE* fout = fopen(file, "r");
	if (fout == NULL)
	{
		perror("fopen error");
		return;
	}

	// ����ǰk�����ݽ�С��
	for (int i = 0; i < k; ++i)
	{
		fscanf(fout, "%d", &topk[i]);
	}

	for (int i = (k - 2) / 2; i >= 0; --i)
	{
		AdjustDown(topk, k, i);
	}

	// 2. ��ʣ��n-k��Ԫ��������Ѷ�Ԫ�ؽ��������������滻
	int val = 0;
	int ret = fscanf(fout, "%d", &val);
	while (ret != EOF)
	{
		if (val > topk[0])
		{
			topk[0] = val;
			AdjustDown(topk, k, 0);
		}

		ret = fscanf(fout, "%d", &val);
	}

	for (int i = 0; i < k; i++)
	{
		printf("%d ", topk[i]);
	}
	printf("\n");

	free(topk);
	fclose(fout);
}

void CreateNDate()
{
	// ������
	int n = 10000000;
	srand(time(0));
	const char* file = "data.txt";
	FILE* fin = fopen(file, "w");
	if (fin == NULL)
	{
		perror("fopen error");
		return;
	}

	for (size_t i = 0; i < n; ++i)
	{
		int x = rand() % 10000;
		fprintf(fin, "%d\n", x);
	}

	fclose(fin);
}

int main()
{
	//int a[10] = { 2, 1, 5, 7, 6, 8, 0, 9, 4, 3}; // ����������
	//HeapSort(a, 10);

	CreateNDate();
	//PrintTopK("data.txt", 10);

	return 0;
}