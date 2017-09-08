/*
 * We are playing the Guess Game. The game is as follows:
 *
 * I pick a number from 1 to n. You have to guess which number I picked.
 *
 * Every time you guess wrong, I'll tell you whether the number is higher or lower.
 *
 * You call a pre-defined API guess(int num) which returns 3 possible results (-1, 1, or 0):
 *
 * -1 : My number is lower
 *  1 : My number is higher
 *  0 : Congrats! You got it!
 * Example:
 * n = 10, I pick 6.
 *
 * Return 6.
 */
/*
 * Source: https://leetcode.com/problems/guess-number-higher-or-lower/
 * Description: binary search, use (r-l)/2+l not (l+r)/2 to avoid overflow
 * Author: guozheng
 * Data: 20170908
 */

// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0

int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int l=0, r=n, m;
        while(l<=r) {
            m = (r-l)/2+l;
            if(guess(m) == 0) return m;
            else if(guess(m)==-1) r=m-1;
            else if(guess(m)==1) l=m+1;
        }
        return -1;
    }
};
