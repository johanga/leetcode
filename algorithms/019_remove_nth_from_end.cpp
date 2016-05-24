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
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        ListNode* it = head;
        ListNode* nthFromIt = NULL;
        ListNode* prevNthFromIt = NULL;
        
        size_t counter = 0;
        while(counter < n)
        {
            it = it->next;
            ++counter;
        }
        nthFromIt = head;
        while (it != NULL)
        {
            it = it->next;
            prevNthFromIt = nthFromIt;
            nthFromIt = nthFromIt->next;
        }
        if (prevNthFromIt == NULL)
        {
            head = head->next;
        }
        else
        {
            prevNthFromIt->next = nthFromIt->next;
        }
        delete nthFromIt;
        return head;
    }
};
