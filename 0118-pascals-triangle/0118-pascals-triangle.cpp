class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> triangle;
        for (int row = 0; row < numRows; row++) {
            vector<int> currentRow(row + 1, 1); 
            for (int j = 1; j < row; j++) {
                currentRow[j] = triangle[row - 1][j - 1] + triangle[row - 1][j];
            }
            triangle.push_back(currentRow);
        }
        return triangle;
    }
};
