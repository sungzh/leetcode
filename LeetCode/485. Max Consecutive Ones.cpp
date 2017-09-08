/*
 * Given a binary array, find the maximum number of consecutive 1s in this array.
 *
 * Example 1:
 * Input: [1,1,0,1,1,1]
 * Output: 3
 * Explanation: The first two digits or the last three digits are consecutive 1s.
 *     The maximum number of consecutive 1s is 3.
 * Note:
 *
 *     The input array will only contain 0 and 1.
 *     The length of input array is a positive integer and will not exceed 10,000
 */

/**
 * Source: https://leetcode.com/problems/max-consecutive-ones/
 * Description: notice the boundary
 * Author: guozheng
 * Data: 20170908
 */

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0;
        int m = 0;
        for(int num: nums)
            if(num) count++;
            else {
                if(m<count) m = count;
                count=0;
            }
        if(m<count) m = count;
        return m;
    }
};
