static void backtracking(int *total, int *nums, char XOR, char i, char numsSize) {
    if (i < numsSize) {
        if (XOR == 0) {
            backtracking(total, nums, nums[i], i + 1, numsSize);
            backtracking(total, nums, 0, i + 1, numsSize);
        }
        else {
            backtracking(total, nums, XOR ^ nums[i], i + 1, numsSize);
            backtracking(total, nums, XOR, i + 1, numsSize);    
        }
    }
    else
        *total += XOR;
}

int subsetXORSum(int* nums, int numsSize) {
    // put appart special cases
    if (numsSize == 0)
        return 0;
    if (numsSize == 1)
        return nums[0];

    // calculate the sum of the XOR of every subsets (elements of powerset)
    int     total = 0;
    backtracking(&total, nums, 0, 0, numsSize);
    return total;
}