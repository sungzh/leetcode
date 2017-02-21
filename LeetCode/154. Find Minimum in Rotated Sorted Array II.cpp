//Follow up for "Find Minimum in Rotated Sorted Array":
//What if duplicates are allowed?
//
//Would this affect the run-time complexity? How and why?
//Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
//
//(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
//
//Find the minimum element.
//
//The array may contain duplicates.
//
//Subscribe to see which companies asked this question.

#include<vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;

        while( high-low > 1) {
            while( high-low>1 && nums[low] == nums[high] ) {
                low++;
            }

            int mid = low + (high-low)/2;
            if(nums[low] <= nums[mid] && nums[mid] <= nums[high]) {
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

        if( high == low ) return nums[low];
        return nums[low] < nums[high] ? nums[low] : nums[high];
                        
    }
};
