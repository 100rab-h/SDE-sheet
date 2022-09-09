class Solution {
public:
    TreeNode* f(vector<int> &inorder, vector<int> &postorder, int is, int ie, int &postIndex) {
        if (is > ie) return NULL;
        
        TreeNode* root = new TreeNode(postorder[postIndex--]);
        int inIndex;
        for (int i = is; i <= ie; i++) {
            if (inorder[i] == root->val) {
                inIndex = i;
                break;
            }    
        }
        
        root->right = f(inorder, postorder, inIndex + 1, ie, postIndex);
        root->left = f(inorder, postorder, is, inIndex - 1, postIndex);
        
        return root;
        
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int ie = inorder.size() - 1;
        int postIndex = postorder.size() - 1;
        
        return f(inorder, postorder, 0, ie, postIndex);
    }
};
