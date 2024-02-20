class Solution {
public:
    int missingNumber(vector<int>& nums) {
        long long int ans = nums.size() * (nums.size() + 1) / 2;
        long long int sum = 0;

        for (const auto& e: nums)
        {
            sum += e;
        }

        return (ans - sum);
    }
};
