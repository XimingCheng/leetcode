class Solution {
public:
    int numTrees(int n) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(n == 0) return 1;
        if(n == 1) return 1;
        int ret = 0;
        for(int i = 0; i < n; i++) {
            ret += numTrees(i)*numTrees(n - i - 1);
        }
        return ret;
    }
};