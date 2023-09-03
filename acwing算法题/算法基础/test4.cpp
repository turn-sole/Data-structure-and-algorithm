//2816. 判断子序列
#include<iostream>
#include<cstdio>
using namespace std;
const int N = 1e5 + 10;
int a[N], b[N];
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    for (int j = 0; j < m; j++) scanf("%d", &b[j]);

    int i = 0;
    for (int j = 0; j < m; j++)
    {
        if (i < n && a[i] == b[j])  i++;
    }
    if (i == n) puts("Yes");
    else puts("No");
    return 0;
}



//801. 二进制中1的个数
#include<iostream>
using namespace std;
int lowbit(int x) {
    return x & (-x);
}
int main() {
    int n;
    cin >> n;
    while (n--) {
        int x;
        cin >> x;

        int res = 0;
        while (x) x -= lowbit(x), res++;

        cout << res << ' ';
    }
    return 0;
}