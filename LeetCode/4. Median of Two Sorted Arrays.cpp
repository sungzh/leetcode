//There are two sorted arrays nums1 and nums2 of size m and n respectively.
//
//Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
//
//Example 1:
//nums1 = [1, 3]
//nums2 = [2]
//
//The median is 2.0
//Example 2:
//nums1 = [1, 2]
//nums2 = [3, 4]
//
//The median is (2 + 3)/2 = 2.5
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    double search(vector<int>& nums1, int s1, int e1, vector<int>& nums2, int s2, int e2, int aim){
        if (e1 > e2)
            return search(nums2, s2, e2, nums1, s1, e1, aim);
        if (e1 == 0)
            return nums2[s2+aim-1];
        if (aim == 1)
            return min(nums1[s1], nums2[s2]);
        int aim1 = min(e1, aim/2);
        int aim2 = aim - aim1;
        if (nums1[s1+aim1-1] < nums2[s2+aim2-1])
            return search(nums1, s1+aim1, e1-aim1, nums2, s2, e2, aim-aim1);
        if (nums1[s1+aim1-1] > nums2[s2+aim2-1])
            return search(nums1, s1, e1, nums2, s2+aim2, e2-aim2, aim-aim2);
        return nums1[aim1-1];
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // if(nums1.size() == 0 && nums2.size() == 0) return 0.0;
        // if(nums1.size() == 0) return nums2.size()%2==1 ? nums2[nums2.size()/2] : (nums2[nums2.size()/2-1] + nums2[nums2.size()/2])/2.0; 
        // if(nums2.size() == 0) return nums1.size()%2==1 ? nums1[nums1.size()/2] : (nums1[nums1.size()/2-1] + nums1[nums1.size()/2])/2.0; 
        if( (nums1.size() + nums2.size())%2 )
            return search(nums1, 0, nums1.size(), nums2, 0, nums2.size(), (nums1.size() + nums2.size()+1)/2);
        return 0.5* (search(nums1, 0, nums1.size(), nums2, 0, nums2.size(), (nums1.size() + nums2.size())/2) + search(nums1, 0, nums1.size(), nums2, 0, nums2.size(), (nums1.size() + nums2.size())/2 + 1));
        
    }
};

int main() {
    Solution s;
    vector<int> nums1, nums2;
    nums1.clear(); nums2.clear();
    nums1.push_back(1);nums1.push_back(3);
    nums2.push_back(2);
    double res = s.findMedianSortedArrays(nums1, nums2);
    cout<< res <<endl;
    nums1.clear(); nums2.clear();
    nums1.push_back(1);nums1.push_back(2);
    nums2.push_back(3);nums2.push_back(4);
    res = s.findMedianSortedArrays(nums1, nums2);
    cout<< res <<endl;
    return 0;
}
