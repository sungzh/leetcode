/*
 * You are given a map in form of a two-dimensional integer grid where 1 represents land and 0 represents water. Grid cells are connected horizontally/vertically (not diagonally). The grid is completely surrounded by water, and there is exactly one island (i.e., one or more connected land cells). The island doesn't have "lakes" (water inside that isn't connected to the water around the island). One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island.
 *
 * Example:
 *
 * [[0,1,0,0],
 *  [1,1,1,0],
 *  [0,1,0,0],
 *  [1,1,0,0]]
 *
 * Answer: 16
 * Explanation: The perimeter is the 16 yellow stripes in the image below:
 */

/*
 * Source: https://leetcode.com/problems/island-perimeter/
 * Description: easy question
 * Author: guozheng
 * Data: 20171221
 */

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int islands = 0, neighbours = 0;
        for(int i=0; i<grid.size(); i++)
            for(int j=0; j<grid[0].size(); j++)
                if(grid[i][j]==1) {
                    islands++;
                    if(i<grid.size()-1 && grid[i+1][j]==1) neighbours++;
                    if(j<grid[i].size()-1 && grid[i][j+1]==1) neighbours++;
                }
        return islands*4-neighbours*2;
    }
};
