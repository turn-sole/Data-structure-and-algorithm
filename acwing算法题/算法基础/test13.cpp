//841. ×Ö·û´®¹şÏ£
#include <algorithm>
#include <iostream>

using namespace std;

typedef unsigned long long ULL;

const int N = 1e5 + 10, P = 131;

int n, m;
char str[N];
ULL h[N], p[N];

ULL get(int l, int r) {
    return h[r] - h[l - 1] * p[r - l + 1];
}

int main() {
    cin >> n >> m;
    cin >> (str + 1);
    p[0] = 1;  // p^0 =1;
    for (int i = 1; i <= n; i++) {
        h[i] = h[i - 1] * P + str[i];
        p[i] = p[i - 1] * P;
    }

    while (m--) {
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        if (get(l1, r1) == get(l2, r2)) {
            puts("Yes");
        }
        else {
            puts("No");
        }
    }
    return 0;
}

//842. ÅÅÁĞÊı×Ö
#include <iostream>

using namespace std;

const int N = 10;

int n;
int path[N]; 

void dfs(int u, int state)
{
    if (u == n) 
    {
        for (int i = 0; i < n; i++) printf("%d ", path[i]); 
        puts(""); 

        return;
    }

    for (int i = 0; i < n; i++)
        if (!(state >> i & 1)) 
        {
            path[u] = i + 1;
            dfs(u + 1, state + (1 << i)); 
        }
}

int main()
{
    scanf("%d", &n);

    dfs(0, 0);

    return 0;
}
