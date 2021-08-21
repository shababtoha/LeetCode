class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> valueStack;
    stack<int> minStack;
    MinStack() {
        
    }
    
    void push(int val) {
        valueStack.push(val);
        int mn;
        if(minStack.empty()) {
            mn = val;
        } else {
            mn = min(val, minStack.top());
        }
        if(val == mn) {
            minStack.push(val);
        }
    }
    
    void pop() {
        int x = valueStack.top();
        int y = minStack.top();
        valueStack.pop();
        if(x == y)
            minStack.pop();
    }
    
    int top() {
        return valueStack.top();
    }
    
    int getMin() {
        return minStack.empty();
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