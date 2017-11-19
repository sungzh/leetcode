/*
 * Given a sorted array, remove the duplicates in-place such that each element appear only once and return the new length.
 *
 * Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.
 *
 * Example:
 *
 * Given nums = [1,1,2],
 *
 * Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively.
 * It doesn't matter what you leave beyond the new length.
 */

/*
 * Source: https://leetcode.com/problems/remove-duplicates-from-sorted-array
 * Description: two pointer
 * Author: guozheng
 * Data: 20171119
 */

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() < 2 ) return nums.size();
        int index = 1;
        for(int j=1; j<nums.size(); j++)
            if(nums[j] != nums[j-1]) nums[index++] = nums[j];
        return index;
    }
};
