/*
 * Initially, there is a Robot at position (0, 0). Given a sequence of its moves, judge if this robot makes a circle, which means it moves back to the original place.
 *
 * The move sequence is represented by a string. And each move is represent by a character. The valid robot moves are R (Right), L (Left), U (Up) and D (down). The output should be true or false representing whether the robot makes a circle.
 *
 * Example 1:
 * Input: "UD"
 * Output: true
 * Example 2:
 * Input: "LL"
 * Output: false
 */

/*
 * Source: https://leetcode.com/problems/judge-route-circle/
 * Description: easy question
 * Author: guozheng
 * Data: 20180118
 */

class Solution {
public:
    bool judgeCircle(string moves) {
        int c1=0, c2=0;
        for(char ch: moves)
            if(ch == 'L') c1++;
            else if(ch == 'R') c1--;
            else if(ch == 'U') c2++;
            else if(ch == 'D') c2--;
        return c1==0 && c2==0;
    }
};
