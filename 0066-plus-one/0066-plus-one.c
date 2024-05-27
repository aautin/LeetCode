/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int size, int* returnSize) {
    char i = 0;
    while (i < size && digits[i] == 9)
        i++;
    if (i == size) {
        *returnSize = ++size;
        int *newDigits = malloc(size * sizeof(int));
        newDigits[0] = 1;
        i = 1;
        while (i < size)
            newDigits[i++] = 0;
        return newDigits;
    }
    *returnSize = size;
    if (size > 0 && digits[size - 1] == 9) {
        i = 1;
        while (i) {
            i = 0;
            digits[size - 1] = 0;
            if (digits[size - 2] == 9) {
                digits[size - 2] = 0;
                i = 1;
            }
            else
                digits[size - 2]++;
            size--;
        }
    }
    else
        digits[size - 1] += 1;
    return digits;
}