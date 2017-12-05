/*
 * Given a singly linked list, determine if it is a palindrome.
 *
 * Follow up:
 * Could you do it in O(n) time and O(1) space?
 */

/*
 * Source:  https://leetcode.com/problems/palindrome-linked-list/
 * Description: reverse the half string
 * Author: guozheng
 * Data: 20171205
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
    bool isPalindrome(ListNode* head) {
        ListNode *slow=head, *fast=head, *rev=NULL;
        while(fast && fast->next) {
            fast = fast->next->next;
            ListNode *next = slow->next;
            slow->next = rev;
            rev = slow;
            slow = next;
        }
        if(fast) slow = slow->next;
        while(rev && rev->val == slow->val) {
            slow = slow->next;
            rev = rev->next;
        }
        return not rev;
    }
};
