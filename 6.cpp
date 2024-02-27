class Solution {
public:
    string convert(string s, int numRows) {
        vector<string> lines(numRows);
        string res;
        int bias = numRows - 1;
        int phase; // 斜めか　まっすぐか(0or1)
        int rest; // 0,1,2
        
        if (bias == 0)
            return (s);
        
        for (int i=0; i<s.size(); i++)
        {
            phase = i/bias%2;
            rest = i%bias;
            if (phase == 0)
                lines[rest] = lines[rest] + s[i];
            else if (phase == 1)
            {
                if (rest == 0)
                    lines.back() = lines.back() + s[i];
                else
                    lines[bias-rest] = lines[bias-rest] + s[i];
            }
        }
        
        for (int i=0; i<lines.size(); i++)
            res += lines[i];
        return (res);
    }
};
