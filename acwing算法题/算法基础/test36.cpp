//4. 多重背包问题 I
#include <iostream>

using namespace std;

int n, m, f[110];

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int v, w, s;
        cin >> v >> w >> s;
        for (int j = m; j >= v; j--)
            for (int k = 0; k <= s; k++)
                if (j >= k * v)
                    f[j] = max(f[j], f[j - k * v] + k * w);
    }
    cout << f[m];

    return 0;
}





//5. 多重背包问题 II
#include <iostream>

using namespace std;

int n, m, f[2010];

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int v, w, s;
        cin >> v >> w >> s;
        for (int k = 1; k <= s; k <<= 1)
        {
            for (int j = m; j >= v * k; j--) f[j] = max(f[j], f[j - v * k] + w * k);
            s -= k;
        }
        if (s)
            for (int j = m; j >= v * s; j--)
                f[j] = max(f[j], f[j - v * s] + w * s);
    }
    cout << f[m];

    return 0;
}

