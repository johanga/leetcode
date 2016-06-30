/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution 
{
private:
    TreeNode* sortedListToBSTR(ListNode** head, int start, int end) 
    {
        int distance = end - start;
        if(distance == 0) return NULL;
        if(head == NULL) return NULL;
        TreeNode* root = new TreeNode(0);
        int mid = start + distance / 2;
        root->left = sortedListToBSTR(head, start, mid);
        root->val = (*head)->val;
        *head = (*head)->next;
        root->right = sortedListToBSTR(head, mid + 1, end);
        return root;
    }
public:
    TreeNode* sortedListToBST(ListNode* head) 
    {
        int len = 0;
        ListNode* current = head;
        while(current)
        {
            ++len;
            current = current->next;
        }
        return sortedListToBSTR(&head, 0, len);
    }
};
