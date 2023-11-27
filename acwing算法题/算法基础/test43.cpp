//285. 没有上司的舞会
#include <iostream>
#include <cstring>

using namespace std;

const int N = 6010;

int e[N], ne[N], h[N], idx;
int happy[N];
int n;
bool has_fa[N];
int f[N][2];

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void dfs(int u)
{
    f[u][1] = happy[u];

    for (int i = h[u]; ~i; i = ne[i])
    {
        int j = e[i];
        dfs(j);

        f[u][1] += f[j][0];
        f[u][0] += max(f[j][0], f[j][1]);
    }
}

int main()
{
    cin >> n;

    for (int i = 1; i <= n; i++)    cin >> happy[i];

    memset(h, -1, sizeof h);

    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> b >> a;
        has_fa[b] = true;
        add(a, b);
    }

    int root = 1;
    while (has_fa[root]) root++;

    dfs(root);

    printf("%d\n", max(f[root][0], f[root][1]));
    return 0;
}





//901. 滑雪
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

const int N = 3e2 + 10;

int n, m;
int g[N][N];
int f[N][N];

int dx[4] = { -1, 0, 1, 0 }, dy[4] = { 0, 1, 0, -1 };

int dp(int x, int y)
{
    int& v = f[x][y];
    if (v != -1) {
        return v;
    }

    v = 1;
    for (int i = 0; i < 4; i++) {
        int a = x + dx[i], b = y + dy[i];
        if (a >= 1 && a <= n && b >= 1 && b <= m && g[x][y] > g[a][b]) {
            v = max(v, dp(a, b) + 1);
        }
    }
    return v;
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> g[i][j];
        }
    }
    memset(f, -1, sizeof f);

    int res = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            res = max(res, dp(i, j));
        }
    }
    cout << res << endl;
    return 0;
}

