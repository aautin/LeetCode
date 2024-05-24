int removeElement(int* nums, int numsSize, int val) {
    char i;
    for (i = 0; i < numsSize; i++) {
        if (nums[i] == val)
            nums[i] = -1;
    }    
    int newSize = 0;
    for (i = 0; i < numsSize; i++) {
        if (nums[i] != -1)
            nums[newSize++] = nums[i];
    }
    return newSize;
}