class Solution {
public:
    int singleNumber(int A[], int n) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int times = 32;
        vector<int> left(A, A+n);
        while(times--) {
            int bit = 32 - times;
            int flag = 1 << bit;
            vector<int> data0;
            vector<int> data1;
            for(auto it = left.begin(); it != left.end(); ++it) {
                int d = ((*it) & flag) >> bit;
                if(d == 1)
                    data1.push_back(*it);
                else
                    data0.push_back(*it);
            }
            if(data0.size() % 3 == 1)
                left.swap(data0);
            else
                left.swap(data1);
            if(left.size() == 1)
                return left[0];
        }
        return left[0];
    }
};
