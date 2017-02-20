//Given an array of non-negative integers, you are initially positioned at the first index of the array.
//
//Each element in the array represents your maximum jump length at that position.
//
//Determine if you are able to reach the last index.
//
//For example:
//A = [2,3,1,1,4], return true.
//
//A = [3,2,1,0,4], return false.
//
//Subscribe to see which companies asked this question.

class Solution {
public:
    bool canJump(vector<int>& nums) {
        if( nums.size() <= 0 ) return false;

        int coverPos = 0;

        for(int i = 0; i <= coverPos && i < nums.size(); i++) {
            if( coverPos < nums[i] + i) {
                coverPos = nums[i] + i;
            }

            if( coverPos >= nums.size()-1 ) {
                return true;
            }
        }
        return false;
    }
};
