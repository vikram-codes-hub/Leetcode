class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> lll = grid;

        for (int i = 0; i < k; i++) {

            vector<vector<int>> ans(n, vector<int>(m, 0)); // Reset every shift

            for (int l = 0; l < n; l++) {

                // Shift elements within the row
                for (int p = 0; p < m - 1; p++) {
                    ans[l][p + 1] = lll[l][p];
                }

                // Last element of row goes to first column of next row
                if (l != n - 1)
                    ans[l + 1][0] = lll[l][m - 1];
            }

            // Last element of grid goes to first position
            ans[0][0] = lll[n - 1][m - 1];

            lll = ans;
        }

        return lll;
    }
};