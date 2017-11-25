/*
 * Given a sorted array consisting of only integers where every element appears twice except for one element which appears once. Find this single element that appears only once.
 *
 * Example 1:
 * Input: [1,1,2,3,3,4,4,8,8]
 * Output: 2
 * Example 2:
 * Input: [3,3,7,7,10,11,11]
 * Output: 10
 * Note: Your solution should run in O(log n) time and O(1) space.
 */

/*
 * Source: https://leetcode.com/problems/single-element-in-a-sorted-array/
 * Description: find the first even-index number not followed by the same number
 * Author: guozheng
 * Data: 20171125
 */

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int start = 0, end = nums.size()/2;
        while(start<end) {
            int mid = (start+end)/2;
            if(nums[2*mid] != nums[2*mid+1]) end = mid;
            else start = mid+1;
        }
        return nums[start*2];
    }
};
