class Solution {
public:
    TreeNode* f(vector<int> &preo, vector<int> &ino, int is, int ie, int &preIndex) {
        if (is > ie) return NULL;
        
        TreeNode* root = new TreeNode(preo[preIndex++]);
        
        int inIndex;
        for (int i = is; i <= ie; i++) {
            if (ino[i] == root->val) {
                inIndex = i;
                break;
            }
        }
        
        root->left = f(preo, ino, is, inIndex - 1, preIndex);
        root->right = f(preo, ino, inIndex + 1, ie, preIndex);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int e = inorder.size() - 1;
        int preIndex = 0;
        return f(preorder, inorder, 0, e, preIndex);
    }
};
