//Given an array of integers, find if the array contains any duplicates. Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct.
//
//Subscribe to see which companies asked this question.

#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, bool> m;
        for(auto num : nums) {
            if (m.find(num) != m.end()) return true;
            m[num] = true;
        }
        return false;
    }
};
