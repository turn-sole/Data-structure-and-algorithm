//906. 区间分组
#include <iostream>
#include<queue>
#define N 100001
using namespace std;

struct Point
{
    int x, y;
}point[N];

int n;
priority_queue<int, vector<int>, greater<int>> p;

bool cmp(Point a, Point b)
{
    return a.x < b.x;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> point[i].x >> point[i].y;

    sort(point, point + n, cmp);

    int ed = INT_MIN;
    for (int i = 0; i < n; ++i)
    {
        if (p.empty() || p.top() >= point[i].x) p.push(point[i].y);
        else
        {
            p.pop();
            p.push(point[i].y);
        }
    }
    cout << p.size();
}





//907. 区间覆盖
#include <algorithm>
#include <iostream>

using namespace std;

const int N = 1e5 + 10;

int n;
struct Range
{
    int l, r;
    bool operator<(const Range& W) const
    {
        return l < W.l;
    }
} range[N];

int main()
{
    int st, ed;
    cin >> st >> ed;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        range[i] = { l, r };
    }

    sort(range, range + n);

    int res = 0;
    bool success = false;
    for (int i = 0; i < n; i++) {
        int j = i, r = -2e9;
        while (j < n && range[j].l <= st) {
            r = max(r, range[j].r);
            j++;
        }

        if (r < st) {
            res = -1;
            break;
        }

        res++;

        if (r >= ed) {
            success = true;
            break;
        }

        st = r;
        i = j - 1;
    }

    if (!success) {
        res = -1;
    }

    cout << res << endl;

    return 0;
}

