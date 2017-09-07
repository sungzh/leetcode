/*
 * You are given a binary tree in which each node contains an integer value.
 *
 * Find the number of paths that sum to a given value.
 *
 * The path does not need to start or end at the root or a leaf, but it must go downwards (traveling only from parent nodes to child nodes).
 *
 * The tree has no more than 1,000 nodes and the values are in the range -1,000,000 to 1,000,000.
 *
 * Example:
 *
 * root = [10,5,-3,3,2,null,11,3,-2,null,1], sum = 8
 *
 *       10
 *      /  \
 *     5   -3
 *    / \    \
 *   3   2   11
 *  / \   \
 * 3  -2   1
 *
 * Return 3. The paths that sum to 8 are:
 *
 * 1.  5 -> 3
 * 2.  5 -> 2 -> 1
 * 3. -3 -> 11
 */

/*
 * Source: https://leetcode.com/problems/path-sum-iii/
 * Description: if just use dfs not record the pre, it will be break off
 * Author: guozheng
 * Data: 20170907
 */


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
    int pathSum(TreeNode* root, int sum) {
        if(root == NULL) return 0;
        return pathSumUp(root, 0, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
        //if(root->left == NULL && root->right == NULL && root->val == sum) { cout<<sum<<"***"<<endl; return 1; }
        //cout<<str<<root->val<<" "<<sum<<endl;
        //return pathSum(root->left, sum-root->val, str+"\t") + pathSum(root->left, sum, str+"\t") + pathSum(root->right, sum-root->val, str+"\t") + pathSum(root->right, sum, str+"\t");
    }

    int pathSumUp(TreeNode* root, int pre, int& sum) {
        if(root ==NULL) return 0;
        int cur = pre + root->val;
        return (cur == sum) + pathSumUp(root->left, cur, sum) + pathSumUp(root->right, cur, sum);
    }

};

int main() {
    TreeNode t1(10), t2(5), t3(-3), t4(3), t5(2), t6(11), t7(3), t8(-2), t9(1);
    t1.left = &t2; t1.right = &t3;
    t2.left = &t4; t2.right = &t5; t3.right = &t6;
    t4.left = &t7; t4.right = &t8; t5.right = &t9;
    Solution s;
    cout<<s.pathSum(&t1, 8, "")<<endl;
}
