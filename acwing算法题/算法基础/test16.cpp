//847. 图中点的层次
#include <cstring>
#include <iostream>

using namespace std;

const int N = 1e5 + 10;

int h[N], e[N], idx, ne[N];
int d[N]; 
int n, m; 
int q[N];

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

int bfs()
{
    int hh = 0, tt = 0;

    q[0] = 1; 

    memset(d, -1, sizeof d);

    d[1] = 0;

    while (hh <= tt)
    {
        int t = q[hh++];

        for (int i = h[t]; i != -1; i = ne[i])
        {
            int j = e[i];
            if (d[j] == -1)
            {
                d[j] = d[t] + 1; 
                q[++tt] = j;
            }
        }
    }

    return d[n];
}

int main()
{
    cin >> n >> m;
    memset(h, -1, sizeof h);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        add(a, b);
    }

    cout << bfs() << endl;
}


//848. 有向图的拓扑序列
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 100010;
int e[N], ne[N], idx;
int h[N];
int q[N], hh = 0, tt = -1;
int n, m;
int d[N];

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void topsort() {
    for (int i = 1; i <= n; i++) {
        if (d[i] == 0)
            q[++tt] = i;
    }
    while (tt >= hh) {
        int a = q[hh++];
        for (int i = h[a]; i != -1; i = ne[i]) {
            int b = e[i];
            d[b]--;
            if (d[b] == 0)
                q[++tt] = b;
        }
    }
    if (tt == n - 1) {
        for (int i = 0; i < n; i++) {
            cout << q[i] << " ";
        }
    }
    else
        cout << -1;
}


int main() {
    cin >> n >> m;
    memset(h, -1, sizeof h);
    while (m--) {
        int a, b;
        cin >> a >> b;
        d[b]++;
        add(a, b);
    }
    topsort();
    return 0;
}

