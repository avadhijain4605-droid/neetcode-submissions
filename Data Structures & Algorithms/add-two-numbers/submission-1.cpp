/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ptr1=l1;
        ListNode* ptr2=l2;
        ListNode* head=new ListNode(-1);
        ListNode* ans=head;
        int carry=0;
        while(ptr1&&ptr2){
            int add=ptr1->val+ptr2->val+carry;
            ans->next=new ListNode(add%10);
            ans=ans->next;
            carry=add/10;
            ptr1=ptr1->next;
            ptr2=ptr2->next;
        }
        while(ptr1){
            int add=ptr1->val+carry;
            ans->next=new ListNode(add%10);
            ans=ans->next;
            carry=add/10;
            ptr1=ptr1->next;
        }
        while(ptr2){
            int add=ptr2->val+carry;
            ans->next=new ListNode(add%10);
            ans=ans->next;
            carry=add/10;
            ptr2=ptr2->next;
        }
        if(carry) ans->next=new ListNode(1);
        return head->next;
    }
};
