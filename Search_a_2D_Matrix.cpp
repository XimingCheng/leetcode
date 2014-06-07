class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        if(matrix.size() == 0 || matrix[0].size() == 0)
            return false;
        
        int row = matrix.size();
        int col = matrix[0].size();
        if(target < matrix[0][0] || target > matrix[row - 1][col - 1])
            return false;

        int idx1 = 0, idx2 = 0;
        for(idx1 = 0; idx1 < row; idx1++)
        {
            int value = matrix[idx1][col - 1];
            if(value == target) return true;
            else if(value < target) continue;
            else break;
        }
        for(idx2 = 0; idx2 < col; idx2++)
        {
            int value = matrix[row - 1][idx2];
            if(value == target) return true;
            else if(value < target) continue;
            else break;
        }
        
        vector<vector<int>> sub_matrix;
        for(int r = 0; r < row - 1 - idx1; r++)
        {
            vector<int> val;
            copy(matrix[r + idx1].begin() + idx2, matrix[r + idx1].begin() + col - 1,
                back_inserter(val));
            sub_matrix.push_back(val);
        }
        return searchMatrix(sub_matrix, target);
    }
};
