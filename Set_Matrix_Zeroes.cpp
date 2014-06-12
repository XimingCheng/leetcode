class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        if(matrix.size() == 0) return;
        else if(matrix[0].size() == 0) return;
        int row = matrix.size();
        int col = matrix[0].size();
        if(row == 1 && col == 1) return;
        bool bFirstRowContainZero = false;
        bool bFisrtColContainZero = false;
        for(int c = 0; c < col; c++)
            if(matrix[0][c] == 0)
            {
                bFirstRowContainZero = true;
                break;
            }
        for(int r = 0; r < row; r++)
            if(matrix[r][0] == 0)
            {
                bFisrtColContainZero = true;
                break;
            }
        for(int r = 1; r < row; r++)
        {
            for(int c = 1; c < col; c++)
            {
                if(matrix[r][c] == 0)
                {
                    matrix[0][c] = 0;
                    matrix[r][0] = 0;
                }
            }
        }
        for(int r = 1; r < row; r++)
        {
            if(matrix[r][0] == 0)
            {
                for(int c = 1; c < col; c++)
                    matrix[r][c] = 0;
            }
        }
        for(int c = 1; c < col; c++)
        {
            if(matrix[0][c] == 0)
            {
                for(int r = 1; r < row; r++)
                    matrix[r][c] = 0;
            }
        }
        if(bFirstRowContainZero)
        {
            for(int c = 0; c < col; c++)
                matrix[0][c] = 0;
        }
        if(bFisrtColContainZero)
        {
            for(int r = 0; r < row; r++)
                matrix[r][0] = 0;
        }
    }
};