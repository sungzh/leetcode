/*
 * Given an array of integers where 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.
 *
 * Find all the elements of [1, n] inclusive that do not appear in this array.
 *
 * Could you do it without extra space and in O(n) runtime? You may assume the returned list does not count as extra space.
 *
 * Example:
 *
 * Input:
 * [4,3,2,7,8,2,3,1]
 *
 * Output:
 * [5,6]
 */

/*
 * Source: https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/
 * Descritpion: mark all num in nums as negtive, and then scan the array find the postive
 * Author: guozheng
 * Data: 20180102
 */

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int len = nums.size();
        for(int i=0; i<len; i++) {
            int index = abs(nums[i])-1;
            nums[index] = nums[index]>0 ? -nums[index]:nums[index];
        }
        vector<int> res;
        for(int i=0; i<len; i++) {
            if(nums[i]>0) res.push_back(i+1);
        }
        return res;
    }
};
