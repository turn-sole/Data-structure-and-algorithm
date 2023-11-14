//887. 求组合数 III
#include<iostream>
using namespace std;
typedef long long ll;

int qsm(int a, int k, int p) {
    int res = 1;
    while (k) {
        if (k & 1) res = (ll)res * a % p;
        k >>= 1;
        a = (ll)a * a % p;
    }
    return res;
}

int C(int a, int b, int p) {  
    if (b > a) return 0;

    int up = 1, down = 1;  
    for (int i = 1, j = a; i <= b; i++, j--) {
        up = (ll)up * j % p;
        down = (ll)down * i % p;
    }
    return (ll)up * qsm(down, p - 2, p) % p;
}

int lucas(ll a, ll b, int p) {
    if (a < p && b < p) return C(a, b, p) % p;
    else return (ll)C(a % p, b % p, p) * lucas(a / p, b / p, p) % p;
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        ll a, b, p;
        cin >> a >> b >> p;
        cout << lucas(a, b, p) % p << endl;
    }
}





//888. 求组合数 IV
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int N = 5e3 + 10;

int primes[N], cnt;
int sum[N];
bool st[N];

void get_primes(int n)
{
    for (int i = 2; i <= n; i++) {
        if (!st[i]) {
            primes[cnt++] = i;
        }
        for (int j = 0; primes[j] <= n / i; j++) {
            st[primes[j] * i] = true;
            if (i % primes[j] == 0) {
                break;
            }
        }
    }
}

int get(int n, int p)
{
    int res = 0;
    while (n) {
        res += n / p;
        n /= p;
    }
    return res;
}

vector<int> mul(vector<int> a, int b)
{
    vector<int> c;
    int t = 0;
    for (int i = 0; i < a.size(); i++) {
        t += a[i] * b;
        c.push_back(t % 10);
        t /= 10;
    }
    while (t) {
        c.push_back(t % 10);
        t /= 10;
    }
    return c;
}

int main()
{
    int a, b;
    cin >> a >> b;

    get_primes(a);

    for (int i = 0; i < cnt; i++) {
        int p = primes[i];
        sum[i] = get(a, p) - get(a - b, p) - get(b, p);
    }

    vector<int> res;
    res.push_back(1);

    for (int i = 0; i < cnt; i++) {
        for (int j = 0; j < sum[i]; j++) {
            res = mul(res, primes[i]);
        }
    }

    for (int i = res.size() - 1; i >= 0; i--) {
        printf("%d", res[i]);
    }

    puts("");

    return 0;
}

