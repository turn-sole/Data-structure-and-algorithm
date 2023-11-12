//883. ��˹��Ԫ�����Է�����
#include <iostream>
#include <iomanip>

using namespace std;

typedef long long i64;

constexpr int N = 110;
constexpr double eps = 1E-8;

int n;
double a[N][N];

int guess() {
    int r, c;
    for (r = 0, c = 0; c < n; c++) {
        int t = r;
        for (int i = r; i < n; i++) {
            if (fabs(a[i][c]) > fabs(a[t][c])) {
                t = i;
            }
        }

        if (fabs(a[t][c]) < eps) {
            continue;
        }

        for (int i = c; i <= n; i++) {
            swap(a[t][i], a[r][i]);
        }

        for (int i = n; i >= c; i--) {
            a[r][i] /= a[r][c];
        }

        for (int i = 0; i < n; i++) {
            if (fabs(a[i][c]) > eps && i != r) {
                for (int j = n; j >= c; j--) {
                    a[i][j] -= a[r][j] * a[i][c];
                }
            }
        }

        r++;
    }

    if (r < n) {
        for (int i = r; i < n; i++) {
            if (fabs(a[i][n]) > eps) {
                return 2;
            }
        }

        return 1;
    }

    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n + 1; j++) {
            cin >> a[i][j];
        }
    }

    int t = guess();
    if (t == 2) {
        cout << "No solution\n";
    }
    else if (t == 1) {
        cout << "Infinite group solutions\n";
    }
    else {
        for (int i = 0; i < n; i++) {
            if (fabs(a[i][n]) < eps) {
                a[i][n] = 0;
            }
            cout << fixed << setprecision(2) << a[i][n] << "\n";
        }
    }

    return 0;
}




//884. ��˹��Ԫ��������Է�����
const int N = 110;
int n;
int g[N][N];

int gauss()
{
    int r = 0, c;
    for (int c = 0; c < n; c++)  
    {
        int t = r; 
        for (int i = r; i < n; i++)
            if (g[i][c])
                t = i;

        if (!g[t][c])
            continue;

        for (int i = c; i <= n; i++)
            swap(g[r][i], g[t][i]); 

        for (int i = r + 1; i < n; i++) 
            if (g[i][c])
                for (int j = n; j >= c; j--)
                    g[i][j] ^= g[r][j];
        r++;
    }
    if (r < n) {
        for (int i = r; i < n; i++) {
            if (g[i][n])
                return 2;
        }
        return 1;
    }

    for (int i = n - 1; i >= 0; i--) {
        for (int j = i + 1; j < n; j++) {
            g[i][n] ^= g[i][j] * g[j][n];
        }
    }
    return 0;
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n + 1; j++) {
            cin >> g[i][j];
        }
    }

    int t = gauss();
    if (t == 0) {
        for (int i = 0; i < n; i++) {
            cout << g[i][n] << endl;
        }
    }
    else if (t == 1)
        puts("Multiple sets of solutions");
    else
        puts("No solution");
    return 0;
}

