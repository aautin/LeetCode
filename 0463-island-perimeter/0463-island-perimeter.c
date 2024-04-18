int islandPerimeter(int** grid, int gridSize, int* gridColSize) {
    unsigned short    perimeter = 0;
    for (char i = 0; i < gridSize; i++) {
        for (char j = 0; j < *gridColSize; j++) {
            if (grid[i][j]) {
                if (!i)
                    perimeter++;
                else if (!grid[i - 1][j])
                    perimeter++;
                if (i == gridSize - 1)
                    perimeter++;
                else if (!grid[i + 1][j])
                    perimeter++;

                if (!j)
                    perimeter++;
                else if (!grid[i][j - 1])
                    perimeter++;
                if (j == *gridColSize - 1)
                    perimeter++;
                else if (!grid[i][j + 1])
                    perimeter++;
            }
        }
    }
    return perimeter;
}