/*
 * Given an array of integers nums and a positive integer k, find whether it's possible to divide this array into k non-empty subsets whose sums are all equal.
 *
 * Example 1:
 * Input: nums = [4, 3, 2, 3, 5, 2, 1], k = 4
 * Output: True
 * Explanation: It's possible to divide it into 4 subsets (5), (1, 4), (2,3), (2,3) with equal sums.
 * Note:
 *
 * 1 <= k <= len(nums) <= 16.
 * 0 < nums[i] < 10000.
 */

/*
 * Source: https://leetcode.com/problems/partition-to-k-equal-sum-subsets
 * Description: dp
 * Author: guozheng
 * Data: 20171120
 */

class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = 0;
        for(int num:nums) sum+=num;
        if(k<=0 || sum%k!=0) return false; 
        vector<bool> visited(nums.size(), false);
        return partitionKSubsets(nums, visited, 0, 0, 0, k, sum/k);
    }

    bool partitionKSubsets(vector<int>& nums, vector<bool>& visited,int start_index, int cur_sum, int cur_num, int k, int target) {
        if(k==1) return true;
        if(cur_sum == target && cur_num > 0 ) return partitionKSubsets(nums, visited, 0, 0, 0, k-1, target);
        for(int i=start_index; i < nums.size(); i++) {
            if(!visited[i]) {
                visited[i] = true;
                if(partitionKSubsets(nums, visited, i+1, cur_sum+nums[i], cur_num+1, k, target)) return true;
                visited[i] = false;
            }
        }
        return false;
    }
};
