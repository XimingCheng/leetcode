class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        int m = obstacleGrid.size();
        if (m == 0) return 0;
        int n = obstacleGrid[0].size();
        if (n == 0) return 0;
        int ** p = new int*[m];
        for (int i = 0; i < m; i++) {
            p[i] = new int[n];
            memset(p[i], 0, n * sizeof(int));
        }
        for(int i = 0; i < m; i++) {
            if (obstacleGrid[i][0] != 0) break;
            p[i][0] = 1;
        }
        for(int i = 0; i < n; i++) {
            if (obstacleGrid[0][i] != 0) break;
            p[0][i] = 1;
        }
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                if (obstacleGrid[i][j] != 0) p[i][j] = 0;
                else p[i][j] = p[i-1][j] + p[i][j-1];
            }
        }
        int ret = p[m-1][n-1];
        for(int i = 0; i < m; i++)
            delete [] p[i];
        delete [] p;
        return ret;
    }
};