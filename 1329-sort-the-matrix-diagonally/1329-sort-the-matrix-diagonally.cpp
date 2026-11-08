class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {

        int m = mat.size();
        int n = mat[0].size();

        for (int col = 0; col < n; col++) {
            vector<int> diagonal;

            int r = 0, c = col;

            while (r < m && c < n) {
                diagonal.push_back(mat[r][c]);
                r++;
                c++;
            }

            sort(diagonal.begin(), diagonal.end());

            r = 0;
            c = col;

            for (int x : diagonal) {
                mat[r][c] = x;
                r++;
                c++;
            }
        }

        for (int row = 1; row < m; row++) {
            vector<int> diagonal;

            int r = row, c = 0;

            while (r < m && c < n) {
                diagonal.push_back(mat[r][c]);
                r++;
                c++;
            }

            sort(diagonal.begin(), diagonal.end());

            r = row;
            c = 0;

            for (int x : diagonal) {
                mat[r][c] = x;
                r++;
                c++;
            }
        }

        return mat;
    }
};