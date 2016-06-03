/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution 
{
public:
    ListNode* deleteDuplicates(ListNode* head) 
    {
        if ( head == 0 ) return head;
        ListNode* current = head;
        while ( current->next != NULL )
        {
            if ( current->val == current->next->val )
            {
                ListNode* next = current->next;
                current->next = next->next;
                delete next;
            }
            else
            {
                current = current->next;
            }
        }
        return head;
    }
};
