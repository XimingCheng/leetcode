class Solution {
public:
    void cal(int* data, int level, int size, vector<int> &candidates,
        int target, vector<vector<int> >& ret, int& sum) {
        if (level > size - 1) {
            if (sum == target) {
                vector<int> com;
                for (int i = 0; i < size; i++) {
                    for (int j = 0; j < data[i]; j++)
                        com.push_back(candidates[i]);
                }
                if (com.size() > 0) {
                    sort(com.begin(), com.end());
                    ret.push_back(com);
                }
            }
        } else {
            int i = 0;
            while (1) {
                data[level] = i;
                int sum = 0;
                for (int i = 0; i <= level; i++) sum += data[i] * candidates[i];
                if (target >= sum)
                    cal(data, level + 1, size, candidates, target, ret, sum);
                else break;
                i++;
            }
        }
    }
    
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        //sort(candidates.begin(), candidates.end());
        int size = candidates.size();
        int *data = new int[size];
        memset(data, 0, size * sizeof(int));
        vector<vector<int> > ret;
        int sum = 0;
        cal(data, 0, size, candidates, target, ret, sum);
        delete [] data;
        return ret;
    }
};