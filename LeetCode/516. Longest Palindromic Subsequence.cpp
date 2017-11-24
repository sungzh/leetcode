/*
 * Given a string s, find the longest palindromic subsequence's length in s. You may assume that the maximum length of s is 1000.
 *
 * Example 1:
 * Input:
 *
 * "bbbab"
 * Output:
 * 4
 * One possible longest palindromic subsequence is "bbbb".
 * Example 2:
 * Input:
 *
 * "cbbd"
 * Output:
 * 2
 * One possible longest palindromic subsequence is "bb".
 */
/*
 * Source: https://leetcode.com/problems/longest-palindromic-subsequence/
 * Description: dp
 * Author: guozheng
 * Data: 20171124
 */

#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        vector<vector<int> > memo(s.size(), vector<int>(s.size()));
        return helper(s, 0, s.size()-1, memo);
    }

    int helper(string s, int i, int j, vector<vector<int> >& memo) {
        if(memo[i][j]!=0) return memo[i][j];
        if(i>j) return 0;
        if(i==j) return 1;
        if(s[i] == s[j]) memo[i][j] = helper(s, i+1, j-1, memo) + 2;
        else memo[i][j] = max(helper(s, i+1, j, memo), helper(s, i, j-1, memo));
        return memo[i][j];
    }

    int longestPalindromeSubseq(string s) {
        vector<vector<int>> dp(s.size(), vector<int>(s.size()));
        for(int i = s.size()-1; i>=0; i--) {
            dp[i][i] = 1;
            for(int j=i+1; j<s.size(); j++) 
                if(s[i] == s[j])
                    dp[i][j] = dp[i+1][j-1] + 2;
                else
                    dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
        }
        return dp[0][s.size()-1];
    }
};

int main() {
    string s="hiddqscdxrhiddqscdxrhiddqscdxrhiddqscdxrhiddqscdxrhiddqscdxrhiddqscdxrhiddqscdxrhiddqscdxrhiddqscdxr";
    Solution sol;
    cout<<sol.longestPalindromeSubseq(s)<<endl;
}



