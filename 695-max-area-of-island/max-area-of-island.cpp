class Solution {
public:

    // DFS function
    void dfs(vector<vector<int>>& grid, int i, int j, int& ans) {

        int n = grid.size();
        int m = grid[0].size();

        if(i < 0 || i >= n || j < 0 || j >= m) {
            return;
        }
        if(grid[i][j] != 1) {
            return;
        }

        grid[i][j] = 0;

        ans++;

        dfs(grid, i-1, j, ans);

        dfs(grid, i+1, j, ans);

        dfs(grid, i, j-1, ans);

        dfs(grid, i, j+1, ans);
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        int maxi = 0;

        for(int i = 0; i < n; i++) {

            for(int j = 0; j < m; j++) {

                if(grid[i][j] == 1) {

                    int ans = 0;
                    
                    dfs(grid, i, j, ans);

                    maxi = max(maxi, ans);
                }
            }
        }

        return maxi;
    }
};