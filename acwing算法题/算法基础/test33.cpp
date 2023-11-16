//891. NimÓÎÏ·
#include <iostream>

using namespace std;

const int N = 100010;
int n;

int main()
{
    int res = 0;
    cin >> n;
    while (n--)
    {
        int x;
        cin >> x;
        res ^= x;
    }

    if (res) puts("Yes");
    else puts("No");
    return 0;
}




//892. Ì¨½× - NimÓÎÏ·
#include <iostream>
using namespace std;

int main()
{

    int res = 0, a, n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> a;
        if (i % 2 != 0) res ^= a;
    }

    if (res == 0) puts("No");
    else puts("Yes");
    return 0;
}