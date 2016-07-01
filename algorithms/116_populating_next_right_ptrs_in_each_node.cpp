/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution 
{
private:
    void connectR(TreeLinkNode *left, TreeLinkNode* right)
    {
        if(left == NULL) return;
        left->next = right;
        connectR(left->left, left->right);
        connectR(left->right, (left->next ? left->next->left : NULL));
    }
public:
    void connect(TreeLinkNode *root) 
    {
        connectR(root, NULL);
    }
};
