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
    ListNode* addTwoNumbers( ListNode* l1, ListNode* l2 ) 
    {
        if ( l1 == NULL && l2 == NULL ) return NULL;

        ListNode* head = NULL;
        ListNode* tail = NULL;

        ListNode* it1 = l1;
        ListNode* it2 = l2;
        unsigned short div = 0;
        while ( it1 || it2 || div )
        {
            unsigned short addDigits = ( it1 ? it1->val : 0 ) + ( it2 ? it2->val : 0 ) + div;
            if ( tail )
            {
                tail->next = new ListNode( addDigits % 10 );
                tail = tail->next;
            }
            else
            {
                head = new ListNode( addDigits % 10 );
                tail = head;
            }

            it1 = it1 ? it1->next : NULL;
            it2 = it2 ? it2->next : NULL;
            div = addDigits / 10;
        }

        return head;
    }
};
