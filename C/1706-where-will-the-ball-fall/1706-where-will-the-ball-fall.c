
#include <stdlib.h>

int* findBall(int** grid, int gridSize, int* gridColSize, int* returnSize) {
    int m = gridSize;
    int n = gridColSize[0];

    int* result = (int*)malloc(n * sizeof(int));
    *returnSize = n;

    for (int col = 0; col < n; col++) {
        int c = col;

        for (int r = 0; r < m; r++) {
            int next = c + grid[r][c];

            if (next < 0 || next >= n ||
                grid[r][c] != grid[r][next]) {
                c = -1;
                break;
            }

            c = next;
        }

        result[col] = c;
    }

    return result;
}
