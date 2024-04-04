char	**createTrace(char const **board, int boardSize, int boardColSize) {
	char	**trace = malloc(boardSize * sizeof(char  *));
	if (trace == NULL)
		return (NULL);

	for (int i = 0; i < boardSize; i++) {
		trace[i] = malloc(boardColSize * sizeof(char));
		if (trace[i] == NULL)
			return (NULL);
		for (int j = 0; j < boardColSize; j++) {
			trace[i][j] = 0;
		}
	}
	return (trace);
}
bool	isInBoard(char **board, int boardSize, int boardColSize, char letter) {
	for (char i = 0; i < boardSize; i++) {
		for (char j = 0; j < boardColSize; j++) {
			if (board[i][j] == letter)
				return (true);
		}
	}
	return (false);
}
bool	search(char **board, char **trace, char posX, char posY, char *word, int size, int colSize) {
	if (!(*word))
		return (true);


	// upward-letter
	if (posX && board[posX - 1][posY] == *word && !trace[posX - 1][posY]) {
		trace[posX - 1][posY] = 1;
		if (search(board, trace, posX - 1, posY, word + 1, size, colSize))
			return (true);
	}

	// downward-letter
	if (posX < size - 1 && board[posX + 1][posY] == *word && !trace[posX + 1][posY]) {
		trace[posX + 1][posY] = 1;
		if (search(board, trace, posX + 1, posY, word + 1, size, colSize))
			return (true);
	}

	// leftward-letter
	if (posY && board[posX][posY - 1] == *word && !trace[posX][posY - 1]) {
		trace[posX][posY - 1] = 1;
		if (search(board, trace, posX, posY - 1, word + 1, size, colSize))
			return (true);
	}

	// rightward-letter
	if (posY < colSize - 1 && board[posX][posY + 1] == *word && !trace[posX][posY + 1]) {
		trace[posX][posY + 1] = 1;
		if (search(board, trace, posX, posY + 1, word + 1, size, colSize))
			return (true);
	}

	trace[posX][posY] = 0;
	return (false);
}
bool	exist(char** board, int boardSize, int* boardColSize, char* word) {
	

	for (char i = 0; word[i]; i++) {
		if (!isInBoard(board, boardSize, *boardColSize, word[i]))
			return (false);
	}
	char	**trace = createTrace(board, boardSize, *boardColSize);
	if (trace == NULL)
		return (false);
	for (char i = 0; i < boardSize; i++) {
		for (char j = 0; j < *boardColSize; j++) {
			if (board[i][j] == *word) {
				trace[i][j] = 1;
				if (search(board, trace, i, j, word + 1, boardSize, *boardColSize))
					return (true);
			}
		}
	}
	return (false);
}
