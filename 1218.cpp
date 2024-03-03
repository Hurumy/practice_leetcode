class Solution {
public:
    int dynamicProgramming(vector<int>& arr, int head, int diff, vector<int>& memo)
    {
        int score = 1;
        int sum = arr[head] + diff;
        const int siz = arr.size();
        
        for (int i=head+1; i<siz; i++)
        {
            if (arr[i] == sum)
            {
                memo[i] = score;
                score ++;
                sum = arr[i] + diff;
            }
        }
        return (score);
    }
    int longestSubsequence(vector<int>& arr, int difference) {
        vector<int> memo(arr.size(), 0);
        int res=0;
        int tmp;
        const int siz=arr.size();
        
        for (int i=0; i<siz; i++)
        {
            if (memo[i] == 0)
            {
                tmp = dynamicProgramming(arr, i, difference, memo);
                if (tmp > res)
                    res = tmp;
            }
        }
        return (res);
    }
};
