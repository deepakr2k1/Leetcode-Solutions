class Solution {
public:
    vector<int> nextGreater(vector<int> A) {
        int n = A.size();
        vector<int> ans(n, n);
        stack<int> st;
        for(int i=n-1; i>=0; i--) {
            while(!st.empty() && A[st.top()] >= A[i]) {
                st.pop();
            }
            if(!st.empty()) {
                ans[i] = st.top();
            }
            st.push(i);
        }
        return ans;
    }
    
    vector<int> prevGreater(vector<int> A) {
        int n = A.size();
        vector<int> ans(n, -1);
        stack<int> st;
        for(int i=0; i<n; i++) {
            while(!st.empty() && A[st.top()] >= A[i]) {
                st.pop();
            }
            if(!st.empty()) {
                ans[i] = st.top();
            }
            st.push(i);
        }
        return ans;
    }
    
    int maximalRectangle(vector<vector<char>>& A) {
        int ans = 0, n = A.size(), m = A[0].size();
        int matrix[n][m];
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                matrix[i][j] = A[i][j] - '0';
            }
        }
        for(int i=0; i<n; i++) {
            vector<int> temp;
            for(int j=0; j<m; j++) {
                if(matrix[i][j] > 0 && i>0) {
                    matrix[i][j] += matrix[i-1][j];
                }
                temp.push_back(matrix[i][j]);
            }
            vector<int> next = nextGreater(temp);
            vector<int> prev = prevGreater(temp);
            for(int j=0; j<m; j++) {
                ans = max(ans, (next[j] - prev[j] - 1) * matrix[i][j]);
            }
        }
        return ans;
    }
};