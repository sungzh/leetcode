//Write a function to find the longest common prefix string amongst an array of strings.
//
//Subscribe to see which companies asked this question
//
//
//
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res;
        if(strs.size() <= 0) return res;
        for(int i = 1; i <= strs[0].size(); i++){
            string w = strs[0].substr(0, i);
            for(int j = 1; j < strs.size(); j++){
                if( i > strs[j].size() || w != strs[j].substr(0, i) ) {
                    return res;
                }
            }
            res = w;
        }
        return res;
    }
};

int main()
{
    Solution sol;
    const char* s[]={"abab","aba","abc"};
    const char* s1[]={"a"};
    vector<string> v(s, s+3);
    vector<string> v1(s1, s1+1);
    cout << sol.longestCommonPrefix(v) <<endl;
    cout << sol.longestCommonPrefix(v1) <<endl;
}
