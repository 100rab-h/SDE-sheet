class Solution {
public:
    int f(TreeNode* root, int &ans) {
        if (!root) return 0;
        int ls = max(0, f(root->left, ans));
        int rs = max(0, f(root->right, ans));
        
        ans = max(ans, ls + rs + root->val);
        
        return root->val + max(ls, rs);
    }
    
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        f(root, ans);
        
        return ans;
    }
};
