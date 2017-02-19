//Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.
//
//Note: The solution set must not contain duplicate quadruplets.
//
//For example, given array S = [1, 0, -1, 0, -2, 2], and target = 0.
//
//A solution set is:
//[
//  [-1,  0, 0, 1],
//  [-2, -1, 1, 2],
//  [-2,  0, 0, 2]
//]
//Subscribe to see which companies asked this question.

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int> > result;
        if(nums.size() < 4) return result;
        sort(nums.begin(), nums.end());

        for(int i = 0; i < nums.size()-3; i++) {
            if(i>0 && nums[i-1] == nums[i]) continue;
            vector<int> n(nums.begin()+i+1, nums.end());
            vector<vector<int> > ret = threeSum(n, target-nums[i]);
            for(int j = 0; j < ret.size(); j++) {
                ret[j].insert(ret[j].begin(), nums[i]);
                result.push_back(ret[j]);
            }
        }
        return result;
    }

    vector<vector<int> > threeSum(vector<int>& nums, int target) {

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
                if(a+b+c == target) {
                    vector<int> v;
                    v.push_back(a);
                    v.push_back(b);
                    v.push_back(c);
                    result.push_back(v);

                    while(left<n-1 && nums[left] == nums[left+1]) left++;
                    while(right>0 && nums[right] == nums[right-1]) right--;
                    left++;
                    right--;
                } else if( a+b+c > target) {
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
