/**
 * A message containing letters from A-Z is being encoded to numbers using the following mapping:
 *
 * 'A' -> 1
 * 'B' -> 2
 * ...
 * 'Z' -> 26
 * Given an encoded message containing digits, determine the total number of ways to decode it.
 *
 * For example,
 * Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).
 *
 * The number of ways decoding "12" is 2.
 */

/*
 * Source: https://leetcode.com/problems/decode-ways/
 * Description: DP[i] = DP[i-1] if s[i] is valid;
 *                      + DP[i-2] if s[i-1] s[i] is valid;
 * Author: guozheng
 * Data: 20170902
 */

class Solution {
public:
    int valid(char ch) {
        return ch == '0'? 0:1;
    }
    int valid(char ch1, char ch2) {
        return (ch1 == '1' || (ch1 == '2' && ch2 <= '6')) ? 1:0;
    }
    int numDecodings(string s) {
        int n = s.size();
        int fn_1 = 0, fn_2 = 0, f = 0;
        if(n==0) return 0;
        if(n==1) return valid(s[0]);
        fn_2 = valid(s[0]);
        fn_1 = valid(s[0])*valid(s[1]) + valid(s[0], s[1]);
        if(n==2) return fn_1;
        for(int i = 2; i < s.size(); i++) {
            if(valid(s[i])) f = fn_1;
            if(valid(s[i-1], s[i])) f = f + fn_2;
            fn_2 = fn_1;
            fn_1 = f;
            f = 0;
        }
        return fn_1;
    }
};
