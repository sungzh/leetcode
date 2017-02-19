//Given a list, rotate the list to the right by k places, where k is non-negative.
//
//For example:
//Given 1->2->3->4->5->NULL and k = 2,
//return 4->5->1->2->3->NULL.
//
//Subscribe to see which companies asked this question.

/**
 * Definition for singly-linked list.
 */

#include<iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if( !head || k<=0) {
            return head;
        }

        int len = 1;
        ListNode *p = head;
        while( p->next != NULL) {
            p = p->next;
            len++;
        }

        p->next = head;
        k = len - k%len;

        while(k--) {
            p = p->next;
        }

        head = p->next;
        p->next = NULL;
        return head;
                        
    }
};
