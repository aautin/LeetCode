int strStr(char* haystack, char* needle) {
    unsigned short i, j;

    i = 0;
    while (haystack[i]) {
        j = 0;
        while (needle[j] && needle[j] == haystack[i + j])
            j++;
        if (!needle[j])
            return i;
        i++;
    }
    return -1;
}