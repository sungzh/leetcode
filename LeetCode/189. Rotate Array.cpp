//Rotate an array of n elements to the right by k steps.
//
//For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].
//
//Note:
//Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.
//
//[show hint]
//Hint:
//Could you do it in-place with O(1) extra space?
//Related problem: Reverse Words in a String II
//
//
//Credits:
//Special thanks to @Freezen for adding this problem and creating all test cases.
//
//Subscribe to see which companies asked this question.
//

#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
    void reverseArray(vector<int>& nums, int start, int end){
        int temp;
        while(start < end) {
            int temp = nums[start];
            nums[start++] = nums[end];
            nums[end--] = temp;
        }
    }

    void rotate(vector<int>& nums, int k) {
        if(k<=0) return;
        int n = nums.size();
        k %= n;
        reverseArray(nums, n-k, n-1);
        reverseArray(nums, 0, n-k-1);
        reverseArray(nums, 0, n-1);
    }
};
