//843. n - 皇后问题
#include <iostream>
using namespace std;

const int N = 11;

char q[N][N];
bool dg[N * 2], udg[N * 2], cor[N];

int n;

void dfs(int r)
{
    if (r == n)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                cout << q[i][j];
            cout << endl;
        }
        cout << endl;
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (!cor[i] && !dg[i + r] && !udg[n - i + r])
        {
            q[r][i] = 'Q';
            cor[i] = dg[i + r] = udg[n - i + r] = 1;
            dfs(r + 1);
            cor[i] = dg[i + r] = udg[n - i + r] = 0;
            q[r][i] = '.';
        }
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            q[i][j] = '.';
    dfs(0);
    return 0;
}


//844. 走迷宫
#include <iostream>
#include <queue>        
#include <cstring>     
using namespace std;

typedef pair<int, int> PII;

const int N = 110;

int n, m;
int g[N][N];   
int d[N][N];   

int bfs() {
    queue<PII> q;   
    q.push({ 0,0 });  

    memset(d, -1, sizeof d);   
    d[0][0] = 0;                

    int dx[4] = { 0,1,0,-1 }, dy[4] = { 1,0,-1,0 };     

    while (!q.empty()) {
        auto t = q.front();     
        q.pop();               

        for (int i = 0; i < 4; i++) {    
            int x = t.first + dx[i], y = t.second + dy[i];  
            if (x >= 0 && x < n && y >= 0 && y < m && g[x][y] == 0 && d[x][y] == -1) {
                d[x][y] = d[t.first][t.second] + 1; 
                q.push({ x,y });                     
            }
        }
    }
    return d[n - 1][m - 1];    
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> g[i][j];    
    cout << bfs() << endl;
    return 0;
}

