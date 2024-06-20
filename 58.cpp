class Solution {
public:
    int lengthOfLastWord(string s) {
        auto iter = s.begin();
        size_t count;
        
        while (iter != s.end())
        {
            if (*iter != ' ')
                count = 0;
            while (iter != s.end() && *iter != ' ')
            {
                count ++;
                iter ++;
            }
            if (iter == s.end())
                return (count);
            iter ++;
        }
        return (count);
    }
};
