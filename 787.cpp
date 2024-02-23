
class Solution {
public:
    int dfs(int focus, int price, int depth, vector<vector<int>>& flights, int &dst, int &k, vector<bool> seen, int result)
    {
        int res = result;
        seen[focus] = true;
        
        if (focus == dst)
            return (price);
        if (depth > k)
            return (-1);
        if (price > result)
            return (-1);

        for (int i=0; i<flights.size(); i++)
        {
            if (flights[i][0] == focus)
            {
                vector<int> f = flights[i];
                if (seen[f[1]] == false)
                {
                    int ret = dfs(f[1], price+f[2], depth+1, flights, dst, k, seen, res);
                    if (ret != -1 && ret < res)
                        res = ret;
                }
            }
        }
        return (res);
    }

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<bool> seen(n, false);
        int res;

        res = dfs(src, 0, 0, flights, dst, k, seen, INT_MAX);
        if (res == INT_MAX)
            return (-1);
        return (res);
    }
};
