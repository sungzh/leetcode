/*
 * Given an array of integers, find out whether there are two distinct indices i and j in the array such that the absolute difference between nums[i] and nums[j] is at most t and the absolute difference between i and j is at most k.
 *
 */

/*
 * Source: https://leetcode.com/problems/contains-duplicate-iii/
 * Description: using lower_bound to get the x and use the formula
 * Author: guozheng
 * Data: 20170906
 */

#include<set>
#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<long> w;
        for(int i = 0; i < nums.size(); i++) {
            if(i > k) w.erase(nums[i-k-1]);
            // | x-nums[i] | <= t ->     -t < x-nums[i] < t
            auto pos = w.lower_bound(long(nums[i]) - t);
            if(pos != w.end()  && long(*pos) - nums[i] <= t) return true;
            w.insert(nums[i]);
        }
        return false;
    }
};

int main() {
    vector<int> v;
    v.push_back(2147483647);
    v.push_back(-2147483647);
    Solution s;
    //cout<<s.containsNearbyAlmostDuplicate(v, 1, 2147483647)<<endl;
    v.clear();
    v.push_back(-2147483647);
    v.push_back(-2147483647);
    cout<<s.containsNearbyAlmostDuplicate(v, 3, 3)<<endl;
    return 0;
}
