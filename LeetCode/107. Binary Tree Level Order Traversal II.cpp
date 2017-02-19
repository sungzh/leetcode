//Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).
//
//For example:
//Given binary tree [3,9,20,null,null,15,7],
//    3
//   / \
//  9  20
//    /  \
//   15   7
//return its bottom-up level order traversal as:
//[
// [15,7],
// [9,20],
// [3]
//]
//Subscribe to see which companies asked this question.

/**
 *  * Definition for a binary tree node.
 *   * struct TreeNode {
 *    *     int val;
 *     *     TreeNode *left;
 *      *     TreeNode *right;
 *       *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 *        * };
 *         */
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int> > vv;
        if( root == NULL ) return vv;

        int level = 0;
        TreeNode * last  = root;
        queue<TreeNode* > q;
        
        q.push(root);
        vv.push_back(vector<int>());
        while( !q.empty() ) {
            TreeNode *p = q.front();
            q.pop();

            vv[level].push_back( p->val );
            if( p->left ) q.push( p->left );
            if( p->right ) q.push( p->right );
            if( p == last) {
                level++;
                last = q.back();
                vv.push_back( vector<int>());
            }
        }
        vv.pop_back();
        reverse(vv.begin(), vv.end());
        return vv;
    }
};
