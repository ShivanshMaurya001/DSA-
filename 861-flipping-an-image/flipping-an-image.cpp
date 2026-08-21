class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {

        int n = image.size();

        for (int i = 0; i < n; i++) {

            reverse(image[i].begin(), image[i].end());

            for (int j = 0; j < image[i].size(); j++) {
                image[i][j] = image[i][j] ^ 1;   // 1st method

                //image[i][j] = 1 - image[i][j];     // 2nd method 
            }
        }
        return image;
    }
};