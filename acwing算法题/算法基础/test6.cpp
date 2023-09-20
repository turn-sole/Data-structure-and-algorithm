//826. 单链表
#include<iostream>

using namespace std;

const int N = 100010;
int idx, head, n[N], ne[N];
int a;
void add_head(int x) 
{
    n[idx] = x;
    ne[idx] = head;
    head = idx++;
}
void add(int k, int x) 
{
    n[idx] = x;
    ne[idx] = ne[k];
    ne[k] = idx++;
}
void remove(int k) 
{
    ne[k] = ne[ne[k]];
}

int main() {

    head = -1; idx = 0;
    cin >> a;
    while (a--) 
    {
        string op;
        int k, x;
        cin >> op;
        if (op == "D")
        {

            cin >> k;
            if (!k)head = ne[head];
            remove(k - 1);
        }
        else if (op == "H")
        {
            cin >> x;
            add_head(x);
        }
        else if (op == "I") 
        {
            int k, x;
            cin >> k >> x;
            add(k - 1, x);
        }
    }
    for (int i = head; i != -1; i = ne[i])
        cout << n[i] << " ";
    return 0;

}


//827. 双链表
#include <iostream>

using namespace std;

const int N = 100010;
int l[N], r[N], e[N], idx;

void init() 
{   
    r[0] = 1, l[1] = 0;
    idx = 2;
}

void insert(int a, int x) 
{
    e[idx] = x;
    l[idx] = a, r[idx] = r[a];
    l[r[a]] = idx, r[a] = idx++;
}

void remove(int k) 
{    
    r[l[k]] = r[k];
    l[r[k]] = l[k];
}

int main() 
{
    int m; 
    cin >> m;
    init();
    while (m--) 
    {
        string op; cin >> op;
        int k, x;
        if (op == "L") 
        {
            cin >> x;
            insert(0, x);
        }
        else if (op == "R") 
        {
            cin >> x;
            insert(l[1], x);
        }
        else if (op == "D") 
        {
            cin >> k;
            remove(k + 1);
        }
        else if (op == "IL") 
        {
            cin >> k >> x;
            insert(l[k + 1], x);
        }
        else 
        {
            cin >> k >> x;
            insert(k + 1, x);
        }
    }

    for (int i = r[0]; i != 1; i = r[i]) cout << e[i] << ' ';
    puts("");
    return 0;
}


//828. 模拟栈
#include<iostream>

using namespace std;

const int N = 100010;
int stack[N], top;

int main()
{
    int m;
    cin >> m;
    while (m--)
    {
        string opration;
        int x;
        cin >> opration;
        if (opration == "push")
        {
            cin >> x;
            stack[top++] = x;
        }
        else if (opration == "pop")
            --top;
        else  if (opration == "empty")
            if (top) printf("NO\n");
            else printf("YES\n");
        else
            cout << stack[top - 1] << endl;
    }
    return 0;
}

