class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        vector<vector<int> > ret;
        int sizeS = S.size();
        if (sizeS == 0) return ret;
        sort(S.begin(), S.end());
        vector<int> empty;
        ret.push_back(empty);
        for (int i = 1; i < (1 << sizeS); i++) {
            vector<int> com;
            int data = i;
            while (data) {
                int left = data;
                data &= (data - 1);
                left -= data;
                int idx = log2(left);
                com.push_back(S[idx]);
            }
            ret.push_back(com);
        }
        return ret;
    }
};