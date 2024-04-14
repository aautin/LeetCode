/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int min = nums[0];
    int max = nums[0];
    for (short a = 1; a < numsSize; a++) {
        if (nums[a] < min)
            min = nums[a];
        if (nums[a] > max)
            max = nums[a];
    }
    printf("min=%d|max=%d", min, max);

    for (short a = 0; a < numsSize; a++) {
        if ((nums[a] <= target && nums[a] + max >= target)
            || (nums[a] >= target && nums[a] + min <= target)) {
            for (short b = 0; b < numsSize; b++) {
                if (b != a && nums[a] + nums[b] == target) {
                    int *res = malloc(2 * sizeof(int));
                    *res = a;
                    *(res + 1) = b;
                    *returnSize = 2;
                    return (res);
                }
            }
        }
    }
    return (NULL);
}