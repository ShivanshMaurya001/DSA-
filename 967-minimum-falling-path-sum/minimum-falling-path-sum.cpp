class Solution {
public:
    int solve(vector<vector<int>>& matrix, int i, int j, int n,
              vector<vector<int>>& dp) {

        if (j < 0 || j >= n) {
            return INT_MAX;
        }

        if (i == n - 1) {
            return matrix[i][j];
        }

        if (dp[i][j] != INT_MAX) {
            return dp[i][j];
        }

        int left = solve(matrix, i + 1, j - 1, n, dp);

        int down = solve(matrix, i + 1, j, n, dp);

        int right = solve(matrix, i + 1, j + 1, n, dp);

        int mini = min(left, min(down, right));

        dp[i][j] = matrix[i][j] + mini;

        return dp[i][j];
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {

        int n = matrix.size();

        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));

        int ans = INT_MAX;

        for (int j = 0; j < n; j++) {
            ans = min(ans, solve(matrix, 0, j, n, dp));
        }

        return ans;
    }
};