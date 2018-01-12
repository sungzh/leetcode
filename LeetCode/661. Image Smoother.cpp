/*
 * Given a 2D integer matrix M representing the gray scale of an image, you need to design a smoother to make the gray scale of each cell becomes the average gray scale (rounding down) of all the 8 surrounding cells and itself. If a cell has less than 8 surrounding cells, then use as many as you can.
 *
 * Example 1:
 * Input:
 * [[1,1,1],
 *  [1,0,1],
 *  [1,1,1]]
 * Output:
 * [[0, 0, 0],
 *  [0, 0, 0],
 *  [0, 0, 0]]
 * Explanation:
 *  For the point (0,0), (0,2), (2,0), (2,2): floor(3/4) = floor(0.75) = 0
 *  For the point (0,1), (1,0), (1,2), (2,1): floor(5/6) = floor(0.83333333) = 0
 *  For the point (1,1): floor(8/9) = floor(0.88888889) = 0
 * Note:
 *  The value in the given matrix is in the range of [0, 255].
 *  The length and width of the given matrix are in the range of [1, 150].
 */

/*
 * Source: https://leetcode.com/problems/image-smoother/
 * Description: using higher 8-bit to store value
 * Author: guozheng
 * Data: 20180112
 */

class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        int m = M.size(), n = M[0].size();
        vector<vector<int>> dirs={{0,-1}, {0,1},{1,0},{-1,0},{1,1},{-1,-1},{1,-1},{-1,1}};
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                int sum = M[i][j], cnt=1;
                for(vector<int> dir:dirs) {
                    int x=i+dir[0],y=j+dir[1];
                    if(x<0 || y<0 || x>=m || y>=n) continue;
                    sum += (M[x][y]&0xFF);
                    cnt++;
                }
                M[i][j] |= ((sum/cnt)<<8);
            }
        }
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                M[i][j]>>=8;
        return M;
    }
};
