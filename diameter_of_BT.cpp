class Solution {
public:
    // int height(TreeNode* &root) {
    //     if (!root) return 0;
    //     return 1 + max(height(root->left), height(root->right));
    // }
    
    int diameter(TreeNode* &root, int &ans) {
        if (!root) return 0;
        int lh = diameter(root->left, ans);
        int rh = diameter(root->right, ans);
        
        ans = max(ans, (lh + rh));
        return 1 + max(lh, rh);
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        // if (!root) return 0;
        // int d = height(root->left) + height(root->right);
        // int d1 = diameterOfBinaryTree(root->left);
        // int d2 = diameterOfBinaryTree(root->right);
        
        // return max(d, max(d1, d2));
        
        int ans = 0;
        diameter(root, ans);
        return ans;
    }
};
