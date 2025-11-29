class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int max_cnt = 0;
        int index = 0;
        int n = mat.size();
        int m = mat[0].size();
        for (int i = 0; i < n; i++) {
            int count_ones = 0;
            for (int x : mat[i]) {
                if (x == 1) count_ones++;
            }
            if (count_ones > max_cnt) {
                max_cnt = count_ones;
                index = i;
            }
        }
        return {index, max_cnt};
    }
};
