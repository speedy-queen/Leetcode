class Solution {
public:
    void preorder(TreeNode* root, vector<int> &v)
    {
        if(root==NULL){
            v.push_back(NULL);
            return;
        }
        v.push_back(root->val);
        preorder(root->left,v);
        
        preorder(root->right,v);
        
    }
    bool isSameTree(TreeNode* p, TreeNode* q) 
    {
        vector<int> v1,v2;
        
        preorder(p,v1);
        preorder(q,v2);
        
        return v1==v2;
    }
};