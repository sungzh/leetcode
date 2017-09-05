/*
 * Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times. The algorithm should run in linear time and in O(1) space.
 */

/*
 * Source: https://leetcode.com/problems/majority-element-ii/
 * Description: the same with one, key tow variable
 * Author: guozheng
 * Data: 20170905
 */

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int candidate1=0, candidate2=1;
        int count1=0, count2=0;
        vector<int> res;
        for(int num:nums){
            if(candidate1 == num) count1++;
            else if(candidate2 == num) count2++;
            else if(count1 == 0) {candidate1 = num; count1++;}
            else if(count2 == 0) {candidate2 = num; count2++;}
            else {
                count1--;count2--;;
            }
        }
        count1 = 0, count2 = 0;
        for(int num:nums){
            if(candidate1 == num) count1++;
            if(candidate2 == num) count2++;
        }
        if(count1 > nums.size()/3) res.push_back(candidate1);
        if(count2 > nums.size()/3) res.push_back(candidate2);
        return res;
    }
};
