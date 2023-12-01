//104. 货仓选址
#include <iostream>
#include<algorithm>
using namespace std;
int a[100001], n, i, c, s;
int main()
{
    cin >> n;
    for (i = 1; i <= n; i++)cin >> a[i];
    sort(a + 1, a + 1 + n);
    s = a[n / 2 + 1];
    for (i = 1; i <= n; i++)c += abs(a[i] - s);
    cout << c;
}




//125. 耍杂技的牛
#include <iostream>
#include <algorithm>
#define N 50005
#define inf 2000000000
using namespace std;

struct Node
{
    int w, s;
    bool operator < (Node x)
    {
        return w + s < x.w + x.s;
    }
}   a[N];

int n, sum, ans = -inf;

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].w >> a[i].s;
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++)
    {
        ans = max(ans, sum - a[i].s), sum += a[i].w;
    }
    cout << ans;
    return 0;
}

