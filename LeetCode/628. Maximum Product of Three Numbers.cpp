/*
 * Given an integer array, find three numbers whose product is maximum and output the maximum product.
 *
 * Example 1:
 * Input: [1,2,3]
 * Output: 6
 * Example 2:
 * Input: [1,2,3,4]
 * Output: 24
 * Note:
 * 1. The length of the given array will be in range [3,104] and all elements are in the range [-1000, 1000].
 * 2. Multiplication of any three numbers in the input won't exceed the range of 32-bit signed integer.
 * 
 */
/*
 * Source: https://leetcode.com/problems/maximum-product-of-three-numbers/
 * Description: the postive integer or two negtive and ont postive integer
 * Author: guozheng
 * Data: 20171120
 */

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN;
        int min1 = INT_MAX, min2 = INT_MAX;
        for(int n:nums) {
            if(n>max1) {
                max3 = max2;
                max2 = max1;
                max1 = n;
            } else if (n>max2) {
                max3 = max2;
                max2 = n;
            } else if (n>max3) {
                max3 = n;
            }

            if(n<min1) {
                min2 = min1;
                min1 = n;
            } else if(n<min2) {
                min2 = n;
            }
        }                
        return max(max1*max2*max3, max1*min1*min2);
    }
};
