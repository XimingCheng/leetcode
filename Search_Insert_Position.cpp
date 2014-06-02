class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(n == 0) return 0;
        int s = 0;
        int e = n - 1;
        if(target <= A[0]) return 0;
        else if(target == A[n - 1]) return n - 1;
        else if(target > A[n - 1]) return n;
        while(s < e - 1) {
            int mid = (e - s)/2 + s;
            //cout<<mid<<" "<<s<<" "<<e<<endl;
            if(A[mid] < target && A[mid + 1] > target) return mid + 1;
            else if(A[mid] == target) return mid;
            else if(A[mid] < target) s = mid + 1;
            else e = mid - 1;
        }
        if(s == e - 1 && A[s] < target && A[e] > target) return s + 1;
        else if(e < n - 1 && A[e] == target) return e;
        else if(e < n - 1 && A[e] < target) return e + 1;
        else if(A[s] >= target) return s;
    }
};