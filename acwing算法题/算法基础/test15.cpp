//845. 八数码
#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_map>

using namespace std;

int bfs(string start) {

    string end = "12345678x";
    queue<string> q;
    unordered_map<string, int> d;

    q.push(start);
    d[start] = 0;

    int dx[4] = { -1,0,1,0 }, dy[4] = { 0,1,0,-1 };


    while (q.size()) {
        auto t = q.front();
        q.pop();

        if (t == end) return d[t];

        int dis = d[t];
        int k = t.find('x');
        int x = k / 3, y = k % 3;

        for (int i = 0; i < 4; i++) {
            int a = x + dx[i], b = y + dy[i];
            if (a >= 0 && a < 3 && b >= 0 && b < 3) {
                swap(t[k], t[a * 3 + b]);

                if (!d.count(t)) {
                    d[t] = dis + 1;
                    q.push(t);
                }

                swap(t[k], t[a * 3 + b]);
            }
        }
    }

    return -1;
}

int main() {
    string start;
    for (int i = 0; i < 9; i++) {
        char num;
        cin >> num;
        start += num;
    }
    cout << bfs(start) << endl;
    return 0;
}


//846. 树的重心
#include<iostream>
using namespace std;
#define pb push_back
int n, a, b, m = 1e7;
bool st[100010];

vector<int> e[100010];

int dfs(int u)
{
    int res = 1, t, h = 0;
    st[u] = 1;
    for (auto x : e[u]) if (!st[x]) t = dfs(x), res += t, h = max(h, t);
    h = max(h, n - res);
    m = min(m, h);
    return res;
}

int main()
{
    cin >> n;
    for (int i = 1; i < n; i++) cin >> a >> b, e[a].pb(b), e[b].pb(a);
    dfs(1);
    cout << m;
}
