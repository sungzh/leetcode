/*
 * Given a non-empty integer array of size n, find the minimum number of moves required to make all array elements equal, where a move is incrementing n - 1 elements by 1.
 *
 * Example:
 *
 * Input:
 * [1,2,3]
 *
 * Output:
 * 3
 *
 * Explanation:
 * Only three moves are needed (remember each move increments two elements):
 *
 * [1,2,3]  =>  [2,3,3]  =>  [3,4,3]  =>  [4,4,4]
 */

/*
 * Source: https://leetcode.com/problems/minimum-moves-to-equal-array-elements/
 * Description: sum as the sum of the array, n as the num of the array.
 *  after m move, sum + m*(n-1) = x *n;   x is the num value and x is minValue + m
 *  the sum + m*n - m = minvalue*n + m*n;   m = sum - minvalue*n
 * Author: guozheng
 * Data: 20170907
 */
class Solution {
public:
    int minMoves(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int sum = 0, minvalue = nums[0];
        for(int num:nums) {
            sum = sum + num;
            minvalue = min(minvalue, num);
        }
        return sum - minvalue*nums.size();                
    }
};
