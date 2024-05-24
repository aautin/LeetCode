int searchInsert(int* nums, int numsSize, int target) {
    while (numsSize > 0 && target <= nums[numsSize - 1])
        numsSize--;
    return numsSize;
}