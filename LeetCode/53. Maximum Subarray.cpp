//Find the contiguous subarray within an array (containing at least one number) which has the largest sum.
//
//For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
//the contiguous subarray [4,-1,2,1] has the largest sum = 6.
//
//click to show more practice.
//
//Subscribe to see which companies asked this question.

#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int m = -2147483647 - 1;
        int sum = 0;
        for(int i=0; i<nums.size(); i++) {
            sum += nums[i];
            m = max(sum, m);
            if( sum < 0) {
                sum = 0;
            }
        }
        return m;
    }
};

int main() {
    vector<int> vv;
    vv.push_back(-2);
    vv.push_back(1);
    vv.push_back(-3);
    vv.push_back(4);
    vv.push_back(-1);
    vv.push_back(2);
    vv.push_back(1);
    vv.push_back(-5);
    vv.push_back(4);
    Solution s;
    cout<< s.maxSubArray(vv) << endl;
}
