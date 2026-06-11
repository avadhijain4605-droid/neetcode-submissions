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
    ListNode* rev(ListNode* temp) {
        ListNode* pre = NULL;
        ListNode* curr = temp;
        while (curr) {
            ListNode* front = curr->next;
            curr->next = pre;
            pre = curr;
            curr = front;
        }
        return pre;
    }
    void insertInLL(ListNode* slow, ListNode* temp) {
        if (slow->next == NULL) {
            slow->next = temp;
            return;
        }
        ListNode* nxtptr=slow->next;
        slow->next=temp;
        temp->next=nxtptr;
    }
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* temp = slow->next;
        slow->next = NULL;
        temp = rev(temp);
        slow = head;
        while (temp != NULL) {
            ListNode* nxtTemp = temp->next;
            insertInLL(slow, temp);
            temp=nxtTemp;
            slow = slow->next->next;
        }
    }
};
