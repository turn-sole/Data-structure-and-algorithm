//787. πÈ≤¢≈≈–Ú
#include<iostream>
using namespace std;
int a[100000];
int q[100000];
void mergesort(int a[], int l, int r)
{
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
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d ", &a[i]);
    }
    mergesort(a, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}
