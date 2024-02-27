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
        {
            if (memo[indices[i]] < score)
                memo[indices[i]] = score;
        }
    }
    int getScore(vector<int>& arr, vector<int>& memo, int index, int diff)
    {
        if (memo[index] == 0)
        {
            dynamicProgramming(arr, index, diff, memo);
            return (memo[index]);
        }
        else
            return (memo[index]);
    }
    int longestSubsequence(vector<int>& arr, int difference) {
        int res = 0;
        int tmp = 0;
        vector<int> memo(arr.size());
        
        for (int i=0; i<arr.size(); i++)
        {
            tmp = getScore(arr, memo, i, difference);
            if(res < tmp)
                res = tmp;
        }
        return (res+1);
    }
};
