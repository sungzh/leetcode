//Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
//
//Note: The solution set must not contain duplicate triplets.
//
//For example, given array S = [-1, 0, 1, 2, -1, -4],
//
//A solution set is:
//[
//  [-1, 0, 1],
//  [-1, -1, 2]
//]
//Subscribe to see which companies asked this question.

class Solution {
public:
    vector<vector<int> > threeSum(vector<int>& nums) {

        vector<vector<int> > result;
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        for(int i = 0; i < n-2; i++) {

            if(i>0 && nums[i-1]==nums[i]) continue;
            int a = nums[i];
            int left = i+1;
            int right = n-1;
            while( left < right ) {
                int b = nums[left];
                int c = nums[right];
                if(a+b+c == 0) {
                    vector<int> v;
                    v.push_back(a);
                    v.push_back(b);
                    v.push_back(c);
                    result.push_back(v);

                    while(left<n-1 && nums[left] == nums[left+1]) left++;
                    while(right>0 && nums[right] == nums[right-1]) right--;
                    left++;
                    right--;
                } else if( a+b+c > 0) {
                    while(right>0 && nums[right] == nums[right-1]) right--;
                    right--;
                } else {
                    while(left<n-1 && nums[left] == nums[left+1]) left++;
                    left++;
                }
            }
        }
        return result;
    }
};
