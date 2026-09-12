class Solution {
public:
    int solve(vector<int>& cost, int index, vector<int>& dp) {

        if (index >= cost.size()) {
            return 0;
        }

        if (dp[index] != -1) {
            return dp[index];
        }

        int a = cost[index] + solve(cost, index + 1, dp);
        int b = cost[index] + solve(cost, index + 2, dp);

        dp[index] = min(a, b);

        return dp[index];
    }
    
    int minCostClimbingStairs(vector<int>& cost) {

        int n = cost.size();

        vector<int> dp(n + 1, -1);

        int a = solve(cost, 0, dp);
        int b = solve(cost, 1, dp);

        return min(a, b);
    }
};