/*
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

* push(x) -- Push element x onto stack.
* pop() -- Removes the element on top of the stack.
* top() -- Get the top element.
* getMin() -- Retrieve the minimum element in the stack.
*/

class MinStack {
public:
    void push(int x) {
        stk.push(x);
        if(minStk.empty() || x <= getMin())
            minStk.push(x);
    }

    void pop() {
        if(stk.top() == getMin())
            minStk.pop();
        stk.pop();
    }

    int top() {
        return stk.top();
    }

    int getMin() {
        return minStk.top();
    }

private:
    stack<int> stk;
    stack<int> minStk;
};
