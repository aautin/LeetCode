#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// queue part
typedef struct sQueue {
	char			code[4];
	struct sQueue	*next;
}	queue;
void	enqueue(queue** toCheck, char* code) {
	queue*	newElement = malloc(sizeof(*newElement));
	newElement->code[0] = code[0];
	newElement->code[1] = code[1];
	newElement->code[2] = code[2];
	newElement->code[3] = code[3];
	newElement->next = NULL;

	if (*toCheck) {
		queue*	ptr = *toCheck;
		while (ptr->next)
			ptr = ptr->next;
		ptr->next = newElement;
	}
	else
		*toCheck = newElement;
}
void	printQueue(queue* queue) {
	while (queue) {
		char*	code = queue->code;
		queue = queue->next;
	}
}

// codes-check part
bool	isSameCode(char* code1, char* code2) {
	return (code1[0] == code2[0] && code1[1] == code2[1] && code1[2] == code2[2]
		&& code1[3] == code2[3]) ? true : false;
}
bool	isDeadends(char** deadends, int deadendsSize, char* code) {
	while (deadendsSize--) {
		if (isSameCode(deadends[deadendsSize], code))
			return true;
	}
	return false;
}
bool	isChecked(queue *history, char *code) {
	while (history) {
		if (isSameCode(history->code, code))
			return true;
		history = history->next;
	}
	return false;
}

int   tryUnlock(queue* toCheck, char* code, char** ends, int endsSize, char* target) {
	queue*	history = NULL;
	enqueue(&history, code);

	int		moves = 0;
	int		layerRemainings = 0, nextLayerRemainings = 1;
	while (nextLayerRemainings) {
    	printQueue(toCheck);
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
				if (!isDeadends(ends, endsSize, code) && !isChecked(history, code)) {
					enqueue(&history, code);
					enqueue(&toCheck, code);
					nextLayerRemainings++;
				}
				code[i] = (toCheck->code[i] + 10 + 1) % 10;
				if (isSameCode(code, target))
					return moves + 1;
				if (!isDeadends(ends, endsSize, code) && !isChecked(history, code)) {
					enqueue(&history, code);
					enqueue(&toCheck, code);
					nextLayerRemainings++;
				}
				code[i] = toCheck->code[i];
			}
			toCheck = toCheck->next;
			layerRemainings--;
		}
		moves++;
	}

    return -1;
}

int openLock(char** deadends, int deadendsSize, char* target) {
	// convert deadends from char to int
    for (int i = 0; i < deadendsSize; i++) {
		if (isSameCode(deadends[i], "0000"))
            return -1;
        deadends[i][0] -= '0';
		deadends[i][1] -= '0';
		deadends[i][2] -= '0';
		deadends[i][3] -= '0';
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
	queue*	toCheck = NULL;
	enqueue(&toCheck, code);

	return tryUnlock(toCheck, code, deadends, deadendsSize, target);
}

int	main(int argc, char **argv) {
	printf("%d\n", openLock(argv + 2, argc - 2, argv[1]));
	return (0);
}
