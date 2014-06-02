class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int n = matrix.size();
        if(n == 0) return;
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                int t = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = t;
            }
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n/2; j++) {
                int t = matrix[i][j];
                matrix[i][j] = matrix[i][n - j - 1];
                matrix[i][n - j - 1] = t;
            }
        }
    }
};