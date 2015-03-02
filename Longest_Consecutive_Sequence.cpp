class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        unordered_map<int,int> hashtable;
        for(int i = 0;i < num.size();i++) {
            if(hashtable.find(num[i]) != hashtable.end())
                continue;
            int minus_1 = num[i] - 1;
            int plus_1 = num[i] + 1;
            unordered_map<int,int>::iterator minus_1iter,plus_1iter;
            minus_1iter = hashtable.find(minus_1);
            plus_1iter = hashtable.find(plus_1);
            if(minus_1iter != hashtable.end() && plus_1iter != hashtable.end()) {
                hashtable[num[i]] = hashtable[minus_1] + hashtable[plus_1] + 1;
                hashtable[num[i] - hashtable[minus_1]] = hashtable[num[i]];
                hashtable[num[i] + hashtable[plus_1]] = hashtable[num[i]];
            }
            else if(minus_1iter == hashtable.end() && plus_1iter == hashtable.end()) {
                hashtable[num[i]] = 1;
            }
            else if(minus_1iter != hashtable.end()) {
                hashtable[num[i]] = hashtable[minus_1] + 1;
                hashtable[num[i] - hashtable[minus_1]] = hashtable[num[i]];
            }
            else {
                hashtable[num[i]] = hashtable[plus_1] + 1;
                hashtable[num[i] + hashtable[plus_1]] = hashtable[num[i]];
            }
        }
         
        //find the maxlen
        int ans = INT_MIN;
        for(unordered_map<int,int>::iterator iter = hashtable.begin();iter != hashtable.end();++iter) {
            if(iter->second > ans)
                ans = iter->second;
        }
        return ans;
    }
};