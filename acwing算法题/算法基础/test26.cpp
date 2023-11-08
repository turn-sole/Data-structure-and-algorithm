//874. 筛法求欧拉函数
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e6 + 10;
int primes[N];
int cnt;
int phi[N];
bool st[N];
long long get_eulers(int n) {
    phi[1] = 1;
    for (int i = 2; i <= n; i++) {
        if (!st[i]) {
            primes[cnt++] = i;
            phi[i] = i - 1;
        }
        for (int j = 0; primes[j] <= n / i; j++) {
            int t = primes[j] * i;
            st[t] = true;
            if (i % primes[j] == 0) {
                phi[t] = phi[i] * primes[j];
                break;
            }
            phi[t] = phi[i] * (primes[j] - 1);
        }
    }
    long long res = 0;
    for (int i = 1; i <= n; i++) res += phi[i];
    return res;
}
int main() {
    int n;
    scanf("%d", &n);
    printf("%lld\n", get_eulers(n));
    return 0;
}



//875. 快速幂
#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    while (n--) {
        long long result = 1;
        long long a, b, p;
        cin >> a >> b >> p;
        while (b) {
            if (b & 1) {
                result = result * a % p;
            }
            b >>= 1;
            a = a * a % p;
        }
        cout << result << endl;
    }
}

