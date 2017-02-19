//Find the contiguous subarray within an array (containing at least one number) which has the largest product.
//
//For example, given the array [2,3,-2,4],
//the contiguous subarray [2,3] has the largest product = 6.
//
//Subscribe to see which companies asked this question.
//
//Show Tags
//Show Similar Problems
//
//
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxPrev = nums[0], minPrev = nums[0];
        int maxHere = nums[0], minHere = nums[0];
        int maxProd = nums[0];

        for(int i=1; i<nums.size(); i++) {
            maxHere = max( max(maxPrev*nums[i], minPrev*nums[i]), nums[i]);
            minHere = min( min(maxPrev*nums[i], minPrev*nums[i]), nums[i]);

            maxProd = max(maxHere, maxProd);
            maxPrev = maxHere;
            minPrev = minHere;
        }

        return maxProd;
                        
    }
};
