static int power(int n, int power) {
    if (power == 0)
        return 1;
    while (power--)
        n *= n;
    return n;
}

static void backtracking(int iNums, int i int **powerset, int *nums, char current, char numsSize, int **returnColumnSizes, char *returnIndex) {
    if ()

}

int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    int size = power(2, numsSize);
    int** powerset = malloc(size * sizeof(int*));
    *returnColumnSizes = malloc(size * sizeof(int));
    *returnSize = size;
    while (size--)
        powerset[size] = 0;

    char index = 0;
    backtracking(0, powerset, nums, 0, numsSize, returnColumnSizes, &index);
    return powerset;
}