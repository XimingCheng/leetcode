#include <iostream>

using namespace std;

class Solution {
public:
    long long reverse(long long x) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        bool bLowerZero = false;
        long long out = 0;
        if(x < 0) {
            bLowerZero = true;
            x = -x;
        }
        while(x) {
            int d = x/10;
            int b = x - d*10;
            out = out*10 + b;
            x = d;
        }
        if(bLowerZero) out = -out;
        return out;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    cout<<s.reverse(1000000003)<<endl;
    return 0;
}