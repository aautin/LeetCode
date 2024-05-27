int comp(const void *n1, const void *n2) {
    return *(int *)n1 - *(int *)n2;
}

int specialArray(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), comp);
    char i = 1;
    while (i <= numsSize && nums[numsSize - i]) {
        if (nums[numsSize - i] >= i && (i == numsSize || nums[numsSize - (i + 1)] < i))
            return i;
        i++;
    }
    return -1;
}