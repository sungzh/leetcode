/*
 * Given a linked list, return the node where the cycle begins. If there is no cycle, return null.
 *
 * Note: Do not modify the linked list.
 *
 * Follow up:
 * Can you solve it without using extra space?
 */

/**
 ** Definition for singly-linked list.
 ** struct ListNode {
 **     int val;
 **     ListNode *next;
 **     ListNode(int x) : val(x), next(NULL) {}
 ** };
 **/

/*
 * Source: https://leetcode.com/problems/linked-list-cycle-ii/
 * Description: start->cycle is L1, cycle->meeting is L2, slow is L1+L2, fast is L1+L2+n*C
 *      C is the cycle, 2(L1+L2) = L1+L2+n*C, L1 = (n-1)C+(C-L2)  so C-L2 is from fast to cycle
 * Author: guozheng
 * Data: 20171207
 */

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL || head->next==NULL) return NULL;
        ListNode *slow=head, *fast=head;
        while(fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) {
                slow = head;
                while(slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }
        return NULL;
    }
};
