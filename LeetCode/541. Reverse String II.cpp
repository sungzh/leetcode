/*
 * Given a string and an integer k, you need to reverse the first k characters for every 2k characters counting from the start of the string. If there are less than k characters left, reverse all of them. If there are less than 2k but greater than or equal to k characters, then reverse the first k characters and left the other as original.
 * Example:
 * Input: s = "abcdefg", k = 2
 * Output: "bacdfeg"
 * Restrictions:
 * The string consists of lower English letters only.
 * Length of the given string and k will in the range [1, 10000]
 */

/*
 * @Source: https://leetcode.com/problems/reverse-string-ii
 * @Description: notice boundary
 * @Author: guozheng
 * @Data: 20170903

class Solution {
public:
    string reverseStr(string s, int k) {
        int n = s.size();
        for(int i = 0; i < n; i++) {
            if((i+1) % (2*k) == 0) reverse(s.begin()+i-2*k+1, s.begin()+i-k+1);
        }
        reverse(s.begin() + 2*k*(n/(2*k)), s.begin() + min(2*k*(n/(2*k))+k, n));
        return s;
    }
};
