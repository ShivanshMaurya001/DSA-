
class Solution {
public:

    void dfs(vector<vector<int>>& image, int r, int c,
             int originalColor, int newColor) {

        int n = image.size();
        int m = image[0].size();

        // Step 1: Check boundaries
        if(r < 0 || r >= n || c < 0 || c >= m) {
            return;
        }

        // Step 2: Agar current cell ka color original color nahi hai
        // toh yahan recursion stop kar do
        if(image[r][c] != originalColor) {
            return;
        }

        // Step 3: Current cell ka color change kar do
        image[r][c] = newColor;

        // Step 4: 4 directions mein DFS call karo

        // Up
        dfs(image, r - 1, c, originalColor, newColor);

        // Down
        dfs(image, r + 1, c, originalColor, newColor);

        // Left
        dfs(image, r, c - 1, originalColor, newColor);

        // Right
        dfs(image, r, c + 1, originalColor, newColor);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image,
                                  int sr, int sc, int color) {

        // Starting pixel ka original color save karo
        int originalColor = image[sr][sc];

        // Agar original aur new color same hain
        // toh directly image return kar do
        if(originalColor == color) {
            return image;
        }

        // DFS start from starting coordinate
        dfs(image, sr, sc, originalColor, color);

        return image;
    }
};
