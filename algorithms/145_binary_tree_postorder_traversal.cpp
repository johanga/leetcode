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
    void postorderTraversalR(vector<int>& vec, TreeNode* root)
    {
        if(root == NULL) return;
        postorderTraversalR(vec, root->left);
        postorderTraversalR(vec, root->right);
        vec.push_back(root->val);
    }
    // iterative solution
    void postorderTraversalI(vector<int>& vec, TreeNode* root)
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
            if(current->left != NULL) st.push(current->left);
            if(current->right != NULL) st.push(current->right);
        }
        reverse(vec.begin(), vec.end());
    }
    
public:
    vector<int> postorderTraversal(TreeNode* root) 
    {
        vector<int> vec;
        postorderTraversalI(vec, root);
        return vec;
    }
};
