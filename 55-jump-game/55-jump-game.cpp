class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxReachableidx = 0, n = nums.size();
        for(int i=0; i<n; i++) {
            if(i > maxReachableidx) {
                return false;
            }
            maxReachableidx = max(maxReachableidx, i + nums[i]);
        }
        return true;
    }
};