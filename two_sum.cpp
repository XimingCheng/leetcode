class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        map<int, set<int>> data;
        vector<int> out;
        int index = 1;
        for(auto it = numbers.begin(); it < numbers.end(); ++it)
            data[*it].insert(index++);
        for(auto it = numbers.begin(); it < numbers.end(); ++it)
        {
            int value = *it;
            int next  = target - value;
            auto res = data.find(next);
            if(res != data.end())
            {
                int index1 = 0, index2 = 0;
                if(value != next)
                {
                    index1 = *data[value].begin();
                    index2 = *data[next].begin();
                }
                else if(value == next && data[value].size() > 1)
                {
                    index1 = *data[value].begin();
                    index2 = *(++data[value].begin());
                }
                else continue;
                out.clear();
                out.push_back(min(index1, index2));
                out.push_back(max(index1, index2));
                return out;
            }
        }
    }
};