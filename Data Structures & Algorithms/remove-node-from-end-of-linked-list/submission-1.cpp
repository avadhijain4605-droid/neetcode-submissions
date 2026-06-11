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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
       int len=0;
       ListNode* temp=head;
       while(temp){
        len++;
        temp=temp->next;
       } 
       cout<<len<<endl;
       temp=head;
       int a=len-n-1;
       if(len==n){
        ListNode* newHead=head->next;
        delete head;
        return newHead;
       } 
       while(a>0){
        temp=temp->next;
        a--;
       }
       ListNode* rem=temp->next;
       temp->next=rem->next;
       delete rem;
       return head;
    }
};
