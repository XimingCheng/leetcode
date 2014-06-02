class Solution {
public:
    int romanToInt(string s) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        // I(1)£¬V(5)£¬X(10)£¬L(50)£¬C(100)£¬D(500)£¬M(1000)
        map<char, int> data;
        data['I'] = 1;
        data['V'] = 5;
        data['X'] = 10;
        data['L'] = 50;
        data['C'] = 100;
        data['D'] = 500;
        data['M'] = 1000;
        int ret = 0;
        for(int i = 0; i < s.size(); i++) {
            if(i + 1 < s.size()) {
                if(data[s[i]] < data[s[i + 1]])
                    ret -= data[s[i]];
                else
                    ret += data[s[i]];
            } else
                ret += data[s[i]];
        }
        return ret;
    }
};