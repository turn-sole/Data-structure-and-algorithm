//905. 区间选点
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100010;

struct Range {
    int l, r;
    bool operator < (const Range& w)const {
        return r < w.r;
    }
}range[N];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        range[i] = { l, r };
    }

    sort(range, range + n);

    int ans = 0, end = -2e9; 
    for (int i = 0; i < n; i++) {
        if (range[i].l > end) {
            ans++;
            end = range[i].r;
        }
    }

    cout << ans << endl;

    return 0;
}




//908. 最大不相交区间数量
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100010;

struct Node {
    int l, r;
    bool operator < (const Node& w)const {
        return r < w.r;
    }

}node[N];

int main() {
    int n; cin >> n;

    for (int i = 0; i < n; i++) {
        int l, r; cin >> l >> r;
        node[i] = { l, r };
    }

    sort(node, node + n);

    int ans = 0, end = -2e9;  

    for (int i = 0; i < n; i++) {
        if (node[i].l > end) { 
            ans++;
            end = node[i].r;
        }
    }

    cout << ans << endl;

    return 0;
}

