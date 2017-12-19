/*
 * Given an arbitrary ransom note string and another string containing letters from all the magazines, write a function that will return true if the ransom note can be constructed from the magazines ; otherwise, it will return false.
 *
 * Each letter in the magazine string can only be used once in your ransom note.
 *
 * Note:
 * You may assume that both strings contain only lowercase letters.
 *
 * canConstruct("a", "b") -> false
 * canConstruct("aa", "ab") -> false
 * canConstruct("aa", "aab") -> true
 */

/*
 * Source: https://leetcode.com/problems/ransom-note/
 * Description: easy question
 * Author: guozheng
 * Data: 20171219
 */

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int arr[26] = {0};
        for(char ch:magazine)
            arr[ch-'a']++;
        for(char ch:ransomNote)
            if(--arr[ch-'a']<0)
                return false;
        return true;
    }
};
