class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        set<vector<int>> st;
        for(int i=0; i<n; i++) {
            int target = -1 * nums[i];
            int l=i+1, r=n-1;
            while(l < r) {
                if(nums[l] + nums[r] == target) {
                    st.insert({nums[i], nums[l], nums[r]});
                    l++;
                    r--;
                } else if(nums[l] + nums[r] < target) {
                    l++;
                } else {
                    r--;
                }
            }
        }
        for(auto x: st) {
            ans.push_back(x);
        }
        return ans;
    }
};