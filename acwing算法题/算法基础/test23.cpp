//868. 筛质数
#include <iostream>
using namespace std;
const int N = 1e6 + 10;
int n, cnt, a[N];
bool st[N];
void is_prime(int n)
{
    for (int i = 2; i <= n; i++) {
        if (st[i] == 0)a[cnt++] = i;
        for (int j = 0; a[j] <= n / i; j++) {
            st[a[j] * i] = true;
            if (i % a[j] == 0) break;
        }
    }
}
int main()
{
    cin >> n;
    is_prime(n);
    cout << cnt << endl;
    return 0;
}



//869. 试除法求约数

vector<int> g(int x)
{
    vector<int> res;
    for (int i = 1; i <= x / i; i++)
    {
        if (x % i == 0)
        {
            res.push_back(i);
            if (i != x / i) res.push_back(x / i);
        }
    }
    sort(res.begin(), res.end());
    return res;
}

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int x;
        cin >> x;
        auto res = g(x);
        for (auto x : res) cout << x << ' ';
        cout << endl;
    }
}

