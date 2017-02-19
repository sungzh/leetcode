//Given a positive integer, return its corresponding column title as appear in an Excel sheet.
//
//For example:
//
//    1 -> A
//    2 -> B
//    3 -> C
//    ...
//    26 -> Z
//    27 -> AA
//    28 -> AB 
//Credits:
//Special thanks to @ifanchu for adding this problem and creating all test cases.
//
//Subscribe to see which companies asked this question.

#include<string>
#include<iostream>
using namespace std;
class Solution {
public:
    string convertToTitle(int n) {
        string ret;
        while(n>0) {
            char ch = 'A' + (n-1)%26;
            ret.insert(ret.begin(), ch);
            n -= (n-1)%26;
            n /= 26;
        }
        return ret;
    }
};

int main() {
    Solution s;
    cout<< s.convertToTitle(26) <<endl;

}
