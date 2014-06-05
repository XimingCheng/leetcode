class Solution {
public:
    int lengthOfLastWord(const char *s) {
        int len = strlen(s);
        if(len == 0) return 0;
        bool bStart = false;
        int idx1 = 0, idx2 = 0;
        for(int idx = len - 1; idx >= 0; idx--)
        {
            if(!bStart && s[idx] != ' ')
            {
                if(idx == 0) return 1;
                bStart = true;
                idx1 = idx;
            }
            else if(bStart && s[idx] == ' ')
            {
                idx2 = idx;
                break;
            }
            else if(bStart && idx == 0)
            {
                idx2 = -1;
                break;
            }
        }
        return idx1 - idx2;
    }
};