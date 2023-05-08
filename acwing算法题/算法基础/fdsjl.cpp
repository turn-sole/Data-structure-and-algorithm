//788. 逆序对的数量

#include<iostream>

using namespace std;
typedef long long ll;

const int N = 100010;
int a[N];
int b[N];

ll calculate(int l, int r)
{
    if (l >= r)
        return 0;
    int mid = l + r >> 1;
    ll res = calculate(l, mid) + calculate(mid + 1, r);

    int k = 0, i = l, j = mid + 1;
    while (i <= mid && j <= r)
    {
        if (a[i] <= a[j])
        {
            b[k++] = a[j++];
        }
        else
        {
            b[k++] = a[j++];
            res += mid - i + 1;
        }
    }

    while (i <= mid)
    {
        b[k++] = a[i++];
    }
    while (j <= r)
    {
        b[k++] = a[j++];
    }

    for (int i = l, j = 0; i <= r; i++, j++)
    {
        a[i] = b[j];
    }

    return res;
}
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int count = calculate(0, n - 1);
    cout << count << endl;
    return 0;
}