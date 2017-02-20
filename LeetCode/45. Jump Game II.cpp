//Given an array of non-negative integers, you are initially positioned at the first index of the array.
//
//Each element in the array represents your maximum jump length at that position.
//
//Your goal is to reach the last index in the minimum number of jumps.
//
//For example:
//Given array A = [2,3,1,1,4]
//
//The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)
//
//Note:
//You can assume that you can always reach the last index.
//
//Subscribe to see which companies asked this question.

class Solution {
public:
    int jump(vector<int>& nums) {
        if( nums.size() <= 1) return 0;

        int steps = 0;
        int coverPos = 0;
        int n = nums.size();
        for(int i=0; i<= coverPos && i < n; ){
            if( nums[i] == 0) return -1;
            if(coverPos < nums[i] + i) {
                coverPos = nums[i] + i;
                steps++;
            }

            if(coverPos >= n-1) {
                return steps;
            }

            int nextPos = 0;
            int maxDistance = 0;
            for(int j = i+1; j <= coverPos; j++) {
                if( nums[j] + j > maxDistance) {
                    maxDistance = nums[j] + j;
                    nextPos = j;
                }
            }
            i = nextPos;
        }
        return steps;
    }
};
