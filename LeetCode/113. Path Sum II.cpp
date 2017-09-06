/*
 * Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.
 *
 * For example:
 * Given the below binary tree and sum = 22,
 *               5
 *              / \
 *             4   8
 *            /   / \
 *           11  13  4
 *          /  \    / \
 *         7    2  5   1
 * return
 * [
 *  [5,4,11,2],
 *  [5,8,4,5]
 * ]
 */

/**
 ** Definition for a binary tree node.
 ** struct TreeNode {
 **     int val;
 **     TreeNode *left;
 **     TreeNode *right;
 **     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 ** };
 **/
/*
 *  Source: https://leetcode.com/problems/path-sum-ii/
 *  Description: remember the pop_back
 *  Author: guozheng
 *  Data: 20170906
 **/
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<int> _path;
        vector<vector<int>> paths;
        path(root, sum, _path, paths);
        return paths;
    }

    void path(TreeNode* root, int sum, vector<int>& _path, vector<vector<int>>& paths) {
        if(root ==NULL) return ;
        _path.push_back(root->val);
        if(root->left==NULL && root->right==NULL && root->val == sum) paths.push_back(_path);
        path(root->left, sum-root->val, _path, paths);
        path(root->right, sum-root->val, _path, paths);
        _path.pop_back();
    }

};
