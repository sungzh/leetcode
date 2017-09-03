/*
 * Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.
 *
 * If the last word does not exist, return 0.
 *
 * Note: A word is defined as a character sequence consists of non-space characters only.
 *
 * For example, 
 * Given s = "Hello World",
 * return 5.
 */
/**
 * Source: https://leetcode.com/problems/length-of-last-word/
 * Description: EASY QUESTION, notice the boundary.
 * Author: guozheng
 * Data: 20170902
 * */

class Solution {
public:
    int lengthOfLastWord(string s) {
        int count = 0;
        bool reset = false;
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == ' ') {
                reset = true;
                continue;
            }
            if(reset == true) count = 0, reset = false;
            count++;
        }
        return count;
    }
};
