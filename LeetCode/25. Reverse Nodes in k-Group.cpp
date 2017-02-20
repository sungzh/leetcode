//Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
//
//k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.
//
//You may not alter the values in the nodes, only nodes itself may be changed.
//
//Only constant memory is allowed.
//
//For example,
//Given this linked list: 1->2->3->4->5
//
//For k = 2, you should return: 2->1->4->3->5
//
//For k = 3, you should return: 3->2->1->4->5
//
//Subscribe to see which companies asked this question.


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 *  };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if( k<=0 ) return head;
        ListNode fake(0);
        fake.next = head;
        ListNode *p = &fake;

        while(p) {
            p->next = reverseList(p->next, k);
            for(int i=0; p && i<k; i++) {
                p = p->next;
            }
        }
        return fake.next;
    }

    ListNode* reverseList(ListNode *head, int k) {
        ListNode* pEnd = head;
        while( pEnd && k>0 ) {
            pEnd = pEnd->next;
            k--;
        }
        if( k>0 ) return head;

        ListNode *pHead = pEnd, *p = head;
        while( p!=pEnd ) {
            ListNode *q = p->next;
            p->next = pHead;
            pHead = p;
            p = q;
        }
        return pHead;
    }
};
