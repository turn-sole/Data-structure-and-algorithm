//900. 整数划分
#include <iostream>

using namespace std;

const int N = 1010, mod = 1e9 + 7;

int n;
int a[N];
int f[N];

int main()
{
    cin >> n;
    f[0] = 1;

    for (int i = 1; i <= n; i++)
        for (int j = i; j <= n; j++)
            f[j] = (f[j] + f[j - i]) % mod;

    cout << f[n] << endl;
    return 0;
}




//338. 计数问题
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int front(vector<int> a, int l, int r)
{
    int res = 0;
    for (int i = l; i >= r; i--)
        res = res * 10 + a[i];
    return res;
}

int pow_10(int x)
{
    int res = 1;
    while (x--)res *= 10;
    return res;
}

int dp(int n, int x)
{
    vector<int> c;
    while (n)c.push_back(n % 10), n /= 10;

    int res = 0;
    for (int i = c.size() - 1 - (x == 0); i >= 0; i--)
    {
        if (i != c.size() - 1) {
            res += front(c, c.size() - 1, i + 1) * pow_10(i);
            if (!x) res -= pow_10(i);
        }
        if (c[i] == x) res += front(c, i - 1, 0) + 1;
        else if (c[i] > x)res += pow_10(i);
    }
    return res;
}

int main()
{
    int a, b;
    while (cin >> a >> b, a || b)
    {
        if (a > b)swap(a, b);
        for (int i = 0; i < 10; i++)
            cout << dp(b, i) - dp(a - 1, i) << ' ';
        puts("");
    }
    return 0;
}

