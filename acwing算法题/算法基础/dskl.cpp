//789. 数的范围
#include<iostream>
using namespace std;

const int N = 100010;

int n, m;
int q[N];

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%d", &q[i]);

    while (m--)
    {
        int x;
        scanf("%d", &x);

        int l = 0, r = n - 1;
        while (l < r)
        {
            int mid = l + r >> 1;
            if (q[mid] >= x)
                r = mid;
            else
                l = mid + 1;
        }
        if (q[l] != x)
            cout << "-1 -1" << endl;
        else
        {
            cout << l << ' ';
            int l = 0, r = n - 1;
            while (l < r)
            {
                int mid = l + r + 1 >> 1;
                if (q[mid] <= x)
                    l = mid;
                else
                    r = mid - 1;
            }
            cout << l << endl;
        }
    }
    return 0;
}

//790. 数的三次方根
int main()
{
    double n;
    cin >> n;
    double l = -10000;
    double r = 10000;
    while (r - l > 1e-8)
    {
        double mid = (l + r) / 2;
        if ((mid * mid * mid) >= n)
            r = mid;
        else
            l = mid;
    }
    printf("%lf\n", l);
    return 0;
}