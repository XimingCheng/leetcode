class Solution {
public:
    void trapOnce(int A[], int begin, int end, int& water) {
        if (begin >= end) return;
        int first = begin + 1;
        for (; first <= end; first++) {
            if (A[first] >= A[begin]) break;
        }
        int last = end - 1;
        for (; last >= begin; last--) {
            if (A[last] >= A[end]) break;
        }
        if (first == end && last == begin) {
            for (int i = begin + 1; i < first; i++) {
                water += (A[begin] - A[i]);
            }
            return;
        }
        if (first != end + 1 && first - begin > 1) {
            for (int i = begin + 1; i < first; i++) {
                water += (A[begin] - A[i]);
            }
        }
        if (first == end + 1) first = begin;
        if (last != begin - 1 && end - last > 1) {
            for (int i = end - 1; i > last; i--) {
                water += (A[end] - A[i]);
            }
        }
        if (last == begin - 1) last = end;
        trapOnce(A, first, last, water);
    }
    
    int trap(int A[], int n) {
        if (n == 0 || n == 1) return 0;
        int water = 0;
        trapOnce(A, 0, n - 1, water);
        return water;
    }
};