//240.  ≥ŒÔ¡¥
#include <iostream>
#include <cstdio>
using namespace std;
int n, k, ans = 0;
int fa[150010]; 
int find(int x) {
    if (fa[x] != x) return fa[x] = find(fa[x]);
    return fa[x];
}
int main() {
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= 3 * n; i++)
        fa[i] = i; 
    while (k--) {
        int op, x, y;
        scanf("%d%d%d", &op, &x, &y);
        if (x > n || y > n) { ans++; continue; }
        if (op == 1) {
            if (find(x) == find(y + n)) {
                ans++;
                continue;
            }
            if (find(x) == find(y + 2 * n)) {
                ans++;
                continue;
            }
            fa[find(y)] = find(x);
            fa[find(y + n)] = find(x + n);
            fa[find(y + 2 * n)] = find(x + 2 * n);
        }
        if (op == 2) {
            if (x == y) { ans++; continue; }
            if (find(x) == find(y)) { ans++; continue; }
            if (find(x) == find(y + 2 * n)) {
                ans++;
                continue;
            }
            fa[find(x)] = find(y + n);
            fa[find(y)] = find(x + 2 * n);
            fa[find(x + n)] = find(y + 2 * n);
        }

    }
    printf("%d", ans);
    return 0;
}


//838. ∂—≈≈–Ú
#include<iostream> 
#include<algorithm>

using namespace std;

const int N = 100010;

int h[N], mySize;

int n, m;

void down(int u)
{
    int t = u;
    if (2 * u <= mySize && h[t] > h[2 * u])
        t = 2 * u;
    if (2 * u + 1 <= mySize && h[t] > h[2 * u + 1])
        t = 2 * u + 1;
    if (u != t)
    {
        swap(h[u], h[t]);
        down(t);
    }
}

int main()
{
    cin >> n >> m;
    mySize = n;
    for (int i = 1; i <= n; i++)
        scanf("%d", &h[i]);
    for (int i = n / 2; i; i--)
        down(i);

    while (m--)
    {
        cout << h[1] << " ";
        h[1] = h[mySize--];
        down(1);
    }

    return 0;
}