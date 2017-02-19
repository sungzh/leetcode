//Given a binary tree, find the maximum path sum.
//
//For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The path must contain at least one node and does not need to go through the root.
//
//For example:
//Given the below binary tree,
//
//       1
//      / \
//     2   3
//Return 6.
//
//Subscribe to see which companies asked this question.
//
//Show Tags
//Show Similar Problems
//

/**
 ** Definition for a binary tree node.
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

    int maxPathSum(TreeNode* root, int& maxSum) {
        if( NULL== root) return 0;

        int left = maxPathSum(root->left, maxSum);
        int right = maxPathSum(root->right, maxSum);

        int val = root->val;
        int maxBranch = left > right ? max(left+val, val): max(right+val, val);
        int m = max(left+right+val, maxBranch);
        maxSum = max(maxSum, m);

        return maxBranch;
    }


    int maxPathSum(TreeNode* root) {
        int maxSum = -2147483647 - 1;
        maxPathSum(root, maxSum);
        return  maxSum; 
    }
};


