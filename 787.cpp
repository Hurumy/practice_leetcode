
class Solution {
public:
    vector<int> dfs(int focus, int price, int depth, vector<vector<int>>& flights, int dst, int k, vector<bool> seen)
    {
        vector<int> res;
        seen[focus] = true;
        
        if (focus == dst)
        {
            res.push_back(price);
            return (res);
        }
        if (depth > k)
            return (res);

        for (int i=0; i<flights.size(); i++)
        {
            if (flights.at(i).at(0) == focus && seen.at(flights.at(i).at(1)) == false)
            {
                vector<int> ret = dfs(flights.at(i).at(1), price+flights.at(i).at(2), depth+1, flights, dst, k, seen);
                res.insert(res.end(), ret.begin(), ret.end());
            }
        }
        return (res);
    }

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<bool> seen(n, false);
        vector<int> res;
        int result;

        res = dfs(src, 0, 0, flights, dst, k, seen);

        if (res.empty())
            return (-1);

        result = *min_element(res.begin(), res.end());
        return (result);
    }
};
