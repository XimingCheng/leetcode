class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        vector<int> out;
        int len = digits.size();
        // if(len == 0) this things would not happen
        int flag = 0;
        for(int i = 0; i <= len - 1; i++)
        {
            int num = digits[len - 1 - i] + flag + (i == 0 ? 1 : 0);
            if(num >= 10)
            {
                out.insert(out.begin(), num - 10);
                flag = 1;
            }
            else
            {
                out.insert(out.begin(), num);
                flag = 0;
            }
        }
        if(flag == 1) out.insert(out.begin(), 1);
        return out;
    }
};