class Solution {
public:

    int solve(int i, int deleted, vector<int>& arr, vector<vector<int>>& dp) {
    if (i == arr.size()) {
        return INT_MIN;
    }
    if (dp[i][deleted] != -1) {
        return dp[i][deleted];
    }

    int take = arr[i] + max(0, solve(i + 1, deleted, arr, dp));

    int skip = INT_MIN;
    if (deleted == 0) {
        skip = solve(i + 1, 1, arr, dp);
    }

    int ans = max(take, skip);
    dp[i][deleted] = ans;
    return ans;
}

    int maximumSum(vector<int>& arr) {

        int n = arr.size();

        vector<vector<int>> dp(n, vector<int>(2, -1));

        int ans = INT_MIN;

        for(int i = 0; i < n; i++) {

            int curr = solve(i, 0, arr, dp);

            ans = max(ans, curr);
        }

        return ans;
    }
};