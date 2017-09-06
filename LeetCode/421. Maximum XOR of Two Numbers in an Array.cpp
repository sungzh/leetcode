/*
 * Given a non-empty array of numbers, a0, a1, a2, … , an-1, where 0 ≤ ai < 231.
 *
 * Find the maximum result of ai XOR aj, where 0 ≤ i, j < n.
 *
 * Could you do this in O(n) runtime?
 *
 * Example:
 *
 * Input: [3, 10, 5, 25, 2, 8]
 *
 * Output: 28
 *
 * Explanation: The maximum result is 5 ^ 25 = 28.
 */
/*
 * Source: https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/
 * Description: using if a^b=c, then a^c=b, b^c=a.  every time cal the prefix, step by step
 * Author: guozheng
 * Data: 20170906
 */

#include<vector>
#include<unordered_set>
#include<iostream>
using namespace std;

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int max = 0, mask = 0;
        unordered_set<int> prefixs;
        for(int i = 31; i>=0; i--) {
            mask |= (1 << i);
            prefixs.clear();
            for(int num : nums) {
                prefixs.insert(num&mask);
            }
            int candidate = max | (1<<i);
            for(int prefix:prefixs){
                if(prefixs.find(prefix^candidate)!=prefixs.end()) {
                    max = candidate;
                    break;
                }
            }
        }
        return max;
    }
};

int main() {
    vector<int> v;
    v.push_back(3);
    v.push_back(10);
    v.push_back(5);
    v.push_back(25);
    v.push_back(2);
    v.push_back(8);
    Solution s;
    cout<<s.findMaximumXOR(v)<<endl;
}
