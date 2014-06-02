class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        vector<vector<int> > data;
        if(numRows == 0) return data;
        vector<int> tmpData;
        tmpData.push_back(1);
        data.push_back(tmpData);
        for(int i = 1; i < numRows; i++) {
            vector<int> t;
            t.push_back(1);
            for(int j = 0; j < tmpData.size(); j++) {
                if(j + 1 < tmpData.size())
                    t.push_back(tmpData[j] + tmpData[j + 1]);
                else
                    t.push_back(tmpData[j]);
            }
            data.push_back(t);
            tmpData.swap(t);
        }
        return data;
    }
};