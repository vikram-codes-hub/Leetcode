class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> lll = grid;

        for (int i = 0; i < k; i++) {

            vector<vector<int>> ans(n, vector<int>(m, 0)); 

            for (int l = 0; l < n; l++) {

               
                for (int p = 0; p < m - 1; p++) {
                    ans[l][p + 1] = lll[l][p];
                }

             
                if (l != n - 1)
                    ans[l + 1][0] = lll[l][m - 1];
            }

         
            ans[0][0] = lll[n - 1][m - 1];

            lll = ans;
        }

        return lll;
    }
};