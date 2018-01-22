/*
 * Suppose you have a long flowerbed in which some of the plots are planted and some are not. However, flowers cannot be planted in adjacent plots - they would compete for water and both would die.
 *
 * Given a flowerbed (represented as an array containing 0 and 1, where 0 means empty and 1 means not empty), and a number n, return if n new flowers can be planted in it without violating the no-adjacent-flowers rule.
 *
 * Example 1:
 * Input: flowerbed = [1,0,0,0,1], n = 1
 * Output: True
 * Example 2:
 * Input: flowerbed = [1,0,0,0,1], n = 2
 * Output: False
 * Note:
 * The input array won't violate no-adjacent-flowers rule.
 * The input array size is in the range of [1, 20000].
 * n is a non-negative integer which won't exceed the input array size.
 */

/*
 * Source: https://leetcode.com/problems/can-place-flowers/
 * Description: get prev and next
 * Author: guozheng
 * Data: 20180122
 */

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        for(int i=0; i<flowerbed.size() && n>0; i++) {
            if(flowerbed[i] == 0) {
                int next = (i==flowerbed.size()-1) ? 0 : flowerbed[i+1];
                int prev = (i==0) ? 0:flowerbed[i-1];
                if(next == 0 && prev == 0) {
                    flowerbed[i] = 1;
                    n--;
                }
            }
        }
        return n==0;
    }
};
