class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> s,minS;
    MinStack() {
    }
    
    void push(int x) {
        s.push(x);
        if(minS.empty() || x <= minS.top()) minS.push(x);
    }
    
    void pop() {
        //if(!s.size()) return;
        int t = s.top(); s.pop();
        if(minS.top() == t) minS.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return minS.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
