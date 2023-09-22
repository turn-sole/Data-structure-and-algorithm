//154. »¬¶¯´°¿Ú
# include <iostream>
using namespace std;
const int N = 1000010;
int a[N], q[N], hh, tt = -1;

int main()
{
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &a[i]);
        if (i - k + 1 > q[hh]) ++hh;                  
        while (hh <= tt && a[i] <= a[q[tt]]) --tt;   
        q[++tt] = i;                                 
        if (i + 1 >= k) printf("%d ", a[q[hh]]);      
    }
    cout << endl;
    hh = 0; tt = -1;                                  
    for (int i = 0; i < n; ++i)
    {
        if (i - k + 1 > q[hh]) ++hh;
        while (hh <= tt && a[i] >= a[q[tt]]) --tt;
        q[++tt] = i;
        if (i + 1 >= k) printf("%d ", a[q[hh]]);
    }
    return 0;
}


//831. KMP×Ö·û´®
#include <iostream>

using namespace std;

const int N = 10010, M = 100010;

int n, m;
int ne[N];
char s[M], p[N];

int main()
{
    cin >> n >> p + 1 >> m >> s + 1;

    for (int i = 2, j = 0; i <= n; i++)
    {
        while (j && p[i] != p[j + 1]) j = ne[j];
        if (p[i] == p[j + 1]) j++;
        ne[i] = j;
    }

    for (int i = 1, j = 0; i <= m; i++)
    {
        while (j && s[i] != p[j + 1]) j = ne[j];
        if (s[i] == p[j + 1]) j++;
        if (j == n)
        {
            printf("%d ", i - n);
            j = ne[j];
        }
    }

    return 0;
}
