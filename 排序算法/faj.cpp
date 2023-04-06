// 冒泡排序
void BubbleSort(int* a, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (a[j] > a[j + 1])
			{
				int tmp = a[j];
				a[j] = a[j+1];
				a[j + 1] = tmp;
			}
		}
	}
}

// 快速排序递归实现
// 快速排序hoare版本
void Swap(int *p, int *q)
{
	int tmp = *p;
	*p = *q;
	*q = tmp;
}
int part(int* a, int left, int right)
{
	int mid = (left + right) / 2;
	if (a[left] < a[mid])
	{
		if (a[mid] < a[right])
		{
			return mid;
		}
		else if (a[left] > a[right])
		{
			return left;
		}
		else
		{
			return right;
		}
	}
	else 
	{
		if (a[mid] > a[right])
		{
			return mid;
		}
		else if (a[left] < a[right])
		{
			return left;
		}
		else
		{
			return right;
		}
	}
}
int PartSort1(int* a, int left, int right)
{
	int mid = part(a, left, right);
	if (mid != left)
		Swap(&a[mid], &a[left]);
	int origin = left;
	while (left < right)
	{
		while (right > 0 && a[right] > a[0])
		{
			--right;
		}
		while (a[left] < a[0])
		{
			++left;
		}
		swap(&a[left], &a[right]);
	}
	swap(&a[origin], a[right]);
	origin = left;
	return origin;
}
// 快速排序挖坑法
int PartSort2(int* a, int left, int right)
{
	int origin = a[left];
	while (left < right)
	{
		while (a[right] >= origin)
		{
			--right;
		}
		a[left] = a[right];
		while (a[left] <= origin)
		{
			++left;
		}
		a[right] = a[left];
	}
	a[left] = origin;
	return left;
}
// 快速排序前后指针法
int PartSort3(int* a, int left, int right)
{
	int mid = part(a, left, right);
	if (mid != left)
		Swap(&a[mid], &a[left]);
	int origin = left;
	int prev = left;
	int cur = left + 1;
	while (cur <= right)
	{
		if (a[cur] < a[origin] && ++prev != cur)
			Swap(&a[cur], &a[prev]);
		++cur;
	}
	Swap(&a[prev], &a[origin]);
	origin = prev;
	return origin;
}
void QuickSort(int* a, int left, int right)
{
	if (left >= right)
		return;
	int keyi = PartSort3(a, left, right);
	QuickSort(a, left, keyi - 1);
	QuickSort(a, keyi + 1, right);
}

// 快速排序 非递归实现
void QuickSortNonR(int* a, int left, int right) {
	stack<int> stk;
	if (left < right) {
		stk.push(left);
		stk.push(right);
	}
	while (!stk.empty()) {
		int right = stk.top();
		stk.pop();
		int left = stk.top();
		stk.pop();
		int mid = PartSort3(a, left, right); 
		if (left < mid - 1) {
			stk.push(left);
			stk.push(mid - 1);
		}
		if (mid + 1 < right) {
			stk.push(mid + 1);
			stk.push(right);
		}
	}
}
