//839. 模拟堆
#include <iostream>

using namespace std;

const int N = 100010;

int h[N], hp[N], ph[N];
int n, m, s;

void heap_swap(int a, int b)
{
    swap(ph[hp[a]], ph[hp[b]]);
    swap(hp[a], hp[b]);
    swap(h[a], h[b]);
}

void down(int u)
{
    int t = u;
    if (u * 2 <= s && h[t] > h[2 * u]) t = 2 * u;
    if (u * 2 + 1 <= s && h[t] > h[2 * u + 1]) t = 2 * u + 1;
    if (t != u) heap_swap(t, u), down(t);
}

void up(int u)
{
    while (u / 2 && h[u] < h[u / 2])
    {
        heap_swap(u, u / 2);
        u /= 2;
    }
}

int main()
{
    scanf("%d", &n);

    while (n--)
    {
        string op;
        int k, x;
        cin >> op;

        if (op == "I")
        {
            scanf("%d", &x);
            s++, m++;
            hp[s] = m, ph[m] = s;
            h[s] = x;
            up(s);
        }
        else if (op == "PM") printf("%d\n", h[1]);
        else if (op == "DM")
        {
            heap_swap(1, s);
            s--;
            down(1);
        }
        else if (op == "D")
        {
            scanf("%d", &k);
            k = ph[k];
            heap_swap(k, s);
            s--;
            down(k), up(k);
        }
        else if (op == "C")
        {
            scanf("%d %d", &k, &x);
            k = ph[k];
            h[k] = x;
            down(k), up(k);
        }
    }
}


//840. 模拟散列表
#include <iostream>

using namespace std;

const int N = 200003; 
const int null = 0x3f3f3f3f; 


int h[N];

int find(int x) {
    int k = (x % N + N) % N;
    while (h[k] != null && h[k] != x) {
        k++;
        if (k == N) k = 0; 
    }
    return k;
}

int main() {
    int n;
    scanf("%d", &n);
    memset(h, 0x3f, sizeof h);
    while (n--) {
        char op[2];
        int x;
        scanf("%s%d", op, &x);
        int k = find(x);
        if (*op == 'I') h[k] = x;
        else {
            if (h[k] != null) puts("Yes");
            else puts("No");
        }
    }
    return 0;
}
