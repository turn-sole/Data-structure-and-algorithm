//876. 快速幂求逆元
#include<iostream>

using namespace std;

typedef long long LL;

int qmi(int a, int b, int p)
{
    int res = 1;
    while (b)
    {
        if (b & 1) res = (LL)res * a % p;
        a = (LL)a * a % p;
        b >>= 1;
    }

    return res;
}

int main()
{
    int n;
    cin >> n;

    while (n--)
    {
        int a, p;
        cin >> a >> p;

        if (a % p) cout << qmi(a, p - 2, p) << endl;
        else cout << "impossible" << endl;
    }

    return 0;
}



//877. 扩展欧几里得算法
#include <iostream>
using namespace std;
void exgcd(int a, int b, int& x, int& y) {
    if (!b) {
        x = 1, y = 0;
        return;
    }
    exgcd(b, a % b, y, x);
    y -= a / b * x;
}

int main() {
    int n;
    scanf("%d", &n);
    while (n--) {
        int a, b, x, y;
        scanf("%d %d", &a, &b);
        exgcd(a, b, x, y);
        printf("%d %d\n", x, y);
    }
}
