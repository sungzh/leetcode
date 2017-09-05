/*
 * Implement the following operations of a queue using stacks.
 *
 * push(x) -- Push element x to the back of queue.
 * pop() -- Removes the element from in front of queue.
 * peek() -- Get the front element.
 * empty() -- Return whether the queue is empty.
 * Notes:
 * You must use only standard operations of a stack -- which means only push to top, peek/pop from top, size, and is empty operations are valid.
 * Depending on your language, stack may not be supported natively. You may simulate a stack by using a list or deque (double-ended queue), as long as you use only standard operations of a stack.
 * You may assume that all operations are valid (for example, no pop or peek operations will be called on an empty queue).
 */
/*
 * Source: https://leetcode.com/problems/implement-queue-using-stacks
 * Description: inteview in baidu on 0904, easy question but need the most economy algo
 * Author: guozheng
 * Data: 20170905
 */

class MyQueue {
    stack<int> s1, s2;
public:
    /** Initialize your data structure here. */
    MyQueue() {                   
    }
                
    /** Push element x to the back of queue. */
    void push(int x) {
        s1.push(x);
    }
                    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        peek();
        int top = s2.top();
        s2.pop();
        return top;
    }
                        
    /** Get the front element. */
    int peek() {
        if(s2.empty()) {
            while(!s1.empty()) s2.push(s1.top()), s1.pop();
        }
        return s2.top();
                                    
    }
                            
    /** Returns whether the queue is empty. */
    bool empty() {
        return s1.empty() && s2.empty();
    }
};
