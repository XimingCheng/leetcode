class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        if(n == 0)
        {
            vector<vector<int> > out;
            return out;
        }
        else if(n == 1)
        {
            vector<vector<int> > out;
            vector<int> o;
            o.push_back(1);
            out.push_back(o);
            return out;
        }
        vector<vector<int> > inner = generateMatrix(n - 2);
        vector<vector<int> > out;
        vector<int> o;
        for(int i = 0; i < n; i++)
            o.push_back(i + 1);
        out.push_back(o);
        if(inner.size() > 0)
        {
            for(int i = 0; i < inner[0].size(); i++)
            {
                vector<int> o;
                o.push_back(4*n - 4 - i);
                for(int idx = 0; idx < inner[i].size(); idx++)
                    o.push_back(inner[i][idx] + 4*n - 4);
                //copy(inner[i].begin(), inner[i].end(), back_inserter(o));
                o.push_back(n + 1 + i);
                out.push_back(o);
            }
        }
        vector<int> o1;
        for(int i = 0; i < n; i++)
            o1.push_back(3*n - 2 - i);
        out.push_back(o1);
        return out;
    }
};