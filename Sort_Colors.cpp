class Solution {
public:
    void sortColors(int A[], int n) {
        if(n == 0 || n == 1) return;
        int cur = 0;
        int i   = 0;
        int j   = n - 1;
        
        while(cur <= j)
        {
            if(A[cur] == 0)
            {
                if(cur > i)
                    swap(A[cur], A[i++]);
                else
                {
                    i++;
                    cur++;
                }
            }
            else if(A[cur] == 2)
            {
                if(cur < j)
                    swap(A[cur], A[j--]);
                else
                    return;
            }
            else
                cur++;
        }
    }
};