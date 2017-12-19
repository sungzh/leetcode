/*
 * Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
 *
 * push(x) -- Push element x onto stack.
 * pop() -- Removes the element on top of the stack.
 * top() -- Get the top element.
 * getMin() -- Retrieve the minimum element in the stack.
 * Example:
 * MinStack minStack = new MinStack();
 * minStack.push(-2);
 * minStack.push(0);
 * minStack.push(-3);
 * minStack.getMin();   --> Returns -3.
 * minStack.pop();
 * minStack.top();      --> Returns 0.
 * minStack.getMin();   --> Returns -2.
 */

/*
 * Source: https://leetcode.com/problems/min-stack/
 * Description: using two stack or one stack using the res
 * Author: guozheng
 * Data: 20171219
 */

class MinStack {
private:
    stack<int> s;
    int m;
public:
    /** initialize your data structure here. */
    MinStack() {
                        
    }
                
    void push(int x) {
        if(s.empty()){
            s.push(0);
            m = x;
        }else {
            s.push(x-m);
            if(x<m) m=x;
        }
    }
                    
    void pop() {
        if(s.empty()) return;
        int p=s.top();
        s.pop();
        if(p<0) m=m-p;
    }
                        
    int top() {
        int t=s.top();
        if(t>0) return t+m;
        else return m;
    }
                            
    int getMin() {
        return m;
    }
};

class MinStack {
private:
    stack<int> s1;
    stack<int> s2;
public:
    /** initialize your data structure here. */
    MinStack() {
                        
    }
                
    void push(int x) {
        s1.push(x);
        if(s2.empty() || x<=getMin()) s2.push(x);
    }
                    
    void pop() {
        if(s1.top()==getMin()) s2.pop();
        s1.pop();
    }
                        
    int top() {
        return s1.top();
    }
                            
    int getMin() {
        return s2.top();
    }
};

/**
 ** Your MinStack object will be instantiated and called as such:
 ** MinStack obj = new MinStack();
 ** obj.push(x);
 ** obj.pop();
 ** int param_3 = obj.top();
 ** int param_4 = obj.getMin();
 **/
