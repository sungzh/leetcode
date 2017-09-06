/*
 * Given an array of integers and an integer k, find out whether there are two distinct indices i and j in the array such that nums[i] = nums[j] and the absolute difference between i and j is at most k.
 */

/*
 * Source: https://leetcode.com/problems/contains-duplicate-ii/
 * Description: using map to recored the num's last index;
 * Author: guozheng
 * Data: 20170906
 */

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for(int i = 0; i < nums.size(); i++) {
            if(m.find(nums[i]) == m.end()) m[nums[i]] = i;
            else if(abs(i-m[nums[i]])<=k) return true;
            else m[nums[i]] = i;
        }
        return false;
    }
};
