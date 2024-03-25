char *ft_strchr(char *s, char a) {
    while (*s) {
        if (*s == a)
            return (s);
        s++;
    }
    return (NULL);
}

int	isEmpty(char toPlace[]) {
	while (*toPlace != -1) {
		if (*toPlace)
			return (0);
        toPlace++;
	}
	return (1);
}

char    *findThem(char toPlace[], char s[], char a) {
	int j;
	while (*s) {
		if (*s == a) {
			j = 0;
			while (j < 26) {
				if (toPlace[j] && !ft_strchr(s, j + 'a'))
					break ;
				j++;
			}
			if (j == 26)
				return (s);
		}
		s++;
	}
	return (NULL);
}

char	*removeDuplicateLetters(char *s) {
    char    toPlace[27] = "";
	char	*res = s;

    // store the letters to place in final result
    int i = 0;
    while (s[i]) {
        toPlace[s[i++] - 'a'] = 1;
    }
    toPlace[26] = -1;

	// select the letters to place in the right order
    int 	resLen = 0;
	char     *ptr;
    while (!isEmpty(toPlace)) {
		i = 0;
		while (i < 26) {
			if (toPlace[i]) {
				ptr = findThem(toPlace, s, i + 'a');
				if (ptr) {
					s = ptr + 1;
					toPlace[i] = 0;
					res[resLen++] = i + 'a';
					break ;
				}
			}
			i++;
		}
    }
	res[resLen] = 0;
    return res;
}