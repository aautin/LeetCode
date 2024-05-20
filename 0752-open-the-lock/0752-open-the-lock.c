// queue part
typedef struct sQueue {
	char			code[4];
	struct sQueue	*next;
}	queue;
void	enqueue(queue **toCheck, queue **ends, char *code) {
	queue	*newElement = malloc(sizeof(*newElement));
	newElement->code[0] = code[0];
	newElement->code[1] = code[1];
	newElement->code[2] = code[2];
	newElement->code[3] = code[3];
	newElement->next = NULL;

	if (*toCheck) {
		(*ends)->next = newElement;
		*ends = newElement;
	}
	else {
		*toCheck = newElement;
		*ends = newElement;
	}
}

// map part
void	initMap(bool map[10][10][10][10], char size) {
	for (int i0 = 0; i0 < size; i0++) {
		for (int i1 = 0; i1 < size; i1++) {
			for (int i2 = 0; i2 < size; i2++) {
				for (int i3 = 0; i3 < size; i3++) {
					map[i0][i1][i2][i3] = 0;
				}
			}
		}
	}
}

// codes-check part
bool	isSameCode(char *code1, char *code2) {
	return (code1[0] == code2[0] && code1[1] == code2[1] && code1[2] == code2[2]
		&& code1[3] == code2[3]) ? true : false;
}
bool	isFree(bool map[10][10][10][10], char *code) {
	return map[code[0]][code[1]][code[2]][code[3]] ? false : true;
}

// unlock part
int	tryUnlock(queue *toCheck, queue *toCheckEnd, char* code, bool taken[10][10][10][10], char *target) {
	int		moves = 0;
	int		layerRemainings = 0, nextLayerRemainings = 1;
	while (nextLayerRemainings) {
		layerRemainings = nextLayerRemainings;
		nextLayerRemainings = 0;
		while (layerRemainings) {
			char code[4];
			code[0] = toCheck->code[0];
			code[1] = toCheck->code[1];
			code[2] = toCheck->code[2];
			code[3] = toCheck->code[3];
			for (char i = 0; i < 4; i++) {
				code[i] = (toCheck->code[i] + 10 - 1) % 10;
				if (isSameCode(code, target))
					return moves + 1;
				if (isFree(taken, code)) {
					taken[code[0]][code[1]][code[2]][code[3]] = 1;
					enqueue(&toCheck, &toCheckEnd, code);
					nextLayerRemainings++;
				}
				code[i] = (toCheck->code[i] + 10 + 1) % 10;
				if (isSameCode(code, target))
					return moves + 1;
				if (isFree(taken, code)) {
					taken[code[0]][code[1]][code[2]][code[3]] = 1;
					enqueue(&toCheck, &toCheckEnd, code);
					nextLayerRemainings++;
				}
				code[i] = toCheck->code[i];
			}
			if (toCheck->next == NULL)
				toCheckEnd = NULL;
			toCheck = toCheck->next;
			layerRemainings--;
		}
		moves++;
	}

    return -1;
}

int openLock(char **ends, int endsSize, char *target) {
	
	// convert ends from char to int and put them into a map
	bool	taken[10][10][10][10];
	initMap(taken, 10);
	taken[0][0][0][0] = 1;
    for (int i = 0; i < endsSize; i++) {
		if (isSameCode(ends[i], "0000"))
            return -1;
		taken[ends[i][0] - '0'][ends[i][1] - '0'][ends[i][2] - '0'][ends[i][3] - '0'] = 1;
	}

	// convert target from char to int
	target[0] -= '0';
	target[1] -= '0';
	target[2] -= '0';
	target[3] -= '0';

	// init first code's position and toCheck's queue
	char	code[4] = {0, 0, 0, 0};
	if (isSameCode(target, code))
		return 0;
	queue	*toCheck = NULL, *toCheckEnd = NULL;
	enqueue(&toCheck, &toCheckEnd, code);

	return tryUnlock(toCheck, toCheckEnd, code, taken, target);
}