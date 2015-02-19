class Solution {
public:
    vector<vector<int> > getData(vector<int>& data, int count, int begin, int end)
    {
        vector<vector<int> > ret;
        int size = end - begin + 1;
        if (size == 0) return ret;
        if (count == 0) return ret;
        if (count == 1)
        {
            for (int i = begin; i <= end; i++)
            {
                vector<int> com;
                com.push_back(data[i]);
                ret.push_back(com);
            }
            return ret;
        }
        if (count == size)
        {
            vector<int> com;
            copy(data.begin() + begin, data.begin() + end + 1, back_inserter(com));
            ret.push_back(com);
            return ret;
        }
        vector<vector<int> > ret1 = getData(data, count - 1, begin, end - 1);
        vector<vector<int> > ret2 = getData(data, count, begin, end - 1);
        for (auto com : ret1)
        {
            com.push_back(data[end]);
            ret.push_back(com);
        }
        for (auto com : ret2)
        {
            ret.push_back(com);
        }
        return ret;
    }
    
    vector<vector<int> > combine(int n, int k) {
        vector<int> data;
        for (int i = 0; i < n; i++) data.push_back(i + 1);
        return getData(data, k, 0, n - 1);
    }
};