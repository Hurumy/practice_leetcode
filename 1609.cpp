/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> getNumList(vector<TreeNode*> &list)
    {
        vector<int> res;
        
        for (int i=0; i<list.size(); i++)
            res.push_back(list[i]->val);
        return (res);
    }
    bool isOkForEven(vector<int> &nums)
    {
        if (nums[0]%2 != 1)
            return (false);
        for (int i=1; i<nums.size(); i++)
        {
            if (nums[i-1] >= nums[i])
                return (false);
            else if (nums[i]%2 != 1)
                return (false);
        }
        return (true);
    }
    bool isOkForOdd(vector<int> &nums)
    {
        if (nums[0]%2 != 0)
            return (false);
        for (int i=1; i<nums.size(); i++)
        {
            if (nums[i-1] <= nums[i])
                return (false);
            else if (nums[i]%2 != 0)
                return (false);
        }
        return (true);
    }
    bool isOK(vector<TreeNode*> &list, int level)
    {
        vector<int> nums;
        bool status;
        
        nums = getNumList(list);
        if (level%2==0)
            status = isOkForEven(nums);
        else
            status = isOkForOdd(nums);
        return (status);
    }
    vector<TreeNode*> putToList(vector<TreeNode*> &list)
    {
        vector<TreeNode*> nextlist;

        for (int i=0; i<list.size(); i++)
        {
            if (list[i]->left)
                nextlist.push_back(list[i]->left);
            if (list[i]->right)
                nextlist.push_back(list[i]->right);
        }
        return (nextlist);
    }
    bool isEvenOddTree(TreeNode* root) {
        vector<TreeNode*> list;
        
        list.push_back(root);
        for (int i=0; !list.empty(); i++)
        {
            if (!isOK(list, i))
                return (false);
            list = putToList(list);
        }
        return (true);
    }
};
