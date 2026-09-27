int numSpecial(int** mat, int matSize, int* matColSize) {
    int count = 0;

    for (int i = 0; i < matSize; i++) {
        for (int j = 0; j < *matColSize; j++) {
            if (mat[i][j] == 1) {
                int valid = 1;

                for (int k = 0; k < *matColSize; k++) {
                    if (k != j && mat[i][k] == 1) {
                        valid = 0;
                        break;
                    }
                }

                if (valid) {
                    for (int k = 0; k < matSize; k++) {
                        if (k != i && mat[k][j] == 1) {
                            valid = 0;
                            break;
                        }
                    }
                }

                if (valid)
                    count++;
            }
        }
    }

    return count;
}