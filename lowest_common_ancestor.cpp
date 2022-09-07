class Solution {
public:
    // bool path(TreeNode* root, vector<TreeNode*> &v, TreeNode* t) {
    //     if (!root) return false;
    //     v.push_back(root); 
    //     if (root == t) return true;
    //     if (path(root->left, v, t) or path(root->right, v, t)) return true;
    //     v.pop_back();
    //     return false;
    // }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//         if (!root) return root;
//         vector<TreeNode*> v1, v2;
//         int i = 0;
//         if(path(root, v1, p) and path(root, v2, q)) {
//             for (i; i < v1.size() - 1 and i < v2.size() - 1; i++) {
//                 if (v1[i + 1] != v2[i + 1]) return v1[i];
//             }
//         }
        
//         return v1[i];
        
        if (!root) return root;
        if (root == p or root == q)  return root;
        TreeNode* lca1 = lowestCommonAncestor(root->left, p, q);
        TreeNode* lca2 = lowestCommonAncestor(root->right, p, q);
        
        if (lca1 != NULL and lca2 != NULL) return root;
        if (lca1 != NULL) return lca1;
        else return lca2;
        
    }
};
