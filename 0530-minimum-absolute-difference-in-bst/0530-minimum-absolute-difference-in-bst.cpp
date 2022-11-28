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
//     void solve(TreeNode* root, int& mini){
//         if(!root) return;
        
//         solve(root->left,mini);
//         solve(root->right, mini);
//         cout<<root->val<<" "<<mini<<endl;
//         if(root->val != mini)
//         mini=min(mini, abs(root->val - mini));
//     }
    vector<int> arr;
    void inorder(TreeNode* root)
    {
        if(!root) return;
        inorder(root->left);
        arr.push_back(root->val);
        inorder(root->right);
    }
    int getMinimumDifference(TreeNode* root) {
        inorder(root);
        int mini;
        for(int i=0; i<arr.size(); i++)
        {
            for(int j=i+1; j<arr.size(); j++){
                int diff = abs(arr[i]-arr[j]);
                mini=min(mini, diff);
            }
        }
        return mini;
    }
};