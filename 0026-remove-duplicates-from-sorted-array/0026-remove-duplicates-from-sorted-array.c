int removeDuplicates(int* nums, int numsSize) {
    unsigned short  i = 0;
    unsigned short  i_fast = 0;

    while (i < numsSize)
    {
        nums[i] = nums[i_fast];
        while (i_fast < numsSize && nums[i] == nums[i_fast])
            i_fast++;
        if (i_fast == numsSize)
            return (i + 1);
        i++;
    }
    return (i + 1);
}