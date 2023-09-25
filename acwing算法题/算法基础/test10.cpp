//836. 合并集合
#include <iostream>
using namespace std;

const int N = 1e5 + 10;
int fa[N];
int n, m;

int Get(int x) {
    if (x == fa[x]) {
        return x;
    }
    return fa[x] = Get(fa[x]);
}

void merge(int x, int y) {
    fa[Get(x)] = Get(y);
}

int main() {
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {  
        fa[i] = i;
    }

    while (m--) {
        char op[2];
        int a, b;
        cin >> op >> a >> b;
        if (op[0] == 'M') {
            // if (Get(a) != Get(b)) {
            //     merge(a, b);
            // }
            merge(a, b);
        }
        else {
            cout << (Get(a) == Get(b) ? "Yes" : "No") << endl;
        }
    }
    return 0;
}

//837. 连通块中点的数量
#include<iostream>
using namespace std;

const int N = 100010;
int p[N], cnt[N];

int find(int x)
{
    if (p[x] != x)return p[x] = find(p[x]);
    return p[x];
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)p[i] = i, cnt[i] = 1;
    while (m--)
    {
        char op[5];
        int a, b;
        cin >> op;
        if (*op == 'C')
        {
            cin >> a >> b;
            if (find(a) != find(b))
            {
                cnt[find(b)] += cnt[find(a)];
                p[find(a)] = find(b);
            }
        }
        else if (op[1] == '1')
        {
            cin >> a >> b;
            if (find(a) == find(b))puts("Yes");
            else puts("No");
        }
        else
        {
            cin >> a;
            cout << cnt[find(a)] << endl;
        }
    }
}
