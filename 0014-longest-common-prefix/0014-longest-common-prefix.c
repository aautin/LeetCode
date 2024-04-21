char* longestCommonPrefix(char** strs, int strsSize) {
    unsigned char   i;
    unsigned char   j;
    for (i = 1; i < strsSize; i++) {
        for (j = 0; strs[0][j]; j++) {
            if (strs[0][j] - strs[i][j]) {
                strs[0][j] = '\0';
                break ;
            }
        }
    }
    return (strs[0]);
}