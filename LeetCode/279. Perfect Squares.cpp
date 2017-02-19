//Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.
//
//For example, given n = 12, return 3 because 12 = 4 + 4 + 4; given n = 13, return 2 because 13 = 4 + 9.
//
//Credits:
//Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.
//
//Subscribe to see which companies asked this question.
//
//
class Solution {
public:
    int numSquares(int n) {
        if( n <= 0 ) return 0;

        static vector<int> dp(1, 0);
        if( dp.size() >= (n+1) ) return dp[n];

        for(int i = dp.size(); i <= n; i++ ) {
            int m = n;
            for( int j = 1; i-j*j >= 0; j++) {
                m = min(m, dp[i-j*j]+1);
            }
            dp.push_back(m);
        }
        return dp[n];
                        
    }
};
