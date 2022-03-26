class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) {
            return 0;
        }
        int maxReachableIdx = 0;
        int jumps = 0;
        int curr = 0;
        for(int i=0; i<n; i++) {
            maxReachableIdx = max(maxReachableIdx,  i + nums[i]);
            if(maxReachableIdx >= n-1) {
                return 1 + jumps;
            }
            if(curr == 0) {
                curr = maxReachableIdx - i;
                jumps++;
            }
            curr--;
            // cout << i << maxReachableIdx << " " <<  curr << " " << jumps << endl;
        }
        return jumps;
    }
};