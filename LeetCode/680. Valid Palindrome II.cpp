/*
 * Given a non-empty string s, you may delete at most one character. Judge whether you can make it a palindrome.
 *
 * Example 1:
 * Input: "aba"
 * Output: True
 * Example 2:
 * Input: "abca"
 * Output: True
 * Explanation: You could delete the character 'c'.
 * Note:
 * The string will only contain lowercase characters a-z. The maximum length of the string is 50000.
 */

/*
 * Source: https://leetcode.com/problems/valid-palindrome-ii/
 * Description: two step
 * Author: guozheng
 * Data: 20171122
 */

class Solution {
public:
    bool validPalindrome(string s) {
        int count =0;
        int l = -1, r = s.size();
        while(++l<--r)
            if(s[l] != s[r]) return isPalindromic(s, l, r+1) || isPalindromic(s, l-1, r);
        return true;
    }
private:
    bool isPalindromic(string s, int l, int r) {
        while(++l<--r)
            if(s[l] != s[r]) return false;
        return true;
    }
};
