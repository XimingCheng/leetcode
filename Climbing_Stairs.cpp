class Solution {
public:
    int climbStairs(int n) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(n < 2) return 1;
        int *d = new int [n + 1];
        d[0] = 1;
        d[1] = 1;
        for(int i = 2; i <= n; i++)
            d[i] = d[i - 1] + d[i - 2];
        int ret = d[n];
        delete [] d;
        return ret;
    }
};