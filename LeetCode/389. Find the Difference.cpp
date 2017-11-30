/*
 * Given two strings s and t which consist of only lowercase letters.
 *
 * String t is generated by random shuffling string s and then add one more letter at a random position.
 *
 * Find the letter that was added in t.
 *
 * Example:
 *
 * Input:
 * s = "abcd"
 * t = "abcde"
 *
 * Output:
 * e
 *
 * Explanation:
 * 'e' is the letter that was added.
 */

/*
 * Source: https://leetcode.com/problems/find-the-difference/
 * Description: xor
 * Author: guozheng
 * Data: 20171127
 */

class Solution {
public:
    char findTheDifference(string s, string t) {
        char c = 0;
        for(char ch:s)
            c^=ch;
        for(char ch:t)
            c^=ch;
        return c;
    }
};