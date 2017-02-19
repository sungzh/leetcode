//Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.
//
//    For example, given array S = {-1 2 1 -4}, and target = 1.
//
//    The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
//Subscribe to see which companies asked this question.
//

#include<math.h>
#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {

        sort(nums.begin(), nums.end());

        int n = nums.size();
        int ret = nums[0] + nums[1] + nums[2];
        int left, right, tmp;

        for(int i = 0; i < nums.size(); i++) {
            left = i+1;
            right = nums.size() - 1;

            while(left < right) {
                tmp = nums[i] + nums[left] + nums[right];
                if ( abs(target-tmp) < abs(target-ret)) {
                    ret = tmp;
                    if( ret == target) {
                        return ret;
                    }
                }
                if ( tmp < target) {
                    left++;
                } else {
                    right--;
                }
            }
        }
        return ret;
    }
};
