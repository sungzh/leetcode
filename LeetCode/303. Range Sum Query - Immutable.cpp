/*
 * Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.
 *
 * Example:
 * Given nums = [-2, 0, 3, -5, 2, -1]
 *
 * sumRange(0, 2) -> 1
 * sumRange(2, 5) -> -1
 * sumRange(0, 5) -> -3
 * Note:
 * You may assume that the array does not change.
 * There are many calls to sumRange function.
 */

/*
 * Source: https://leetcode.com/problems/range-sum-query-immutable/
 * Description: using acc num  to store the forwars sum
 * Author: guozheng
 * Data: 20171227
 */

class NumArray {
private:
    vector<int> _nums;
public:
    NumArray(vector<int> nums) {
        _nums.push_back(0);
        for(int num:nums)
            _nums.push_back(_nums.back()+num);
    }
                
    int sumRange(int i, int j) {
        return _nums[j+1] - _nums[i];
    }
};

/**
 ** Your NumArray object will be instantiated and called as such:
 ** NumArray obj = new NumArray(nums);
 ** int param_1 = obj.sumRange(i,j);
 **/
