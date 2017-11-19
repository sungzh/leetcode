/*
 * Given a binary tree, determine if it is height-balanced.
 *
 * For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1
 *
 */

/*
 * Source: https://leetcode.com/problems/balanced-binary-tree
 * Description: using dfs, but return height if the tree is balanced, otherwise return -1
 * Author: guozheng
 * Data: 20171119
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
class Solution {
public:
    int depth(TreeNode* root) {
        if(root==NULL) return 0;
        return max(depth(root->left), depth(root->right))+1;
    }

    bool isBalanced(TreeNode* root) {
        if(root==NULL) return true;
        int left = depth(root->left);
        int right = depth(root->right);
        return abs(left-right) <=1 && isBalanced(root->left) && isBalanced(root->right);
    }
};


class Solution {
public:
    int dfs(TreeNode* root) {
        if( root ==NULL) return 0;
        int left = dfs(root->left);
        if(left == -1) return -1;
        int right = dfs(root->right);
        if(right == -1) return -1;
        if(abs(left-right) >1) return -1;
        return max(left,right)+1;
    }                
    bool isBalanced(TreeNode* root) {
        return dfs(root) != -1;
    }
};


