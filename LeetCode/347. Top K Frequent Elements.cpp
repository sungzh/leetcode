/*
 * Given a non-empty array of integers, return the k most frequent elements.
 *
 * For example,
 * Given [1,1,1,2,2,3] and k = 2, return [1,2].
 *
 * Note: 
 * You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
 * Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
 */

/**
 * Source: https://leetcode.com/problems/top-k-frequent-elements/
 * Description: Also boundary, take me a lot of time
 * Author: guozheng
 * Data: 20170902
 */

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> result;
        unordered_map<int, int>  freq;
        vector<vector<int> > cells(nums.size()+1, vector<int>());
        for(int num : nums) freq[num]++;
        for(auto& it:freq) cells[it.second].push_back(it.first);
        for(int i = nums.size(); i > 0 && k != 0; i--) {
            int len = cells[i].size();
            int n = min(k, len);
            if(n == 0) continue;
            result.insert(result.end(), cells[i].begin(), cells[i].begin() + n);
            k = k - n;
        }
        return result;
    }
};

int main()
{
    Solution s;
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(2);
    nums.push_back(3);
    int k = 2;
    vector<int> res = s.topKFrequent(nums, k);
    for(int r:res)cout<<r<<",";
    cout<<endl;
}
