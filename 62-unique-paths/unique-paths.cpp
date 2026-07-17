class Solution {
public:

    int solve(int i, int j, int m, int n, vector<vector<int>> &dp){

        if(i >= m || j >= n){
            return 0;
        }

        if(i == m - 1 && j == n - 1){
            return 1;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        int down = solve(i + 1, j, m, n, dp);

        int right = solve(i, j + 1, m, n, dp);

        dp[i][j] = down + right;

        return dp[i][j];
    }

    int uniquePaths(int m, int n){

        vector<vector<int>> dp(m, vector<int>(n, -1));

        int i = 0; int j = 0;

        return solve(i, j, m, n, dp);
    }
};