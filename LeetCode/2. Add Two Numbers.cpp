/*
 *
 * You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
 *
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
 */


/*
 * Definition for singly-linked list.
 */
// using array to eliminate complex logic
#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 

class Solution {
    public:
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

            int x = 0, y = 0, carry = 0, sum = 0;
            ListNode* res = NULL;
            ListNode** p = &res;
            
            while(l1 != NULL || l2 != NULL) {
                x = 0, y = 0;
                if(l1 != NULL) {
                    x = l1->val;
                    l1 = l1->next;
                }
                if(l2 != NULL) {
                    y = l2->val;
                    l2 = l2->next;
                }
                sum = x + y + carry;
                ListNode* node = new ListNode(sum%10);
                carry = sum/10;
                *p = node;
                p = (&node->next);
            }
            if(carry > 0) {
                ListNode* tail = new ListNode(carry);
                *p = tail;
            }
            return res;
        }
};

int main() 
{
    ListNode* l1 = new ListNode(3);
    //ListNode* l11 = new ListNode(4);
    //ListNode* l12 = new ListNode(3);
    //l1->next = l11; l11->next = l12;

    ListNode* l2 = new ListNode(5);
    ListNode* l21 = new ListNode(6);
    ListNode* l22 = new ListNode(2);
    l2->next = l21; l21->next = l22;
    Solution* s = new Solution();
    ListNode* res = s->addTwoNumbers(l1, l2);
    cout<<"start"<<endl;
    while(res != NULL) {
        cout<<res->val<<endl;
        res = res->next;
    }
    cout<<"end"<<endl;
    return 0;

}

