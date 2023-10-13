//853. 有边数限制的最短路
#include<iostream>
using namespace std;
const int N = 100010;
int dist[N], backup[N];
int k, n, m;
struct edge {
    int a; int b; int w;
}edge[N];
int bellman_ford()
{
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    for (int i = 1; i <= k; i++)
    {
        memcpy(backup, dist, sizeof dist);
        for (int j = 1; j <= m; j++)
        {
            int a = edge[j].a, b = edge[j].b, w = edge[j].w;
            dist[b] = min(dist[b], backup[a] + w);
        }
    }
    return dist[n];
}
int main()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edge[i].a = a, edge[i].b = b, edge[i].w = c;
    }
    int t = bellman_ford();
    if (t >= 0x3f3f3f3f / 2)puts("impossible");
    else cout << t << endl;
}


//851. spfa求最短路
#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>

using namespace std;
const int N = 1e5 + 10;
int h[N], e[N], w[N], ne[N], idx;
int n, m;
queue<int> q;
int st[N], dist[N];

void add(int a, int b, int c) {
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

int spfa() {
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    q.push(1);
    st[1] = true;
    while (q.size()) {
        int t = q.front();
        q.pop();
        st[t] = false;
        for (int i = h[t]; i != -1; i = ne[i]) {
            int j = e[i];
            if (dist[j] > dist[t] + w[i]) {
                dist[j] = dist[t] + w[i];
                if (!st[j]) {
                    st[j] = true;
                    q.push(j);
                }
            }
        }
    }
    if (dist[n] > 0x3f3f3f3f / 2) return -1;
    else return dist[n];
}

int main() {
    memset(h, -1, sizeof h);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        add(a, b, c);
    }
    int t = spfa();
    if (t == -1) cout << "impossible" << endl;
    else cout << t << endl;
}
