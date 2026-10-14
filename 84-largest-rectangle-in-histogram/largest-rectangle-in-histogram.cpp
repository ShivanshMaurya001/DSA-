
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {

        int n = heights.size();

        // Stack mein indices store karenge
        stack<int> st;

        int maxArea = 0;

        // i == n par extra step lenge
        // taaki stack ke remaining bars process ho sakein
        for (int i = 0; i <= n; i++) {

            // i == n means end of array
            // Is case mein sabhi remaining bars pop karenge
            while (!st.empty() &&
                   (i == n || heights[st.top()] > heights[i])) {

                // Pop hone wale bar ki height
                int height = heights[st.top()];
                st.pop();

                // Rectangle ki width calculate karo
                int width;

                if (st.empty()) {
                    width = i;
                }
                else {
                    width = i - st.top() - 1;
                }

                // Rectangle ka area
                int area = height * width;

                // Maximum area update karo
                if (area > maxArea) {
                    maxArea = area;
                }
            }

            // Actual array ke indices hi push karne hain
            if (i < n) {
                st.push(i);
            }
        }

        return maxArea;
    }
};
