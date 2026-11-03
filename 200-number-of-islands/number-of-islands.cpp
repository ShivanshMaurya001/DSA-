class Solution {
public:

    void bfs(vector<vector<char>>& grid, int sr, int sc,
             map<pair<int,int>, bool>& vis) {

        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int,int>> q;

        q.push({sr, sc});

        vis[{sr, sc}] = true;

        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};

        while(!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;

            q.pop();

            for(int i = 0; i < 4; i++) {

                int nr = r + dx[i];
                int nc = c + dy[i];

                if(nr >= 0 && nr < n && nc >= 0 && nc < m) {

                    if(grid[nr][nc] == '1' && !vis[{nr, nc}]) {

                        vis[{nr, nc}] = true;

                   
                        q.push({nr, nc});
                    }
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        map<pair<int,int>, bool> vis;

        int count = 0;

        for(int i = 0; i < n; i++) {

            for(int j = 0; j < m; j++) {

                if(grid[i][j] == '1' && !vis[{i, j}]) {

                    count++;

                    bfs(grid, i, j, vis);
                }
            }
        }

        return count;
    }
};
