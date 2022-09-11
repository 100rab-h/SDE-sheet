class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});
        int ans = 0;
        
        while (!q.empty()) {
            int size = q.size();
            int mini = q.front().second;
            int first, last;
            for (int i = 0; i < size; i++) {
                TreeNode* curr = q.front().first;
                int id = q.front().second - mini;
                q.pop();
                
                if (i == 0) first = id;
                if (i == size - 1) last = id;
                if (curr->left) q.push({curr->left, (long long)id * 2 + 1});
                if (curr->right) q.push({curr->right, (long long) id * 2 + 2});
            }
            
            ans = max(ans, last - first + 1);
        }
        
        return ans;
    }
};
