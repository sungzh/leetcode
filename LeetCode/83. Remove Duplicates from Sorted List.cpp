/**
 * Given a sorted linked list, delete all duplicates such that each element appear only once.
 *
 * For example,
 * Given 1->1->2, return 1->2.
 * Given 1->1->2->3->3, return 1->2->3.
 */

/**
 * * Source: https://leetcode.com/problems/remove-duplicates-from-sorted-list/
 * * Description: Easy Question, no track
 * * Author: guozheng
 * * Data: 20170902
 * */


#include<vector>
using namespace std;
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode * p = head;
        while(p != NULL){
            if(p->next != NULL && p->val == p->next->val) {
                p->next = p->next->next;
            }
            else {
                p = p->next;
            }
        }
        return head;
    }
};
