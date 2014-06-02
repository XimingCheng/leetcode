class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(n == 0) return 0;
        for(int i = 0; i < n; i++) {
            if(A[i] == elem) {
                for(int j = i + 1; j < n; j++)
                    A[j - 1] = A[j];
                n--;
                i--;
            }
        }
        return n;
    }
};