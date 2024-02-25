#include <math.h>

class Solution {
public:
    bool isPrime(int num)
    {
        if (num < 2) return false;
        else if (num == 2) return true;
        else if (num % 2 == 0) return false;
        double sqrtNum = sqrt(num);
        for (int i = 3; i <= sqrtNum; i += 2)
        {
            if (num % i == 0)
                return false;
        }
        return true;
    }
    vector<int> dfs(int i, vector<int> &primes, vector<vector<int>> &edges, vector<int> &nums, vector<int> used)
    {
        vector<int> dummy;
        if (find(used.begin(), used.end(), primes[i]) != used.end())
            return (dummy);
        used.push_back(primes[i]);
        if (used.size() == nums.size())
            return (used);
        if (i >= edges.size())
        {
            for (int j=0; j<nums.size(); j++)
            {
                if (find(used.begin(), used.end(), j) == used.end())
                {
                    // まず前方に追加して探索
                    if (gcd(used[0], j) > 1)
                    {
                        used.push_front(j);
                        if (used.size() == nums.size())
                            return (used);
                        vector<int> res = dfs(i+1, primes, edges, nums, used);
                        if (res.size() == nums.size())
                            return (res);
                        used.pop_front();
                    }

                    // 次に後方に追加して探索
                    if (gcd(*used.end(), j) > 1)
                    {
                        used.push_back(j);
                        if (used.size() == nums.size())
                            return (used);
                        vector<int> res = dfs(i+1, primes, edges, nums, used);
                        if (res.size() == nums.size())
                            return (res);
                        used.pop_back();
                    }
                }
            }
        }
        else
        {
            for (int j=0; j<edges[i].size(); j++)
            {
                if (find(used.begin(), used.end(), edges[i][j]) != used.end())
                    continue;
                used.push_back(edges[i][j]);
                if (used.size() == nums.size())
                    return (used);
                vector<int> res = dfs(i+1, primes, edges, nums, used);
                if (res.size() == nums.size())
                    return (res);
                used.pop_back();
            }
            return (dummy);
        }
        return (dummy);
    }
    bool canTraverseAllPairs(vector<int>& nums)
    {
        vector<int> primes;
        vector<vector<int>> edges;
        
        // 素数をリストアップ
        for (int i=0; i<nums.size(); i++)
        {
            if (isPrime(nums[i]))
                primes.push_back(i);
        }
        
        // 各素数に対して辺を作る
        for (int i=0; i+1<primes.size(); i++)
        {
            vector<int> tmp;
            for (int j=0; j<nums.size(); j++)
            {
                if (gcd(nums[j], nums[primes[i]])>1 && gcd(nums[j], nums[primes[i+1]])>1)
                    tmp.push_back(j);
            }
            edges.push_back(tmp);
        }
        
        // 全てのインデックスを回収できるか探索する
        // 今のところ要素数が奇数の時しか対応してない
        // 余ったインデックスもくっつける
        vector<int> used;
        vector<int> res = dfs(0, primes, edges, nums, used);
        if (res.empty() == true)
            return (false);
        else
            return (true);
    }
};
