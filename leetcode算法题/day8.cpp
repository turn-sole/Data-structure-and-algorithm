#include<iostream>
#include<list>

using namespace std;

//int main()
//{
//	int ar[] = { 0,1, 2, 3, 4,  5, 6, 7, 8, 9 };
//	int n = sizeof(ar) / sizeof(int);
//
//	list<int> mylist(ar, ar + n);
//	list<int>::iterator pos = find(mylist.begin(), mylist.end(), 5);
//
//	reverse(mylist.begin(), pos);
//	reverse(pos, mylist.end());
//
//	list<int>::const_reverse_iterator crit = mylist.crbegin();
//
//	while (crit != mylist.crend())
//	{
//		cout << *crit << " ";
//		++crit;
//	}
//	cout << endl;
//}

int main()
{
	int array[] = { 1, 2, 3, 4, 0, 5, 6, 7, 8, 9 };
	int n = sizeof(array) / sizeof(int);
	list<int> mylist(array, array + n);
	auto it = mylist.begin();

	while (it != mylist.end())
	{
		if (*it != 0)
			cout << *it << " ";
		else
			it = mylist.erase(it);
		++it;
	}
	return 0;
}

//155. 最小栈
class MinStack {
public:
    stack<int> vals;
    stack<int> minvals;
    MinStack() {

    }

    void push(int val) {
        vals.emplace(val);
        if (minvals.empty())
        {
            minvals.emplace(val);
        }
        else
        {
            minvals.emplace(min(minvals.top(), val));
        }
    }

    void pop() {
        vals.pop();
        minvals.pop();
    }

    int top() {
        return vals.top();
    }

    int getMin() {
        return minvals.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */


