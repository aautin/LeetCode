/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

static bool inTab(int **res, int resSize, int i, int j, int k) {
    for (int index = 0; index < resSize; index++) {
        if ((res[index][0] == i && res[index][1] == j && res[index][2] == k)
            || (res[index][0] == i && res[index][1] == k && res[index][2] == j)
            || (res[index][0] == j && res[index][1] == i && res[index][2] == k)
            || (res[index][0] == j && res[index][1] == k && res[index][2] == i)
            || (res[index][0] == k && res[index][1] == i && res[index][2] == j)
            || (res[index][0] == k && res[index][1] == j && res[index][2] == i))
            return true;
    }
    return false;
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    int i, j, k;
    int resSize = 0;
    for (i = 0; i < numsSize; i++) {
        for (j = 0; j < numsSize; j++) {
            for (k = 0; k < numsSize; k++) {
                if (i - j && i - k && j - k && nums[i] + nums[j] + nums[k] == 0)
                    resSize++;
            }
        }
    }
    if (resSize == 0)
        return NULL;
    int **res = calloc(resSize, sizeof(int*));
    *returnColumnSizes = calloc(resSize, sizeof(int));
    int index = 0;
    for (i = 0; i < numsSize; i++) {
        for (j = 0; j < numsSize; j++) {
            for (k = 0; k < numsSize; k++) {
                if (i - j && i - k && j - k && nums[i] + nums[j] + nums[k] == 0 && !inTab(res, index, nums[i], nums[j], nums[k])) {
					(*returnColumnSizes)[index] = 3;
                    res[index] = calloc(3, sizeof(int));
                    res[index][0] = nums[i];
                    res[index][1] = nums[j];
                    res[index][2] = nums[k];
                    index++;
                }
            }
        }
    }
    *returnSize = index;
    return res;
}

int main() {
    int nums[] = {-1, 0, 1, 2, -1, -4};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int returnSize;
    int *returnColumnSizes;

    int **result = threeSum(nums, numsSize, &returnSize, &returnColumnSizes);

    printf("Number of triplets: %d\n", returnSize);
    for (int i = 0; i < returnSize; i++) {
        printf("[%d, %d, %d]\n", result[i][0], result[i][1], result[i][2]);
        free(result[i]);
    }
    free(result);
    free(returnColumnSizes);

    return 0;
}