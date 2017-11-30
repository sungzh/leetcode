/*
 * Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.
 *
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
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
 * Source: https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/
 * Description: the same to 108, find the mid, then dp
 * Author: guozheng
 * Data: 20171130
 */

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        return helper(head, NULL);
    }

    TreeNode* helper(ListNode* start, ListNode* end) {
        if(start == end) return NULL;
        ListNode* slow=start;
        ListNode* fast=start;
        while(fast!=end && fast->next!=end) {
            fast = fast->next->next;
            slow = slow->next;
        }
        TreeNode *node = new TreeNode(slow->val);
        node->left = helper(start, slow);
        node->right = helper(slow->next, end);
        return node;
    }
};
