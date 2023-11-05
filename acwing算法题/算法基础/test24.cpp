//870. 约数个数
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
const long long mod = 1e9 + 7;
int main() {
    int n;
    scanf("%d", &n);
    map <int, int> primes;
    while (n--) {
        int x;
        scanf("%d", &x);
        for (int i = 2; i <= x / i; i++) {
            while (x % i == 0) {
                x /= i;
                primes[i] ++;
            }
        }
        if (x > 1) primes[x] ++;
    }
    long long res = 1;
    for (auto prime : primes) res = res * (prime.second + 1) % mod;
    printf("%lld\n", res);
    return 0;
}



//871. 约数之和
#include <unordered_map>
#define ll long long
using namespace std;

const int mod = 1e9 + 7;

int n, a;
unordered_map<int, int> prime;

void hkx(int n)
{
    for (int i = 2; i <= n / i; ++i)
        while (n % i == 0)
        {
            n /= i;
            prime[i] ++;
        }

    //不能忘了
    if (n > 1) prime[n] ++;
}

int main()
{
    cin >> n;
    while (n--)
    {
        cin >> a;
        hkx(a);
    }

    ll res = 1;
    for (auto it : prime)
    {
        int p = it.first;
        int a = it.second;
        ll t = 1;
        while (a--) t = (t * p + 1) % mod;
        res = res * t % mod;
    }

    cout << res;
}
