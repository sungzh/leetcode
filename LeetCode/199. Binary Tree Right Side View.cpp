/*
 * Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.
 *
 * For example:
 * Given the following binary tree,
 *    1            <---
 *   /   \
 *  2     3         <---
 *   \     \
 *    5     4       <---
 * You should return [1, 3, 4].
 *
 * Credits:
 * Special thanks to @amrsaqr for adding this problem and creating all test cases.
 */

/*
 * Source: https://leetcode.com/problems/binary-tree-right-side-view
 * Description: right side, use list to store result and level to label
 * Author: guozheng
 * Data: 20171012
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *   int val;
 *   TreeNode *left;
 *   TreeNode *right;
 *   TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 *   };
 **/

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        rightSide(root, result, 0);
        return result;
    }

    void rightSide(TreeNode* root, vector<int>& rightlist, int level) {
        if(root == NULL) return;
        if(rightlist.size() == level) rightlist.push_back(root->val);
        
        rightSide(root->right, rightlist, level+1);
        rightSide(root->left, rightlist, level+1);
    }
};
