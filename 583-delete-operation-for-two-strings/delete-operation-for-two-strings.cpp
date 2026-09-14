class Solution {
public:
    int solve(int i, int j, string& word1, string& word2,
              vector<vector<int>>& dp) {

        if (i == word1.size())
            return word2.size() - j;

        if (j == word2.size())
            return word1.size() - i;

        if (dp[i][j] != -1)
            return dp[i][j];

        int ans = 0;

        if (word1[i] == word2[j]) {
            ans = solve(i + 1, j + 1, word1, word2, dp);
        } else {
            int  w1= 1 + solve(i + 1, j, word1, word2, dp);
            int w2 = 1 + solve(i, j + 1, word1, word2, dp);

            ans = min(w1,w2);
        }

        dp[i][j] = ans;

        return dp[i][j];
    }

    int minDistance(string word1, string word2) {

        int n = word1.size();
        int m = word2.size();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        return solve(0, 0, word1, word2, dp);
    }
};