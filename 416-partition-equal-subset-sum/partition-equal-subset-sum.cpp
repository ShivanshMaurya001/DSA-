class Solution {
public:
    bool solve(int indx, vector<int>& nums, int target,vector<vector<int>>& dp) {

        int n = nums.size();

        if (indx >= n) {
            return 0;
        }
        if (target < 0) {
            return 0;
        }
        if (target == 0) {
            return 1;
        }

        if (dp[indx][target] != -1) {
            return dp[indx][target];
        }

        bool incl = solve(indx + 1, nums, target - nums[indx], dp);

        bool excl = solve(indx + 1, nums, target, dp);

        dp[indx][target] = (incl || excl);

        return dp[indx][target];
    }

    bool canPartition(vector<int>& nums) {

        int sum = 0;

        for (int i = 0; i < nums.size(); i++) {
            sum = sum + nums[i];
        }
        if (sum & 1) {
            return false;
        }
        int target = sum / 2;

        int indx = 0;

        vector<vector<int>> dp(nums.size(), vector<int>(target + 1, -1));

        bool ans = solve(indx, nums, target, dp);

        return ans;
    }
};
