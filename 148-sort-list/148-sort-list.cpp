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
    
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(-1), *curr=head;
        
        while(l1 && l2) {
            if(l1->val < l2->val) {
                curr->next = l1;
                l1=l1->next;
            } else {
                curr->next = l2;
                l2=l2->next;
            }
            curr=curr->next;
        }
        
        if(l1) curr->next = l1;
        if(l2) curr->next = l2;
        
        return head->next;
    }
    
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* fast=head, *slow=head, *temp=NULL;
        
        while(fast && fast->next) {
            temp = slow;
            fast=fast->next->next;
            slow=slow->next;
        }
        
        temp->next = NULL;
        ListNode *l1 = sortList(head);
        ListNode *l2 = sortList(slow);
        
        return merge(l1, l2);
    }
};