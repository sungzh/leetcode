//Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
//
//(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
//
//Find the minimum element.
//
//You may assume no duplicate exists in the array.
//
//Subscribe to see which companies asked this question.

#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;

        while( high-low>1 ) {
            int mid = low + (high - low)/2;
            if(nums[low] < nums[mid] && nums[mid] < nums[high]) {
                return nums[low];
            }
            
            if( nums[low] > nums[mid] ) {
                high = mid;
                continue;
            }
            if( nums[mid] > nums[high] ) {
                low = mid;
                continue;
            }
        }

        //1 element
        if( high == low ) return nums[low];
        //2 elements
        return nums[low] < nums[high] ? nums[low] : nums[high];
    }
};

int main() {
    vector<int> nums;
    nums.push_back(3);
    nums.push_back(2);
    nums.push_back(1);
    Solution s;
    cout<< s.findMin(nums) << endl;
}
