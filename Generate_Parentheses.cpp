class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> out;
        set<string> outdata;
        if(n == 1)
        {
            string t = "()";
            out.push_back(t);
            return out;
        }
        vector<string> out3;
        for(int i = 1; i < n; i++)
        {
            vector<string> out1 = generateParenthesis(i);
            vector<string> out2 = generateParenthesis(n - i);
            if(i == 1) out3 = out2;
            for(int m = 0; m < out1.size(); m++)
            {
                string t1 = out1[m];
                for(int n = 0; n < out2.size(); n++)
                {
                    string t2 = out2[n];
                    string t = t1 + t2;
                    outdata.insert(t);
                }
            }
        }
        for(int m = 0; m < out3.size(); m++)
        {
            string t1 = out3[m];
            string t = "(" + t1 + ")";
            outdata.insert(t);
        }
        for(set<string>::iterator it = outdata.begin(); it != outdata.end(); ++it)
            out.push_back(*it);
        return out;
    }
};