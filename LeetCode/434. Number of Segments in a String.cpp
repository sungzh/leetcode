/*
 * Count the number of segments in a string, where a segment is defined to be a contiguous sequence of non-space characters.
 *
 * Please note that the string does not contain any non-printable characters.
 *
 * Example:
 *
 * Input: "Hello, my name is John"
 * Output: 5
 */

/*
 * Source: https://leetcode.com/problems/number-of-segments-in-a-string/
 * Description: easy question
 * Author: guozheng
 * Data: 20171229
 */

class Solution {
public:
    int countSegments(string s) {
        char pre = ' ';
        int count = 0;
        for(char ch:s) {
            if(ch != ' ' && pre == ' ')
                count++;
            pre = ch;
        }
        return count;
    }
};
