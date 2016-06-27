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
    // recursive inorder traversal
    void inorderTraversalR(vector<int>& vec, TreeNode* root)
    {
        if(root == NULL) return;
        inorderTraversalR(vec, root->left);
        vec.push_back(root->val);
        inorderTraversalR(vec, root->right);
    }
    // iterative inorder traversal
    void inorderTraversalI(vector<int>& vec, TreeNode* root)
    {
        if(root == NULL) return;

        std::stack< TreeNode* > st;
        TreeNode* current = root;
        while(!st.empty() || current != NULL)
        {
            if(current != NULL)
            {
                st.push(current);
                current = current->left;
            }
            else
            {
                current = st.top();
                st.pop();
                vec.push_back(current->val);
                current = current->right;
            }
        }
    }
    
public:
    vector<int> inorderTraversal(TreeNode* root) 
    {
        vector<int> vec;
        inorderTraversalI(vec, root);
        return vec;
    }
};
