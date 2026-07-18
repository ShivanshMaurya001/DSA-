class Solution {
public:
    int solve(vector<vector<char>>& matrix, int i, int j, int m, int n,
              vector<vector<int>>& dp) {

        if (i >= m || j >= n) {
            return 0;
        }

        if (dp[i][j] != -1) {   // practise i dont get the intuition ok ... medium to hard ha ye question rle to matrix dp okkk 
            return dp[i][j];
        }

        if (matrix[i][j] == '0') {
            return dp[i][j] = 0;
        }

        int right = solve(matrix, i, j + 1, m, n, dp);

        int down = solve(matrix, i + 1, j, m, n, dp);

        int diagonal = solve(matrix, i + 1, j + 1, m, n, dp);

        int mini = min(right, down);
        mini = min(mini, diagonal);

        dp[i][j] = 1 + mini;

        return dp[i][j];
    }

    int maximalSquare(vector<vector<char>>& matrix) {

        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> dp(m, vector<int>(n, -1));

        int maxi = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                maxi = max(maxi, solve(matrix, i, j, m, n, dp));
            }
        }

        return maxi * maxi;
    }
};