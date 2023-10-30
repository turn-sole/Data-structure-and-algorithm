//858. Prim算法求最小生成树
#include<iostream>
#include<cstring>

using namespace std;
const int N = 510, INF = 0x3f3f3f3f;
int dist[N], g[N][N];
int n, m;
bool st[N];
int res = 0;

int prim() {
    memset(dist, 0x3f, sizeof dist);

    for (int i = 0; i < n; i++) {

        int t = -1;
        for (int j = 1; j <= n; j++) {
            if (!st[j] && (t == -1 || dist[j] < dist[t])) {
                t = j;
            }
        }

        if (i && dist[t] == INF) return INF;//
        st[t] = true;

        if (i) res += dist[t];//

        for (int j = 1; j <= n; j++) {
            dist[j] = min(dist[j], g[t][j]);//
        }
    }

    return res;

}

int main() {
    memset(g, 0x3f, sizeof g);
    cin >> n >> m;
    //
    for (int i = 0; i < m; i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        g[a][b] = g[b][a] = min(g[a][b], c);
    }

    int t = prim();
    if (t == INF) puts("impossible");
    else cout << t << endl;
}



//859. Kruskal算法求最小生成树
#include<iostream>
#include<algorithm>

using namespace std;
const int N = 1e5 + 10, M = 2e5 + 10, INF = 0x3f3f3f3f;
int n, m;
int p[N];

struct Edge {
    int a, b, w;

    bool operator<(const Edge& e) const {
        return w < e.w;
    }
} es[M];

int find(int x) {
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int kruskal() {
    int cnt = 0, res = 0;

    sort(es, es + m);

    for (int i = 1; i <= n; i++) p[i] = i;

    for (int i = 0; i < m; i++) {
        int a = es[i].a, b = es[i].b, w = es[i].w;
        a = find(a), b = find(b);
        if (a != b) {
            p[a] = b;
            res += w;
            cnt++;
        }
    }

    if (cnt < n - 1) return INF;
    else return res;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, w;
        scanf("%d%d%d", &a, &b, &w);
        es[i] = { a, b, w };
    }

    int t = kruskal();
    if (t == INF) cout << "impossible";
    else cout << t;
}

