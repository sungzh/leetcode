/*
 * Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.
 *
 * Example 1:
 *
 * 11110
 * 11010
 * 11000
 * 00000
 * Answer: 1
 *
 * Example 2:
 *
 * 11000
 * 11000
 * 00100
 * 00011
 * Answer: 3
 *
 * Credits:
 * Special thanks to @mithmatt for adding this problem and creating all test cases.
 */

/*
 * Source: https://leetcode.com/problems/number-of-islands/
 * Description: dfs
 * Author: guozheng
 * Data: 20171125
 */

class Solution {
public:
    int n,m;
    int numIslands(vector<vector<char>>& grid) {
        n=grid.size();
        if(n==0) return 0;
        int count = 0;
        m = grid[0].size();
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                if(grid[i][j] == '1') {
                    dfs(grid, i, j);
                    count++;
                }
        return count;
    }
    
    void dfs(vector<vector<char>>& grid, int i, int j) {
        if(i<0 || j<0 || i>=n || j>=m || grid[i][j] !='1') return;
        grid[i][j] = '0';
        dfs(grid, i+1, j);
        dfs(grid, i-1, j);
        dfs(grid, i, j+1);
        dfs(grid, i, j-1);
    }
};
