/*
 * Given numRows, generate the first numRows of Pascal's triangle.
 *
 * For example, given numRows = 5,
 * Return
 *
 * [
 *   [1],
 *   [1,1],
 *   [1,2,1],
 *   [1,3,3,1],
 *   [1,4,6,4,1]
 * ]
 */

/*
 * Source: https://leetcode.com/problems/pascals-triangle
 * Description: start and end is 1
 * Author: guozheng
 * Data: 20171120
 */

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res(numRows);
        for(int line=0; line < numRows; line++) {
            res[line].resize(line+1); 
            res[line][0] = res[line][line] = 1;
            for(int i=1; i<line; i++) {
                res[line][i] = res[line-1][i-1] + res[line-1][i];
            }
        }
        return res;
    }
};
