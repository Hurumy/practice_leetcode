class Solution {
public:
    void dynamicProgramming(vector<int>& arr, int head, int diff, vector<int>& memo)
    {
        vector<int> indices;
        int score = 0;
        int cidx = head;
        
        for (int i=head+1; i<arr.size(); i++)
        {
            if (arr[i] == arr[cidx] + diff)
            {
                indices.push_back(i);
                score ++;
                cidx = i;
            }
        }
        
        for (int i=0; i<indices.size(); i++)
            memo[indices[i]] = score;
    }
    int longestSubsequence(vector<int>& arr, int difference) {
        int res = 0;
        int tmp;
        vector<int> memo(arr.size(), 0);
        
        for (int i=0; i<arr.size(); i++)
        {
            if (memo[i] == 0)
                dynamicProgramming(arr, i, difference, memo);
            tmp = memo[i];
            if (res < tmp)
                res = tmp;
        }
        return (res+1);
    }
};
