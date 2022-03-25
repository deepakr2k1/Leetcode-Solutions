class Solution {
public:
    long long dp[100][101];
    long long getMinCost(vector<vector<int>>& costs, int idx, int k) {
        if(idx == 0) {
            if(k==1) {
                return costs[0][0];
            } else if(k==0) {
                return costs[0][1];
            } else {
                return INT_MAX;
            }
        }
        if(k < 0) {
            return INT_MAX;
        }
        if(dp[idx][k] != -1)  {
            return dp[idx][k];
        }
        
        long long cost = min(costs[idx][0] + getMinCost(costs, idx-1, k-1), costs[idx][1] + getMinCost(costs, idx-1, k));
        dp[idx][k] = cost;
        return cost;
    }
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int n = costs.size();
        memset(dp, -1, sizeof(dp));
        int ans = getMinCost(costs, n-1, n/2);
        return ans;
    }
};