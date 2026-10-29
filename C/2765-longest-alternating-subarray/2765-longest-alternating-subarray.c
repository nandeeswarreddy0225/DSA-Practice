
int alternatingSubarray(int* nums, int numsSize) {
    int maxLen = -1;

    for (int i = 0; i < numsSize - 1; i++) {
        if (nums[i + 1] != nums[i] + 1) {
            continue;
        }

        int j = i + 2;

        while (j < numsSize &&
               nums[j] == nums[i] + ((j - i) % 2)) {
            j++;
        }

        int len = j - i;

        if (len > maxLen) {
            maxLen = len;
        }
    }

    return maxLen;
}
