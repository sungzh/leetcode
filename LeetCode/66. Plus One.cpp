/*
 * Given a non-negative integer represented as a non-empty array of digits, plus one to the integer.
 *
 * You may assume the integer do not contain any leading zero, except the number 0 itself.
 *
 * The digits are stored such that the most significant digit is at the head of the list.
 *
 */

/**
 * * Source: https://leetcode.com/problems/plus-one/
 * * Description: Easy Question, no track
 * * Author: guozheng
 * * Data: 20170902
 * */

#include<vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        for(int i = digits.size()-1; i >= 0; i--) {
            int val = (digits[i] + carry)%10;
            carry = (digits[i] + carry)/10;
            digits[i] = val;
            if(carry == 0)
                break;
        }
        if(carry == 1) {
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};
