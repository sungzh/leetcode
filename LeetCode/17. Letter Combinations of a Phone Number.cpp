/*
 * Given a digit string, return all possible letter combinations that the number could represent.
 *
 * A mapping of digit to letters (just like on the telephone buttons) is given below.
 *
 * Input:Digit string "23"
 * Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 * Note:
 * Although the above answer is in lexicographical order, your answer could be in any order you want.
 *
 */

/*
 * Source: https://leetcode.com/problems/letter-combinations-of-a-phone-number/
 * Description:  using two vecotr or one queue
 * Author: guozheng
 * Data: 20171118
 */

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if(digits == "") return res;
        string charmap[10] = {"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        res.push_back("");
        for(char digit: digits) { 
            vector<string> tmp;
            string value = charmap[digit-'0'];
            for(char ch: value)                
                for(string str: res)
                    tmp.push_back(str+ch);
            res = tmp;
        }
        return res;
    }
};
