/*
 * Given an integer, write a function to determine if it is a power of two.
 *
 * Credits:
 * Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.
 */

/*
 * Source: https://leetcode.com/problems/power-of-two/
 * Description: n&(n-1)==0  power 2
 * Author: guozheng
 * Data: 20170915
 */

class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n>0 && (n&(n-1))==0;
    }
};
