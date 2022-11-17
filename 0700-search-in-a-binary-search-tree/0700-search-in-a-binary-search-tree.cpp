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
    void solve(TreeNode* root, int target, TreeNode* &ans)
    {
        if(!root)
            return;
        if(root->val == target){
            ans=root;
            return;
        }
        if(root->val > target)
            solve(root->left, target, ans);
        else
            solve(root->right, target, ans);
    }
    TreeNode* searchBST(TreeNode* root, int val) {
        TreeNode* ans=NULL;
        solve(root, val, ans);
        return ans;
    }
};