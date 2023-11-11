//878. 线性同余方程
#include<iostream>
using namespace std;
#define int long long
int n, a, b, m, x, y;
void exgcd(int a, int m, int& d, int& x, int& y) {
    if (!m) {
        d = a, x = 1, y = 0;
        return;
    }
    exgcd(m, a % m, d, y, x), y -= a / m * x;
}
int main() {
    scanf("%d", &n);
    while (n--) {
        scanf("%d %d %d", &a, &b, &m);
        int d;
        exgcd(a, m, d, x, y);
        if (b % d) printf("impossible\n");
        else printf("%d\n", x * (b / d) % m);
    }
    return 0;
}



//204. 表达整数的奇怪方式
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
ll exgcd(ll a, ll b, ll& x, ll& y) {
    if (!b) {
        x = 1, y = 0;
        return a;
    }
    ll d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}
int main() {
    int n;
    cin >> n;
    ll x = 0, m1, a1, m2, a2, k1, k2;
    cin >> a1 >> m1;
    for (int i = 0; i < n - 1; i++) {
        cin >> a2 >> m2;
        ll d = exgcd(a1, -a2, k1, k2);
        if ((m2 - m1) % d) {
            x = -1;
            break;
        }
        k1 *= (m2 - m1) / d;
        k1 = (k1 % (a2 / d) + a2 / d) % (a2 / d);
        x = k1 * a1 + m1;
        ll a = abs(a1 / d * a2);
        m1 = k1 * a1 + m1;
        a1 = a;
    }
    if (x != -1) x = (x % a1 + a1) % a1;
    cout << x << endl;
    return 0;
}

