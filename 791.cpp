class Solution {
public:
    string customSortString(string order, string s) {
        vector<bool> memo(s.size(), false);
        string res;
        
        for (int i=0; i<order.size(); i++)
        {
            for (int j=0; j<s.size(); j++)
            {
                if (order[i] == s[j])
                {
                    memo[j] = true;
                    res += s[j];
                }
            }
        }
        for (int i=0; i<memo.size(); i++)
        {
            if (!memo[i])
                res += s[i];
        }
        return (res);
    }
};
