/*
 * Given an integer, write a function to determine if it is a power of three.
 *
 * Follow up:
 * Could you do it without using any loop / recursion?
 *
 * Credits:
 * Special thanks to @dietpepsi for adding this problem and creating all test cases.
 *
 */

/*
 * Source:https://leetcode.com/problems/power-of-three/
 * Description: 3^19 the max int  power 3
 * Data: 20170915
 * Author: guozheng
 */

class Solution {
public:
    bool isPowerOfThree(int n) {
        return n>0 && 1162261467%n==0;
    }
};
