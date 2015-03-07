class Solution {
public:
    int search(int A[], int begin, int end, int target) {
        if (begin > end) return -1;
        if (begin == end && target != A[begin]) return -1;
        int mid = begin + (end - begin)/2;
        if (A[mid] == target) return mid;
        if (A[mid] < target) return search(A, mid + 1, end, target);
        if (A[mid] > target) return search(A, begin, mid - 1, target);
    }
    
    vector<int> searchRange(int A[], int n, int target) {
        vector<int> ret;
        int idx = search(A, 0, n - 1, target);
        if (idx == -1) {
            ret.push_back(-1);
            ret.push_back(-1);
            return ret;
        }
        int i = idx - 1;
        for (; i >= 0; i--) {
            if (A[i] != target) break;
        }
        ret.push_back(i + 1);
        i = idx + 1;
        for (; i < n; i++) {
            if (A[i] != target) break;
        }
        ret.push_back(i - 1);
        return ret;
    }
};