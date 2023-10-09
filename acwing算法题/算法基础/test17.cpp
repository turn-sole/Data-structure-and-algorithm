//849. Dijkstra求最短路 I
#include<iostream>
#include<cstring>
using namespace std;
const  int N = 510;
int g[N][N], dist[N], n, m;
bool st[N];


int dijkstrac() {
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    for (int i = 0; i < n; i++) {
        int t = -1;
        for (int j = 1; j <= n; j++)
            if (!st[j] && (t == -1 || dist[j] < dist[t]))
                t = j;
        st[t] = true;
        for (int j = 1; j <= n; j++)
            dist[j] = min(dist[j], dist[t] + g[t][j]);
    }
    if (dist[n] == 0x3f3f3f3f)return -1;
    return dist[n];
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    memset(g, 0x3f, sizeof g);
    while (m--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        g[a][b] = min(g[a][b], c);
    }
    cout << dijkstrac() << endl;
    return 0;
}


//850. Dijkstra求最短路 II
#include<iostream>
#include<cstring>
using namespace std;
const int N = 100010;
int n, m;
int h[N], e[N], ne[N], w[N], idx;
int dist[N];
bool found[N];

int heap[N], hp[N], ph[N], sizee;
void heap_swap(int a, int b)
{
    swap(ph[hp[a]], ph[hp[b]]);
    swap(hp[a], hp[b]);
    swap(heap[a], heap[b]);
}
void down(int k)
{
    int t = k;
    if (k * 2 <= sizee && heap[t] > heap[k * 2]) t = k * 2;
    if (k * 2 + 1 <= sizee && heap[t] > heap[k * 2 + 1]) t = k * 2 + 1;
    if (k != t)
    {
        heap_swap(k, t);
        down(t);
    }
}
void up(int k)
{
    while (k / 2 && heap[k] < heap[k / 2])
    {
        heap_swap(k, k / 2);
        k >>= 1;
    }
}

int dijkstra()
{
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;

    sizee++;
    ph[1] = sizee; 
    hp[sizee] = 1; 
    heap[sizee] = 0;
    up(sizee);

    while (sizee)
    {
        int cur_dist = heap[1];
        int cur_ver = hp[1];
        heap_swap(1, sizee--);
        down(1);

        for (int i = h[cur_ver]; i != -1; i = ne[i])
        {
            int j = e[i];                           
            if (dist[j] > cur_dist + w[i])
            {
                dist[j] = cur_dist + w[i];

                if (ph[j] != 0)
                {
                    heap[ph[j]] = dist[j];
                    up(ph[j]);
                    down(ph[j]);
                }
                else
                {
                    sizee++;
                    ph[j] = sizee;
                    hp[sizee] = j;
                    heap[sizee] = dist[j];
                    up(sizee);
                }
            }
        }
    }
    if (dist[n] == 0x3f3f3f3f) return -1;
    return dist[n];

}
int main()
{
    cin >> n >> m;
    memset(h, -1, sizeof h);
    while (m--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        e[idx] = b; w[idx] = c; ne[idx] = h[a]; h[a] = idx++;
    }


    cout << dijkstra();
}
