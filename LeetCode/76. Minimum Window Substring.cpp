/*
 * Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).
 *
 * For example,
 * S = "ADOBECODEBANC"
 * T = "ABC"
 * Minimum window is "BANC".
 *
 * Note:
 * If there is no such window in S that covers all characters in T, return the empty string "".
 *
 * If there are multiple such windows, you are guaranteed that there will always be only one unique minimum window in S.
 */

/**
 * Source: https://leetcode.com/problems/minimum-window-substring/description/
 * Description: substring template
 * Author: guozheng
 * Data: 20170902
 */

#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> freq(128, 0);
        for(auto c:t) freq[c]++;
        int count = t.size();
        int begin = 0, end = 0;
        int d = s.size(), head = 0;
        while(end < s.size()) {
            if(freq[s[end++]]-->0) count--;
            while(count == 0) {
                if( end-begin < d )  d= end - (head = begin);
                if(freq[s[begin++]]++==0) count++;
            }
        }
        return d == s.size()? "":s.substr(head, d);
                        
    }
};


int main() 
{
    Solution sol;
    string s="abc";
    string t="QWERTYUIOPASDFGHJKLZXCVBNMqwertyuioapsdfghjklzxcvbnm";
    sol.minWindow(s,t);

}
