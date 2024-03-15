int lengthOfLastWord(char* s) {
    short  i = 0;
    
    while (s[i + 1])
        i++;
    while (s[i] == ' ')
        i--;
    while (i > 0 && s[i] != ' ')
        i--;
    if (s[i] == ' ')
        i++;
    s = s + i;
    i = 0;
    while (s[i] && s[i] != ' ')
        i++;
    return (i);
}
