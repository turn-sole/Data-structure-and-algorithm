//291. 蒙德里安的梦想
#include <cstring>
#include <iostream>

using namespace std;

const int N = 1e1 + 2, M = 1 << N;

typedef long long ll;

int n, m;
ll dp[N][M];  
bool st[M];

int main()
{
    while (cin >> n >> m, n || m) {
        for (int i = 0; i < 1 << n; i++) {
            int cnt = 0;
            st[i] = true;
            for (int j = 0; j < n; j++) {
                if (i >> j & 1) {
                    if (cnt & 1) {
                        st[i] = false;
                    }
                    cnt = 0;
                }
                else {
                    cnt++;
                }
            }
            if (cnt & 1) {
                st[i] = false;
            }
        }
        memset(dp, 0, sizeof dp);
        dp[0][0] = 1;
        for (int i = 1; i <= m; i++) {
            for (int j = 0; j < 1 << n; j++) {
                for (int k = 0; k < 1 << n; k++) {
                    if ((j & k) == 0 && st[j | k]) {
                        dp[i][j] += dp[i - 1][k];
                    }
                }
            }
        }
        cout << dp[m][0] << endl;
    }
    return 0;
}




//91. 最短Hamilton路径
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 20;
int w[N][N], f[1 << N][N];


int main()
{
    int n; cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &w[i][j]);

    memset(f, 0x3f, sizeof f);
    f[1][0] = 0;
    for (int i = 0; i < 1 << n; i++)
        for (int j = 0; j < n; j++)
            if (i & (1 << j))
                for (int k = 0; k < n; k++)
                    if ((i - (1 << j)) & (1 << k))
                        f[i][j] = min(f[i][j], f[i - (1 << j)][k] + w[k][j]);

    cout << f[(1 << n) - 1][n - 1] << endl;

    return 0;
}

