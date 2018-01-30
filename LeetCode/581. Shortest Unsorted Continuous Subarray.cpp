/*
 * Given an integer array, you need to find one continuous subarray that if you only sort this subarray in ascending order, then the whole array will be sorted in ascending order, too.
 *
 * You need to find the shortest such subarray and output its length.
 *
 * Example 1:
 * Input: [2, 6, 4, 8, 10, 9, 15]
 * Output: 5
 * Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.
 * Note:
 * Then length of the input array is in range [1, 10,000].
 * The input array may contain duplicates, so ascending order here means <=.
 */

/*
 * Source: https://leetcode.com/problems/shortest-unsorted-continuous-subarray/
 * Description: 1 3 2 2 2 so need using max and min
 * Author: guozheng
 * Data: 20180130
 */

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int start = -1, end = -2, n = nums.size();
        int _max = nums[0], _min = nums[n-1]; 
        for(int i = 1; i < nums.size(); i++) {
            _max = max(_max, nums[i]);
            _min = min(_min, nums[n-1-i]);
            if( nums[i] < _max) end = i;
            if(_nums[n-1-i] > _min) start = n-1-i;
        }
        return end - start + 1;
    }
};
