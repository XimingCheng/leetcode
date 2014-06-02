class Solution {
public:
    vector<int> grayCode(int n) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        vector<int> data;
        int num = 0;
        data.push_back(num);
        if(n == 0) return data;
        int total = 1 << n;
        for(int i = 1; i < total; i++) {
           for(int j = 0; j < n; j++) {
               int d = (1 << j) ^ num;
               //cout<<"data-> "<<d<<endl;
               if(find(data.begin(), data.end(), d) == data.end()) {
                   data.push_back(d);
                   num = d;
                   break;
               }
           }
        }
        return data;
    }
};