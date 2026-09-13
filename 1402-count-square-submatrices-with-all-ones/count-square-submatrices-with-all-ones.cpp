class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& matrix,
              vector<vector<int>>& dp) {

        int n = matrix.size();
        int m = matrix[0].size();

        if (i < 0 || j < 0 || i >= n || j >= m) {
            return 0;
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        if (matrix[i][j] == 0) {
            dp[i][j] = 0;
            return dp[i][j];
        }

        int top = solve(i - 1, j, matrix, dp);
        int left = solve(i, j - 1, matrix, dp);
        int diagonal = solve(i - 1, j - 1, matrix, dp);

        int mini = min(diagonal,min(top, left)) + 1;

        dp[i][j] = mini;

        return dp[i][j];
    }


    int countSquares(vector<vector<int>>& matrix) {

        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        int ans = 0;

        for (int i = 0; i < n; i++) {

            for (int j = 0; j < m; j++) {

                int current = solve(i, j, matrix, dp);

                ans = ans + current;
            }
        }

        return ans;
    }
};