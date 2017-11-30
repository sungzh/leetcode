/*
 * Given a non-empty special binary tree consisting of nodes with the non-negative value, where each node in this tree has exactly two or zero sub-node. If the node has two sub-nodes, then this node's value is the smaller value among its two sub-nodes.
 *
 * Given such a binary tree, you need to output the second minimum value in the set made of all the nodes' value in the whole tree.
 *
 * If no such second minimum value exists, output -1 instead.
 *
 * Example 1:
 * Input: 
 *     2
 *    / \
 *   2   5
 *      / \
 *     5   7
 *
 * Output: 5
 * Explanation: The smallest value is 2, the second smallest value is 5.
 * Example 2:
 * Input: 
 *     2
 *    / \
 *   2   2
 *
 * Output: -1
 * Explanation: The smallest value is 2, but there isn't any second smallest value.
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
 * Source: https://leetcode.com/problems/second-minimum-node-in-a-binary-tree/
 * Description: parent <= children, if equal, recursion; else min(children)
 * Author: guozheng
 * Data: 20171123
 */
class Solution {
public:
    int findSecondMinimumValue(TreeNode* root) {
        if(root==NULL) return -1;
        if(root->left == NULL && root->right == NULL) return -1;
        int left = root->left->val; int right = root->right->val;
        if(left == root->val) left = findSecondMinimumValue(root->left);
        if(right == root->val) right =findSecondMinimumValue(root->right);
        if(left != -1 && right != -1)
            return min(left, right);
        else if(left != -1) return  left;
        else return right;
    }
};