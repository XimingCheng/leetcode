class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(m == 0) {
            memcpy(A, B, n*sizeof(int));
            return;
        }
        else if(n == 0) return;
        int larger = A[m - 1] > B[n - 1] ? A[m - 1] : B[n - 1];
        A[m + n - 1] = larger;
        if(larger == A[m - 1])
            merge(A, m - 1, B, n);
        else
            merge(A, m, B, n - 1);
    }
};