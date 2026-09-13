class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& triangle,
              vector<vector<int>>& dp) {

        int n = triangle.size();

        if (i == n - 1) {
            return triangle[i][j];
        }

        if (dp[i][j] != INT_MAX) {
            return dp[i][j];
        }

        int left = solve(i + 1, j, triangle, dp);
        int right = solve(i + 1, j + 1, triangle, dp);

        int ans = triangle[i][j] + min(left, right);

        dp[i][j] = ans;

        return ans;
    }

    int minimumTotal(vector<vector<int>>& triangle) {

        int n = triangle.size();

        vector<vector<int>> dp(n, vector<int>(n,  INT_MAX));
        int i = 0;
        int j = 0;

        int ans = solve(i, j, triangle, dp);

        return ans;
    }
};