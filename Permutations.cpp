class Solution {
public:
    void subPermute(vector<vector<int> >& out, vector<int> &num, int s, int e) {
        if(s >= e)
            out.push_back(num);
        else {
            for(int i = s; i <= e; i++) {
                int t = num[s];
                num[s] = num[i];
                num[i] = t;
                subPermute(out, num, s + 1, e);
                t = num[i];
                num[i] = num[s];
                num[s] = t;
            }
        }
    }
    
    vector<vector<int> > permute(vector<int> &num) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        vector<vector<int> > data;
        if(num.size() == 0) return data;
        subPermute(data, num, 0, num.size() - 1);
        return data;
    }
};
