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
    ListNode* reverseList(ListNode* head)
    {
        ListNode* current = head;
        ListNode* prev = NULL;
        ListNode* next = NULL;
        while ( current )
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k)
    {
        if ( k < 2 ) return head;

        ListNode* current = head;
        ListNode* start = NULL;
        ListNode* end = NULL;
        int counter = 1;
        while ( current )
        {
            if ( counter == 1 )
            {
                start = current;
                ++counter;
                current = current->next;
            }
            else if ( counter == k )
            {
                end = current;
                current = current->next;
                end->next = NULL;
                counter = 1;
                reverseList(start);
                start->next = reverseKGroup(current, k);
                return end;
            }
            else
            {
                ++counter;
                current = current->next;
            }
        }

        return head;
    }
};
