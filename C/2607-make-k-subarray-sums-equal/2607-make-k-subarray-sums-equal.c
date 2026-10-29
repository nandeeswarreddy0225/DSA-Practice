
#include <stdlib.h>

int cmp(const void* a, const void* b) {
    int x = *(const int*)a;
    int y = *(const int*)b;
    return (x > y) - (x < y);
}

long long makeSubKSumEqual(int* arr, int arrSize, int k) {
    long long operations = 0;
    int* visited = (int*)calloc(arrSize, sizeof(int));
    int* group = (int*)malloc(arrSize * sizeof(int));

    for (int i = 0; i < arrSize; i++) {
        if (visited[i]) {
            continue;
        }

        int count = 0;
        int j = i;

        while (!visited[j]) {
            visited[j] = 1;
            group[count++] = arr[j];
            j = (j + k) % arrSize;
        }

        qsort(group, count, sizeof(int), cmp);

        int median = group[count / 2];

        for (int t = 0; t < count; t++) {
            long long diff = (long long)group[t] - median;
            operations += diff < 0 ? -diff : diff;
        }
    }

    free(visited);
    free(group);

    return operations;
}
