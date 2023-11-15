//889. 满足条件的01序列
#include <algorithm>
#include <iostream>

using namespace std;

typedef long long ll;

const int N = 1e5 + 10, mod = 1e9 + 7;

int quick_power(int a, int k, int p)
{
    int res = 1 % p;
    while (k) {
        if (k & 1) {
            res = (ll)res * a % p;
        }
        k >>= 1;
        a = (ll)a * a % p;
    }
    return res;
}

int main() {
    int n;
    cin >> n;

    int a = n * 2, b = n;
    int res = 1;
    for (int i = a; i > a - b; i--) {
        res = (ll)res * i % mod;
    }

    for (int i = 1; i <= b; i++) {
        res = (ll)res * quick_power(i, mod - 2, mod) % mod;
    }

    res = (ll)res * quick_power(n + 1, mod - 2, mod) % mod;

    cout << res << endl;

    return 0;
}




//890. 能被整除的数
#include <iostream>
using namespace std;

int n, m;
const int N = 20;
int p[N], ans;

void dfs(int u, int cnt, int res)
{
    if (u == m)
    {
        if (!cnt) return;
        if (cnt % 2 == 0) ans -= res;
        else ans += res;
        return;
    }

    dfs(u + 1, cnt + 1, res / p[u]);
    dfs(u + 1, cnt, res);
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++) scanf("%d", &p[i]);
    dfs(0, 0, n);
    cout << ans;
}

