//899. 编辑距离
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int N = 1010, M = 15;
int n, m;
vector<string> str(N);
int f[N][N];

int match(string a, string b) {
    int la = a.size(), lb = b.size();

    for (int i = 0; i <= la; i++) f[i][0] = i;
    for (int i = 0; i <= lb; i++) f[0][i] = i;

    for (int i = 1; i <= la; i++)
        for (int j = 1; j <= lb; j++) {
            f[i][j] = min(f[i - 1][j], f[i][j - 1]) + 1;
            int t = (a[i] != b[j]);
            f[i][j] = min(f[i][j], f[i - 1][j - 1] + t);
        }

    return f[la][lb];
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> str[i];
        str[i] = ' ' + str[i];
    }

    while (m--) {
        string s;
        int limit;
        cin >> s >> limit;
        s = ' ' + s;

        int cnt = 0;
        for (int i = 0; i < n; i++)
            if (match(str[i], s) <= limit)
                cnt++;

        cout << cnt << endl;
    }

    return 0;
}





//282. 石子合并
#include <iostream>

using namespace std;
const int N = 3e2 + 10;
int n;
int s[N], dp[N][N];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> s[i], s[i] += s[i - 1];
    }

    for (int len = 2; len <= n; len++) {
        for (int i = 1; i + len - 1 <= n; i++) { 
            int l = i, r = i + len - 1;
            dp[l][r] = 0x3f3f3f3f;
            for (int k = l; k < r; k++) {  
                dp[l][r] = min(dp[l][r], dp[l][k] + dp[k + 1][r] + s[r] - s[l - 1]);
            }
        }
    }
    cout << dp[1][n] << endl;

    return 0;
}

