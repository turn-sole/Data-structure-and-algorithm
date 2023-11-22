//897. 最长公共子序列
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int main(void) {
    int leng1, leng2;
    cin >> leng1 >> leng2;

    string str1, str2;
    cin >> str1 >> str2;

    vector<vector<int>>dp(leng1 + 1, vector<int>(leng2 + 1));

    for (int i = 0; i < leng1; ++i) {
        for (int j = 0; j < leng2; ++j) {
            if (str1[i] == str2[j])
                dp[i + 1][j + 1] = dp[i][j] + 1;
            else
                dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
        }
    }

    cout << dp.back().back() << endl;

    return 0;
}




//902. 最短编辑距离
#include<iostream>
using namespace std;
const int N = 1010;
char a[N], b[N];
int f[N][N];
int n, m;
int main()
{
    cin >> n >> a + 1;
    cin >> m >> b + 1;
    for (int i = 1; i <= n; i++) f[i][0] = i;
    for (int i = 1; i <= m; i++) f[0][i] = i;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            f[i][j] = min(f[i - 1][j] + 1, f[i][j - 1] + 1);
            f[i][j] = min(f[i][j], f[i - 1][j - 1] + (a[i] != b[j]));
        }
    }
    cout << f[n][m];
    return 0;
}

