class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int n = heights.size();
        int maxArea = 0;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[i] < heights[st.top()]) {
                int h = heights[st.top()];
                st.pop();
                int pse = st.empty() ? -1 : st.top();
                int nse = i;
                maxArea = max(maxArea, h * (nse - pse - 1));
            }
            st.push(i);
        }
        while (!st.empty()) {
            int h = heights[st.top()];
            st.pop();
            int pse = st.empty() ? -1 : st.top();
            int nse = n;
            maxArea = max(maxArea, h * (nse - pse - 1));
        }
        return maxArea;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<int> heights(cols, 0);
        int maxRectangle = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == '1')
                    heights[j] += 1;
                else
                    heights[j] = 0;
            }
            maxRectangle = max(maxRectangle, largestRectangleArea(heights));
        }
        return maxRectangle;
    }
};
