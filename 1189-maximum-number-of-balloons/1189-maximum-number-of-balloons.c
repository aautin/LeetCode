// hashTab-order : [a, b, l, n, o]
int maxNumberOfBalloons(char* text) {
    short   hashTab[5] = {0};

    while (*text) {
		switch(*text) {
            case 'a':
                hashTab[0]++;
                break;
            case 'b':
                hashTab[1]++;
                break;
            case 'l':
                hashTab[2]++;
                break;
            case 'n':
                hashTab[3]++;
                break;
            case 'o':
                hashTab[4]++;
        }
		text++;
    }

    hashTab[2] >>= 1;
    hashTab[4] >>= 1;

    if (hashTab[1] < hashTab[0])
        hashTab[0] = hashTab[1];
    hashTab[1] = 2;
    while (hashTab[1] < 5) {
        if (hashTab[hashTab[1]] < hashTab[0])
            hashTab[0] = hashTab[hashTab[1]];
        hashTab[1]++;
    }
    return (hashTab[0]);
}