//799. 最长连续不重复子序列
# include <iostream>
using namespace std;

const int N = 100010;
int a[N], s[N];

int main()
{
    int n, r = 0;
    cin >> n;

    for (int i = 0, j = 0; i < n; ++i)
    {
        cin >> a[i];
        ++s[a[i]];
        while (s[a[i]] > 1) --s[a[j++]]; 
        r = max(r, i - j + 1);
    }
    cout << r;

    return 0;
}

//800. 数组元素的目标和
#include <iostream>
#include <cstdio>
using namespace std;

const int N = 1e5 + 10;

int n, m, k;
int a[N], b[N];
#define read(x) scanf("%d",&x)

int main()
{
    read(n), read(m), read(k);
    for (int i = 0; i < n; i++) read(a[i]);
    for (int i = 0; i < m; i++) read(b[i]);

    for (int i = 0, j = m - 1; i < n; i++) {
        while (j >= 0 && a[i] + b[j] > k) j--;
        if (j >= 0 && a[i] + b[j] == k) printf("%d %d\n", i, j);
    }
    return 0;
}
