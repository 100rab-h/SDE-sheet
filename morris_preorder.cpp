class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode* curr = root;
        
        while (curr) {
            if (curr->left == NULL) {
                ans.push_back(curr->val);
                curr = curr->right;
            } else {
                TreeNode* prev = curr->left;
                while (prev->right and prev->right != curr) prev = prev->right;
                if (prev->right == curr) {
                    prev->right = NULL;
                    curr = curr->right;
                } else {
                    prev->right = curr;
                    ans.push_back(curr->val);
                    curr = curr->left;
                }
            }
        }
        
        return ans;
    }
};
