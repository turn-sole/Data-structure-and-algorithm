785. 快速排序
#include<iostream>
using namespace std;
int q[100010];
void quicksort(int q[], int l, int r)
{
    int x = q[(l + r) / 2], i = l - 1, j = r + 1;
    if (l >= r)return;
    while (i < j)
    {
        while (q[++i] < x);
        while (q[--j] > x);
        if (i < j)swap(q[i], q[j]);
    }
    quicksort(q, l, j);
    quicksort(q, j + 1, r);
}
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> q[i];
    quicksort(q, 0, n - 1);
    for (int i = 0; i < n; i++)
        cout << q[i] << " ";
    return 0;
}
786. 第k个数
void quicksort(int q[], int l, int r)
{
    int x = q[(l + r) >> 1], i = l - 1, j = r + 1;
    if (l >= r)return;
    while (i < j)
    {
        while (q[++i] < x);
        while (q[--j] > x);
        if (i < j)swap(q[i], q[j]);
    }
    quicksort(q, l, j);
    quicksort(q, j + 1, r);
}
int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++)
    {
        scanf("%d ", &q[i]);
    }
    quicksort(q, 0, n - 1);
    cout << q[k - 1];
}