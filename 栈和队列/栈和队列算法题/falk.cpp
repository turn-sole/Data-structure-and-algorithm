//225. 用队列实现栈
class MyStack {
private:
    queue<int> q;
public:
    MyStack() {

    }

    void push(int x) {
        q.push(x);
        for (int i = 0; i < q.size() - 1; i++) {
            q.push(q.front());
            q.pop();
        }

    }

    int pop() {
        int i = q.front();
        q.pop();
        return i;
    }

    int top() {
        return q.front();
    }

    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
232. 用栈实现队列
class MyQueue {
public:
    stack<int> a, b;
    MyQueue() {}

    void push(int x) {
        while (!b.empty()) {
            a.push(b.top());
            b.pop();
        }
        a.push(x);
        while (!a.empty()) {
            b.push(a.top());
            a.pop();
        }
    }

    int pop() {
        int ret = b.top();
        b.pop();
        return ret;
    }

    int peek() {
        return b.top();
    }

    bool empty() {
        return b.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */