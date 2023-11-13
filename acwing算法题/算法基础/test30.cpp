//885. 求组合数 I
#include<iostream>
using namespace std;
const int mod = 1e9 + 7, N = 2010;
int n;
int c[N][N];

void init() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= i; j++) {
            if (!j) c[i][j] = 1;
            else c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
        }
    }
}

int main() {
    init();

    cin >> n;
    while (n--) {
        int a, b;
        cin >> a >> b;

        cout << c[a][b] << endl;
    }
}




//886. 求组合数 II
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 1e5 + 10, mod = 1e9 + 7;
typedef long long LL;

LL fact[N], infact[N];

int quick_power(int a, int k, int p) 
{
    int res = 1 % p;
    while (k)
    {
        if (k & 1) res = (LL)res * a % p;
        a = (LL)a * a % p;
        k >>= 1;
    }
    return res;
}


int main()
{
    int n;

    scanf("%d", &n);

    fact[0] = 1; 
    infact[0] = 1;

    for (int i = 1; i <= N; i++)
    {
        fact[i] = (LL)fact[i - 1] * i % mod; 
        infact[i] = (LL)infact[i - 1] * quick_power(i, mod - 2, mod) % mod; 
    }

    while (n--)
    {
        int a, b;
        scanf("%d%d", &a, &b);

        printf("%d\n", (LL)fact[a] * infact[b] % mod * infact[a - b] % mod);
    }
    return 0;
}

