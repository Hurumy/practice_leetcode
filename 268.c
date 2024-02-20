
int missingNumber(int* nums, int numsSize)
{
    int lst[numsSize + 1];

    //memset((void *)lst, -1, (size_t)(numsSize * sizeof(int)));
    for (int i = 0; i < numsSize + 1; i++)
    {
        lst[i] = -1;
    }

    for (int i = 0; i < numsSize; i++)
    {
        lst[nums[i]] = nums[i];
    }

    for (int i = 0; i < numsSize + 1; i++)
    {
        if (lst[i] == -1)
        {
            return (i);
        }
    }
    return (-1);
}

