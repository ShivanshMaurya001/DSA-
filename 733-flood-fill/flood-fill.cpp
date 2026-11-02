
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {

        int n = image.size();
        int m = image[0].size();

        int originalColor = image[sr][sc];

        if(originalColor == color) {
            return image;
        }

        queue<pair<int,int>> q;

        q.push({sr, sc});

        image[sr][sc] = color;

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

                    if(image[nr][nc] == originalColor) {

                        image[nr][nc] = color;

                        q.push({nr, nc});
                    }
                }
            }
        }
        return image;
    }
};
