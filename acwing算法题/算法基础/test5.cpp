//802. 区间和
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

const int N = 300010;
typedef pair<int, int> PII;

int a[N], s[N];

vector<int> alls;
vector<PII> add, query;

int find(int x)
{
    int l = 0, r = alls.size() - 1;
    while (l < r)
    {
        int mid = (l + r) / 2;
        if (alls[mid] >= x) r = mid;
        else l = mid + 1;
    }
    return r + 1;
}

int main()
{
    int n, m; cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int x, c;
        cin >> x >> c;
        add.push_back({ x,c });
        alls.push_back(x);
    }
    for (int i = 0; i < m; i++)
    {
        int l, r;
        cin >> l >> r;
        query.push_back({ l,r });
        alls.push_back(l);
        alls.push_back(r);
    }
    sort(alls.begin(), alls.end());
    alls.erase(unique(alls.begin(), alls.end()), alls.end());
    for (auto itdm : add)
    {
        int x;
        x = find(itdm.first);
        a[x] += itdm.second;
    }
    for (int i = 1; i <= alls.size(); i++) s[i] = s[i - 1] + a[i];

    for (auto itdm : query)
    {
        int l, r;
        l = find(itdm.first);
        r = find(itdm.second);
        printf("%d\n", s[r] - s[l - 1]);
    }
    return 0;
}


//803. 区间合并
#include<iostream>
#include<algorithm>
using namespace std;
const int N = 1e6 + 10;
typedef pair<int, int> PII;
PII a[N];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)scanf("%d%d", &a[i].first, &a[i].second);
    sort(a + 1, a + n + 1);
    int ed = a[1].second, ans = 0;
    for (int i = 2; i <= n; i++)
    {
        if (ed >= a[i].first)ed = max(ed, a[i].second);
        else ans++, ed = a[i].second;
    }
    cout << ans + 1 << endl;
}
