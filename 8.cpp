class Solution {
public:
    int myAtoi(string s) {
        unsigned int i=0;
        bool isminus = false;
        int res=0;
        while (i < s.size() && s[i] == ' ')
            i ++;
        if (s[i] == '-')
            isminus = true;
        while (i < s.size())
        {
            if (res < INT_MAX/10)
                res = res*10 + (s[i]-48);
            else if (res < INT_MAX/10)
                return (INT_MAX);
        }
        if (isminus)
            return ((int)res*-1);
        return (res);
    }
};
