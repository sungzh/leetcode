/*
 * Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
 *
 * The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
 */

/*
 * Source: https://leetcode.com/problems/valid-parentheses/
 * Description: using stack
 * Author: guozheng
 * Data: 20170921
 */

class Solution {
public:
    bool isValid(string s) {
        stack<char> _stack;
        for(char c:s){
            if(c=='(') _stack.push(')');
            else if(c=='{') _stack.push('}');
            else if(c=='[') _stack.push(']');
            else if(_stack.empty() || _stack.top() != c) return false;
            else _stack.pop();
        }
        return _stack.empty();
    }
};
