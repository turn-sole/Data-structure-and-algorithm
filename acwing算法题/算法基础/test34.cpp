//893. 集合 - Nim游戏
#include <iostream>
#include<unordered_set>
#define N 110
#define M 10010
using namespace std;

int n, m;
int s[N];
int f[M];

int sg(int x)
{
    if (f[x] != -1) return f[x];

    unordered_set<int> S;
    for (int i = 0; i < n; ++i)
    {
        int sum = s[i];
        if (x >= sum) S.insert(sg(x - sum));
    }

    for (int i = 0; ; ++i)
        if (!S.count(i))
            return f[x] = i;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> s[i];

    memset(f, -1, sizeof f);

    int res = 0;
    cin >> m;
    for (int i = 0, a; i < m; ++i)
    {
        cin >> a;
        res ^= sg(a);
    }

    if (!res)
    {
        cout << "No";
        return 0;
    }
    cout << "Yes";
}




//894. 拆分 - Nim游戏
#include<iostream>
#include<cstring>
#include<unordered_set>

using namespace std;

const int N = 110;

int f[N], a[N];
int n;

int SG(int x)
{
    if (f[x] != -1) return f[x];

    unordered_set<int> S; 
    for (int i = 0; i < x; i++)
        for (int j = 0; j <= i; j++)
            S.insert(SG(i) ^ SG(j));

    // mex
    for (int i = 0;; i++)
    {
        if (!S.count(i)) return f[x] = i;
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    memset(f, -1, sizeof f);

    int res = 0;
    for (int i = 0; i < n; i++)
        res ^= SG(a[i]);

    if (res) puts("Yes");
    else puts("No");

    return 0;
}

