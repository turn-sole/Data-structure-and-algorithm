//9. 分组背包问题
#include <iostream>

using namespace std;

const int N = 110;
int v[N][N], w[N][N], f[N], s[N], n, m;

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
        for (int j = 0; j < s[i]; j++)
            cin >> v[i][j] >> w[i][j];
    }
    for (int i = 0; i < n; i++)
        for (int j = m; j >= 0; j--)
            for (int k = 0; k <= s[i]; k++)
                if (j >= v[i][k])
                    f[j] = max(f[j], f[j - v[i][k]] + w[i][k]);
    cout << f[m];

    return 0;
}





//898. 数字三角形
#include <iostream>
using namespace std;
int n, a[510][510];
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= n + 1; j++)a[i][j] = -10000000;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= i; j++) {
            cin >> a[i][j];
            a[i][j] += max(a[i - 1][j], a[i - 1][j - 1]);
        }
    int ans = -10000000;
    for (int i = 1; i <= n; i++)ans = max(ans, a[n][i]);
    cout << ans;
}

