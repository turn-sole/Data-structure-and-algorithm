//2. 01背包问题
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1010;
int v[N];
int w[N];
int f[N][N];
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d%d", &v[i], &w[i]);
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            f[i % 2][j] = f[(i - 1) % 2][j];
            if (j >= v[i]) f[i % 2][j] = max(f[i % 2][j], f[(i - 1) % 2][j - v[i]] + w[i]);
        }
    }
    printf("%d", f[n % 2][m]);
    return 0;
}





//3. 完全背包问题
#include <iostream>
using namespace std;
int c[1010], w[1010], dp[1010], n, m;
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d%d", &c[i], &w[i]);
    for (int i = 1; i <= n; i++)
        for (int j = c[i]; j <= m; j++)
            dp[j] = max(dp[j], dp[j - c[i]] + w[i]);
    printf("%d\n", dp[m]);
    return 0;
}

