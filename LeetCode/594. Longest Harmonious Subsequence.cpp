/*
 * We define a harmonious array is an array where the difference between its maximum value and its minimum value is exactly 1.
 *
 * Now, given an integer array, you need to find the length of its longest harmonious subsequence among all its possible subsequences.
 *
 * Example 1:
 * Input: [1,3,2,2,5,2,3,7]
 * Output: 5
 * Explanation: The longest harmonious subsequence is [3,2,2,2,3].
 * Note: The length of the input array will not exceed 20,000.
 */

/*
 * Source: https://leetcode.com/problems/longest-harmonious-subsequence/
 * Description: using map to count the nummber
 * Author: guozheng
 * Data: 20180130
 */

class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> m;
        for(int num:nums)
            m[num]++;
        int res=0;
        for(auto it:m) 
            if(m.count(it.first-1)>0) 
                res = max(res, it.second + m[it.first-1]);
        return res;
    }
};
