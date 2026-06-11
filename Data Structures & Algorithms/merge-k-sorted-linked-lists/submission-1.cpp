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
    ListNode* merge(ListNode* p,ListNode* q){
        if(!p&&!q) return p;
        else if(p==NULL) return q;
        else if(q==NULL) return p;
        ListNode* newHead=new ListNode(-1);
        ListNode* temp=newHead;
        while(p!=NULL&&q!=NULL){
            if(p->val<=q->val){
                temp->next=p;
                p=p->next;
            }
            else {
                temp->next=q;
                q=q->next;
            }
            temp=temp->next;
        }
        while(p!=NULL){
            temp->next=p;
            p=p->next;
            temp=temp->next;
        }
        while(q!=NULL){
            temp->next=q;
            q=q->next;
            temp=temp->next;
        }
        return newHead->next;
    }
    ListNode* mergeList(int low,int high,vector<ListNode*>& lists){
        if(low>high) return NULL;
        else if(low==high) return lists[low];
        int mid=(low+high)/2;
        ListNode* left=mergeList(low,mid,lists);
        ListNode* right=mergeList(mid+1,high,lists);
        return merge(left,right);
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n=lists.size();
        return mergeList(0,n-1,lists);
    }
};
