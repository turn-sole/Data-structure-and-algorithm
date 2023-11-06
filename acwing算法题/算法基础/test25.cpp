//872. 最大公约数
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;
}

int n, a, b;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a >> b;
        cout << gcd(a, b) << endl;
    }

    return 0;
}



//873. 欧拉函数
int main()
{
    int n;
    cin >> n;

    while (n--)
    {
        int x;
        cin >> x;

        int res = x;
        for (int i = 2; i <= x / i; i++)
            if (x % i == 0)
            {
                res = res / i * (i - 1);
                while (x % i == 0) x /= i;
            }

        if (x > 1) res = res / x * (x - 1);

        cout << res << endl;
    }

    return 0;
}

