/*
 * Given two arrays, write a function to compute their intersection.
 *
 * Example:
 * Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2].
 *
 * Note:
 * Each element in the result must be unique.
 * The result can be in any order.
 */

/**
 * Source: https://leetcode.com/problems/intersection-of-two-arrays/
 * Description: easy question, but because it was easy, then the trap is you should consider all scene
 * Author: guozheng
 * Data: 20170903
 */

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> s;
        vector<int> res;
        if(nums1.size() == 0 || nums2.size() == 0) return res;
        for(int num: nums1) s.insert(num);
        for(int num: nums2) 
            if(s.find(num) != s.end()) {
                s.erase(num);
                res.push_back(num);
            }
        return res;
    }
};
