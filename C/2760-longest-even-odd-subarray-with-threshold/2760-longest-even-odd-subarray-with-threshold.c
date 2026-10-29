
int longestAlternatingSubarray(int* nums, int numsSize, int threshold) {
    int maxLen = 0;
    int i = 0;

    while (i < numsSize) {
        if (nums[i] > threshold || nums[i] % 2 != 0) {
            i++;
            continue;
        }

        int j = i;

        while (j + 1 < numsSize &&
               nums[j + 1] <= threshold &&
               nums[j] % 2 != nums[j + 1] % 2) {
            j++;
        }

        int len = j - i + 1;

        if (len > maxLen) {
            maxLen = len;
        }

        i = j + 1;
    }

    return maxLen;
}
