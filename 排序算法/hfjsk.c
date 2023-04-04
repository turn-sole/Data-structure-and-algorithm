// —°‘Ò≈≈–Ú
void SelectSort(int* a, int n) 
{
    for (int i = 0; i < n - 1; ++i) 
    {
        int minIndex = i;
        for (int j = i + 1; j < n; ++j) 
        {
            if (a[j] < a[minIndex]) 
            {
                minIndex = j;
            }
        }
        if (minIndex != i) 
        {
            int temp = a[i];
            a[i] = a[minIndex];
            a[minIndex] = temp;
        }
    }
}

// ∂—≈≈–Ú
void AdjustDown(int* a, int n, int root) 
{
    int value = a[root];
    int child = root * 2 + 1;
    while (child < n) 
    {
        if (child + 1 < n && a[child + 1] > a[child]) 
        {
            ++child;
        }
        if (value >= a[child]) 
        {
            break;
        }
        a[root] = a[child];
        root = child;
        child = root * 2 + 1;
    }
    a[root] = value;
}

void HeapSort(int* a, int n) 
{
    for (int i = n / 2 - 1; i >= 0; --i) 
    {
        AdjustDown(a, n, i);
    }
    for (int i = n - 1; i > 0; --i) 
    {
        int temp = a[i];
        a[i] = a[0];
        a[0] = temp;
        AdjustDown(a, i, 0);
    }
}