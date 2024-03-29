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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(!head) return NULL;
        ListNode *fast=head, *slow=head, *prev=NULL;
        while(fast && fast->next) {
            prev = slow;
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode *mid = slow;
        ListNode *right = mid->next;
        if(prev) prev->next = NULL;
        
        TreeNode *curr = new TreeNode(mid->val);
        if(prev) curr->left = sortedListToBST(head);
        curr->right = sortedListToBST(right);
        
        return curr;
    }
};











