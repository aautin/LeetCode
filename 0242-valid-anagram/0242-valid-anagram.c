bool isAnagram(char* s, char* t) {
    short    hashTab[26] = {
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0
    };

    while (*s) {
        hashTab[*s - 'a']++;
        s++;
    }
    while (*t) {
        hashTab[*t - 'a']--;
        t++;
    }

    short   i = 26;
    while (i--) {
        if (hashTab[i])
            return (false);
    }
    return (true);
}