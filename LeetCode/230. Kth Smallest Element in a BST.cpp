//Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.
//
//Note: 
//You may assume k is always valid, 1 ≤ k ≤ BST's total elements.
//
//Follow up:
//What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently? How would you optimize the kthSmallest routine?
//
//Hint:
//
//Try to utilize the property of a BST.
//What if you could modify the BST node's structure?
//The optimal runtime complexity is O(height of BST).
//Credits:
//Special thanks to @ts for adding this problem and creating all test cases.
//
//Subscribe to see which companies asked this question.

/**
 * Definition for a binary tree node.
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        if (root == NULL) return 0;

        int result = kthSmallest(root->left, k);
        if( k==0 ) return result;

        k--;
        if( k==0 ) return root->val;

        return kthSmallest(root->right, k);
    }
};
