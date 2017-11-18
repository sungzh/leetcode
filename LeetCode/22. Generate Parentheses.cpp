/*
 * Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
 *
 * For example, given n = 3, a solution set is:
 *
 * [
 *   "((()))",
 *   "(()())",
 *   "(())()",
 *   "()(())",
 *   "()()()"
 * ]
 */

/*
 * Source: https://leetcode.com/problems/generate-parentheses
 * Description: left,right, i meet in an interview and write this in 10min, but after one month I write this in 20min..  must pratice everyday
 * Author: guozheng
 * Data: 20171118
 */

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        genParenthesis(res, "", n, 0);
        return res;
    }
    
    void genParenthesis(vector<string>& res, string str, int l, int r) {
        if(l == 0 && r == 0) res.push_back(str);
        if(r>0) genParenthesis(res, str+')', l, r-1);
        if(l>0) genParenthesis(res, str+'(', l-1, r+1);
    }
};
