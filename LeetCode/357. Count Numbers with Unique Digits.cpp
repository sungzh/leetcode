/*
 * Given a non-negative integer n, count all numbers with unique digits, x, where 0 ≤ x < 10n.
 *
 * Example:
 * Given n = 2, return 91. (The answer should be the total numbers in the range of 0 ≤ x < 100, excluding [11,22,33,44,55,66,77,88,99])
 *
 * Credits:
 * Special thanks to @memoryless for adding this problem and creating all test cases.
 */

/*
 * Source: https://leetcode.com/problems/count-numbers-with-unique-digits/description/
 * Description: f(n) = 9*8*7*……*1, n>11 is zero
 * Author: guozheng
 * Data: 20171129
 */

class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n==0) return 1;
        int res=10;
        int uniqueDigits = 9;
        int avaiableNumber = 9;
        while(n-- >1 && avaiableNumber>0) {
            uniqueDigits = uniqueDigits * avaiableNumber;
            res += uniqueDigits;
            avaiableNumber--;
        }
        return res;
    }
};
