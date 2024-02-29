class Solution {
public:
    void dynamicProgramming(vector<int>& arr, int head, int diff, vector<int>& memo)
    {
        vector<int> indices;
        int score = 1;
        int cidx = head;
        
        for (int i=head+1; i<arr.size(); i++)
        {
            if (arr[i] == arr[cidx] + diff)
            {
                memo[i] = score;
                score ++;
                cidx = i;
            }
        }
    }
    int longestSubsequence(vector<int>& arr, int difference) {
        vector<int> memo(arr.size(), 0);
        
        for (int i=0; i<arr.size(); i++)
        {
            if (memo[i] == 0)
                dynamicProgramming(arr, i, difference, memo);
        }
        int res = *max_element(memo.begin(), memo.end());
        return (res+1);
    }
};
