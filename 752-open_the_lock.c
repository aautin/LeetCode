#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// queue part
typedef struct sQueue {
	char			code[4];
	struct sQueue	*next;
}	queue;
void	enqueue(queue **toCheck, char code[4]) {
	queue	*newElement = malloc(sizeof(*newElement));
	newElement->code[0] = code[0];
	newElement->code[1] = code[1];
	newElement->code[2] = code[2];
	newElement->code[3] = code[3];
	newElement->next = NULL;

	if (*toCheck) {
		queue	*ptr = *toCheck;
		while ((*toCheck)->next) {
			(*toCheck) = (*toCheck)->next;
		}
		(*toCheck)->next = newElement;
		*toCheck = ptr;
	}
	else
		*toCheck = newElement;
}

void	printQueue(queue *queue) {
	while (queue) {
		char	*code = queue->code;
 		printf("[%d%d%d%d]\n", code[0], code[1], code[2], code[3]);
		queue = queue->next;
	}
	printf("-------\n");
}

// check-codes part
bool	isSameCode(char code1[4], char code2[4]) {
	if (code1[0] == code2[0] && code1[1] == code2[1]
		&& code1[2] == code2[2] && code1[3] == code2[3])
		return true;
	return false;
}
bool	isDeadends(char deadends[][4], short deadendsSize, char code[4]) {
	while (deadendsSize--) {
		if (isSameCode(deadends[deadendsSize], code))
			return true;
	}
	return false;
}
bool	isChecked(queue *history, char code[4]) {
	while (history) {
		if (isSameCode(history->code, code))
			return true;
		history = history->next;
	}
	return false;
}

short   tryUnlock(queue *toCheck, char code[4], char ends[][4], short endsSize, char target[4]) {
	queue	*history = toCheck;
	queue	*nextToCheck = toCheck;

	short	moves = 0;
	char	temp;
	while (nextToCheck) {
    	printQueue(nextToCheck);
		toCheck = nextToCheck;
		nextToCheck = NULL;
		while (toCheck) {
			for (char i = 0; i < 4; i++) {
				temp = toCheck->code[i];
				toCheck->code[i] = (temp + 10 - 1) % 10;
				if (isSameCode(toCheck->code, target))
					return moves + 1;
				if (!isDeadends(ends, endsSize, toCheck->code) && !isChecked(history, toCheck->code)) {
					enqueue(&nextToCheck, toCheck->code);
					enqueue(&history, toCheck->code);
				}
				toCheck->code[i] = (temp + 10 + 1) % 10;
				if (isSameCode(toCheck->code, target))
					return moves + 1;
				if (!isDeadends(ends, endsSize, toCheck->code) && !isChecked(history, toCheck->code)) {
					enqueue(&nextToCheck, toCheck->code);
					enqueue(&history, toCheck->code);
				}
				toCheck->code[i] = temp;
			}
			toCheck = toCheck->next;
		}
		moves++;
	}

    return -1;
}
int openLock(char deadends[][4], int deadendsSize, char* target) {
	// convert the deadends ascii nbrs into value nbrs
	for (int i = 0; i < deadendsSize; i++) {
		deadends[i][0] -= '0';
		deadends[i][1] -= '0';
		deadends[i][2] -= '0';
		deadends[i][3] -= '0';
	}

	// convert the target ascii nbrs into value nbrs
	target[0] -= '0';
	target[1] -= '0';
	target[2] -= '0';
	target[3] -= '0';

	// init the first code's position, init the queue and start the BFS
	char	code[4] = {0, 0, 0, 0};
	queue	*toCheck = NULL;
	enqueue(&toCheck, code);
	return tryUnlock(toCheck, code, deadends, deadendsSize, target);
}

int	main(int argc, char **argv) {
	printf("%d\n", openLock(argv + 2, argc - 2, argv[1]));
	return (0);
}


    // // code[0] rev-rotate and rotate
    // temp = code[0];
	// code[0] = ((temp - 1) + 10) % 10;
	// if (!isDeadends(ends, endsSize, code) && !) {
    //     moves = tryUnlock(history, code, ends, endsSize, target, movesNbr);
    //     if (minMoves == -1 || moves < minMoves)
    //         minMoves = moves;
    // }
	// code[0] = ((temp + 1) + 10) % 10;
    // if (!isDeadends(ends, endsSize, code) && !isChecked(*history, code)) {
    //     moves = tryUnlock(history, code, ends, endsSize, target, movesNbr);
    //     if (moves != -1 && moves < minMoves)
    //         minMoves = moves;
    // }
	// code[0] = temp;

    // // code[1] rev-rotate and rotate
	// temp = code[1];
	// code[1] = ((temp - 1) + 10) % 10;
    // if (!isDeadends(ends, endsSize, code) && !isChecked(*history, code)) {
    //     moves = tryUnlock(history, code, ends, endsSize, target, movesNbr);
    //     if (moves != -1 && moves < minMoves)
    //         minMoves = moves;
    // }
	// code[1] = ((temp + 1) + 10) % 10;
    // if (!isDeadends(ends, endsSize, code) && !isChecked(*history, code)) {
    //     moves = tryUnlock(history, code, ends, endsSize, target, movesNbr);
    //     if (moves != -1 && moves < minMoves)
    //         minMoves = moves;
    // }
	// code[1] = temp;

    // // code[2] rev-rotate and rotate
	// temp = code[2];
	// code[2] = ((temp - 1) + 10) % 10;
    // if (!isDeadends(ends, endsSize, code) && !isChecked(*history, code)) {
    //     moves = tryUnlock(history, code, ends, endsSize, target, movesNbr);
    //     if (moves != -1 && moves < minMoves)
    //         minMoves = moves;
    // }
	// code[2] = ((temp + 1) + 10) % 10;
    // if (!isDeadends(ends, endsSize, code) && !isChecked(*history, code)) {
    //     moves = tryUnlock(history, code, ends, endsSize, target, movesNbr);
    //     if (moves != -1 && moves < minMoves)
    //         minMoves = moves;
    // }
	// code[2] = temp;

	// // code[3] rev-rotate and rotate
	// temp = code[3];
	// code[3] = ((temp - 1) + 10) % 10;
    // if (!isDeadends(ends, endsSize, code) && !isChecked(*history, code)) {
    //     moves = tryUnlock(history, code, ends, endsSize, target, movesNbr);
    //     if (moves != -1 && moves < minMoves)
    //         minMoves = moves;
    // }
	// code[3] = ((temp + 1) + 10) % 10;
    // if (!isDeadends(ends, endsSize, code) && !isChecked(*history, code)) {
    //     moves = tryUnlock(history, code, ends, endsSize, target, movesNbr);
    //     if (moves != -1 && moves < minMoves)
    //         minMoves = moves;
    // }
	// code[3] = temp;