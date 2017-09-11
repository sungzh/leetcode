/*
 * Write a program to find the n-th ugly number.
 *
 * Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. For example, 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.
 *
 * Note that 1 is typically treated as an ugly number, and n does not exceed 1690.
 *
 * Credits:
 * Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.
 */

/*
 * Source: https://leetcode.com/problems/ugly-number-ii/
 * Description: every time move 2, or 3, or 5
 * Author: guozheng
 * Data: 20170911
 */

class Solution {
public:
    int nthUglyNumber(int n) {
        if(n==1) return 1;
        vector<int> ugly(n);
        ugly[0] = 1;
        int t2=0, t3=0, t5=0;
        for(int i = 1; i <n; i++) {
            ugly[i] = min(ugly[t2]*2, min(ugly[t3]*3, ugly[t5]*5));
            if(ugly[i] == ugly[t2]*2) t2++;
            if(ugly[i] == ugly[t3]*3) t3++;
            if(ugly[i] == ugly[t5]*5) t5++;
        }
        return ugly[n-1];
    }
};
