//148. 合并果子
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);

    priority_queue<int, vector<int>, greater<int>> heap;
    while (n--)
    {
        int x;
        scanf("%d", &x);
        heap.push(x);
    }

    int res = 0;
    while (heap.size() > 1)
    {
        int a = heap.top(); heap.pop();
        int b = heap.top(); heap.pop();
        res += a + b;
        heap.push(a + b);
    }

    printf("%d\n", res);
    return 0;
}




//913. 排队打水
#include<iostream>
using namespace std;
int main()
{
    long n, s = 0;
    long  k = 0;
    cin >> n;
    int a[n + 1];
    for (long i = 1; i <= n; i++)cin >> a[i];
    sort(a + 1, a + 1 + n);
    s = a[1];
    for (long i = 2; i <= n; i++)
        k += s, s += a[i];
    cout << k;
    return 0;
}