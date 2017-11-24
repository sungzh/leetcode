/*
 * Given a string, your task is to count how many palindromic substrings in this string.
 *
 * The substrings with different start indexes or end indexes are counted as different substrings even they consist of same characters.
 *
 * Example 1:
 * Input: "abc"
 * Output: 3
 * Explanation: Three palindromic strings: "a", "b", "c".
 * Example 2:
 * Input: "aaa"
 * Output: 6
 * Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
 * Note:
 * The input string length won't exceed 1000.
 */

/*
 * Source: https://leetcode.com/problems/palindromic-substrings/
 * Description: check from one point to extend palindrome
 * Author: guozheng
 * Data: 20171124
 */
class Solution {
public:
    int count = 0;
    int countSubstrings(string s) {
        if(s.size()==0) return 0;
        for(int i=0; i<s.size(); i++){
            check(s, i, i);
            check(s, i, i+1);
        }
        return count;
    }
    void check(string s, int left, int right) {
        while(left>=0 && right<s.size() && s[left] == s[right]) {
            count++; left--; right++;
        }
    }
};
