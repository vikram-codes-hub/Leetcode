class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> ans = matrix;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (matrix[i][j] == 0) {

                    // Make entire row zero
                    for (int col = 0; col < m; col++) {
                        ans[i][col] = 0;
                    }

                    // Make entire column zero
                    for (int row = 0; row < n; row++) {
                        ans[row][j] = 0;
                    }
                }
            }
        }

        matrix = ans;
    }
};