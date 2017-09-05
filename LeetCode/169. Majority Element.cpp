/*
 * Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.
 *
 * You may assume that the array is non-empty and the majority element always exist in the array.
 *
 * Credits:
 * Special thanks to @ts for adding this problem and creating all test cases.
 */

/*
 * Source: https://leetcode.com/problems/majority-element
 * Description: Meet on baidu 20170904
 * Author: guozheng
 * Data: 20170905
 */
                        


class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate;
        int count=0;
        for(int num: nums) {
            if(count == 0) candidate = num;
            if(candidate == num)
                count++;
            else
                count--;
        }
        return candidate;
    }
};
