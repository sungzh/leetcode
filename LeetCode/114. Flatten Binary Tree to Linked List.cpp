/*
 * Given a binary tree, flatten it to a linked list in-place.
 *
 * For example,
 * Given
 *
 *          1
 *         / \
 *        2   5
 *       / \   \
 *      3   4   6
 *  The flattened tree should look like:
 *      1
 *       \
 *        2
 *         \
 *          3
 *           \
 *            4
 *             \
 *              5
 *               \
 *                6
 *
 */
/*
 * * Source: https://leetcode.com/problems/flatten-binary-tree-to-linked-list/
 * * Description: dfs, must care which binary need first
 * * Author: guozheng
 * * Data: 20170903
 **/

#include<iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* prev = NULL;
    void flatten(TreeNode* root) {
        if(root == NULL) return;
        flatten(root->right);
        flatten(root->left);
        root->right = prev;
        root->left = NULL;
        prev = root;
    }
};

int main() {
    TreeNode r(1);
    TreeNode l(2);
    r.left = &l;
    Solution s;
    s.flatten(&r);
    cout<<r.right->val<<endl;
}

