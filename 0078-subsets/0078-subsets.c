/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume
 * caller calls free().
 */
static int power(int n, int power) {
    int res = 1;
    while (power--)
        res *= n;
    return res;
}

static void backtracking(int currentSet, int iNums, int *iSet, int **powerset, int *nums, int numsSize, int **columnSizes) {
    if (iNums < numsSize) {
		backtracking(currentSet, iNums + 1, iSet, powerset, nums, numsSize, columnSizes);
		backtracking(currentSet + (1 << iNums), iNums + 1, iSet, powerset, nums, numsSize, columnSizes);
        return ;
	}
    char i = 0;
    char size = 0;
    for (i = 0; i < 16; i++) {
        if (currentSet & (1 << i))
            size++;
    }
    (*columnSizes)[*iSet] = size;
    powerset[*iSet] = malloc(size * sizeof(int));
    int index = 0;
    for (i = 0; i < 16; i++) {
        if (currentSet & (1 << i)) {
            powerset[*iSet][index++] = nums[i]; 
        }
    }
    (*iSet)++;
}

int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    int size = power(2, numsSize);
    int** powerset = malloc(size * sizeof(int*));
    *returnColumnSizes = malloc(size * sizeof(int));
    *returnSize = size;
    while (size--)
        powerset[size] = 0;
    int iSet = 0;
    backtracking(0, 0, &iSet, powerset, nums, numsSize, returnColumnSizes);
    return powerset;
}