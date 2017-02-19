//Given a string, find the length of the longest substring without repeating characters.
//
//Examples:
//
//Given "abcabcbb", the answer is "abc", which the length is 3.
//
//Given "bbbbb", the answer is "b", with the length of 1.
//
//Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.

#include <map>
#include <string>
#include <iostream>
using namespace std;

//abba  add last < m[s[i]] to advoid this, advoid the char that is not using, in abba, bb alreay repeat, so the first a is ignore, using the last < m[s[i]] to start the new begining
// 1. store the index
// 2. find the repeat 
// 3. get maxlen
// 4. start from the new index, last < m[s[i]]
// 5. repeat 1

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> m;
        int last = -1;
        int maxlen = 0;
        for(int i = 0; i < s.length(); i++) {
            if(m.find(s[i]) != m.end() && last < m[s[i]])
                last = m[s[i]];
            if(i - last > maxlen) 
                maxlen = i - last;
            m[s[i]] = i;
        }
        return maxlen;
    }
};

int main() {
    Solution sol;
    string s = "abcabcbb";
    int res = sol.lengthOfLongestSubstring(s);
    cout<<s<< " " <<res <<endl;
    s = "bbbbbb";
    res = sol.lengthOfLongestSubstring(s);
    cout<<s<< " " <<res <<endl;
    s = "bbabcdb";
    res = sol.lengthOfLongestSubstring(s);
    cout<<s<< " " <<res <<endl;
    s = "abba";
    res = sol.lengthOfLongestSubstring(s);
    cout<<s<< " " <<res <<endl;
}
