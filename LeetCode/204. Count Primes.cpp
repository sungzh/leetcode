/*
 * Description:
 *
 * Count the number of prime numbers less than a non-negative number, n.
 *
 * Credits:
 * Special thanks to @mithmatt for adding this problem and creating all test cases.
 *
 */

/*
 * Source: https://leetcode.com/problems/count-primes/
 * Description: primes  use the table
 * Author: guozheng
 * Data: 20170911
 */

class Solution {
public:
    int countPrimes(int n) {
        vector<bool> notPrime(n, false);
        int count=0;
        for(int i = 2; i < n; i++){
            if(notPrime[i]==false) {
                count++;
                for(int j = 2; i*j <n; j++) {
                    notPrime[i*j] = true;
                }
            }
        }
        return count;
    }
};
