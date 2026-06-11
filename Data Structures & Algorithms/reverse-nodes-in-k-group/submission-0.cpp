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
    ListNode* reverse(ListNode* head){
        ListNode* pre=NULL;
        ListNode* curr=head;
        while(curr!=NULL){
            ListNode* front=curr->next;
            curr->next=pre;
            pre=curr;
            curr=front;
        } 
        return pre;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        //ListNode* newHead=new ListNode(-1);
        ListNode* temp=head;
        ListNode* prevNode=NULL;
        ListNode* nextNode=NULL;
        while(temp!=NULL){
            ListNode* startNode=temp;
            ListNode* kthNode=temp;
            int c=k-1;
            while(c--&&kthNode){
                kthNode=kthNode->next;
            }
            if(kthNode==NULL){
                //prevNode->next=startNode;
                break;
            }
             nextNode=kthNode->next;
            kthNode->next=NULL;
            kthNode=reverse(startNode);
            if(temp==head){
                head=kthNode;
            }else{
                prevNode->next=kthNode;
            }
             prevNode=temp;
            temp=nextNode;
        }
        if(temp!=NULL){
            prevNode->next=temp;
        }
        return head;
    }
};
