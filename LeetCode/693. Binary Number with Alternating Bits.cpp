/*
 * Given a positive integer, check whether it has alternating bits: namely, if two adjacent bits will always have different values.
 *
 * Example 1:
 * Input: 5
 * Output: True
 * Explanation:
 * The binary representation of 5 is: 101
 * Example 2:
 * Input: 7
 * Output: False
 * Explanation:
 * The binary representation of 7 is: 111.
 * Example 3:
 * Input: 11
 * Output: False
 * Explanation:
 * The binary representation of 11 is: 1011.
 * Example 4:
 * Input: 10
 * Output: True
 * Explanation:
 * The binary representation of 10 is: 1010.
 */

/*
 * Source: https://leetcode.com/problems/binary-number-with-alternating-bits/
 * Description: using the alternating bits's nature
 * Author: guozheng
 * Data: 20171126
 */

#include<iostream>
using namespace std;

class Solution {
public:
    bool hasAlternatingBits(int n) {
        return !((n ^= n/4) & n-1);
    }
};

int main() {
    int n = 5;
    cout<<n/4<<endl;
    n ^= n/4;
    cout<<n<<endl;
    cout<<(n ^= n/4) & n-1 <<endl;
    cout<<!((n ^= n/4) & n-1)<<endl;
}
