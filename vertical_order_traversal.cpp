class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, vector<int>> m;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        while (!q.empty()) {
            int n = q.size();
            map<int, vector<int>> tm;
            for (int i = 0; i < n; i++) {
                TreeNode* curr = q.front().first;
                int x = q.front().second;
                q.pop();
                
                tm[x].push_back(curr->val);
                if (curr->left) q.push({curr->left, x - 1});
                if (curr->right) q.push({curr->right, x + 1});
            }
            for(auto x : tm) {
                vector<int> temp = x.second;
                sort(temp.begin(), temp.end());
                m[x.first].insert(m[x.first].end(), temp.begin(), temp.end());
            }
        }
        
        vector<vector<int>> ans;
        for (auto x : m) {
            ans.push_back(x.second);
        }
        
        return ans;
    }
};
