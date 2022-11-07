class Solution {
public:
	int ans=INT_MIN;
	int rec(TreeNode* root) 
	{
		if(root==NULL)
			return 0;

		int lh = rec(root-> left);
		int rh = rec(root->right);

		//if the root is in the path of maximum sum 
		int ka = max(lh,max(lh+rh,max(0,rh)));
		ans = max(ans,ka +root->val);

		return max(0,max(lh,rh))+(root->val);
	}
	int maxPathSum(TreeNode* root) {
		rec(root);
		return ans;
	}
};