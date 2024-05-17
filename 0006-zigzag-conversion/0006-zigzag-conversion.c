// time complexity : nRows * sLen
// space complexity : void* + (sLen * char) + (4 * short)
char* convert(char* s, int nRows) {
    if (nRows == 1)
        return s;
    short   sLen = strlen(s);
    char    *result = malloc((sLen + 1) * sizeof(char));
    result[sLen] = '\0';

    for (short i = 0, k = 0; i < nRows; i++) {
        for (short j = 0; j < sLen; j++) {
            if ((j % ((nRows - 1) * 2) < nRows && j % ((nRows - 1) * 2) == i)
                || (j % ((nRows - 1) * 2) >= nRows && ((nRows - 1) * 2) - (j % ((nRows - 1) * 2)) == i))
                result[k++] = s[j];
        }
    }
    return result;
}