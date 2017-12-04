/*
 * Given two strings s and t, write a function to determine if t is an anagram of s.
 *
 * For example,
 * s = "anagram", t = "nagaram", return true.
 * s = "rat", t = "car", return false.
 *
 * Note:
 * You may assume the string contains only lowercase alphabets.
 *
 * Follow up:
 * What if the inputs contain unicode characters? How would you adapt your solution to such case
 */

/*
 * Source: https://leetcode.com/problems/valid-anagram/
 * Description: using array
 * Author: guozheng
 * Data: 20171204
 */

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;
        int count[26] = {0};
        for(int i=0; i< s.length(); i++){
            count[s[i]-'a']++;
            count[t[i]-'a']--;
        }
        for(int num:count) if(num) return false;
        return true;
    }
};
