#include < vector >
#include<iostream>
#include <algorithm>
using namespace std;
// 归并排序递归实现
void mergesort(int* a, int l, int r)
{
    int q[100000];
    if (l >= r)
        return;
    int mid = (l + r) >> 1;
    mergesort(a, l, mid);
    mergesort(a, mid + 1, r);
    int k = 0, i = l, j = mid + 1;
    while (i <= mid && j <= r)
    {
        if (a[i] <= a[j])
            q[k++] = a[i++];
        else
            q[k++] = a[j++];
    }
    while (i <= mid)
    {
        q[k++] = a[i++];
    }
    while (j <= r)
    {
        q[k++] = a[j++];
    }
    for (i = l, j = 0; i <= r; i++, j++)
    {
        a[i] = q[j];
    }
}
void MergeSort(int* a, int n)
{
    int l = 0;
    int r = n - 1;
    mergesort(a, l, r);
}
// 归并排序非递归实现
void MergeSortNonR(int* a, int n)
{
    int step = 1;
    while (step < n) 
    {
        int left = 0;
        while (left + step < n) 
        {
            int mid = left + step - 1;
            int right = mid + step;
            if (right >= n) 
            {
                right = n - 1;
            }
            Merge(a, left, mid, right);
            left = right + 1;
        }
        step *= 2;
    }
}
// 计数排序
void CountSort(int* a, int n)
{
    if (n <= 1) 
    {
        return;
    }
    int max_val = a[0], min_val = a[0];
    for (int i = 1; i < n; ++i) 
    {
        if (a[i] > max_val) 
        {
            max_val = a[i];
        }
        if (a[i] < min_val) 
        {
            min_val = a[i];
        }
    }
    int count_size = max_val - min_val + 1;
    int* count = new int[count_size];
    memset(count, 0, count_size * sizeof(int));
    for (int i = 0; i < n; ++i) 
    {
        count[a[i] - min_val]++;
    }
    for (int i = 1; i < count_size; ++i) 
    {
        count[i] += count[i - 1];
    }
    int* temp = new int[n];
    for (int i = n - 1; i >= 0; --i) 
    {
        temp[count[a[i] - min_val] - 1] = a[i];
        count[a[i] - min_val]--;
    }
    memcpy(a, temp, n * sizeof(int));
    delete[] count;
    delete[] temp;
}