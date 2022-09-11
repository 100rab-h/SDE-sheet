class Solution {
public:
    
//     --------- Recursive Approach --------
    
//     void f(TreeNode* root, TreeNode* &prev) {
//         if (!root) return;
//         f(root->right, prev);
//         f(root->left, prev);
        
//         root->right = prev;
//         root->left = NULL;
        
//         prev = root;
//     }
    
    
//     ------------- Using stack -----------
    
//     void flatten (TreeNode* root) {
//        // TreeNode* prev = NULL; 
//        // f(root, prev);
//        //  return;
        
//         stack<TreeNode*> st;
//         if (!root) return;
//         st.push(root);
        
//         while (!st.empty()) {
//             TreeNode* curr = st.top();
//             st.pop();
            
//             if (curr->right) st.push(curr->right);
//             if (curr->left) st.push(curr->left);
            
//             if (!st.empty()) curr->right = st.top();
//             curr->left = NULL;
//         }
//     }
    
    
    void flatten (TreeNode* root) {
        if (!root) return;
        TreeNode* curr = root;
        
        while(curr) {
            if (curr->left != NULL) {
                TreeNode* prev = curr->left;
                while (prev->right) prev = prev->right;
                prev->right = curr->right;
                curr->right = curr->left;
                curr->left = NULL;
            }
            curr = curr->right;
        }
        
    }
    
};
