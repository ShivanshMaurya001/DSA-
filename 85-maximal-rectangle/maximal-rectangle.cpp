
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        stack<int> st;  
        int maxArea = 0;

        for (int i = 0; i <= n; i++) {

            while (!st.empty() &&
                   (i == n || heights[st.top()] > heights[i])) {

                int height = heights[st.top()];
                st.pop();

                int width;

                if (st.empty()) {
                    width = i;
                }
                else {
                    width = i - st.top() - 1;
                }

                int area = height * width;

                if (area > maxArea) {
                    maxArea = area;
                }
            }

            if (i < n) {
                st.push(i);
            }
        }

        return maxArea;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {

        if (matrix.empty() || matrix[0].empty()) {
            return 0;
        }

        int rows = matrix.size();
        int cols = matrix[0].size();

        vector<int> heights(cols, 0);

        int maxArea = 0;

        for (int i = 0; i < rows; i++) {

            for (int j = 0; j < cols; j++) {

                if (matrix[i][j] == '1') {
                    heights[j] = heights[j] + 1;
                }
                else {
                    heights[j] = 0;
                }
            }

            int area = largestRectangleArea(heights);

            if (area > maxArea) {
                maxArea = area;
            }
        }

        return maxArea;
    }
};
