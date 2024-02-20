class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> index(nums);
        vector<int> res;
        int a;
        int b;
        int sum;

        sort(nums.begin(), nums.end());

        a = 0;
        b = nums.size() - 1;
        for (int i=0; i < nums.size(); i++)
        {
            sum = nums[a] + nums[b];
            if (sum > target)
            {
                b --;
            }
            else if (sum < target)
            {
                a ++;
            }
            else if (sum == target)
            {
                res.push_back(find(index.begin(), index.end(), nums[a]) - index.begin());
                res.push_back(index.rend() - find(index.rbegin(), index.rend(), nums[b]) - 1);
                return (res);
            }
        }
        return (res);
    }
};
