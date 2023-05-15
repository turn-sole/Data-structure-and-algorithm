#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
//791. 高精度加法
string add(const string& A, const string& B)
{
    string C;
    int t = 0;
    for (int i = A.size() - 1, j = B.size() - 1; i >= 0 || j >= 0 || t > 0; i--, j--)
    {
        if (i >= 0) t += (A[i] - '0');
        if (j >= 0) t += (B[j] - '0');
        C += ((t % 10) + '0');
        t /= 10;
    }

    reverse(C.begin(), C.end());
    return C;
}

int main()
{
    ios::sync_with_stdio(false);
    string A, B;
    cin >> A >> B;
    cout << add(A, B) << endl;
    return 0;
}
