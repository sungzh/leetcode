/*
 * Given a linked list, remove the nth node from the end of list and return its head.
 *
 * For example,
 *
 *    Given linked list: 1->2->3->4->5, and n = 2.
 *
 *    After removing the second node from the end, the linked list becomes 1->2->3->5.
 *    Note:
 *    Given n will always be valid.
 *    Try to do this in one pass.
 */

/*
 * Source: https://leetcode.com/problems/remove-nth-node-from-end-of-list
 * Description: must care the boundary, and using one point pointer the head
 * Author: guozheng
 * Data: 20171118
 */

/**
 ** Definition for singly-linked list.
 ** struct ListNode {
 **     int val;
 **     ListNode *next;
 **     ListNode(int x) : val(x), next(NULL) {}
 ** };
 **/
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode **p=&head, *q=head;
        while(--n) q=q->next;
        while(q->next!=NULL) {
            p = &((*p)->next);
            q = q->next;
        }
        (*p) = (*p)->next;
        return head;
    }
};
