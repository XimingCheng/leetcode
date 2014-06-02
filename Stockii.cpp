#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(prices.size() < 2) return 0;
        int ret = 0;
        bool state = false;
        for(int i = 0; i < prices.size() - 1; i++) {
            int cur = prices[i];
            int next = prices[i + 1];
            if(!state) {
                if(cur < next) {
                    ret -= cur;
                    state = true;
                }
            }
            else {
                if(cur > next) {
                    ret += cur;
                    state = false;
                }
            }
        }
        if(state) {
            ret += *prices.rbegin();
            state = false;
        }
        return ret;
    }
};