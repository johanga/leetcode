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
    // returns last node
    TreeNode* flattenR(TreeNode* root)
    {
        if(root == NULL) return NULL;
        
        TreeNode* left = flattenR(root->left);
        TreeNode* right = flattenR(root->right);
        if(left == NULL && right == NULL) return root;
        if(left)
        {
            TreeNode* tmp = root->right;
            root->right = root->left;
            root->left = NULL;
            left->right = tmp;
        }
        return right ? right : left;
    }
public:
    void flatten(TreeNode* root) 
    {
        flattenR(root);
    }
};
