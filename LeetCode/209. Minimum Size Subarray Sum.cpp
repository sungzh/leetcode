/*
 * Given an array of n positive integers and a positive integer s, find the minimal length of a contiguous subarray of which the sum ≥ s. If there isn't one, return 0 instead.
 *
 * For example, given the array [2,3,1,2,4,3] and s = 7,
 * the subarray [4,3] has the minimal length under the problem constraint.
 *
 * click to show more practice.
 *
 * More practice:
 * If you have figured out the O(n) solution, try coding another solution of which the time complexity is O(n log n).
 *
 * Credits:
 * Special thanks to @Freezen for adding this problem and creating all test cases.
 */

/*
 * Source: https://leetcode.com/problems/minimum-size-subarray-sum/
 * Description: using two point
 * Author: guozheng
 * Data: 20171120
 */

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int i=0, j=0;
        int sum=0, _min=INT_MAX;
        for(i=0; i<nums.size(); i++) {
            sum += nums[i];
            while(sum>=s) {
                _min = min(_min,i-j+1);
                sum-=nums[j++];
            }
        }
        return _min == INT_MAX ? 0:_min;
    }
};
