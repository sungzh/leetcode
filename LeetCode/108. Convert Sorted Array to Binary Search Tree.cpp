/*
 * Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/*
 * Source: https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
 * Description: dp , interview in mobike on 20171127
 * Author: guozheng
 * Data: 20171130
 */

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size() == 0) return NULL;
        TreeNode *root = helper(nums, 0, nums.size()-1);
        return root;
    }
    
    TreeNode* helper(vector<int>& nums, int start, int end) {
        if(start>end) return NULL;
        int mid=(start+end)/2;
        TreeNode *node = new TreeNode(nums[mid]);
        node->left=helper(nums, start, mid-1);
        node->right=helper(nums, mid+1, end);
        return node;
    }
};
