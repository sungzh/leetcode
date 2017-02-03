//Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.
//
//Example:
//
//Input: "babad"
//
//Output: "bab"
//
//Note: "aba" is also a valid answer.
//Example:
//
//Input: "cbbd"
//
//Output: "bb"

#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n<=1) return s;

        string longest;
        string str;
        for(int i = 0; i<n-1; i++) {
            str = findPalindrome(s, i, i);
            //cout<< i << " " << str<<endl;
            if (str.size() > longest.size()) {
                longest = str;
            }
            str = findPalindrome(s, i, i+1);
            //cout<< i+1 << " " << str<<endl;
            if (str.size() > longest.size()) {
                longest = str;
            }
        }
        return longest;
    }

    string findPalindrome(string s, int left, int right) {
        int n = s.size();
        while (left>=0 && right<=n-1 && s[left] == s[right]) {
            //cout<< s << left << right <<endl;
            left--;
            right++;
        }
        return s.substr(left+1, right-left-1);
    }


};

int main() {
    string s = "babad";
    Solution sol;
    cout << sol.longestPalindrome(s) <<endl;

}
