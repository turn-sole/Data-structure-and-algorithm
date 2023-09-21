//3302. 表达式求值
#include <iostream>
#include <string>
#include <stack>
#include <unordered_map>

using namespace std;

stack<char> op;
stack<int> num;
unordered_map<char, int> pr = { {'+', 1}, {'-', 1}, {'*', 2}, {'/', 2} };

void eval()
{
    int b = num.top(); num.pop();
    int a = num.top(); num.pop();
    char c = op.top(); op.pop();

    int x;
    if (c == '+') x = a + b;
    else if (c == '-') x = a - b;
    else if (c == '*') x = a * b;
    else x = a / b;

    num.push(x);
}

int main()
{
    string s;
    cin >> s;

    for (int i = 0; i < s.size(); i++)
    {
        char c = s[i];
        if (isdigit(c))
        {
            int x = 0, j = i;
            while (j < s.size() && isdigit(s[j])) x = 10 * x + s[j++] - '0';
            i = j - 1;
            num.push(x);
        }
        else if (c == '(') op.push(c);
        else if (c == ')')
        {
            while (op.size() && op.top() != '(') eval();
            op.pop();
        }
        else
        {
            while (op.size() && pr[op.top()] >= pr[c]) eval();
            op.push(c);
        }
    }
    while (op.size()) eval();
    cout << num.top() << endl;

    return 0;
}


//829. 模拟队列
#include<iostream>

using namespace std;
const int N = 1e5 + 10;

int q[N];

int main() {
    int n;
    cin >> n;
    int hh = 0, tt = -1;
    while (n--) {
        string op;
        int x;
        cin >> op;
        if (op == "push") {
            cin >> x;
            q[++tt] = x;
        }
        else if (op == "pop") {
            hh++;
        }
        else if (op == "empty") {
            if (hh <= tt) puts("NO");
            else puts("YES");
        }
        else {
            cout << q[hh] << endl;
        }
    }
}


//830. 单调栈
#include<iostream>
using namespace std;
const int N = 100010;
int s[N], tt;
int n;
int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        while (tt && s[tt] >= x)tt--;
        if (tt)cout << s[tt] << " ";
        else cout << "-1" << " ";
        s[++tt] = x;

    }
    return 0;
}