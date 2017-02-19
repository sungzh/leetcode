//Given an unsorted array, find the maximum difference between the successive elements in its sorted form.
//
//Try to solve it in linear time/space.
//
//Return 0 if the array contains less than 2 elements.
//
//You may assume all elements in the array are non-negative integers and fit in the 32-bit signed integer range.
//
//Credits:
//Special thanks to @porker2008 for adding this problem and creating all test cases.
//
//Subscribe to see which companies asked this question.
//

#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if (nums.size() < 2) return 0;

        int min = nums[0], max = nums[0];
        for(int i=1; i<nums.size(); i++){
            min = min > nums[i] ? nums[i] : min;
            max = max < nums[i] ? nums[i] : max;
        }

        int bucket_size = (max-min)/nums.size() + 1;
        int bucket_num = (max-min)/bucket_size + 1;
        cout<< bucket_size << " " <<bucket_num<<endl;

        vector<vector<int> > buckets( nums.size());
        for(int i=0; i<nums.size(); i++){
            int idx = (nums[i] - min)/bucket_size;                
            if( buckets[idx].empty()) {
                buckets[idx].push_back(nums[i]);
                buckets[idx].push_back(nums[i]);
            }
            else {
                buckets[idx][0] = buckets[idx][0] > nums[i] ? nums[i] : buckets[idx][0];
                buckets[idx][1] = buckets[idx][1] < nums[i] ? nums[i] : buckets[idx][1];
            }
        }

        int maxGap = 0;
        int prev = 0;
        for(int i = 1; i < buckets.size(); i++) {
            if( buckets[i].empty()) continue;
            int gap = buckets[i][0] - buckets[prev][1];
            maxGap = maxGap > gap ? maxGap : gap;
            prev = i;
        }
        return maxGap;
    }
};

int main() {
    //int a[] = {1,1,1,1,1,5,5,5,5,5};
    int a[] = {1,2};
    vector<int> nums(a, a+sizeof(a)/sizeof(a[0]));
    Solution s;
    cout<< s.maximumGap(nums) <<endl;
}
