//Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).
//For example, this binary tree [1,2,2,3,4,4,3] is symmetric.
//But the following [1,2,2,null,3,null,3] is not.

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
public:
    bool isSymmetric(TreeNode* root) 
    {
        if(root == NULL) return true;
        return isSymmetricR(root->left, root->right);
    }
private:
    static bool isSymmetricR(TreeNode* left, TreeNode* right)
    {
        if(left == NULL) return (right == NULL);
        if(right == NULL) return false;
        if(left->val != right->val) return false;
        return isSymmetricR(left->left, right->right) && isSymmetricR(left->right, right->left);
    }
};
