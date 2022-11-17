/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void inorder(TreeNode* root, vector<int> &ans)
    {
        if(!root)
            return;
        //LNR
        inorder(root->left, ans);
        ans.push_back(root->val);
        inorder(root->right, ans);
    }
    
    void create(TreeNode* root, vector<int> ans)
    {
        int n=ans.size();
        for(int i=0; i<ans.size(); i++)
        {
            TreeNode* newN = new TreeNode();
            newN->val = ans[i];
            root->left=NULL;
            root->right = newN;
            root = newN;
        }
    }
    TreeNode* increasingBST(TreeNode* root) {
        vector<int> ans;
        inorder(root, ans);
        
        TreeNode* res = new TreeNode();
        create(res, ans);
        return res->right;
    }
};