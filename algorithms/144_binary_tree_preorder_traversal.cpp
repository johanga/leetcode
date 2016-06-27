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
    // recursive solution
    void preorderTraversalR(vector<int>& vec, TreeNode* root)
    {
        if(root == NULL) return;
        vec.push_back(root->val);
        preorderTraversalR(vec, root->left);
        preorderTraversalR(vec, root->right);
    }
    // iterative solution
    void preorderTraversalI(vector<int>& vec, TreeNode* root)
    {
        if(root == NULL) return;

        std::stack< TreeNode* > st;
        TreeNode* current = root;
        st.push(current);
        while(!st.empty())
        {
            current = st.top();
            st.pop();
            vec.push_back(current->val);
            if(current->right != NULL) st.push(current->right);
            if(current->left != NULL) st.push(current->left);
        }
    }
public:
    vector<int> preorderTraversal(TreeNode* root) 
    {
        vector<int> vec;
        preorderTraversalI(vec, root);
        return vec;
    }
};
