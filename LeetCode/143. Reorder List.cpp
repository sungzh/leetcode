/*
 * Given a singly linked list L: L0→L1→…→Ln-1→Ln,
 * reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…
 *
 * You must do this in-place without altering the nodes' values.
 *
 * For example,
 * Given {1,2,3,4}, reorder it to {1,4,2,3}.
 */

/*
 * Source: https://leetcode.com/problems/reorder-list/
 * Description:  find the mid, reverse the half, reorder one by one
 * Author: guozheng
 * Data: 20171126
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
    void reorderList(ListNode* head) {
        if(head==NULL || head->next==NULL) return;
        ListNode *p1 = head, *p2=head;
        while(p2->next&&p2->next->next) {
            p1=p1->next;
            p2=p2->next->next;
        }

        ListNode *preMid = p1, *preCur=p1->next;
        while(preCur->next!=NULL) {
            ListNode* cur = preCur->next;
            preCur->next = cur->next;
            cur->next=preMid->next;
            preMid->next=cur;
        }

        p1=head,p2=preMid->next;
        while(p1!=preMid) {
            preMid->next=p2->next;
            p2->next=p1->next;
            p1->next=p2;
            p1=p2->next;
            p2=preMid->next;
        }
    }
};
