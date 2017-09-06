/*
 * Given a pattern and a string str, find if str follows the same pattern.
 *
 * Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in str.
 *
 * Examples:
 * pattern = "abba", str = "dog cat cat dog" should return true.
 * pattern = "abba", str = "dog cat cat fish" should return false.
 * pattern = "aaaa", str = "dog cat cat dog" should return false.
 * pattern = "abba", str = "dog dog dog dog" should return false.
 * Notes:
 * You may assume pattern contains only lowercase letters, and str contains lowercase letters separated by a single space.
 *
 * Credits:
 * Special thanks to @minglotus6 for adding this problem and creating all test cases.
 */

/*
 * Source: https://leetcode.com/problems/word-pattern/
 * Description: c++ have not split and need tow map to record the index
 * Author: guozheng
 * Data: 20170906
 */

#include<unordered_map>
#include<string>
#include<sstream>
using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        unordered_map<string, int> s;
        unordered_map<char, int>  w;
        istringstream in(str);
        int i = 0, n = pattern.size();
        for(string word; in>>word; i++){
            if(i == n || s[word] != w[pattern[i]]) return false;
            s[word] = w[pattern[i]] = i+1;
        }
        return i==n;
    }
};
