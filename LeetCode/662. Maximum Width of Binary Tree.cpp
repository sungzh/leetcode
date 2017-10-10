/*
 * Given a binary tree, write a function to get the maximum width of the given tree. The width of a tree is the maximum width among all levels. The binary tree has the same structure as a full binary tree, but some nodes are null.
 *
 * The width of one level is defined as the length between the end-nodes (the leftmost and right most non-null nodes in the level, where the null nodes between the end-nodes are also counted into the length calculation.
 *
 * Example 1:
 * Input: 
 *
 *            1
 *          /   \
 *         3     2
 *        / \     \  
 *       5   3     9 
 *
 * Output: 4
 * Explanation: The maximum width existing in the third level with the length 4 (5,3,null,9).
 *
 * Example 2:
 * Input: 
 *
 *           1
 *          /  
 *         3    
 *        / \       
 *       5   3     
 *
 * Output: 2
 * Explanation: The maximum width existing in the third level with the length 2 (5,3).
 *
 * Example 3:
 * Input: 
 *
 *           1
 *          / \
 *         3   2 
 *        /        
 *       5      
 *
 * Output: 2
 * Explanation: The maximum width existing in the second level with the length 2 (3,2).
 *
 * Example 4:
 * Input: 
 *
 *           1
 *          / \
 *         3   2
 *        /     \  
 *       5       9 
 *      /         \
 *     6           7
 * Output: 8
 * Explanation:The maximum width existing in the fourth level with the length 8 (6,null,null,null,null,null,null,7).
 *
 * Note: Answer will in the range of 32-bit signed integer.
 */

/*
 * Source: https://leetcode.com/problems/maximum-width-of-binary-tree
 * Description: using vector to store every level width, left is 2*node_i, right is 2*node_i+1
 * Author: guozheng
 * Data: 20171010
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *   int val;
 *   TreeNode *left;
 *   TreeNode *right;
 *   TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 **/
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        return dfs(root, 0, 1, vector<pair<int, int>>() = {});
    }

    int dfs(TreeNode* root, int level, int order, vector<pair<int, int>>& vec){
        if(root == NULL) return 0;
        if(vec.size() == level) vec.push_back({order, order});
        else vec[level].second = order;
        return max( {vec[level].second - vec[level].first + 1, dfs(root->left, level+1, 2*order, vec),  dfs(root->right, level+1, 2*order+1, vec) });
    }
};
