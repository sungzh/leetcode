/*
 * You have a total of n coins that you want to form in a staircase shape, where every k-th row must have exactly k coins.
 *
 * Given n, find the total number of full staircase rows that can be formed.
 *
 * n is a non-negative integer and fits within the range of a 32-bit signed integer.
 *
 * Example 1:
 *
 * n = 5
 *
 * The coins can form the following rows:
 * ¤
 * ¤ ¤
 * ¤ ¤
 *
 * Because the 3rd row is incomplete, we return 2.
 * Example 2:
 *
 * n = 8
 *
 * The coins can form the following rows:
 * ¤
 * ¤ ¤
 * ¤ ¤ ¤
 * ¤ ¤
 *
 * Because the 4th row is incomplete, we return 3.
 */

/*
 * Source: https://leetcode.com/problems/arranging-coins/
 * Description: sum = (x + 1) * x / 2, then using formula to cal x=(-b+sqrt(b^2-4ac))/2a
 * Author: guozheng
 * Data: 20171129
 */

class Solution {
public:
    int arrangeCoins(int n) {
        return (int)((-1+sqrt(1+8*n))/2);
    }
};
