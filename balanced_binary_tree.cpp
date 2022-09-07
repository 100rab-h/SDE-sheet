class Solution {
public:
//     int height(TreeNode* &root) {
//         if (!root) return 0;
        
//         return 1 + max(height(root->left), height(root->right));
//     }
    
    int isBalancedUtil(TreeNode* root) {
        if (!root) return 0;
        int lh = isBalancedUtil(root->left);
        if (lh == -1) return -1;
        int rh = isBalancedUtil(root->right);
        if (rh == -1) return -1;
        if (abs(lh - rh) > 1) return -1;
        return 1 + max(lh, rh);
    }
    
    bool isBalanced(TreeNode* root) {
//         if (!root) return true;
//         int lh = height(root->left);
//         int rh = height(root->right);
        
//         return (abs(lh - rh) <= 1 and isBalanced(root->left) and isBalanced(root->right));
//     }
        
        int ans = isBalancedUtil(root);
        if (ans == -1) return false;
        return true;
    }
 };
