//Given a string s, partition s such that every substring of the partition is a palindrome.
//
//Return the minimum cuts needed for a palindrome partitioning of s.
//
//For example, given s = "aab",
//Return 1 since the palindrome partitioning ["aa","b"] could be produced using 1 cut.
//
//Subscribe to see which companies asked this question.
//
#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    int minCut(string s) {
        if( s.size()<=1 ) return 0;
        vector<int> res(s.size(), 0);

        bool mp[s.size()][s.size()];

        for(int i=s.size()-1; i>0; i--) {
            for(int j=i; j<s.size(); j++) {
                if( (s[i] ==s[j]) && (j-i<2 ||mp[i+1][j-1])) {
                    mp[i][j] = true;
                } else {
                    mp[i][j] = false;
                }
            }
        }

        for(int i = 0; i < s.size(); i++) {
            if(mp[0][i] == true) {
                res[i] = 0;
            } else {
                int ms = s.size();
                for(int j = 0; j<i; j++) {
                    if(mp[j+1][i] && ms > res[j]+1) {
                        ms = res[j]+1;
                    }
                }
                res[i] = ms;
            }
        }
        return res[s.size()-1];
                        
    }
};

int main(){
    string s = "aab";
    Solution sol;
    cout<< sol.minCut(s) <<endl;
}
