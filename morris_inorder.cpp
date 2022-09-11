class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        
        TreeNode* curr = root;
        
        while (curr) {
            if (!curr->left) {
                ans.push_back(curr->val);
                curr = curr->right;
            } else {
                TreeNode* prev = curr->left;
                while (prev->right != NULL and prev->right != curr) prev = prev->right;
                if (prev->right == NULL) {
                    prev->right = curr;
                    curr = curr->left;
                } else {
                    prev->right = NULL;
                    ans.push_back(curr->val);
                    curr = curr->right;
                }
                
            }
        }
        
        return ans;
    }
};
