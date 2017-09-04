/*
 * Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.
 *
 * The Sudoku board could be partially filled, where empty cells are filled with the character '.'.
 *
 * A partially filled sudoku which is valid.
 *
 * Note:
 * A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated.
 */

/**
 * Source: https://leetcode.com/problems/valid-sudoku
 * Description: using three array to label the status
 * Author: guozheng
 * Data: 20170904
 */


class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int row[9][9] = {0}, col[9][9] = {0}, cell[9][9] = {0};
        for(int i = 0; i < board.size(); i++)
            for(int j = 0; j < board[i].size(); j++)
                if(board[i][j] != '.') {
                    int num = board[i][j]-'0'-1, k = i/3*3+j/3;
                    if(row[i][num] || col[j][num] || cell[k][num])
                        return false;
                    row[i][num] = col[j][num] = cell[k][num] = 1;
                }
        return true;
    }
};
