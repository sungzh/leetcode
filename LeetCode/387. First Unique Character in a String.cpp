/*
 * Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.
 *
 * Examples:
 *
 * s = "leetcode"
 * return 0.
 *
 * s = "loveleetcode",
 * return 2.
 * Note: You may assume the string contain only lowercase letters.
 */

/*
 * Source: https://leetcode.com/problems/first-unique-character-in-a-string
 * Description: Easy question using array
 * Author: guozheng
 * Data: 20170904
 */

class Solution {
public:
    int firstUniqChar(string s) {
        int freq[26]={0};
        for(char ch : s) freq[ch-'a']++;
        for(int i = 0; i < s.size(); i++) if(freq[s[i]-'a']==1) return i; 
        return -1;
    }
};
