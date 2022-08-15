vector<int> Solution::prevSmaller(vector<int> &A) {
    stack<int> s;
    int n = A.size();
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        while (!s.empty()) {
            if (s.top() >= A[i]) s.pop();
            else break;
        }
        if (s.empty()) {
            ans.push_back(-1);
            s.push(A[i]);
        } else {
            ans.push_back(s.top());
            s.push(A[i]);
        }
        
    }
    return ans;
}
