//835. Trie字符串统计
#include<iostream>
using namespace std;
const int N = 1e5 + 10;
int trie[N][26], q[N], idx;
void insert(string x)
{
    int p = 0;
    for (int i = 0; x[i]; i++)
    {
        int word = x[i] - 'a';
        if (!trie[p][word]) trie[p][word] = ++idx;
        p = trie[p][word];
    }
    q[p]++;
}
int query(string x)
{
    int p = 0;
    for (int i = 0; x[i]; i++)
    {
        int word = x[i] - 'a';
        if (!trie[p][word]) return 0;
        p = trie[p][word];
    }
    return q[p];
}
int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        char op[2];
        cin >> op;
        string word;
        cin >> word;
        if (op[0] == 'I')
            insert(word);
        else
            cout << query(word) << endl;
    }
}


//143. 最大异或对
#include <iostream>

using namespace std;

const int N = 1e5 + 10, M = 31 * N;

int ne[M][2], a[N], idx = 1;

void insert(int x)
{
    int u = 0;
    for (int i = 30; i >= 0; i--)
    {
        int v = x >> i & 1;
        if (!ne[u][v]) ne[u][v] = idx++;
        u = ne[u][v];
    }
}

int query(int x)
{
    int u = 0, res = 0;
    for (int i = 30; i >= 0; i--)
    {
        int v = x >> i & 1;
        if (ne[u][!v])
        {
            u = ne[u][!v];
            res = res * 2 + !v;
        }
        else
        {
            u = ne[u][v];
            res = res * 2 + v;
        }
    }
    return res;
}

int main()
{
    int n, res = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        insert(a[i]);
        res = max(res, query(a[i]) ^ a[i]);
    }

    cout << res << endl;

    return 0;
}

