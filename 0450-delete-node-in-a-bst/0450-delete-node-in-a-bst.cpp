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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root)
            return root;
        //find the key
        if(key < root->val)
            root->left = deleteNode(root->left, key);
        else if(key > root->val)
            root->right = deleteNode(root->right, key);
        else
        {
            //key is prresent
            if(!root->left && !root->right)
                return NULL;
            //one child
            if(root->left && !root->right) return root->left;
            else if(!root->left && root->right) return root->right;
            
            //both child
            //finding inorder successor i.e smallest value in right subtree
            TreeNode* temp = root->right;
            while(temp->left) temp=temp->left;
            //replace key with inorder successor
            root->val = temp->val;
            //delete the node from its previous position which took place of key
            root->right = deleteNode(root->right, temp->val);
        }
        return root;
    }
};