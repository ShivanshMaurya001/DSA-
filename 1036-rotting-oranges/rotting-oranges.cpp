class Solution {
public:

    int bfs(vector<vector<int>>& grid, queue<pair<int,int>>& q) {

        int n = grid.size();
        int m = grid[0].size();

        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};

        int time = 0;

        while(!q.empty()) {

            int sz = q.size();
            bool rotted = false;

            for(int k = 0; k < sz; k++) {

                int r = q.front().first;
                int c = q.front().second;

                q.pop();

                for(int i = 0; i < 4; i++) {

                    int nr = r + dx[i];
                    int nc = c + dy[i];

                    if(nr >= 0 && nr < n && nc >= 0 && nc < m) {

                        if(grid[nr][nc] == 1) {

                            grid[nr][nc] = 2;
                            rotted = true;

                            q.push({nr, nc});
                        }
                    }
                }
            }

            if(rotted) {
                time++;
            }
        }

        return time;
    }

    int orangesRotting(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int,int>> q;

        for(int i = 0; i < n; i++) {

            for(int j = 0; j < m; j++) {

                if(grid[i][j] == 2) {
                    q.push({i, j});
                }
            }
        }

        int ans = bfs(grid, q);

        for(int i = 0; i < n; i++) {

            for(int j = 0; j < m; j++) {

                if(grid[i][j] == 1) {
                    return -1;
                }
            }
        }

        return ans;
    }
};