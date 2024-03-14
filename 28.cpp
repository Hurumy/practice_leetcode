class Solution {
public:
    int strStr(string haystack, string needle) {
        for (int i=0; i<haystack.size(); i++)
        {
            if (haystack[i] == needle[0])
            {
                for (int j=0; j<=needle.size() && i+j<=haystack.size(); j++)
                {
                    if (needle.size() == j)
                        return (i);
                    else if (haystack.size() == i+j)
                        break ;
                    else if (haystack[i+j] != needle[j])
                        break;
                }
            }
        }
        return (-1);
    }
};
