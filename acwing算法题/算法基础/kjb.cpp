#include<iostream>
#include<vector>

using namespace std;
//793. 高精度乘法
vector<int>mul(vector<int>& A, int b)
{
    vector<int>C;

    int t = 0;
    for (int i = 0; i < A.size() || t; i++)
    {
        if (i < A.size())
            t += A[i] * b;
        C.push_back(t % 10);
        t /= 10;
    }

    while (C.size() > 1 && C.back() == 0)
        C.pop_back();
    return C;
}

int main()
{
    string a;
    int b;

    cin >> a >> b;
    vector<int>A;
    for (int i = a.size() - 1; i >= 0; i--)
        A.push_back(a[i] - '0');
    auto C = mul(A, b);
    for (int i = C.size() - 1; i >= 0; i--)
        printf("%d", C[i]);

    return 0;
}


#include<algorithm>


//794. 高精度除法
vector<int>div(vector<int>& A, int b, int& r)
{
    vector<int>C;

    r = 0;
    for (int i = A.size() - 1; i >= 0; i--)
    {
        r = r * 10 + A[i];
        C.push_back(r / b);
        r %= b;
    }
    reverse(C.begin(), C.end());

    while (C.size() > 1 && C.back() == 0)
        C.pop_back();

    return C;
}

int main()
{
    string a;
    int b;

    cin >> a >> b;
    vector<int>A;

    for (int i = a.size() - 1; i >= 0; i--)
        A.push_back(a[i] - '0');

    int r;
    auto C = div(A, b, r);

    for (int i = C.size() - 1; i >= 0; i--)
        printf("%d", C[i]);

    cout << endl << r << endl;

    return 0;
}
