int abs(int a) {
    return a >= 0 ? a : -a;
}

int noPair(char* s, int pointsNb) {
    char    hashTab[26] = "";
    
    while (pointsNb--) {
        if (hashTab[s[pointsNb] - 'a'] == 1)
            return false;
        hashTab[s[pointsNb] - 'a']++;
    }  
    return true;
}

int isValidSquare(int** points, int pointsNb, char* s, int sqSize) {
    char    hashTab[26] = "";
    
    while (pointsNb--) {
        if (abs(points[pointsNb][0]) <= sqSize && abs(points[pointsNb][1]) <= sqSize)
        {
            if (hashTab[s[pointsNb] - 'a'] == 1)
                return false;
            else
                hashTab[s[pointsNb] - 'a'] = 1;
        }
    }
    return true;
}

int pointsInSquare(int** points, int pointsNb, char* s, int sqSize) {
    int nb = 0;
    while (pointsNb--) {
        if (abs(points[pointsNb][0]) <= sqSize && abs(points[pointsNb][1]) <= sqSize)
            nb++;
    }
    return nb;
}

int nextNb(int size, int **points, int pointsNb) {
    int minimalNext = INT_MAX;
    while (pointsNb--) {
        if (abs(points[pointsNb][0]) > size && abs(points[pointsNb][0]) < minimalNext)
            minimalNext = abs(points[pointsNb][0]);
        if (abs(points[pointsNb][1]) > size && abs(points[pointsNb][1]) < minimalNext)
            minimalNext = abs(points[pointsNb][1]);
    }
    return minimalNext;    
}

int maxPointsInsideSquare(int** points, int pointsNb, int* jaipaslu, char* s) {
    int sqSize = 0;

    if (noPair(s, pointsNb))
        return pointsNb;
    while (sqSize <= 1000000000 && isValidSquare(points, pointsNb, s, sqSize))
         sqSize = nextNb(sqSize, points, pointsNb);
    if (sqSize == 0)
        return 0;
    return pointsInSquare(points, pointsNb, s, sqSize - 1);
}  