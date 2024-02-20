
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        vector<int> lst(nums.size() + 1, -1);

        for (int i = 0; i < nums.size(); i++)
        {
            lst[nums[i]] = nums[i];
        }

        for (int i = 0; i < nums.size() + 1; i++)
        {
            if (lst[i] == -1)
            {
                return (i);
            }
        }
        return (-1);
    }
};
