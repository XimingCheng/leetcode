class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int m = grid.size();
        if(m == 0) return 0;
        int n = grid[0].size();
        if(n == 0) return 0;
        int **pData = new int* [m];
        for(int i = 0; i < m; i++) {
            pData[i] = new int [n];
            memset(pData[i], 0, n*sizeof(int));
        }
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++){
                int dUp = (i > 0) ? pData[i - 1][j] : -1;
                int dLeft = (j > 0) ? pData[i][j - 1] : -1;
                if(dUp >= 0 && dLeft >= 0)
                    pData[i][j] = min(dUp, dLeft) + grid[i][j];
                else if(dUp >= 0)
                    pData[i][j] = dUp + grid[i][j];
                else if(dLeft >= 0)
                    pData[i][j] = dLeft + grid[i][j];
                else
                    pData[i][j] = grid[i][j];
            }
        }
        int ret = pData[m - 1][n - 1];
        for(int i = 0; i < m; i++)
            delete [] pData[i];
        delete [] pData;
        return ret;
    }
};