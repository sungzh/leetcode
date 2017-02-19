//Given a positive integer num, write a function which returns True if num is a perfect square else False.
//
//Note: Do not use any built-in library function such as sqrt.
//
//Example 1:
//
//Input: 16
//Returns: True
//Example 2:
//
//Input: 14
//Returns: False
//Credits:
//Special thanks to @elmirap for adding this problem and creating all test cases.

class Solution {
public:
    bool isPerfectSquare(int num) {
        int left = 1, right = num;
        while(left <= right) {
            long mid = left+ (right - left)/2;
            if( mid*mid == num) return true;
            if( mid*mid < num) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return false;
    }
};
