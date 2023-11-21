//895. 最长上升子序列
#include<iostream>
using namespace std;
int a[200001], f[200001];
int main()
{
    int i, ans = 0, mx, x, n, j;
    cin >> n;
    f[1] = 1;
    for (i = 1; i <= n; i++)cin >> a[i];
    for (i = 2; i <= n; i++) {
        mx = 0;
        for (j = 1; j <= i - 1; j++) {
            if (a[j] < a[i])mx = max(mx, f[j]);
        }
        f[i] = mx + 1;
    }
    for (i = 1; i <= n; i++)
        ans = max(ans, f[i]);
    cout << ans;
}





//896. 最长上升子序列 II
#include<iostream>
using namespace std;

const int N = 100010;

int n;
int a[N], q[N];

int main()
{
    cin >> n;

    for (int i = 0; i < n; i++) cin >> a[i];

    int len = 0;
    for (int i = 0; i < n; i++)
    {
        int l = 0, r = len;
        while (l < r)
        {
            int mid = l + r + 1 >> 1;
            if (q[mid] < a[i]) l = mid;
            else r = mid - 1;
        }

        len = max(len, r + 1);
        q[r + 1] = a[i];
    }

    cout << len << endl;

    return 0;
}
