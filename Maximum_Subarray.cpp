class Solution {
public:
    int maxSubArray(int A[], int n) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(n == 0) return 0;
        int maxA = A[0], maxE = A[0];
        for(int i = 1; i < n; i++) {
            maxE = max(maxE + A[i], A[i]);
            maxA = max(maxA, maxE);
        }
        return maxA;
    }
};