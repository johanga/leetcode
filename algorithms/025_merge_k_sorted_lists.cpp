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
    ListNode* merge2Lists(ListNode* l1, ListNode* l2)
    {
        if (l1 == NULL) return l2;
        if (l2 == NULL) return l1;

        ListNode* head = NULL;
        if (l1->val < l2->val)
        {
            head = l1;
            l1 = l1->next;
        }
        else
        {
            head = l2;
            l2 = l2->next;
        }

        ListNode* tail = head;
        while (l1 || l2)
        {
            if (l1 == NULL)
            {
                tail->next = l2;
                break;
            }
            if (l2 == NULL)
            {
                tail->next = l1;
                break;
            }

            if (l1->val < l2->val)
            {
                tail->next = l1;
                l1 = l1->next;
                tail = tail->next;
            }
            else
            {
                tail->next = l2;
                l2 = l2->next;
                tail = tail->next;
            }
        }
        return head;
    }

    // Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
        const size_t k = lists.size();

        if ( k == 0 ) return NULL;
        if ( k == 1 ) return lists[0];

        for(size_t i = 1; i < k; i = i * 2)
        {
            for(size_t j = 0; j < k - i; j = j + i * 2)
            {
                lists[j] = merge2Lists( lists[j], lists[ i + j ] );
            }
        }
        return lists[0];
    }
};
