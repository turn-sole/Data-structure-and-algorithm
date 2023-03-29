// �ѵĹ���
void AdjustDown(HPDataType* a, int n, int parent)
{
	int child = parent * 2 + 1;
	while (child < n)
	{
		if (child+1<n&&a[child + 1] > a[child])
		{
			++child;
		}
		if (a[child] > a[parent])
		{
			Swap(&a[child] = &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}
void HeapCreate(Heap* hp, HPDataType* a, int n)
{
	assert(hp);
	hp->a = (HPDataType*)malloc(sizeof(HPDataType) * a);
	if (hp->a == NULL)
	{
		perror("malloc fail");
		return;
	}
	hp->size = n;
	hp->capacity = n;
	for (int i = (n - 2) / 2; i >= 0; i--)
	{
		AdjustDown(ph->a, ph->size, i);
	}
}
// �ѵ�����
void HeapDestory(Heap* hp)
{
	assert(hp);
	free(hp->a);
	hp->a=NULL;
	hp->capacity = hp->size = 0;
}
// �ѵĲ���
void Swap(HPDataType* p1, HPDataType* p2)
{
	HPDataType x = *p1;
	*p1 = *p2;
	*p2 = x;
}
void AdjustUp(HPDataType* a, int child)
{
	int parent = (child - 1) / 2;
	while (child > 0)
	{
		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}
void HeapPush(Heap* hp, HPDataType x)
{
	assert(ph);
	if (ph->size == ph->capacity)
	{
		HPDataType* tmp = (HPDataType*)realloc(ph->a, sizeof(HPDataType) * ph->capacity * 2);
		if (tmp == NULL)
		{
			perror("realloc fail");
			return;
		}
		ph->a = tmp;
		ph->capacity *= 2;
	}
	ph->a[ph->size] = x;
	ph->size++;
	AdjustUp(ph->a, ph->size - 1);
}
// �ѵ�ɾ��
void HeapPop(Heap* hp)
{
	assert(hp);
	assert(!HeapEmpty(hp));
	Swap(&hp->a[0], &hp->a[hp->size - 1]);
	hp->size--;
	AdjustDown(hp->a, hp->size, 0);
}
// ȡ�Ѷ�������
HPDataType HeapTop(Heap* hp)
{
	assert(hp);
	return hp->a[0];
}
// �ѵ����ݸ���
int HeapSize(Heap* hp)
{
	assert(hp);
	return hp->size;
}
// �ѵ��п�
int HeapEmpty(Heap* hp)
{
	assert(ph);
	return ph->size;
}

// TopK���⣺�ҳ�N�����������/��С��ǰK�����⡣
// ���磺δ��������ǰ10�����ɣ�������ͨ��ѧ������ҫ����ǰ10�ĺ��ţ�ȫ������ǰ10����ס��ȵ����ⶼ��Topk���⣬
// ��Ҫע�⣺
// ������ǰK��������K������С��
// ����С��ǰK��������K�����Ĵ��
void PrintTopK(int* a, int n, int k)
{
	int* topk = (int*)malloc(sizeof(int) * k);
	assert(topk);
	for (int i = 0; i < k; ++i)
	{
		topk[i] = a[i];
	}
	for (int i = (k - 2) / 2; i >= 0; --i)
	{
		AdjustDown(topk, k, i);
	}
	for (int j = k; j < n; j++)
	{
		if (a[j] > topk[0])
		{
			topk[0] = a[j];
			AdjustDown(topk, k, 0);
		}
	}
	for (int i = 0; i < k; i++)
	{
		printf("%d ", topk[i]);
	}
	printf("\n");
}
void TestTopk()
{
	int n = 10000;
	int* a = (int*)malloc(sizeof(int) * n);
	srand(time(0));
	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % 10000;
	}
	PrintTopK(a, n, k);
}
// ��������ж�����
void HeapSort(int* a, int n)
{
	for (int i = (n - 1 - 1) / 2; i >= 0; --i)
	{
		AdjustDown(a, n, i);
	}
}
