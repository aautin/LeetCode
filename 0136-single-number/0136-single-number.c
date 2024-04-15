int singleNumber(int* nums, int numsSize) {
    char    hashTab[60000] = "";
    short i;
    for (i = 0; i < numsSize; i++) {
        hashTab[nums[i] + 30000]++;
    }
    for (i = 0; hashTab[nums[i] + 30000] != 1; i++) {
    }
    return (nums[i]);
}