class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(prices.size() < 2) return 0;
        int maxData = 0, minData = prices[0];
        for(int i = 1; i < prices.size(); i++) {
            if(prices[i] - minData > maxData)
                maxData = prices[i] - minData;
            if(prices[i] < minData)
                minData = prices[i];
        }
        return maxData;
    }
};