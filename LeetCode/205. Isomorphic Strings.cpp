/*
 * Given two strings s and t, determine if they are isomorphic.
 *
 * Two strings are isomorphic if the characters in s can be replaced to get t.
 *
 * All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character but a character may map to itself.
 *
 * For example,
 * Given "egg", "add", return true.
 *
 * Given "foo", "bar", return false.
 *
 * Given "paper", "title", return true.
 *
 * Note:
 * You may assume both s and t have the same length.
 */

/*
 * Source: https://leetcode.com/problems/isomorphic-strings/
 * Description: link to store the clue
 * Author: guozheng
 * Data: 20171226
 */

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int m1[256]={0}, m2[256]={0};
        int n = s.size();
        for(int i=0; i<n; i++) {
            if(m1[s[i]] != m2[t[i]]) return false;
            m1[s[i]] = i+1;
            m2[t[i]] = i+1;
        }
        return true;
    }
};
