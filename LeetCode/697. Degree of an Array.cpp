/*
 * Given a non-empty array of non-negative integers nums, the degree of this array is defined as the maximum frequency of any one of its elements.
 *
 * Your task is to find the smallest possible length of a (contiguous) subarray of nums, that has the same degree as nums.
 *
 * Example 1:
 * Input: [1, 2, 2, 3, 1]
 * Output: 2
 * Explanation: 
 * The input array has a degree of 2 because both elements 1 and 2 appear twice.
 * Of the subarrays that have the same degree:
 * [1, 2, 2, 3, 1], [1, 2, 2, 3], [2, 2, 3, 1], [1, 2, 2], [2, 2, 3], [2, 2]
 * The shortest length is 2. So return 2.
 * Example 2:
 * Input: [1,2,2,3,1,4,2]
 * Output: 6
 * Note:
 *
 * nums.length will be between 1 and 50,000.
 * nums[i] will be an integer between 0 and 49,999.
 */

/*
 * Source: https://leetcode.com/problems/degree-of-an-array/
 * Description: using two hash map
 * Author: guozheng
 * Data: 20180110
 */

class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, int> startindex, freq;
        int len = nums.size(), max_freq = 0;
        for(int i=0; i<nums.size(); i++) {
            if(startindex.count(nums[i])==0) startindex[nums[i]] = i;
            freq[nums[i]]++;
            if(freq[nums[i]] == max_freq) 
                len = min(i-startindex[nums[i]]+1, len);
            if(freq[nums[i]] > max_freq) {
                len = i-startindex[nums[i]]+1;
                max_freq = freq[nums[i]];
            }
        }
        return len;
    }
};
