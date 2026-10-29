
#include <stdlib.h>

int minimumIndex(int* nums, int numsSize) {
    int candidate = 0;
    int balance = 0;

    for (int i = 0; i < numsSize; i++) {
        if (balance == 0) {
            candidate = nums[i];
            balance = 1;
        } else if (nums[i] == candidate) {
            balance++;
        } else {
            balance--;
        }
    }

    int total = 0;

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == candidate) {
            total++;
        }
    }

    int leftCount = 0;

    for (int i = 0; i < numsSize - 1; i++) {
        if (nums[i] == candidate) {
            leftCount++;
        }

        int rightCount = total - leftCount;

        if (leftCount * 2 > i + 1 &&
            rightCount * 2 > numsSize - i - 1) {
            return i;
        }
    }

    return -1;
}
