//Given a string which consists of lowercase or uppercase letters, find the length of the longest palindromes that can be built with those letters.
//
//This is case sensitive, for example "Aa" is not considered a palindrome here.
//
//Note:
//Assume the length of given string will not exceed 1,010.
//
//Example:
//
//Input:
//"abccccdd"
//
//Output:
//7
//
//Explanation:
//One longest palindrome that can be built is "dccaccd", whose length is 7.
//
//
#include <iostream>
using namespace std;

class Solution {
    public:
        int longestPalindrome(string s) {
            int hashtable[128];
            memset(hashtable, 0, sizeof(hashtable));

            for(char ch : s) {
                hashtable[ch]++;
            }
            int res = 0;
            bool hasOdd = false;
            for(int n : hashtable) {
                if( n%2 == 0) {
                    res += n;
                } else {
                    res += n -1;
                    hasOdd = true;
                }
            }
            return hasOdd ? res + 1 : res;
                        
        }
};
