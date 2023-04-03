/ ≤Â»Î≈≈–Ú
void InsertSort(int* a, int n)
{
	for (i = 1; i < n; i++)
	{
		int tmp = a[i];
		int j = i - 1;
		while (j >= 0 && a[j] > tmp)
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = tmp;
	}
}

// œ£∂˚≈≈–Ú
void ShellSort(int* a, int n)
{
	int gap = n / 2;
	while (gap > 0)
	{
		for (int i = gap; i < n; i++)
		{
			int tmp = a[i];
			int j = i - gap;
			while (j >= 0 && a[j] > tmp)
			{
				a[j + gap] = a[j];
				j -= gap;
			}
			a[j + gap] = tmp;
		}
		gap /= 2;
	}
}