/*
 * Given a string, you need to reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.
 *
 * Example 1:
 * Input: "Let's take LeetCode contest"
 * Output: "s'teL ekat edoCteeL tsetnoc"
 * Note: In the string, each word is separated by single space and there will not be any extra space in the string.
 */

/*
 * Source: https://leetcode.com/problems/reverse-words-in-a-string-iii
 * Description: Easy question
 * Author: guozheng
 * Data: 20170903
 */

#include<string>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        string res, word;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == ' '){
                reverse(word.begin(), word.end());
                res = res + word + s[i];
                word = "";
                continue;
            }
            word = word + s[i];
        }
        if(word != "") {
            reverse(word.begin(), word.end());
            res = res + word;
        }
        return res;
    }
};
