//866. 试除法判定质数
#include<iostream>
using namespace std;
bool is_prime(int x)
{
    if (x < 2) return false;
    for (int i = 2; i <= x / i; i++)
        if (x % i == 0) return false;
    return true;
}
int main()
{
    int n;
    cin >> n;
    while (n--) {
        int x;
        cin >> x;
        if (is_prime(x))puts("Yes");
        else puts("No");
    }
    return 0;
}


//867. 分解质因数
using namespace std;
int n;
void divv(int x)
{
    for (int i = 2; i <= x / i; i++)
    {
        if (x % i == 0)
        {
            int s = 0;
            while (x % i == 0)
            {
                s++;
                x /= i;
            }
            printf("%d %d\n", i, s);
        }
    }
    if (x > 1)printf("%d %d\n", x, 1);
}
int main()
{
    cin >> n;
    while (n--)
    {
        int x;
        cin >> x;
        divv(x);
        puts(" ");
    }
    return 0;
}
